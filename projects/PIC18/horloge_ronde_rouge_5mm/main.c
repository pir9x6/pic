//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&                   Titre   :   Horloge à LED                           &&&
//&&&                   Auteur  :   Pierre Blaché                           &&&
//&&&                   Date    :   Juin 2010                               &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

#include "main.h"



//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//----------------------- Configuration du Processeur -------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
#pragma config WDT = OFF        // Watchdog OFF
#pragma config OSC = HS         // Quartz 16MHz
#pragma config LVP = OFF        // Low Power Prog OFF


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//---------------------------- Global variables -------------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
t_time time;
u8 display_counter = 0;         // Compteur timer & Afficheur
u8 display_en = 1;              // autoriser (1) ou non (0) la rotation de l'affichage


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------------------- Sous-Prog D'interruption --------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
#pragma interrupt InterruptTimer2
void InterruptTimer2 (void)
{
    static u8 timer_counter = 0;

    T2CONbits.TMR2ON = 0;           // Timer 2 off

    // pour ajuster à 1 seconde
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop();

    PIR1bits.TMR2IF = 0;            // RAZ du Timer
    T2CONbits.TMR2ON = 1;           // Timer 2 on

    timer_counter ++;
    if (timer_counter >= 100)              // 100 x 10ms = 1s
    {
        HEURE = !HEURE;
        time.sec++;
        timer_counter = 0;

        // allumage de la LED "seconde" suivante
        if (time.min % 2)
        {
            DATA = 1;
            REG4094_PULSE;
            DATA = 0;
        }
        else
        {
            DATA = 0;
            REG4094_PULSE;
        }

        // rotation de l'affichage
        // 0 = Date, 1 = Temp, 2 et 3 = Heure
//        if (display_en)
//        {
//            display_counter++;              // incrementer compteur d'affichage
//            if (display_counter == 4)
//                display_counter = 0;
//        }

        // calcul de l'heure et de la date
        if (time.sec >= 60){time.sec = 0; time.min ++;}
        if (time.min >= 60){time.min = 0; time.hrs ++;}
        if (time.hrs >= 24){time.hrs = 0; time.day ++;}
        switch (time.mth)
        {
            case 1:  if (time.day >= 32) {time.day = 1; time.mth=2;}  break;   // janvier
            case 2:  if (time.day >= 29) {time.day = 1; time.mth=3;}  break;   // fevrier
            case 3:  if (time.day >= 32) {time.day = 1; time.mth=4;}  break;   // mars
            case 4:  if (time.day >= 31) {time.day = 1; time.mth=5;}  break;   // avril
            case 5:  if (time.day >= 32) {time.day = 1; time.mth=6;}  break;   // mai
            case 6:  if (time.day >= 31) {time.day = 1; time.mth=7;}  break;   // juin
            case 7:  if (time.day >= 32) {time.day = 1; time.mth=8;}  break;   // juillet
            case 8:  if (time.day >= 32) {time.day = 1; time.mth=9;}  break;   // aout
            case 9:  if (time.day >= 31) {time.day = 1; time.mth=10;} break;   // septembre
            case 10: if (time.day >= 32) {time.day = 1; time.mth=11;} break;   // octobre
            case 11: if (time.day >= 31) {time.day = 1; time.mth=12;} break;   // novembre
            case 12: if (time.day >= 32) {time.day = 1; time.mth=1;}  break;   // decembre
        }
    }
    Nop();
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//---------------------- High priority interrupt vector -----------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
#pragma code VectorHigh = 0x08
void InterruptVectorHigh(void)
{
    _asm goto InterruptTimer2 _endasm
}
#pragma code





//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------------------------ Main Program ---------------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void main (void)
{
    //------------------------- Local Variables -------------------------------
    u8 temperature[2] = {0, 0};
    u8 bcd[5];
    f32 data;
    CHANGE change_state = CHANGE_NONE;
    u8 aff1=1, aff2=2, aff3=3, aff4=4;
    const u8 seg7[12] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x63, 0x00};

    //----------------------- Initialisation du PIC ---------------------------
    TRISA = 0x38;               // RA3,4,5 en entrée (switches)
    TRISB = 0x00;               // PORTB en sortie
    TRISC = 0x18;               // SCl et SDA en entrée
    ADCON1 = 0x07;              // PORTA en I/O Numériques

    //------------- Configuration de l'interruption TIMER 2 -------------------
    PR2 = 226;                  // Valeur de debordement du Timer 2
    T2CONbits.TOUTPS3 = 1;      // Postscaler is 1:10
    T2CONbits.TOUTPS2 = 0;
    T2CONbits.TOUTPS1 = 1;
    T2CONbits.TOUTPS0 = 0;
    T2CONbits.T2CKPS1 = 1;      // Prescaler is 16
    T2CONbits.T2CKPS0 = 1;
    T2CONbits.TMR2ON = 1;       // Timer 2 on
    PIE1bits.TMR2IE = 1;        // Enabled Timer 2 interrupt
    RCONbits.IPEN = 1;          // Interruption prioritaires activées
    INTCONbits.GIE = 1;         // Enabled interrupts

    //-------------------------------------------------------------------------
//    i2c_init(I2C_BUS_1, I2C_FREQ, I2C_MASTER);
//    uart_init(UART_FREQ, UART_EN_IT_RX);
//    i2c_detect(I2C_BUS_1);

    //-------------------------------------------------------------------------
    STROBE = 1;
//    ds1307_init(I2C_BUS_1);
//    ds1307_set_time(I2C_BUS_1, t);
//    ds1307_get_time(&t);
    time.sec = 0;
    time.min = 6;
    time.hrs = 22;
    display_en = 1;
    reset_sec_led ();                  // eteindre toutes les LEDs

//    while(1){
//        uart_write('r');
//        delay_ms(200);
//        DATE = !DATE;
//    }-
    //-------------------------------------------------------------------------
    while (1)
    {
        //------------------ Interrupteurs de Changement d'Heure --------------
        // Bouton de selection
        // au premier appui on choisi de changer les  jours
        // les mois lors du 2é appui, les minutes, les heures
        // puis on reviens au fonctionnement normal
        if (SW_SELECT == 0){
            delay_ms (200);             // Tempo d'anti Rebonds
            if (change_state == CHANGE_NONE){
                display_en = 1;
                change_state = CHANGE_DAY;
            } else if (change_state == CHANGE_DAY){
                display_en = 1;
                change_state = CHANGE_MTH;
            } else if (change_state == CHANGE_MTH){
                display_en = 1;
                change_state = CHANGE_MIN;
            } else if (change_state == CHANGE_MIN){
                display_en = 1;
                change_state = CHANGE_HRS;
            } else {
                change_state = CHANGE_NONE;
            }
//            uart_write_hexa_u8((u8)change_state, UART_OPT_NONE);
        }

        // bouton de décrementation
        if (SW_MINUS == 0)
        {
            delay_ms (200);             // Tempo d'anti Rebonds
            switch (change_state)
            {
                case CHANGE_DAY:
                {
                    time.day --;
                    if (time.day < 1 && time.day > 31)
                        time.day = 31;
                    display_counter = 1;
                    break;
                }
                case CHANGE_MTH:
                {
                    time.mth --;
                    if (time.mth < 1 && time.mth > 12)
                        time.mth = 12;
                    display_counter = 1;
                    break;
                }
                case CHANGE_MIN:
                {
                    time.min --;
                    if (time.min > 59)
                        time.min = 59;
                    display_counter = 3;
                    break;
                }
                case CHANGE_HRS:
                {
                    time.hrs --;
                    if (time.hrs > 23)
                        time.hrs = 23;
                    display_counter = 3;
                    break;
                }
            }
        }

        // bouton d'incrémentation
        if (SW_PLUS == 0)
        {
            delay_ms (200);             // Tempo d'anti Rebonds
            switch (change_state)
            {
                case CHANGE_DAY:
                {
                    time.day ++;
                    if (time.day >= 31)
                        time.day = 1;
                    display_counter = 1;
                    break;
                }
                case CHANGE_MTH:
                {
                    time.mth ++;
                    if (time.mth >= 13)
                        time.mth = 1;
                    display_counter = 1;
                    break;
                }
                case CHANGE_MIN:
                {
                    time.min ++;
                    if (time.min >= 60)
                        time.min = 0;
                    display_counter = 3;
                    break;
                }
                case CHANGE_HRS:
                {
                    time.hrs ++;
                    if (time.hrs >= 24)
                        time.hrs = 0;
                    display_counter = 3;
                    break;
                }
            }
        }

        //----------- acquisition de la temperature sur le DS1621 -------------
//        ds1621_read_temp(I2C_BUS_1, temperature);

        //-------------------- Affichage des données --------------------------

        dec_2_bcd (time.hrs, bcd);
        aff1 = bcd[1];
        aff2 = bcd[0];
        dec_2_bcd (time.min, bcd);
        aff3 = bcd[1];
        aff4 = bcd[0];


        /*switch (display_counter)
        {
            case 1:                 // Date
            {
                DATE = 1;   HEURE = 0;  THERMO = 1;
                dec_2_bcd (time.day, bcd);
                aff1 = bcd[1];
                aff2 = bcd[0];
                dec_2_bcd (time.mth, bcd);
                aff3 = bcd[1];
                aff4 = bcd[0];
                break;
            }
            case 2:                 // Temperature
            {
                DATE = 0;   HEURE = 0;  THERMO = 1;
                dec_2_bcd (temperature[1]-3, bcd);
                aff1 = bcd[1];
                aff2 = bcd[0];
                if (temperature[0]!=0)
                    aff3 = 5;       // xx,5°
                else
                    aff3 = 0;       // xx,0°
                aff4 = 10;          // °
                break;
            }
            case 3:                 // Heure 1ere fois
            {
                DATE = 0;   HEURE = 1;  THERMO = 0;
                dec_2_bcd (time.hrs, bcd);
                aff1 = bcd[1];
                aff2 = bcd[0];
                dec_2_bcd (time.min, bcd);
                aff3 = bcd[1];
                aff4 = bcd[0];
                break;
            }
            case 4:                 // Heure 2e fois
            {
                DATE = 0;   HEURE = 1;  THERMO = 0;
                dec_2_bcd (time.hrs, bcd);
                aff1 = bcd[1];
                aff2 = bcd[0];
                dec_2_bcd (time.min, bcd);
                aff3 = bcd[1];
                aff4 = bcd[0];
                break;
            }
            default :
            {
                break;
            }
        }*/

        //------------------------- Load data on display ----------------------
        if (change_state == CHANGE_NONE || change_state == CHANGE_HRS){
            LATB = seg7[aff1];
            Select_Aff_1
            delay_ms (2);

            LATB = seg7[aff2];
            Select_Aff_2
            delay_ms (2);
        }else{
            LATB = 0x40;    // BUG WHEN NO SEGMENTS ARE DISPLAYED !!
            Select_Aff_1
            delay_ms (2);

            LATB = 0x40;
            Select_Aff_2
            delay_ms (2);
        }

        if (change_state == CHANGE_NONE || change_state == CHANGE_MIN){
            LATB = seg7[aff3];
            Select_Aff_3
            delay_ms (2);

            LATB = seg7[aff4];
            Select_Aff_4
            delay_ms (2);
        }else{
            LATB = 0x40;
            Select_Aff_3
            delay_ms (2);

            LATB = 0x40;
            Select_Aff_4
            delay_ms (2);
        }

        LATB = 0x00;
        Select_Aff_All
    }
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//----------------------- Registres à Décalages 4094 --------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void reset_sec_led (void)
{
    u8 i;
    for (i=0; i<60; i++)
    {
        DATA = 0;               // Eteindre toutes les LEDs
        REG4094_PULSE;
    }
}
