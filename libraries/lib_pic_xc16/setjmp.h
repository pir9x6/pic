#ifndef __XC16__
#error "This version of setjmp.h is intended for MPLAB XC16 only"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __HAS_ISA32__
typedef unsigned int jmp_buf[18];
#else
typedef unsigned int jmp_buf[16+32+3+1];
#endif

void longjmp(jmp_buf, int);
int setjmp(jmp_buf);

#ifdef __cplusplus
}
#endif
