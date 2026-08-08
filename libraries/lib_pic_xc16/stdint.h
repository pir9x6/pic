#ifndef _STDINT_H
#define _STDINT_H

#define __NEED_int8_t
#define __NEED_int16_t
#define __NEED_int32_t
#define __NEED_int64_t

#define __NEED_uint8_t
#define __NEED_uint16_t
#define __NEED_uint32_t
#define __NEED_uint64_t

#define __NEED_intptr_t
#define __NEED_uintptr_t

#define __NEED_intmax_t
#define __NEED_uintmax_t

#include <bits/alltypes.h>

#ifdef __INT_FAST8_TYPE__
typedef __INT_FAST8_TYPE__ int_fast8_t;
#else
typedef int16_t int_fast8_t;
#endif

#ifdef __INT_FAST64_TYPE__
typedef __INT_FAST64_TYPE__ int_fast64_t;
#else
typedef int64_t int_fast64_t;
#endif

#ifdef __INT_LEAST8_TYPE__
typedef __INT_LEAST8_TYPE__ int_least8_t;
#else
typedef int8_t  int_least8_t;
#endif

#ifdef __INT_LEAST16_TYPE__
typedef __INT_LEAST16_TYPE__ int_least16_t;
#else
typedef int16_t int_least16_t;
#endif

#ifdef __INT_LEAST24_TYPE__
typedef __INT_LEAST24_TYPE__ int_least24_t;
#else
typedef int32_t int_least24_t;
#endif

#ifdef __INT_LEAST32_TYPE__
typedef __INT_LEAST32_TYPE__ int_least32_t;
#else
typedef int32_t int_least32_t;
#endif

#ifdef __INT_LEAST64_TYPE__
typedef __INT_LEAST64_TYPE__ int_least64_t;
#else
typedef int64_t int_least64_t;
#endif

#ifdef __UINT_FAST8_TYPE__
typedef __UINT_FAST8_TYPE__ uint_fast8_t;
#else
typedef uint16_t uint_fast8_t;
#endif

#ifdef __UINT_FAST24_TYPE__
typedef __UINT_FAST24_TYPE__ uint_fast24_t;
#else
typedef uint32_t uint_fast24_t;
#endif

#ifdef __UINT_FAST64_TYPE__
typedef __UINT_FAST64_TYPE__ uint_fast64_t;
#else
typedef uint64_t uint_fast64_t;
#endif

#ifdef __UINT_LEAST8_TYPE__
typedef __UINT_LEAST8_TYPE__ uint_least8_t;
#else
typedef uint8_t  uint_least8_t;
#endif

#ifdef __UINT_LEAST16_TYPE__
typedef __UINT_LEAST16_TYPE__ uint_least16_t;
#else
typedef uint16_t uint_least16_t;
#endif

#ifdef __UINT_LEAST24_TYPE__
typedef __UINT_LEAST24_TYPE__ uint_least24_t;
#else
typedef uint32_t uint_least24_t;
#endif

#ifdef __UINT_LEAST32_TYPE__
typedef __UINT_LEAST32_TYPE__ uint_least32_t;
#else
typedef uint32_t uint_least32_t;
#endif

#ifdef __UINT_LEAST64_TYPE__
typedef __UINT_LEAST64_TYPE__ uint_least64_t;
#else
typedef uint64_t uint_least64_t;
#endif

#ifdef __INT8_MAX__
#undef	INT8_MAX
#define INT8_MAX   __INT8_MAX__
#undef	INT8_MIN
#define INT8_MIN   (-__INT8_MAX__ - 1)
#else
#define INT8_MAX   (0x7f)
#define INT8_MIN   (-1-0x7f)
#endif

#ifdef __INT16_MAX__
#undef	INT16_MAX
#define INT16_MAX  __INT16_MAX__
#undef	INT16_MIN
#define INT16_MIN  (-__INT16_MAX__-1)
#else
#define INT16_MAX  (0x7fff)
#define INT16_MIN  (-1-0x7fff)
#endif

#ifdef __INT32_MAX__
#undef	INT32_MAX
#define INT32_MAX  __INT32_MAX__
#undef	INT32_MIN
#define INT32_MIN  (-__INT32_MAX__-1)
#else
#define INT32_MAX  (0x7fffffff)
#define INT32_MIN  (-1-0x7fffffff)
#endif


#ifdef __INT64_MAX__
#undef	INT64_MAX
#define INT64_MAX  __INT64_MAX__
#undef	INT64_MIN
#define INT64_MIN  (-__INT64_MAX__-1)
#else
#define INT64_MAX  (0x7fffffffffffffff)
#define INT64_MIN  (-1-0x7fffffffffffffff)
#endif


#ifdef __UINT8_MAX__
#undef	UINT8_MAX
#define UINT8_MAX  __UINT8_MAX__
#else
#define UINT8_MAX  (0xff)
#endif

