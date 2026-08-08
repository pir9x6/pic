#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) \
 || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#define PAGE_SIZE 4096
#define LONG_BIT 32
#endif

/* int properties */
#define SHRT_MAX   0x7fff

#ifdef __HAS_ISA32__
#define INT_MAX    0x7fffffff
#else
#define INT_MAX    SHRT_MAX
#endif

/* long properties */
#define LONG_MAX   0x7fffffff

/* long long properties */
#define LLONG_MAX  0x7fffffffffffffffLL
