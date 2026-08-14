import json, os, subprocess, threading, time, uuid, re
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from urllib.parse import urlparse

BASE_DIR=os.path.dirname(os.path.abspath(__file__))
CONFIG_FILE=os.path.join(BASE_DIR,"projects.json")
LOG_DIR=os.path.join(BASE_DIR,"logs")
os.makedirs(LOG_DIR,exist_ok=True)
state_lock=threading.Lock(); projects_state={}; running_all=False

def load_config():
    with open(CONFIG_FILE,encoding="utf-8") as f: return json.load(f)

def get_last_build(pid):
    """Return the timestamp of the most recent build log for a project."""
    prefix=f"{pid}_"
    latest=None
    try:
        for name in os.listdir(LOG_DIR):
            if not (name.startswith(prefix) and name.endswith(".log")):
                continue
            m=re.match(rf"^{re.escape(pid)}_(\d{{8}}_\d{{6}})_",name)
            if not m:
                continue
            try:
                dt=time.strptime(m.group(1),"%Y%m%d_%H%M%S")
                stamp=time.strftime("%Y-%m-%d %H:%M:%S",dt)
                if latest is None or stamp > latest:
                    latest=stamp
            except ValueError:
                pass
    except OSError:
        pass
    return latest

def init_state():
    global projects_state
    with state_lock:
        for p in load_config()["projects"]:
            projects_state[p["id"]]={"id":p["id"],"name":p["name"],"status":"NOT BUILT","running":False,
              "duration":None,"log_file":None,"error":None,"error_lines":[],"enabled":p.get("enabled",True),"last_build":get_last_build(p["id"])}

def get_project(pid):
    return next((p for p in load_config()["projects"] if p["id"]==pid),None)

def set_state(pid,**kw):
    with state_lock:
        if pid in projects_state: projects_state[pid].update(kw)

def set_project_enabled(pid, enabled):
    data=load_config()
    changed=False
    for project in data["projects"]:
        if project["id"]==pid:
            project["enabled"]=enabled
            changed=True
            break
    if not changed: return False
    tmp=CONFIG_FILE+".tmp"
    with open(tmp,"w",encoding="utf-8") as f:
        json.dump(data,f,ensure_ascii=False,indent=2)
    os.replace(tmp,CONFIG_FILE)
    set_state(pid,enabled=enabled)
    return True

def extract_errors(text):
    out=[]
    diag=re.compile(r"[^\\/:]+(?:\.[chS]|\.s|\.asm)?(?::\d+(?::\d+)?)?\s*:\s*(?:fatal error|error|warning)\s*:",re.I)
    for line in text.splitlines():
        s=line.strip()
        if diag.search(s) or re.search(r"make(?:\[\d+\])?:\s+\*\*\*.*(?:Error|error|failed)",s,re.I):
            if s not in out: out.append(s)
    return out[:5]

def run_project(pid):
    p=get_project(pid)
    if not p: set_state(pid,status="FAILED",error="Project not found"); return False
    if not p.get("enabled",True): return False
    path=os.path.abspath(p["path"]); script=p.get("script","compile.bat")
    script_path=os.path.join(path,script)
    log_name=f'{pid}_{time.strftime("%Y%m%d_%H%M%S")}_{uuid.uuid4().hex[:6]}.log'
    log_path=os.path.join(LOG_DIR,log_name)
    set_state(pid,status="BUILDING",running=True,duration=None,log_file=log_name,error=None,error_lines=[])
    start=time.time()
    try:
        if not os.path.isdir(path): raise RuntimeError(f"Project directory does not exist: {path}")
        if not os.path.isfile(script_path): raise RuntimeError(f"Build script does not exist: {script_path}")
        proc=subprocess.Popen(["cmd.exe","/c",script],cwd=path,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,
                              stdin=subprocess.DEVNULL,text=True,encoding="utf-8",errors="replace",bufsize=1)
        captured=[]
        with open(log_path,"w",encoding="utf-8",errors="replace") as log:
            log.write(f"PROJECT: {p['name']}\nPATH: {path}\nSCRIPT: {script}\n"+"="*80+"\n\n")
            for line in proc.stdout: captured.append(line); log.write(line); log.flush()
            code=proc.wait(); log.write(f"\n{'='*80}\nEXIT CODE: {code}\n")
        errors=extract_errors("".join(captured)); duration=round(time.time()-start,1)
        set_state(pid,status="PASSED" if code==0 else "FAILED",running=False,duration=duration,
                  last_build=time.strftime("%Y-%m-%d %H:%M:%S"),
                  error=None if code==0 else f"Build returned exit code {code}",error_lines=errors)
        return code==0
    except Exception as e:
        with open(log_path,"a",encoding="utf-8",errors="replace") as log: log.write("\nEXCEPTION: "+str(e)+"\n")
        set_state(pid,status="FAILED",running=False,duration=round(time.time()-start,1),
                  last_build=time.strftime("%Y-%m-%d %H:%M:%S"),
                  error=str(e),error_lines=[str(e)])
        return False

