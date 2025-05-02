/*******************************************************************

                  Generic Type Definitions

********************************************************************
 FileName:        GenericTypeDefs.h
 Dependencies:    None
 Processor:       PIC10, PIC12, PIC16, PIC18, PIC24, dsPIC, PIC32
*******************************************************************/

#ifndef __GENERIC_TYPE_DEFS_H_
#define __GENERIC_TYPE_DEFS_H_

#include "types.h"
/* Specify an extension for GCC based compilers */
#if defined(__GNUC__)
#define __EXTENSION __extension__
#else
#define __EXTENSION
#endif

#if !defined(__PACKED)
    #define __PACKED
#endif

/* get compiler defined type definitions (NULL, size_t, etc) */
#include <stddef.h> 

// typedef enum _BOOL { FALSE = 0, TRUE } BOOL;    /* Undefined size */
typedef enum _BIT { CLEAR = 0, SET } BIT;

#define PUBLIC                                  /* Function attributes */
#define PROTECTED
#define PRIVATE   static

/* INT is processor specific in length may vary in size */
// typedef signed int          INT;
// typedef signed char         s8;
// typedef signed short int    s16;
// typedef signed long int     s32;


/* UINT is processor specific in length may vary in size */
// typedef unsigned int        UINT;
// typedef unsigned char       u8;
// typedef unsigned short int  u16;
// typedef unsigned long int   u32;     /* other name for 32-bit integer */

typedef union
{
    u8 Val;
    struct
    {
        __EXTENSION u8 b0:1;
        __EXTENSION u8 b1:1;
        __EXTENSION u8 b2:1;
        __EXTENSION u8 b3:1;
        __EXTENSION u8 b4:1;
        __EXTENSION u8 b5:1;
        __EXTENSION u8 b6:1;
        __EXTENSION u8 b7:1;
    } bits;
} UINT8_VAL, UINT8_BITS;

typedef union 
{
    u16 Val;
    u8 v[2] __PACKED;
    struct __PACKED
    {
        u8 LB;
        u8 HB;
    } byte;
    struct __PACKED
    {
        __EXTENSION u8 b0:1;
        __EXTENSION u8 b1:1;
        __EXTENSION u8 b2:1;
        __EXTENSION u8 b3:1;
        __EXTENSION u8 b4:1;
        __EXTENSION u8 b5:1;
        __EXTENSION u8 b6:1;
        __EXTENSION u8 b7:1;
        __EXTENSION u8 b8:1;
        __EXTENSION u8 b9:1;
        __EXTENSION u8 b10:1;
        __EXTENSION u8 b11:1;
        __EXTENSION u8 b12:1;
        __EXTENSION u8 b13:1;
        __EXTENSION u8 b14:1;
        __EXTENSION u8 b15:1;
    } bits;
} UINT16_VAL, UINT16_BITS;


typedef union
{
    u32 Val;
    u16 w[2] __PACKED;
    u8  v[4] __PACKED;
    struct __PACKED
    {
        u16 LW;
        u16 HW;
    } word;
    struct __PACKED
    {
        u8 LB;
        u8 HB;
        u8 UB;
        u8 MB;
    } byte;
    struct __PACKED
    {
        UINT16_VAL low;
        UINT16_VAL high;
    }wordUnion;
    struct __PACKED
    {
        __EXTENSION u8 b0:1;
        __EXTENSION u8 b1:1;
        __EXTENSION u8 b2:1;
        __EXTENSION u8 b3:1;
        __EXTENSION u8 b4:1;
        __EXTENSION u8 b5:1;
        __EXTENSION u8 b6:1;
        __EXTENSION u8 b7:1;
        __EXTENSION u8 b8:1;
        __EXTENSION u8 b9:1;
        __EXTENSION u8 b10:1;
        __EXTENSION u8 b11:1;
        __EXTENSION u8 b12:1;
        __EXTENSION u8 b13:1;
        __EXTENSION u8 b14:1;
        __EXTENSION u8 b15:1;
        __EXTENSION u8 b16:1;
        __EXTENSION u8 b17:1;
        __EXTENSION u8 b18:1;
        __EXTENSION u8 b19:1;
        __EXTENSION u8 b20:1;
        __EXTENSION u8 b21:1;
        __EXTENSION u8 b22:1;
        __EXTENSION u8 b23:1;
        __EXTENSION u8 b24:1;
        __EXTENSION u8 b25:1;
        __EXTENSION u8 b26:1;
        __EXTENSION u8 b27:1;
        __EXTENSION u8 b28:1;
        __EXTENSION u8 b29:1;
        __EXTENSION u8 b30:1;
        __EXTENSION u8 b31:1;
    } bits;
} UINT32_VAL;


