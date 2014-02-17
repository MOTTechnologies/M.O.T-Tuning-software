#ifndef _FENV_H
#define _FENV_H


#include <machine/intrinsics.h>


/* IEEE754 rounding modes */
/* Macros according to ISO/IEC 9899:1999 */
#define FE_TONEAREST  0x0UL /* Rounding toward nearest */
#define FE_UPWARD     0x1UL /* Rounding toward +INFINITY */
#define FE_DOWNWARD   0x2UL /* Rounding toward -INFINITY */
#define FE_TOWARDZERO 0x3UL /* Rounding toward zero */


extern inline int fesetround(int)  __attribute__ ((always_inline));
extern inline int fegetround(void) __attribute__ ((always_inline));
/* 
   A CALL saves the context and a RET restores the context.
   Therefore a RET makes the changes in PSW to get lost.
   => Functions must be inlined and cannot be part of a lib. 
*/


/* Get current IEE754 rounding mode */
extern inline int fegetround(void)
{
    /* PSW bitfield RM, bits [25:24] contains rounding mode */
    return((_mfcr($psw) & 0x03000000UL) >> 24uL);
}


/* Set IEE754 rounding mode */
extern inline int fesetround(int round)
{
    /*
		set rounding mode useing updfl
    */
#if __TRIC_TOOL_VERSION > 28
#if defined(ERRATA_CPU114)
	asm volatile ("updfl %0" :: "d" (0xf00 | (round & 3)));
#else
	asm volatile ("updfl %0" :: "d" (0x300 | (round & 3)));
#endif
#else
#if defined(ERRATA_CPU114)
	asm volatile ("updfl %0" :: "d" (0xf00 | (round & 3)): "d0");
#else
	asm volatile ("updfl %0" :: "d" (0x300 | (round & 3)): "d0");
#endif
#endif
    return(0);
}


#endif  /* FENV_H */