#ifdef __UINT16_MAX__
#undef	UINT16_MAX
#define UINT16_MAX __UINT16_MAX__
#else
#define UINT16_MAX (0xffff)
#endif

#ifdef __UINT32_MAX__
#undef	UINT32_MAX
#define UINT32_MAX __UINT32_MAX__
#else
#define UINT32_MAX (0xffffffffu)
#endif

#ifdef __UINT64_MAX__
#undef	UINT64_MAX
#define UINT64_MAX __UINT64_MAX__
#else
#define UINT64_MAX (0xffffffffffffffffu)
#endif



#ifdef __INT_FAST8_MAX__
#undef INT_FAST8_MAX
#define INT_FAST8_MAX   __INT_FAST8_MAX__
#undef INT_FAST8_MIN
#define INT_FAST8_MIN   (-__INT_FAST8_MAX__-1)
#else
#define INT_FAST8_MAX   INT8_MAX
#define INT_FAST8_MIN   INT8_MIN
#endif

#ifdef __INT_FAST24_MAX__
#undef INT_FAST24_MAX
#define INT_FAST24_MAX   __INT_FAST24_MAX__
#undef INT_FAST24_MIN
#define INT_FAST24_MIN   (-__INT_FAST24_MAX__-1)
#else
#define INT_FAST24_MAX   INT32_MAX
#define INT_FAST24_MIN   INT32_MIN
#endif

#ifdef __INT_FAST64_MAX__
#undef	INT_FAST64_MAX
#define INT_FAST64_MAX  __INT_FAST64_MAX__
#undef	INT_FAST64_MIN
#define INT_FAST64_MIN  (-__INT_FAST64_MAX__-1)
#else
#define INT_FAST64_MAX  INT64_MAX
#define INT_FAST64_MIN  INT64_MIN
#endif

#ifdef __INT_LEAST8_MAX__
#undef	INT_LEAST8_MAX
#define INT_LEAST8_MAX   __INT_LEAST8_MAX__
#undef	INT_LEAST8_MIN
#define INT_LEAST8_MIN   (-__INT_LEAST8_MAX__-1)
#else
#define INT_LEAST8_MAX   INT8_MAX
#define INT_LEAST8_MIN   INT8_MIN
#endif

#ifdef __INT_LEAST16_MAX__
#undef	INT_LEAST16_MAX
#define INT_LEAST16_MAX  __INT_LEAST16_MAX__
#undef	INT_LEAST16_MIN
#define INT_LEAST16_MIN  (-__INT_LEAST16_MAX__-1)
#else
#define INT_LEAST16_MAX  INT16_MAX
#define INT_LEAST16_MIN  INT16_MIN
#endif

#ifdef __INT_LEAST24_MAX__
#undef	INT_LEAST24_MAX
#define INT_LEAST24_MAX  __INT_LEAST24_MAX__
#undef	INT_LEAST24_MIN
#define INT_LEAST24_MIN  (-__INT_LEAST24_MAX__-1)
#else
#define INT_LEAST24_MAX  INT32_MAX
#define INT_LEAST24_MIN  INT32_MIN
#endif

#ifdef __INT_LEAST32_MAX__
#undef INT_LEAST32_MAX
#define INT_LEAST32_MAX  __INT_LEAST32_MAX__
#undef INT_LEAST32_MIN
#define INT_LEAST32_MIN  (-__INT_LEAST32_MAX__-1)
#else
#define INT_LEAST32_MAX  INT32_MAX
#define INT_LEAST32_MIN  INT32_MIN
#endif

#ifdef __INT_LEAST64_MAX__
#undef INT_LEAST64_MAX
#define INT_LEAST64_MAX  __INT_LEAST64_MAX__
#undef INT_LEAST64_MIN
#define INT_LEAST64_MIN  (-__INT_LEAST64_MAX__-1)
#else
#define INT_LEAST64_MAX  INT64_MAX
#define INT_LEAST64_MIN  INT64_MIN
#endif

#ifdef __UINT_FAST8_MAX__
#undef	UINT_FAST8_MAX
#define UINT_FAST8_MAX  __UINT_FAST8_MAX__
#else
#define UINT_FAST8_MAX  UINT8_MAX
#endif

#ifdef __UINT_FAST24_MAX__
#undef	UINT_FAST24_MAX
#define UINT_FAST24_MAX  __UINT_FAST24_MAX__
#else
#define UINT_FAST24_MAX  UINT32_MAX
#endif

#ifdef __UINT_FAST64_MAX__
#undef	UINT_FAST64_MAX
#define UINT_FAST64_MAX __UINT_FAST64_MAX__
#else
#define UINT_FAST64_MAX UINT64_MAX
#endif

#ifdef __UINT_LEAST8_MAX__
#undef	UINT_LEAST8_MAX
#define UINT_LEAST8_MAX  __UINT_LEAST8_MAX__
#else
#define UINT_LEAST8_MAX  UINT8_MAX
#endif