/***********************************************************************************/

/* Alternate definitions */
typedef void                    VOID;

// typedef char                    CHAR8;
// typedef unsigned char           UCHAR8;

// typedef unsigned char           u8;                           /* 8-bit unsigned  */
// typedef unsigned short int      u16;                           /* 16-bit unsigned */
// typedef unsigned long           u32;                          /* 32-bit unsigned */
/* MPLAB C Compiler for PIC18 does not support 64-bit integers */
__EXTENSION
// typedef unsigned long long      u32;                          /* 64-bit unsigned */
typedef signed char             CHAR;                           /* 8-bit signed    */
typedef signed short int        SHORT;                          /* 16-bit signed   */
typedef signed long             LONG;                           /* 32-bit signed   */
/* MPLAB C Compiler for PIC18 does not support 64-bit integers */
__EXTENSION
typedef signed long long        LONGLONG;                       /* 64-bit signed   */
typedef union
{
    u8 Val;
    struct __PACKED
    {
        __EXTENSION u8 b0:1;
        __EXTENSION u8 b1:1;
        __EXTENSION u8 b2:1;
        __EXTENSION u8 b3:1;
        __EXTENSION u8 b4:1;
        __EXTENSION u8 b5:1;
        __EXTENSION u8 b6:1;
        __EXTENSION u8 b7:1;
    } bits;
} BYTE_VAL, BYTE_BITS;

typedef union
{
    u16 Val;
    u8 v[2] __PACKED;
    struct __PACKED
    {
        u8 LB;
        u8 HB;
    } byte;
    struct __PACKED
    {
        __EXTENSION u8 b0:1;
        __EXTENSION u8 b1:1;
        __EXTENSION u8 b2:1;
        __EXTENSION u8 b3:1;
        __EXTENSION u8 b4:1;
        __EXTENSION u8 b5:1;
        __EXTENSION u8 b6:1;
        __EXTENSION u8 b7:1;
        __EXTENSION u8 b8:1;
        __EXTENSION u8 b9:1;
        __EXTENSION u8 b10:1;
        __EXTENSION u8 b11:1;
        __EXTENSION u8 b12:1;
        __EXTENSION u8 b13:1;
        __EXTENSION u8 b14:1;
        __EXTENSION u8 b15:1;
    } bits;
} WORD_VAL, WORD_BITS;

typedef union
{
    u32 Val;
    u16 w[2] __PACKED;
    u8 v[4] __PACKED;
    struct __PACKED
    {
        u16 LW;
        u16 HW;
    } word;
    struct __PACKED
    {
        u8 LB;
        u8 HB;
        u8 UB;
        u8 MB;
    } byte;
    struct __PACKED
    {
        WORD_VAL low;
        WORD_VAL high;
    }wordUnion;
    struct __PACKED
    {
        __EXTENSION u8 b0:1;
        __EXTENSION u8 b1:1;
        __EXTENSION u8 b2:1;
        __EXTENSION u8 b3:1;
        __EXTENSION u8 b4:1;
        __EXTENSION u8 b5:1;
        __EXTENSION u8 b6:1;
        __EXTENSION u8 b7:1;
        __EXTENSION u8 b8:1;
        __EXTENSION u8 b9:1;
        __EXTENSION u8 b10:1;
        __EXTENSION u8 b11:1;
        __EXTENSION u8 b12:1;
        __EXTENSION u8 b13:1;
        __EXTENSION u8 b14:1;
        __EXTENSION u8 b15:1;
        __EXTENSION u8 b16:1;
        __EXTENSION u8 b17:1;
        __EXTENSION u8 b18:1;
        __EXTENSION u8 b19:1;
        __EXTENSION u8 b20:1;
        __EXTENSION u8 b21:1;
        __EXTENSION u8 b22:1;
        __EXTENSION u8 b23:1;
        __EXTENSION u8 b24:1;
        __EXTENSION u8 b25:1;
        __EXTENSION u8 b26:1;
        __EXTENSION u8 b27:1;
        __EXTENSION u8 b28:1;
        __EXTENSION u8 b29:1;
        __EXTENSION u8 b30:1;
        __EXTENSION u8 b31:1;
    } bits;
} DWORD_VAL;

