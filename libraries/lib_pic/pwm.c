/*****************************************************************************
* includes
******************************************************************************/
#include "pwm.h"
#include "xc.h"

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//----------------------------- Init of PWM Module ----------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
result_t pwm_init (const PWM_CFG_t *cfg)
{
    if (cfg->duty > 100){
        return ERROR;
    }

    #if defined (_18F252) || defined (_18LF252)

        if (cfg->pwm_id == PWM_ID_1){
            CCP1CONbits.CCP1M = 15;             // PWM mode
        }
        else if (cfg->pwm_id == PWM_ID_2){
            CCP2CONbits.CCP2M = 15;             // PWM mode
        }
        else{
            return ERROR;
        }

    #elif defined (_18F26K42) || defined (_18F57K42) || defined (_18F57Q43)

        if (cfg->pwm_id == PWM_ID_1){
            CCP1CONbits.MODE = 15;             // PWM mode
            return ERROR;
        }
        else if (cfg->pwm_id == PWM_ID_2){
            CCP2CONbits.MODE = 15;             // PWM mode
            return ERROR;
        }
        else{
            return ERROR;
        }

    #elif defined(__PIC24F__) || defined(__dsPIC33F__)

        u16 comp_reg = (u16)((u32)cfg->freq * cfg->duty / 100); /* u32 to avoid overflow */

        // Initialize Output Compare Module
        if (cfg->pwm_id == PWM_ID_1){
            OC1CONbits.OCM = 0b000;                 // Disable Output Compare Module
            OC1R = 0;                               // Read-only reg in PWM mode
            OC1RS = comp_reg;                       // Load the Compare Register Value
            OC1CONbits.OCTSEL = cfg->timer_source;  // Select Timer 2 or 3 as output compare time base
            OC1CONbits.OCM = 0b110;                 // output compare module is configure for PWM mode
        }else if (cfg->pwm_id == PWM_ID_2){
            OC2CONbits.OCM = 0b000;                 // Disable Output Compare Module
            OC2R = 0;                               // Read-only reg in PWM mode
            OC2RS = comp_reg;                       // Load the Compare Register Value
            OC2CONbits.OCTSEL = cfg->timer_source;  // Select Timer 2 or 3 as output compare time base
            OC2CONbits.OCM = 0b110;                 // output compare module is configure for PWM mode

        #if defined (__dsPIC33FJ128MC802__) || (__dsPIC33FJ256MC710__)
        }else if (cfg->pwm_id == PWM_ID_3){
            OC3CONbits.OCM = 0b000;                 // Disable Output Compare Module
            OC3R = 0;                               // Read-only reg in PWM mode
            OC3RS = comp_reg;                       // Load the Compare Register Value
            OC3CONbits.OCTSEL = cfg->timer_source;  // Select Timer 2 or 3 as output compare time base
            OC3CONbits.OCM = 0b110;                 // output compare module is configure for PWM mode
        }else if (cfg->pwm_id == PWM_ID_4){
            OC4CONbits.OCM = 0b000;                 // Disable Output Compare Module
            OC4R = 0;                               // Read-only reg in PWM mode
            OC4RS = comp_reg;                       // Load the Compare Register Value
            OC4CONbits.OCTSEL = cfg->timer_source;  // Select Timer 2 or 3 as output compare time base
            OC4CONbits.OCM = 0b110;                 // output compare module is configure for PWM mode

        #endif

        }else{
            return ERROR;
        }

        // Initialize and enable Timer
        if (cfg->timer_source == PWM_FROM_TMR2){
            T2CONbits.TON = 0;          // Disable Timer
            T2CONbits.TCS = 0;          // Select internal instruction cycle clock
            T2CONbits.TGATE = 0;        // Disable Gated Timer mode
            T2CONbits.TCKPS = 0b00;     // Select 1:1 Prescaler
            TMR2 = 0;                   // Clear timer register
            PR2 = cfg->freq;            // Load the period value
            _T2IP = 0x01;               // Set Timer 2 Interrupt Priority Level
            _T2IF = 0;                  // Clear Timer 2 Interrupt Flag
            _T2IE = 0;                  // Disable Timer 2 interrupt
            T2CONbits.TON = 1;          // Start Timer
        }else if (cfg->timer_source == PWM_FROM_TMR3){
            T3CONbits.TON = 0;          // Disable Timer
            T3CONbits.TCS = 0;          // Select internal instruction cycle clock
            T3CONbits.TGATE = 0;        // Disable Gated Timer mode
            T3CONbits.TCKPS = 0b00;     // Select 1:1 Prescaler
            TMR3 = 0;                   // Clear timer register
            PR3 = cfg->freq;            // Load the period value
            _T3IP = 0x01;               // Set Timer 2 Interrupt Priority Level
            _T3IF = 0;                  // Clear Timer 2 Interrupt Flag
            _T3IE = 0;                  // Disable Timer 2 interrupt
            T3CONbits.TON = 1;          // Start Timer
        }else{
            return ERROR;
        }

    #else

        #error -- processor ID not specified in generic header file

    #endif

    return SUCCESS;
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------------------------- Set Duty Cycle ------------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
result_t pwm_set_duty (const PWM_CFG_t *cfg)
{
    if (cfg->duty > 100){
        return ERROR;
    }

    #if defined (_18F252) || defined (_18LF252)

        if (cfg->pwm_id == PWM_ID_1){
            CCPR1L = (u8)(cfg->duty >> 2);                       // bits 9 to 2
            CCP1CONbits.DC1B1 = (duty >> 1) & 0x01;     // bit 1
            CCP1CONbits.DC1B0 = duty & 0x01;            // bit 0
        }
        else if (cfg->pwm_id == PWM_ID_2){
            CCPR2L = (u8)(cfg->duty >> 2);                       // bits 9 to 2
            CCP2CONbits.DC2B1 = (cfg->duty >> 1) & 0x01;     // bit 1
            CCP2CONbits.DC2B0 = cfg->duty & 0x01;            // bit 0
        }
        else{
            return ERROR;
        }

    #elif defined (_18F26K42) || defined (_18F57K42) || defined (_18F57Q43)

        return ERROR;

    #elif defined(__PIC24F__) || defined(__dsPIC33F__)

        u16 comp_reg = (u16)((u32)cfg->freq * cfg->duty / 100); /* u32 to avoid overflow */

        if (cfg->pwm_id == PWM_ID_1){
            OC1RS = comp_reg;                      // Load the Compare Register Value
        }else if (cfg->pwm_id == PWM_ID_2){
            OC2RS = comp_reg;                      // Load the Compare Register Value

        #if defined (__dsPIC33FJ128MC802__) || (__dsPIC33FJ256MC710__)

        }else if (cfg->pwm_id == PWM_ID_3){
            OC3RS = comp_reg;                      // Load the Compare Register Value
        }else if (cfg->pwm_id == PWM_ID_4){
            OC4RS = comp_reg;                      // Load the Compare Register Value

        #endif

        }else{
            return ERROR;
        }

    #else
        #error -- processor ID not specified in generic header file
    #endif

    return SUCCESS;
}