#ifdef __UINT_LEAST16_MAX__
#undef	UINT_LEAST16_MAX
#define UINT_LEAST16_MAX __UINT_LEAST16_MAX__
#else
#define UINT_LEAST16_MAX UINT16_MAX
#endif

#ifdef __UINT_LEAST24_MAX__
#undef	UINT_LEAST24_MAX
#define UINT_LEAST24_MAX __UINT_LEAST24_MAX__
#else
#define UINT_LEAST24_MAX UINT32_MAX
#endif

#ifdef __UINT_LEAST32_MAX__
#undef	UINT_LEAST32_MAX
#define UINT_LEAST32_MAX __UINT_LEAST32_MAX__
#else
#define UINT_LEAST32_MAX UINT32_MAX
#endif

#ifdef __UINT_LEAST64_MAX__
#undef	UINT_LEAST64_MAX
#define UINT_LEAST64_MAX __UINT_LEAST64_MAX__
#else
#define UINT_LEAST64_MAX UINT64_MAX
#endif

#ifdef __INTMAX_MIN__
#undef	INTMAX_MIN
#define INTMAX_MIN  __INTMAX_MIN__
#else
#define INTMAX_MIN  INT64_MIN
#endif

#ifdef __INTMAX_MAX__
#undef	INTMAX_MAX
#define INTMAX_MAX  __INTMAX_MAX__
#else
#define INTMAX_MAX  INT64_MAX
#endif

#ifdef __UINTMAX_MAX__
#undef	UINTMAX_MAX
#define UINTMAX_MAX __UINTMAX_MAX__
#else
#define UINTMAX_MAX UINT64_MAX
#endif

#ifdef __WINT_MIN__
#undef WINT_MIN
#define WINT_MIN __WINT_MIN__
#else
#undef WINT_MIN
#define WINT_MIN 0U
#endif

#ifdef __WINT_MAX__
#undef WINT_MAX
#define WINT_MAX __WINT_MAX__
#else
#undef WINT_MAX
#define WINT_MAX UINT16_MAX
#endif

#ifdef __WCHAR_MIN__
#undef WCHAR_MIN
#define WCHAR_MIN __WCHAR_MIN__
#else
#undef WCHAR_MIN
#define WCHAR_MIN 0U
#endif

#ifdef __WCHAR_MAX__
#undef WCHAR_MAX
#define WCHAR_MAX __WCHAR_MAX__
#else
#undef WCHAR_MAX
#define WCHAR_MAX UINT16_MAX
#endif

#ifdef __SIG_ATOMIC_MIN__
#undef	SIG_ATOMIC_MIN
#define SIG_ATOMIC_MIN  __SIG_ATOMIC_MIN__
#else
#define SIG_ATOMIC_MIN  INT16_MIN
#endif

#ifdef __SIG_ATOMIC_MAX__
#undef	SIG_ATOMIC_MAX
#define SIG_ATOMIC_MAX  __SIG_ATOMIC_MAX__
#else
#define SIG_ATOMIC_MAX  INT16_MAX
#endif

#include <bits/stdint.h>

#ifdef __INT8_C
#undef	INT8_C
#define INT8_C(c) __INT8_C(c)
#else
#define INT8_C(c)  c
#endif

#ifdef __INT16_C
#undef	INT16_C
#define INT16_C(c) __INT16_C(c)
#else
#define INT16_C(c) c
#endif

#ifdef __INT32_C
#undef	INT32_C
#define INT32_C(c) __INT32_C(c)
#else
#define INT32_C(c) c ## L
#endif

#ifdef __UINT8_C
#undef	UINT8_C
#define UINT8_C(c)  __UINT8_C(c)
#else
#define UINT8_C(c)  c
#endif

#ifdef __UINT16_C
#undef	UINT16_C
#define UINT16_C(c) __UINT16_C(c)
#else
#define UINT16_C(c) c
#endif

#ifdef __UINT32_C
#undef	UINT32_C
#define UINT32_C(c) __UINT32_C(c)
#else
#define UINT32_C(c) c ## UL
#endif

#ifdef __INT64_C
#undef	INT64_C
#define INT64_C(c) __INT64_C(c)
#else
#define INT64_C(c) c ## LL
#endif

#ifdef __UINT64_C
#undef	UINT64_C
#define UINT64_C(c) __UINT64_C(c)
#else
#define UINT64_C(c) c ## ULL
#endif

#ifdef __INTMAX_C
#undef INTMAX_C
#define INTMAX_C(c)  __INTMAX_C(c)
#else
#define INTMAX_C(c)  c ## LL
#endif

#ifdef __UINTMAX_C
#undef	UINTMAX_C
#define UINTMAX_C(c) __UINTMAX_C(c)
#else
#define UINTMAX_C(c) c ## ULL
#endif

#endif
