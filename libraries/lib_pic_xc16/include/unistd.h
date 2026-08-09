#ifndef	_UNISTD_H
#define	_UNISTD_H

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

#define STDIN_FILENO  0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

#ifdef __cplusplus
#define NULL 0L
#else
#define NULL ((void*)0)
#endif

#define __NEED_size_t
#define __NEED_ssize_t
#define __NEED_uid_t
#define __NEED_gid_t
#define __NEED_off_t
#define __NEED_pid_t
#define __NEED_intptr_t
#define __NEED_useconds_t

#include <bits/alltypes.h>

int close(int);
off_t lseek(int, off_t, int);

int read(int, void *, unsigned int);
int write(int, const void *, unsigned int);
int open(const char *, int, int);

#define F_OK 0
#define R_OK 4
#define W_OK 2
#define X_OK 1

_Noreturn void _exit(int);

#define F_ULOCK 0
#define F_LOCK  1
#define F_TLOCK 2
#define F_TEST  3


#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#define L_SET 0
#define L_INCR 1
#define L_XTND 2
int brk(void *);
void *sbrk(intptr_t);
#endif

#ifdef __cplusplus
}
#endif

#endif
