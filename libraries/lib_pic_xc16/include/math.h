#ifndef _MATH_H
#define _MATH_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <features.h>

#define __NEED_float_t
#define __NEED_double_t
#include <bits/alltypes.h>

#if 100*__GNUC__+__GNUC_MINOR__ >= 303
#define NAN       __builtin_nanf("")
#define INFINITY  __builtin_inff()
#else
#define NAN       (0.0f/0.0f)
#define INFINITY  1e5000f
#endif

#define HUGE_VALF INFINITY
#define HUGE_VAL  ((double)INFINITY)
#define HUGE_VALL ((long double)INFINITY)

#define MATH_ERRNO  1
#define MATH_ERREXCEPT 2
#define math_errhandling 1

#define FP_ILOGBNAN INT_MAX
#define FP_ILOGB0   INT_MIN

#define FP_NAN       0
#define FP_INFINITE  1
#define FP_ZERO      2
#define FP_SUBNORMAL 3
#define FP_NORMAL    4

int __fpclassify(double);
int __fpclassifyf(float);
int __fpclassifyl(long double);

static __inline uint32_t __FLOAT_BITS(float __f)
{
	union {float __f; uint32_t __i;} __u;
	__u.__f = __f;
	return __u.__i;
}
static __inline uint64_t __LONG_DOUBLE_BITS(long double __f)
{
	union {long double __f; uint64_t __i;} __u;
	__u.__f = __f;
	return __u.__i;
}

#define fpclassify(x) ( \
	sizeof(x) == sizeof(float) ? __fpclassifyf(x) : \
	                             __fpclassifyl(x) )

#ifdef __HAS_ISA32__
#define isinf(x) ( \
        sizeof(x) == sizeof(float) ? (__builtin_isinff(x)) : \
                                     (__builtin_isinfl(x)))
#else
#define isinf(x) ( \
        sizeof(x) == sizeof(float) ? (__FLOAT_BITS(x) & 0x7fffffff) == 0x7f800000 : \
                                     (__LONG_DOUBLE_BITS(x) & -1ULL>>1) == 0x7ffULL<<52 )
#endif

#ifdef __HAS_ISA32__
#define isnan(x) ( \
        sizeof(x) == sizeof(float) ? (__builtin_isnanf(x)) : \
                                     (__builtin_isnanl(x)))
#else
#define isnan(x) ( \
        sizeof(x) == sizeof(float) ? (__FLOAT_BITS(x) & 0x7fffffff) > 0x7f800000 : \
                                     (__LONG_DOUBLE_BITS(x) & -1ULL>>1) > 0x7ffULL<<52 )
#endif

#define isnormal(x) ( \
        sizeof(x) == sizeof(float) ? ((__FLOAT_BITS(x)+0x00800000) & 0x7fffffff) >= 0x01000000 : \
                                     ((__LONG_DOUBLE_BITS(x)+(1ULL<<52)) & -1ULL>>1) >= 1ULL<<53 )

#define isfinite(x) ( \
	sizeof(x) == sizeof(float) ? (__FLOAT_BITS(x) & 0x7fffffff) < 0x7f800000 : \
	                             (__LONG_DOUBLE_BITS(x) & -1ULL>>1) < 0x7ffULL<<52 )

int __signbit(double);
int __signbitf(float);
int __signbitl(long double);

#define signbit(x) ( \
	sizeof(x) == sizeof(float) ? ((int32_t)__FLOAT_BITS(x)>>31) :   \
	                             ((int64_t)__LONG_DOUBLE_BITS(x)>>63) )

#define isunordered(x,y) (isnan((x)) ? ((void)(y),1) : isnan((y)))

#define __ISREL_DEF(rel, op, type) \
static __inline int __is##rel(type __x, type __y) \
{ return !isunordered(__x,__y) && __x op __y; }

__ISREL_DEF(lessf, <, float_t)
__ISREL_DEF(less, <, double_t)
__ISREL_DEF(lessl, <, long double)
__ISREL_DEF(lessequalf, <=, float_t)
__ISREL_DEF(lessequal, <=, double_t)
__ISREL_DEF(lessequall, <=, long double)
__ISREL_DEF(lessgreaterf, !=, float_t)
__ISREL_DEF(lessgreater, !=, double_t)
__ISREL_DEF(lessgreaterl, !=, long double)
__ISREL_DEF(greaterf, >, float_t)
__ISREL_DEF(greater, >, double_t)
__ISREL_DEF(greaterl, >, long double)
__ISREL_DEF(greaterequalf, >=, float_t)
__ISREL_DEF(greaterequal, >=, double_t)
__ISREL_DEF(greaterequall, >=, long double)

