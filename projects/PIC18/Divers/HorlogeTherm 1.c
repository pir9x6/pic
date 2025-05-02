//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&               Titre   :   Horloge - Thermometre - Calendrier  &&&
//&&&               Auteur  :   Pierre Blaché                       &&&
//&&&               Date    :   Décembre 2008                       &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

//--------------------- Inclusion dse headers -------------------------
#include "p18CXXX.h"                // 18F242
//------------------- Configuration du processeur ---------------------
#pragma config WDT = OFF            // Watchdog OFF
#pragma config OSC = HS             // Quartz 20MHz
#pragma config LVP = OFF            // Low Power Prog OFF
//-------------------- Declaration des constantes ---------------------
#define Baud        100             // Frequence de l'horloge du bus I2C en kHz
#define Fosc        16000           // Frequence du Quartz en khz
#define L_DATE      PORTAbits.RA0   // LED d'affichage de la Date
#define L_HEURE     PORTAbits.RA1   // LED d'affichage de l'heure
#define L_TEMP      PORTAbits.RA2   // LED d'affichage de la temperature
#define SW2         PORTAbits.RA3   // Switch d'incrementation
#define SW3         PORTAbits.RA4   // Switch de desincrementation
#define SW1         PORTAbits.RA5   // Switch de selection
#define Aff_a       PORTBbits.RB0   // segment a
#define Aff_b       PORTBbits.RB1   // segment b
#define Aff_c       PORTBbits.RB2   // segment c
#define Aff_d       PORTBbits.RB3   // segment d
#define Aff_e       PORTBbits.RB4   // segment e
#define Aff_f       PORTBbits.RB5   // segment f
#define Aff_g       PORTBbits.RB6   // segment g
#define AFFICHEUR4  PORTBbits.RB7   // Selection du 4é afficheur
#define REG_STROBE  PORTCbits.RC0   // Strobe Registres à decalage
#define REG_DATA    PORTCbits.RC1   // Données Registres à decalage
#define REG_CLOCK   PORTCbits.RC2   // Horloge registres à decalage
#define SCL         PORTCbits.RC3   // Horloge du bus I2C
#define SDA         PORTCbits.RC4   // Données du bus I2C
#define AFFICHEUR1  PORTCbits.RC5   // Selection du 1e afficheur
#define AFFICHEUR2  PORTCbits.RC6   // Selection du 2e afficheur
#define AFFICHEUR3  PORTCbits.RC7   // Selection du 3e afficheur
//-------------------- Declaration des variables ----------------------
u8 Ones, Tens, Hund;     // Conversion Bin vers BCD
u8 Min, Hrs;             // HH:MM
u8 Day, Mth;             // Jours et mois
u8 Sec;                  // Chenillard des 60 secondes
u8 TempH, TempL;         // Temperature du DS1621
u8 CntTmr, CntDisp;      // Compteur timer & Afficheur
u8 CntTime, CntSw;       // Compteur Temps & boutons
u8 Aff1, Aff2, Aff3, Aff4;
u8 Seg[]=                // valeur des segments
{0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x63};
//--------------------------- Prototypes ------------------------------
void InterruptTimer2 (void);        // interruption sur le Timer 2
void DS1621 (void);                 // capteur de temperature
void Delay_us (u16 Cnt);   // tempos en micro-secondes
void Delay_ms (u16 Cnt);   // tempos en milli-secondes
void Reg4094 (u8 k);     // registres à decalage 4094
void Bin2BCD (u8 Temp);  // Conversion Binaire vers BCD
void RazLed (void);                 // extinction des LED
void I2CWait(void);                 // attendre fin d'operation I2C
void I2CStart(void);                // Start-Condition I2C
void I2CRstart(void);               // Repeated Start-Condition I2C
void I2CStop(void);                 // Stop-Condition I2C
int I2CRead(u8 ack);     // Lecture du bus I2C
u8 I2CWrite(u8 i2cWriteData); // Ecriture I2C

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//--------------------- Sous-Prog D'interruption ----------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
#pragma interrupt InterruptTimer2
void InterruptTimer2 (void)
{
    CntTmr ++;
    if (CntTmr >= 100)
    {
        Sec++;
        CntTmr = 0;
        REG_DATA = 1;
        REG_CLOCK = 1;          // une impulsion sur l'horloge
        REG_CLOCK = 0;
        CntDisp++;              // incrementer compteur d'affichage
        if (CntDisp == 4)
        {
            CntDisp = 0;
        }
    }
    PIR1bits.TMR2IF = 0;
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------------ High priority interrupt vector -------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
#pragma code VectorHigh = 0x08
void InterruptVectorHigh(void)
{
    _asm goto InterruptTimer2 _endasm
}
#pragma code


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//--------------------------- Main Program ----------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void main (void)
{
    char x;
//----------------------- Initialisation du PIC -----------------------
    TRISA = 0x38;               // A3 à A5 en entrée (switches)
    TRISB = 0x00;               // B0 à B6 en sortie (afficheur 7 segments)
    TRISC = 0x18;               // C3 à C4 en entrée (Bus I2C)
    ADCON1 = 0x07;              // CAN off - PORTA en I/O numérique
//------------- Configuration de l'interruption TIMER 2 ---------------
    PR2 = 249;                  // Valeur de debordement du Timer 2
    CntTmr = 250;               // 1s = 100x250x10x16x0.25us
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
//---------------------------------------------------------------------
    TRISCbits.TRISC3 = 1;
    TRISCbits.TRISC4 = 1;
    SSPCON1 = 0x38;             // set I2C master mode
    SSPCON2 = 0x00;
    SSPADD = 39;
    SSPSTATbits.CKE = 0;        // use I2C levels
    SSPSTATbits.SMP = 0;        // disable slew rate control
    x = SSPBUF;                 // dummy read clears BF
    PIR1bits.SSPIF  = 0;        // clear SSPIF interrupt flag
    PIR2bits.BCLIF  = 0;        // clear bus collision flag
//---------------------------------------------------------------------
    REG_STROBE = 1;
    Sec = 0;
    Min = 0;
    Hrs = 0;
    Day = 1;
    Mth = 1;
    RazLed ();                  // eteindre toutes les LEDs
//------------------------ Début du Programme -------------------------
    while (1)
    {
        // reglage de l'heure
        if (Sec >= 60){Sec = 0; Min ++;}
        if (Min >= 60){Min = 0; Hrs ++;}
        if (Hrs >= 24){Hrs = 0; Day ++;}
        switch (Mth)
        {
            case 1:  if (Day >= 32) {Day = 1; Mth ++;} break;   // janvier
            case 2:  if (Day >= 29) {Day = 1; Mth ++;} break;   // fevrier
            case 3:  if (Day >= 32) {Day = 1; Mth ++;} break;   // mars
            case 4:  if (Day >= 31) {Day = 1; Mth ++;} break;   // avril
            case 5:  if (Day >= 32) {Day = 1; Mth ++;} break;   // mai
            case 6:  if (Day >= 31) {Day = 1; Mth ++;} break;   // juin
            case 7:  if (Day >= 32) {Day = 1; Mth ++;} break;   // juillet
            case 8:  if (Day >= 32) {Day = 1; Mth ++;} break;   // aout
            case 9:  if (Day >= 31) {Day = 1; Mth ++;} break;   // septembre
            case 10: if (Day >= 32) {Day = 1; Mth ++;} break;   // octobre
            case 11: if (Day >= 31) {Day = 1; Mth ++;} break;   // novembre
            case 12: if (Day >= 32) {Day = 1; Mth ++;} break;   // decembre
        }
        if (Mth >= 12){Mth = 0;}

//---------------- Interrupteurs de Changement d'Heure ----------------
        if (SW1 == 0)                   // Bouton de selection
        {
            CntTime ++;
            Delay_ms (200);
            if (CntTime >= 5) CntTime = 0;
        }
        if (SW2 == 0)                   // si bouton d'incrementation appuyé et que
        {
            switch (CntTime)
            {
                case 0: Day ++; break;  // CntTime = 1 alors increment les Jours
                case 1: Mth ++; break;
                case 2: Hrs ++; break;
                case 3: Min ++; break;
                case 4: Sec ++; break;
            }
            Delay_ms (200);             // Tempo d'anti Rebonds
        }
        if (SW3 == 0)
        {
            switch (CntTime)
            {
                case 0: Day --; break;
                case 1: Mth --; break;
                case 2: Hrs --; break;
                case 3: Min --; break;
                case 4: Sec --; break;
            }
            Delay_ms (200);             // Tempo d'anti Rebonds
        }

//----------------- Recuperation de la temperature --------------------
        DS1621 ();
//-------------------- Affichage des données --------------------------
        switch (CntDisp)
        {
            case 1:                 // Date
            {
                L_DATE = 1;
                L_HEURE = 0;
                L_TEMP = 1;
                Bin2BCD (Day);
                Aff1 = Tens;
                Aff2 = Ones;
                Bin2BCD (Mth);
                Aff3 = Tens;
                Aff4 = Ones;
                break;
            }
            case 2:                 // Temperature
            {
                L_DATE = 0;
                L_HEURE = 0;
                L_TEMP = 1;
                Bin2BCD (TempH);
                Aff1 = Tens;
                Aff2 = Ones;
                if (TempL!=0)
                    Aff3 = 5;       // xx,5°
                else
                    Aff3 = 0;       // xx,0°
                break;
                Aff4 = 10;          // °
            }
            case 3:                 // Heure 1ere fois
            {
                L_DATE = 0;
                L_HEURE = 1;
                L_TEMP = 0;
                Bin2BCD (Hrs);
                Aff1 = Tens;
                Aff2 = Ones;
                Bin2BCD (Min);
                Aff3 = Tens;
                Aff4 = Ones;
                break;
            }
            case 4:                 // Heure 2e fois
            {
                L_DATE = 0;
                L_HEURE = 1;
                L_TEMP = 0;
                Bin2BCD (Hrs);
                Aff1 = Tens;
                Aff2 = Ones;
                Bin2BCD (Min);
                Aff3 = Tens;
                Aff4 = Ones;
                break;
            }
        }
//---------------------------------------------------------------------
        PORTB = Seg[Aff1];
        AFFICHEUR1 = 1;
        AFFICHEUR2 = 0;
        AFFICHEUR3 = 0;
        AFFICHEUR4 = 0;
        Delay_ms (1);

        PORTB = Seg[Aff2];
        AFFICHEUR1 = 0;
        AFFICHEUR2 = 1;
        AFFICHEUR3 = 0;
        AFFICHEUR4 = 0;
        Delay_ms (1);

        PORTB = Seg[Aff3];
        AFFICHEUR1 = 0;
        AFFICHEUR2 = 0;
        AFFICHEUR3 = 1;
        AFFICHEUR4 = 0;
        Delay_ms (1);

        PORTB = Seg[Aff4];
        AFFICHEUR1 = 0;
        AFFICHEUR2 = 0;
        AFFICHEUR3 = 0;
        AFFICHEUR4 = 1;
        Delay_ms (1);
    }
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------- Lecture de la Temperature sur le DS1621 ---------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void DS1621 (void)
{
    I2C_Start ();               // Start Condition
    I2C_Write (0x90);           // Adresse + bit Write
    I2C_Write (0xAC);           // Acces au registre de config.
    I2C_Write (0x00);           // Configurer le capteur
    I2C_Stop ();                    // Stop Condition

    I2C_Start ();               // Start Condition
    I2C_Write (0x90);           // Adresse + bit Write
    I2C_Write (0xEE);           // Lancer la conversion
    I2C_Stop ();                    // Stop Condition

    I2C_Start ();               // Start Condition
    I2C_Write (0x90);           // Adresse + bit Write
    I2C_Write (0xAA);           // Envoyer la commande "lire la temp"
    I2C_Rstart ();              // Repeated Start-condition
    I2C_Write (0x91);           // Adresse + bit Read
    TempH = I2CRead (1);        // Recuperer le Msb
    TempL = I2CRead (1);        // Recuperer le LSB
    I2C_Stop ();                    // Stop Condition
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//--------------------------- Temporisations --------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void Delay_us (u16 Cnt)
{
    u16 i;
    for (i = (Cnt>>2); i!=0; i--);// Boucle executée Cnt/4 fois
}


void Delay_ms (u16 Cnt)
{
    u16 x, y;
    for (x=Cnt; x!=0; x--)      // Boucle executée Cnt fois
    {
        for (y=332; y!=0; y--); // 332 @ 20MHz
    }
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------------- Registres à Décalages 4094 ----------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void Reg4094 (u8 k)
{
    u8 i;
    for (i=0; i<k; i++)
    {
        REG_DATA = 1;               // Allumer k LED
        REG_CLOCK = 1;
        REG_CLOCK = 0;
    }
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------------- Conversion Binaire vers BCD ---------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void Bin2BCD (u8 Temp)
{
    Ones=Tens=Hund = 0;
    while (Temp >= 100) {Temp -= 100; Hund++;}
    while (Temp >= 10)  {Temp -= 10; Tens++;}
    Ones = Temp;                    // unités = reste
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------------ Extinction de toutes les LEDs --------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void RazLed (void)
{
    u8 i;
    for (i=0; i<60; i++)
    {
        REG_DATA = 0;               // Eteindre toutes les LEDs
        REG_CLOCK = 1;
        REG_CLOCK = 0;
    }
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//----------------- Attendre que le bus soit libéré -------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void I2CWait(void)
{
    while (( SSPCON2 & 0x1F ) | SSPSTATbits.R_W);
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//-------------------- Envoi du Start-Condition -----------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void I2CStart(void)
{
    I2CWait ();
    SSPCON2bits.SEN = 1;
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//--------------- Envoi du Reapeted Start-Condition -------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void I2CRstart(void)
{
    I2CWait ();
    SSPCON2bits.RSEN = 1;
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//-------------------- Envoi du Stop-Condition ------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void I2CStop(void)
{
    I2CWait ();
    SSPCON2bits.PEN = 1;
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//---------------------- Lecture du bus I2C ---------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
int I2CRead(u8 ack)
{
    u8 i2cReadData;
    I2CWait ();
    SSPCON2bits.RCEN = 1;
    I2CWait ();
    i2cReadData = SSPBUF;
    I2CWait ();
    if (ack)    SSPCON2bits.ACKDT = 0;  // ack
    else        SSPCON2bits.ACKDT = 1;  // noack
    SSPCON2bits.ACKEN = 1;      // send acknowledge sequence

    return( i2cReadData );
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//-------------------- Ecriture sur le bus I2C ------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
u8 I2CWrite(u8 i2cWriteData)
{
    I2CWait ();
    SSPBUF = i2cWriteData;
    return ( ! (SSPCON2bits.ACKSTAT)  ); // function returns '1' if transmission is acknowledged
}
