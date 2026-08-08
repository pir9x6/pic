/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */





/*
 * MPLAB XC-DSC - dsPIC33A Fixed Point Math Library
 *
 *
 * Signed fixed point types are defined as follows:
 *
 * _Qn_m, where:
 *
 *    n is the number of data bits to the left of the radix point
 *    m is the number of data bits to the right of the radix point
 *    (note: a sign bit is implied)
 *
 * For convenience, short names are also defined:
 *
 *  Exact Name     # Bits Required      Short Name
 *  ----------     ---------------      ----------
 *   _Q0_31              32                _Q31
 *
 *
 * Functions in the library are prefixed with the type
 *  of the return value. For example, _Q31acos returns
 *  a _Q31 value equal to the arc cosine of its argument.
 *
 * Note that argument types do not always match the
 * return type. Refer to the function prototype for
 * a specification of its arguments.
 *
 * In cases where the return value is not a fixed point
 * type, the argument type is appended to the function name.
 * For example, function _itoaQ31 accepts a type
 * _Q31 argument.
 *
 *
 */

#ifndef _libq_h_
#define _libq_h_ 

#ifdef	__cplusplus
extern "C" {
#endif


#define Q31(X) \
   ((X < 0.0) ? (int)(0x80000000*(X) - 0.5) : (int)(0x7FFFFFFF*(X) + 0.5)) 


typedef int _Q0_31;


typedef _Q0_31  _Q31;

/*
 * Global variables defined in the library
 */

 extern long  _Q31randomSeed;

/* Used by the "NoSat" functions to indicate that an overflow or underflow has occurred. */
/* Clear a flag before calling the related function.   */
 extern short _Q31shlSatFlag;  
 extern short _Q31shrSatFlag;  


/*
 * Prototypes for _Q31 Functions
 */
_Q31 _Q31abs(_Q31);
_Q31 _Q31acos(_Q31);
_Q31 _Q31acosByPI(_Q31);
_Q31 _Q31add(_Q31, _Q31);
_Q31 _Q31mul(_Q31, _Q31);
_Q31 _Q31div(_Q31, _Q31);
_Q31 _Q31asin(_Q31);
_Q31 _Q31asinByPI(_Q31);
_Q31 _Q31atan(_Q31);
_Q31 _Q31atanByPI(_Q31);
_Q31 _Q31atanYByX(_Q31,_Q31);
_Q31 _Q31atanYByXByPI(_Q31,_Q31);
_Q31 _Q31atoi(const unsigned char *);
_Q31 _Q31cos(_Q31);
_Q31 _Q31cosPI(_Q31);
_Q31 _Q31exp(_Q31);
_Q31 _Q31ftoi(float);
_Q31 _Q31log(_Q31);
_Q31 _Q31log10(_Q31);
_Q31 _Q31neg(_Q31);  /* this is the correct spelling */
_Q31 _Q31neq(_Q31) __attribute__((deprecated));
_Q31 _Q31norm (_Q31);
_Q31 _Q31power(_Q31, _Q31);
_Q31 _Q31random();
_Q31 _Q31shl (_Q31, short);
_Q31 _Q31shlNoSat(_Q31, short);
_Q31 _Q31shr (_Q31, short);
_Q31 _Q31shrNoSat (_Q31, short);
_Q31 _Q31sin(_Q31);
_Q31 _Q31sinPI(_Q31);
_Q31 _Q31sqrt(_Q31);
_Q31 _Q31sub(_Q31, _Q31);
_Q31 _Q31tan(_Q31);
_Q31 _Q31tanPI(_Q31);

float _itofQ31(_Q31);
void  _itoaQ31(_Q31, unsigned char *);
short _Q31sinSeries(_Q31, short, short, _Q31 *);

#ifdef	__cplusplus
}
#endif

 #endif
 
