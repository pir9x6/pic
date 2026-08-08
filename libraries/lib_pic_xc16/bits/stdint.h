#ifdef __INT_FAST16_TYPE__
typedef __INT_FAST16_TYPE__ int_fast16_t;
#else
typedef int16_t int_fast16_t;
#endif

#ifdef __INT_FAST32_TYPE__
typedef __INT_FAST32_TYPE__ int_fast32_t;
#else
typedef int32_t int_fast32_t;
#endif

#ifdef __UINT_FAST16_TYPE__
typedef __UINT_FAST16_TYPE__ uint_fast16_t;
#else
typedef uint32_t uint_fast16_t;
#endif

#ifdef __UINT_FAST32_TYPE__
typedef __UINT_FAST32_TYPE__ uint_fast32_t;
#else
typedef uint32_t uint_fast32_t;
#endif

#ifdef __INT_FAST16_MAX__
#undef INT_FAST16_MAX
#define INT_FAST16_MAX  __INT_FAST16_MAX__
#undef INT_FAST16_MIN
#define INT_FAST16_MIN  (-__INT_FAST16_MAX__-1)
#else
#warning "__INT_FAST16_MAX__ is not defined"
#define INT_FAST16_MAX  INT16_MAX
#define INT_FAST16_MIN  INT16_MIN
#endif

#ifdef __INT_FAST32_MAX__
#undef INT_FAST32_MAX
#define INT_FAST32_MAX  __INT_FAST32_MAX__
#undef INT_FAST32_MIN
#define INT_FAST32_MIN  (-__INT_FAST32_MAX__-1)
#else
#warning "__INT_FAST32_MAX__ is not defined"
#define INT_FAST32_MIN  INT32_MIN
#define INT_FAST32_MAX  INT32_MAX
#endif


#ifdef __UINT_FAST16_MAX__
#undef UINT_FAST16_MAX
#define UINT_FAST16_MAX __UINT_FAST16_MAX__
#else
#warning "__UINT_FAST16_MAX__ is not defined"
#define UINT_FAST16_MAX UINT32_MAX
#endif

#ifdef __UINT_FAST32_MAX__
#undef UINT_FAST32_MAX
#define UINT_FAST32_MAX __UINT_FAST32_MAX__
#else
#warning "__UINT_FAST32_MAX__ is not defined"
#define UINT_FAST32_MAX UINT32_MAX
#endif

#ifdef __INTPTR_MAX__
#undef INTPTR_MAX
#define INTPTR_MAX      __INTPTR_MAX__
#undef INTPTR_MIN
#define INTPTR_MIN      (-__INTPTR_MAX__-1)
#else
#warning "__INTPTR_MAX__ is not defined"
#define INTPTR_MIN      INT16_MIN
#define INTPTR_MAX      INT16_MAX
#endif

#ifdef __UINTPTR_MAX__
#undef UINTPTR_MAX
#define UINTPTR_MAX     __UINTPTR_MAX__
#else
#warning "__UINTPTR_MAX__ is not defined"
#define UINTPTR_MAX     UINT16_MAX
#endif

#ifdef __PTRDIFF_MAX__
#undef PTRDIFF_MAX
#define PTRDIFF_MAX     __PTRDIFF_MAX__
#undef PTRDIFF_MIN
#define PTRDIFF_MIN     (-__PTRDIFF_MAX__-1)
#else
#warning "__PTRDIFF_MAX__ is not defined"
#define PTRDIFF_MIN     INT16_MIN
#define PTRDIFF_MAX     INT16_MAX
#endif

#ifdef __SIZE_MAX__
#define SIZE_MAX        __SIZE_MAX__
#else
#warning "__SIZE_MAX__ is not defined"
#define SIZE_MAX        UINT16_MAX
#endif
