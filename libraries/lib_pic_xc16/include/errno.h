#ifndef	_ERRNO_H
#define _ERRNO_H

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

#include <bits/errno.h>

extern int *__errno (void);
extern int __errno_val;
#define errno (__errno_val)

#ifdef __cplusplus
}
#endif

#endif

