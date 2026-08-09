/*****************************************************************************
* Title:    Delays functions
******************************************************************************
* Versions: v1.0    01/10/2013  MPLAB: vx.x   XC16: vx.x
*                   Initial version
*           v1.1    08/08/2026  MPLAB: 6.05   XC-DSC: 4.00
*                   Added delays functions from XC-DSC library (more accurate)
******************************************************************************/

#include "hardware_profile.h"
#include "delays.h"

#if defined(__PIC24F__) || defined(__PIC24H__) || defined(__PIC24E__) || defined(__dsPIC33F__) || defined(__dsPIC33E__)
    #include <libpic30.h>
#endif

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------------------------ Delay in us ----------------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void delay_us (u16 loop)
{
#if defined(__PIC32MX__)
    unsigned int i;
    for (i=(usec*13); i!=0; i--);        // @ 80 MHz

#elif defined(__PIC24F__) || defined(__PIC24H__) || defined(__PIC24E__) || defined(__dsPIC33F__) || defined(__dsPIC33E__)

    __delay_us(loop);

#else

    u16 i, k;
    for (i=loop; i!=0; i--)
        for (k=US_LOOP; k!=0; k--);
#endif
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------------------------ Delay in ms ----------------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void delay_ms (u16 loop)
{
#if defined(__PIC32MX__)

    u16 tWait, tStart;
    tWait=(GetSystemClock()/2000)*loop;
    tStart=ReadCoreTimer();
    while((ReadCoreTimer()-tStart)<tWait);  // wait for the time to pass

#elif defined(__PIC24F__) || defined(__PIC24H__) || defined(__PIC24E__) || defined(__dsPIC33F__) || defined(__dsPIC33E__)

    __delay_ms(loop);

#else
    u16 i, k;
    for (i=loop; i!=0; i--)
        for (k=MS_LOOP; k!=0; k--);
#endif



}

