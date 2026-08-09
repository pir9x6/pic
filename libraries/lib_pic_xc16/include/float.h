#ifndef _FLOAT_H_
#define _FLOAT_H_


/* Characteristics of floating types */

#define FLT_RADIX 2
#define FLT_ROUNDS 1

/* C99 specific macros */
#if (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) \
     || (defined (__cplusplus) && __cplusplus >= 201103L)

#undef  FLT_EVAL_METHOD
#ifdef __FLT_EVAL_METHOD__
#define FLT_EVAL_METHOD __FLT_EVAL_METHOD__
#else
#define FLT_EVAL_METHOD 0
#endif

#undef DECIMAL_DIG
#ifdef __DECIMAL_DIG__
#define DECIMAL_DIG __DECIMAL_DIG__
#else 
#define DECIMAL_DIG 17
#endif
     
#endif /* C99 */

/*
* These values provide information pertaining to the float type.
*/
#define FLT_EPSILON __FLT_EPSILON__
#define FLT_MAX __FLT_MAX__
#define FLT_MIN __FLT_MIN__
#define FLT_DIG __FLT_DIG__
#define FLT_MANT_DIG __FLT_MANT_DIG__
#define FLT_MAX_10_EXP __FLT_MAX_10_EXP__
#define FLT_MAX_EXP __FLT_MAX_EXP__
#define FLT_MIN_10_EXP __FLT_MIN_10_EXP__
#define FLT_MIN_EXP __FLT_MIN_EXP__



/*
* These values provide information pertaining to the double type
* The values are dependant upon the presence of the -fno-short-double
* compiler option.
*/
#define DBL_EPSILON __DBL_EPSILON__
#define DBL_MAX __DBL_MAX__
#define DBL_MIN __DBL_MIN__
#define DBL_DIG __DBL_DIG__
#define DBL_MANT_DIG __DBL_MANT_DIG__
#define DBL_MAX_10_EXP __DBL_MAX_10_EXP__
#define DBL_MAX_EXP __DBL_MAX_EXP__
#define DBL_MIN_10_EXP __DBL_MIN_10_EXP__
#define DBL_MIN_EXP __DBL_MIN_EXP__



/*
* These values provide information pertaining to the long double type.
*/
#define LDBL_EPSILON __LDBL_EPSILON__
#define LDBL_MAX __LDBL_MAX__
#define LDBL_MIN __LDBL_MIN__
#define LDBL_DIG __LDBL_DIG__
#define LDBL_MANT_DIG __LDBL_MANT_DIG__
#define LDBL_MAX_10_EXP __LDBL_MAX_10_EXP__
#define LDBL_MAX_EXP __LDBL_MAX_EXP__
#define LDBL_MIN_10_EXP __LDBL_MIN_10_EXP__
#define LDBL_MIN_EXP __LDBL_MIN_EXP__



/* C11*/
#if defined (__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
/* Versions of DECIMAL_DIG for each floating-point type.  */

#undef FLT_DECIMAL_DIG
#ifdef __FLT_DECIMAL_DIG__
#define FLT_DECIMAL_DIG __FLT_DECIMAL_DIG__
#else 
#define FLT_DECIMAL_DIG 9
#endif

#undef DBL_DECIMAL_DIG
#ifdef __DBL_DECIMAL_DIG__
#define DBL_DECIMAL_DIG __DBL_DECIMAL_DIG__ 
#else
#define DBL_DECIMAL_DIG 17
#endif

#undef LDBL_DECIMAL_DIG
#ifdef __LDBL_DECIMAL_DIG__
#define LDBL_DECIMAL_DIG __LDBL_DECIMAL_DIG__
#else
#define LDBL_DECIMAL_DIG DECIMAL_DIG
#endif

/* Whether types support subnormal numbers.  */
#undef FLT_HAS_SUBNORM
#ifdef __FLT_HAS_DENORM__
#define FLT_HAS_SUBNORM __FLT_HAS_DENORM__
#else
#define FLT_HAS_SUBNORM 1
#endif

#undef DBL_HAS_SUBNORM
#ifdef __DBL_HAS_DENORM__
#define DBL_HAS_SUBNORM __DBL_HAS_DENORM__
#else
#define DBL_HAS_SUBNORM 1
#endif

#undef LDBL_HAS_SUBNORM
#ifdef __LDBL_HAS_DENORM__
#define LDBL_HAS_SUBNORM __LDBL_HAS_DENORM__
#else
#define LDBL_HAS_SUBNORM 1
#endif

/* Minimum positive values, including subnormals.  */
#undef FLT_TRUE_MIN
#ifdef __FLT_DENORM_MIN__
#define FLT_TRUE_MIN __FLT_DENORM_MIN__
#else
#define FLT_TRUE_MIN 1.40129846432481707092e-45F
#endif

#undef DBL_TRUE_MIN
#ifdef __DBL_DENORM_MIN__
#define DBL_TRUE_MIN __DBL_DENORM_MIN__
#else
#define DBL_TRUE_MIN 4.94065645841246544177e-324
#endif

#undef LDBL_TRUE_MIN
#ifdef __LDBL_DENORM_MIN__
#define LDBL_TRUE_MIN __LDBL_DENORM_MIN__
#else
#define LDBL_TRUE_MIN 4.94065645841246544177e-324L
#endif

#endif /* C11 */




#endif