/* MPLAB C Compiler for PIC18 does not support 64-bit integers */
typedef union
{
    u32 Val;
    u32 d[2] __PACKED;
    u16 w[4] __PACKED;
    u8 v[8] __PACKED;
    struct __PACKED
    {
        u32 LD;
        u32 HD;
    } dword;
    struct __PACKED
    {
        u16 LW;
        u16 HW;
        u16 UW;
        u16 MW;
    } word;
    struct __PACKED
    {
        __EXTENSION u8 b0:1;
        __EXTENSION u8 b1:1;
        __EXTENSION u8 b2:1;
        __EXTENSION u8 b3:1;
        __EXTENSION u8 b4:1;
        __EXTENSION u8 b5:1;
        __EXTENSION u8 b6:1;
        __EXTENSION u8 b7:1;
        __EXTENSION u8 b8:1;
        __EXTENSION u8 b9:1;
        __EXTENSION u8 b10:1;
        __EXTENSION u8 b11:1;
        __EXTENSION u8 b12:1;
        __EXTENSION u8 b13:1;
        __EXTENSION u8 b14:1;
        __EXTENSION u8 b15:1;
        __EXTENSION u8 b16:1;
        __EXTENSION u8 b17:1;
        __EXTENSION u8 b18:1;
        __EXTENSION u8 b19:1;
        __EXTENSION u8 b20:1;
        __EXTENSION u8 b21:1;
        __EXTENSION u8 b22:1;
        __EXTENSION u8 b23:1;
        __EXTENSION u8 b24:1;
        __EXTENSION u8 b25:1;
        __EXTENSION u8 b26:1;
        __EXTENSION u8 b27:1;
        __EXTENSION u8 b28:1;
        __EXTENSION u8 b29:1;
        __EXTENSION u8 b30:1;
        __EXTENSION u8 b31:1;
        __EXTENSION u8 b32:1;
        __EXTENSION u8 b33:1;
        __EXTENSION u8 b34:1;
        __EXTENSION u8 b35:1;
        __EXTENSION u8 b36:1;
        __EXTENSION u8 b37:1;
        __EXTENSION u8 b38:1;
        __EXTENSION u8 b39:1;
        __EXTENSION u8 b40:1;
        __EXTENSION u8 b41:1;
        __EXTENSION u8 b42:1;
        __EXTENSION u8 b43:1;
        __EXTENSION u8 b44:1;
        __EXTENSION u8 b45:1;
        __EXTENSION u8 b46:1;
        __EXTENSION u8 b47:1;
        __EXTENSION u8 b48:1;
        __EXTENSION u8 b49:1;
        __EXTENSION u8 b50:1;
        __EXTENSION u8 b51:1;
        __EXTENSION u8 b52:1;
        __EXTENSION u8 b53:1;
        __EXTENSION u8 b54:1;
        __EXTENSION u8 b55:1;
        __EXTENSION u8 b56:1;
        __EXTENSION u8 b57:1;
        __EXTENSION u8 b58:1;
        __EXTENSION u8 b59:1;
        __EXTENSION u8 b60:1;
        __EXTENSION u8 b61:1;
        __EXTENSION u8 b62:1;
        __EXTENSION u8 b63:1;
    } bits;
} QWORD_VAL;

#undef __EXTENSION

#endif /* __GENERIC_TYPE_DEFS_H_ */