#define __tg_pred_2(x, y, p) ( \
	sizeof((x)+(y)) == sizeof(float) ? p##f(x, y) : \
	sizeof((x)+(y)) == sizeof(double) ? p(x, y) : \
	p##l(x, y) )

#define isless(x, y)            __tg_pred_2(x, y, __isless)
#define islessequal(x, y)       __tg_pred_2(x, y, __islessequal)
#define islessgreater(x, y)     __tg_pred_2(x, y, __islessgreater)
#define isgreater(x, y)         __tg_pred_2(x, y, __isgreater)
#define isgreaterequal(x, y)    __tg_pred_2(x, y, __isgreaterequal)

#ifdef __cplusplus
/* not compatible with C++ */
#undef __XCDSC_BUILTIN_LIB__
#endif

#if (__DBL_MANT_DIG__ != __FLT_MANT_DIG__)
#ifdef __XCDSC_BUILTIN_LIB__
  /* use __builtin_<fn>() where appropriate, disable with:
   *   -fno-builtin on the command line, or 
   *   -U__XCDSC_BUILTIN_LIB__ on the command line, or
   *   #undef __XCDSC_BUILTIN_LIB__ in source code (before including math.h).
   */
#define sqrt __builtin_sqrt
#else
double      sqrt(double);
#endif

double      acos(double);
double      acosh(double);
double      asin(double);
double      asinh(double);
double      atan(double);
double      atan2(double, double);
double      atanh(double);
double      cbrt(double);
double      ceil(double);
double      copysign(double, double);
double      cos(double);
double      cosh(double);
double      erf(double);
double      erfc(double);
double      exp(double);
double      exp2(double);
double      expm1(double);
double      fabs(double);
double      fdim(double, double);
double      floor(double);
double      fma(double, double, double);
double      fmax(double, double);
double      fmin(double, double);
double      fmod(double, double);
double      frexp(double, int *);
double      hypot(double, double);
double      ldexp(double, int);
double      lgamma(double);
double      log(double);
double      log10(double);
double      log1p(double);
double      log2(double);
double      logb(double);
double      modf(double, double *);
double      nan(const char *);
double      nearbyint(double);
double      nextafter(double, double);
double      nexttoward(double, long double);
double      pow(double, double);
double      remainder(double, double);
double      remquo(double, double, int *);
double      rint(double);
double      round(double);
double      scalbln(double, long);
double      scalbn(double, int);
double      sin(double);
double      sinh(double);
double      tan(double);
double      tanh(double);
double      tgamma(double);
double      trunc(double);
int         ilogb(double);
long long   llrint(double);
long long   llround(double);
long        lrint(double);
long        lround(double);
#endif

/*
 *   prototypes for the float maths functions. 
 */
#ifdef __XCDSC_BUILTIN_LIB__
  /* use __builtin_<fn>() where appropriate, disable with:
   *   -fno-builtin on the command line, or 
   *   -U__XCDSC_BUILTIN_LIB__ on the command line, or
   *   #undef __XCDSC_BUILTIN_LIB__ in source code (before including math.h).
   */
#define sqrtf __builtin_sqrtf
#define cosf  __builtin_cosf
#define sinf  __builtin_sinf
#else
float       sqrtf(float);
float       cosf(float);
float       sinf(float);
#endif

float       acosf(float);
float       acoshf(float);
float       asinf(float);
float       asinhf(float);
float       atanf(float);
float       atan2f(float, float);
float       atanhf(float);
float       cbrtf(float);
float       ceilf(float);
float       copysignf(float, float);
float       coshf(float);
float       erff(float);
float       erfcf(float);
float       expf(float);
float       exp2f(float);
float       expm1f(float);
float       fabsf(float);
float       fdimf(float, float);
float       floorf(float);
float       fmaf(float, float, float);
float       fmaxf(float, float);
float       fminf(float, float);
float       fmodf(float, float);
float       frexpf(float, int *);
float       hypotf(float, float);
float       ldexpf(float, int);
float       lgammaf(float);
float       logf(float);
float       log10f(float);
float       log1pf(float);
float       log2f(float);
float       logbf(float);

