@echo off
cd /d "%~dp0"

echo Starting MPLAB Build Dashboard...
start "" http://127.0.0.1:8000

python compiler/server.py

pause
