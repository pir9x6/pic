#include "interrupts_management.h"
#include "hardware_profile.h"
#include "console.h"

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//--------------------- Timer 1 Interrupt Sub Routine -------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void timer1_isr (void)
{

}

void timer2_isr (void)
{
    LED2 = !LED2;
}

void timer3_isr (void)
{

}

void timer4_isr (void)
{

}

void timer5_isr (void)
{

}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//--------------------- External Interrupt Sub Routine ------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void ext_int0_isr()
{
    
}
    
void ext_int1_isr()
{
    
}

void ext_int2_isr()
{
    
}

void ext_int3_isr()
{

}

void ext_int4_isr()
{

}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------------- Output Compare Interrupt Sub Routine --------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void output_compare0_isr()
{

}



//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//--------------------- Uart 1 Interrupt Sub Routine --------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void uart_isr (void)
{
    if (U1STAbits.URXDA)                // si donnée dans buffer RX alors :
    {
        //command_line_interpreter(U1RXREG);
    }
}