#if (__DBL_MANT_DIG__ == __FLT_MANT_DIG__)
/*
 *  Without -fno-short-double, float * and double * are compatable, but a
 *  warning can still be produced.
 */
float       modff(float, void *);
#else
float       modff(float, float *);
#endif

float       nanf(const char *);
float       nearbyintf(float);
float       nextafterf(float, float);
float       nexttowardf(float, long double);
float       powf(float, float);
float       remainderf(float, float);
float       remquof(float, float, int *);
float       rintf(float);
float       roundf(float);
float       scalblnf(float, long);
float       scalbnf(float, int);
float       sinhf(float);
float       tanf(float);
float       tanhf(float);
float       tgammaf(float);
float       truncf(float);
int         ilogbf(float);
long long   llrintf(float);
long long   llroundf(float);
long        lrintf(float);
long        lroundf(float);


/*
 *    prototypes for long double maths functions.  On dsPIC30, long double
 *      is always 64bits regardless of the setting of the -fno-short-double
 *      and -fshort-double options.
 */
#ifdef __XCDSC_BUILTIN_LIB__
  /* use __builtin_<fn>() where appropriate, disable with:
   *   -fno-builtin on the command line, or 
   *   -U__XCDSC_BUILTIN_LIB__ on the command line, or
   *   #undef __XCDSC_BUILTIN_LIB__ in source code (before including math.h).
   */
#define sqrtl __builtin_sqrtl
#else
long double      sqrtl(long double);
#endif

long double acosl(long double);
long double acoshl(long double);
long double asinl(long double);
long double asinhl(long double);
long double atanl(long double);
long double atan2l(long double, long double);
long double atanhl(long double);
long double cbrtl(long double);
long double ceill(long double);
long double copysignl(long double, long double);
long double cosl(long double);
long double coshl(long double);
long double erfl(long double);
long double erfcl(long double);
long double expl(long double);
long double exp2l(long double);
long double expm1l(long double);
long double fabsl(long double);
long double fdiml(long double, long double);
long double floorl(long double);
long double fmal(long double, long double, long double);
long double fmaxl(long double, long double);
long double fminl(long double, long double);
long double fmodl(long double, long double);
long double frexpl(long double, int *);
long double hypotl(long double, long double);
int         ilogbl(long double);
long double ldexpl(long double, int);
long double lgammal(long double);
long long   llrintl(long double);
long long   llroundl(long double);
long double logl(long double);
long double log10l(long double);
long double log1pl(long double);
long double log2l(long double);
long double logbl(long double);
long        lrintl(long double);
long        lroundl(long double);
long double modfl(long double, long double *);
long double nanl(const char *);
long double nearbyintl(long double);
long double nextafterl(long double, long double);
long double nexttowardl(long double, long double);
long double powl(long double, long double);
long double remainderl(long double, long double);
long double remquol(long double, long double, int *);
long double rintl(long double);
long double roundl(long double);
long double scalblnl(long double, long);
long double scalbnl(long double, int);
long double sinl(long double);
long double sinhl(long double);
long double tanl(long double);
long double tanhl(long double);
long double tgammal(long double);
long double truncl(long double);


#if defined(_XOPEN_SOURCE) || defined(_BSD_SOURCE)
#undef  MAXFLOAT
#define MAXFLOAT        3.40282346638528859812e+38F
#endif

#if defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#define M_E             2.7182818284590452354   /* e */
#define M_LOG2E         1.4426950408889634074   /* log_2 e */
#define M_LOG10E        0.43429448190325182765  /* log_10 e */
#define M_LN2           0.69314718055994530942  /* log_e 2 */
#define M_LN10          2.30258509299404568402  /* log_e 10 */
#define M_PI            3.14159265358979323846  /* pi */
#define M_PI_2          1.57079632679489661923  /* pi/2 */
#define M_PI_4          0.78539816339744830962  /* pi/4 */
#define M_1_PI          0.31830988618379067154  /* 1/pi */
#define M_2_PI          0.63661977236758134308  /* 2/pi */
#define M_2_SQRTPI      1.12837916709551257390  /* 2/sqrt(pi) */
#define M_SQRT2         1.41421356237309504880  /* sqrt(2) */
#define M_SQRT1_2       0.70710678118654752440  /* 1/sqrt(2) */