def build_one(pid):
    threading.Thread(target=run_project,args=(pid,),daemon=True).start()

def build_failed():
    global running_all
    with state_lock:
        running_all=True

    def worker():
        global running_all
        try:
            for p in load_config()["projects"]:
                pid=p["id"]
                with state_lock:
                    state=projects_state.get(pid,{})
                    should_build=(
                        state.get("status")=="FAILED"
                        and state.get("enabled",p.get("enabled",True))
                    )
                if should_build:
                    run_project(pid)
        finally:
            with state_lock:
                running_all=False

    threading.Thread(target=worker,daemon=True).start()

def build_all():
    global running_all
    with state_lock: running_all=True
    def worker():
        global running_all
        try:
            for p in load_config()["projects"]:
                if p.get("enabled",True): run_project(p["id"])
        finally:
            with state_lock: running_all=False
    threading.Thread(target=worker,daemon=True).start()

class Handler(BaseHTTPRequestHandler):
    def send_json(self,data,status=200):
        b=json.dumps(data,ensure_ascii=False).encode()
        self.send_response(status); self.send_header("Content-Type","application/json; charset=utf-8")
        self.send_header("Content-Length",str(len(b))); self.send_header("Cache-Control","no-cache"); self.end_headers(); self.wfile.write(b)
    def send_file(self,path,ctype):
        try:
            b=open(path,"rb").read()
            self.send_response(200); self.send_header("Content-Type",ctype); self.send_header("Content-Length",str(len(b))); self.end_headers(); self.wfile.write(b)
        except FileNotFoundError: self.send_error(404)
    def do_GET(self):
        p=urlparse(self.path).path
        if p=="/": return self.send_file(os.path.join(BASE_DIR,"templates","index.html"),"text/html; charset=utf-8")
        if p=="/api/status":
            with state_lock: return self.send_json({"running_all":running_all,"projects":list(projects_state.values())})
        if p.startswith("/api/log/"):
            pid=p[len("/api/log/"):]
            with state_lock: s=projects_state.get(pid)
            if not s or not s["log_file"]: return self.send_json({"error":"No log available"},404)
            try: return self.send_json({"log":open(os.path.join(LOG_DIR,s["log_file"]),encoding="utf-8",errors="replace").read()})
            except FileNotFoundError: return self.send_json({"error":"Log not found"},404)
        self.send_error(404)
    def do_POST(self):
        global running_all
        p=urlparse(self.path).path
        with state_lock: busy=running_all or any(x["running"] for x in projects_state.values())
        if p.startswith("/api/toggle/"):
            pid=p[len("/api/toggle/"):]
            if pid not in projects_state: return self.send_json({"error":"Unknown project"},404)
            if busy: return self.send_json({"error":"A build is already running"},409)
            try:
                length=int(self.headers.get("Content-Length","0") or 0)
                data=json.loads(self.rfile.read(length) or "{}")
                enabled=bool(data.get("enabled",True))
            except Exception:
                return self.send_json({"error":"Invalid request"},400)
            if not set_project_enabled(pid,enabled): return self.send_json({"error":"Unknown project"},404)
            return self.send_json({"ok":True,"enabled":enabled})

        if p.startswith("/api/open-folder/"):
            pid=p[len("/api/open-folder/"):]
            project=get_project(pid)
            if not project:
                return self.send_json({"error":"Unknown project"},404)
            path=os.path.abspath(project["path"])
            if not os.path.isdir(path):
                return self.send_json({"error":f"Project directory does not exist: {path}"},404)
            try:
                os.startfile(path)
                return self.send_json({"ok":True})
            except Exception as e:
                return self.send_json({"error":str(e)},500)

        if p.startswith("/api/build/"):
            pid=p[len("/api/build/"):]
            if pid not in projects_state: return self.send_json({"error":"Unknown project"},404)
            if busy: return self.send_json({"error":"A build is already running"},409)
            if not projects_state[pid].get("enabled",True): return self.send_json({"error":"Build is disabled"},409)
            build_one(pid); return self.send_json({"ok":True})
        if p=="/api/build-failed":
            if busy:
                return self.send_json({"error":"A build is already running"},409)

            with state_lock:
                failed_count=sum(
                    1 for s in projects_state.values()
                    if s.get("status")=="FAILED" and s.get("enabled",True)
                )

            if failed_count==0:
                return self.send_json(
                    {"error":"No enabled projects have failed builds"},409
                )

            build_failed()
            return self.send_json({"ok":True})

        if p=="/api/build-all":
            if busy: return self.send_json({"error":"A build is already running"},409)
            build_all(); return self.send_json({"ok":True})
        self.send_error(404)
    def log_message(self,*args): pass

if __name__=="__main__":
    init_state(); host="127.0.0.1"; port=8000
    print(f"MPLAB Build Dashboard\nOpen http://{host}:{port}\nPress Ctrl+C to stop.")
    ThreadingHTTPServer((host,port),Handler).serve_forever()