extern int signgam;

double      j0(double);
double      j1(double);
double      jn(int, double);

double      y0(double);
double      y1(double);
double      yn(int, double);
#endif

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#define HUGE            3.40282346638528859812e+38F

double      drem(double, double);
float       dremf(float, float);

int         finite(double);
int         finitef(float);

double      scalb(double, double);
float       scalbf(float, float);

double      significand(double);
float       significandf(float);

double      lgamma_r(double, int*);
float       lgammaf_r(float, int*);

float       j0f(float);
float       j1f(float);
float       jnf(int, float);

float       y0f(float);
float       y1f(float);
float       ynf(int, float);
#endif

#ifdef _GNU_SOURCE
long double lgammal_r(long double, int*);

void        sincos(double, double*, double*);
void        sincosf(float, float*, float*);
void        sincosl(long double, long double*, long double*);

double      exp10(double);
float       exp10f(float);
long double exp10l(long double);

double      pow10(double);
float       pow10f(float);
long double pow10l(long double);
#endif

/*
 *   macro definitions to ensure that the default functions are correct
 *     for the chosen size of double:  see -fno-short-double and -fshort-double
 */

#if (__DBL_MANT_DIG__ == __FLT_MANT_DIG__)
#define __MPROTO(x)  x ## f
#else
#define __MPROTO(x)  x
#endif

#define acos          __MPROTO(acos)
#define acosh         __MPROTO(acosh)
#define asin          __MPROTO(asin)
#define asinh         __MPROTO(asinh)
#define atan          __MPROTO(atan)
#define atan2         __MPROTO(atan2)
#define atanh         __MPROTO(atanh)
#define cbrt          __MPROTO(cbrt)
#define ceil          __MPROTO(ceil)
#define copysign      __MPROTO(copysign)
#define cos           __MPROTO(cos)
#define cosh          __MPROTO(cosh)
#define erf           __MPROTO(erf)
#define erfh          __MPROTO(erfh)
#define exp           __MPROTO(exp)
#define exp2          __MPROTO(exp2)
#define expm1         __MPROTO(expm1)
#define fabs          __MPROTO(fabs)
#define fdim          __MPROTO(fdim)
#define floor         __MPROTO(floor)
#define fma           __MPROTO(fma)
#define fmax          __MPROTO(fmax)
#define fmin          __MPROTO(fmin)
#define fmod          __MPROTO(fmod)
#define frexp         __MPROTO(frexp)
#define hypot         __MPROTO(hypot)
#define ldexp         __MPROTO(ldexp)
#define ldgamma       __MPROTO(ldgamma)
#define log           __MPROTO(log)
#define log10         __MPROTO(log10)
#define log1p         __MPROTO(log1p)
#define log2          __MPROTO(log2)
#define logb          __MPROTO(logb)
#define modf          __MPROTO(modf)
#define nan           __MPROTO(nan)
#define nearbyint     __MPROTO(nearbyint)
#define nextafter     __MPROTO(nextafter)
#define nexttoward    __MPROTO(nexttoward)
#define pow           __MPROTO(pow)
#define remainder     __MPROTO(remainder)
#define remquo        __MPROTO(remquo)
#define rint          __MPROTO(rint)
#define round         __MPROTO(round)
#define scalbln       __MPROTO(scalbln)
#define scalbn        __MPROTO(scalbn)
#define sin           __MPROTO(sin)
#define sinh          __MPROTO(sinh)
#define sqrt          __MPROTO(sqrt)
#define tan           __MPROTO(tan)
#define tanh          __MPROTO(tanh)
#define tgamma        __MPROTO(tgamma)
#define trunc         __MPROTO(trunc)
#define trunc         __MPROTO(trunc)
#define ilogb         __MPROTO(ilogb)
#define llrint        __MPROTO(llrint)
#define llround       __MPROTO(llround)
#define lrint         __MPROTO(lrint)
#define lround        __MPROTO(lround)

#ifdef __cplusplus
}
#endif

#endif
