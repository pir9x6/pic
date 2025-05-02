#define THIS_IS_STACK_APPLICATION

#include "main.h"
#include "TCPIP.h"

//these variables must have these names because they're used externally in the stack
APP_CONFIG AppConfig; //holds TCPIP setup
static const u8 MACAddress[6] = {MAC_1, MAC_2, MAC_3, MAC_4, MAC_5, MAC_6};
u8 AN0String[8];
u8 temperature[2] = {0, 0};
void display_ip(void);

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------------------------ Main Program ---------------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
int main(void)
{
    static unsigned long dwLastIP = 0;
    __C30_UART = 1;
    t_time t;

    //-------------------- configuration de l'oscillateur -------------------------
    #if defined (__dsPIC33FJ256MC710__)
        oscillator_init(OSC_32MHZ);
    #endif

    //-------------------------- Init Peripherals ---------------------------------
    io_config();

    // config osc (MUST BE DONE AFTER IO INIT FOR PIC24 devices !! )
    #if defined (__PIC24F__)
        __builtin_write_OSCCONL(OSCCON | 0x40); // Lock PPS
    #endif

    tcpip_init();

    uart_init(UART_FREQ, UART_EN_IT_RX);

    adc_init();

    i2c_init(I2C_BUS_2, I2C_FREQ, I2C_MASTER);

    //--------------------------------- init chips --------------------------------
    lcd_2x16_init();
    lcd_2x16_clear();

    while(1)
    {

        //service the stack, includes PING, DHCP client, etc
        StackTask();
        StackApplications();
        //ApplicationTasks();

        if(dwLastIP != AppConfig.MyIPAddr.Val)
        {
            dwLastIP = AppConfig.MyIPAddr.Val;
            #if defined(STACK_USE_ANNOUNCE) //announce IP address change if enabled
                AnnounceIP();
            #endif
        }

        LED1 = !LED1;
        LED2 = !LED1;

        lcd_display_ip(AppConfig.MyIPAddr);

        ds1621_read_temp(I2C_BUS_2, temperature);
        uart_write_temperature(temperature);
        lcd_write_temperature(I2C_BUS_2, temperature, LCD_LINE_1, 5);

        ds1337_get_time(I2C_BUS_2, &t);
        uart_write_date(t);

        delay_ms(100);

    }
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//----------------------- Init TCP-IP Stack ---------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void tcpip_init()
{
    TickInit(); //setup the tick timer
    MPFSInit();

    // Start out zeroing all AppConfig bytes to ensure all fields are
    // deterministic for checksum generation
    memset((void*)&AppConfig, 0x00, sizeof(AppConfig));

    //setup the TCPIP stack config variable
    AppConfig.Flags.bIsDHCPEnabled = TRUE;
    AppConfig.Flags.bInConfigMode = TRUE;
    memcpypgm2ram((void*)&AppConfig.MyMACAddr, (ROM void*)MACAddress, sizeof(AppConfig.MyMACAddr));
    AppConfig.MyIPAddr.Val =           IP_1      | IP_2<<8ul      | IP_3<<16ul      | IP_4<<24ul;
    AppConfig.DefaultIPAddr.Val = AppConfig.MyIPAddr.Val;
    AppConfig.MyMask.Val =             MASK_1    | MASK_2<<8ul    | MASK_3<<16ul    | MASK_4<<24ul;
    AppConfig.DefaultMask.Val = AppConfig.MyMask.Val;
    AppConfig.MyGateway.Val =          GATE_1    | GATE_2<<8ul    | GATE_3<<16ul    | GATE_4<<24ul;
    AppConfig.PrimaryDNSServer.Val =   PRI_DNS_1 | PRI_DNS_2<<8ul | PRI_DNS_3<<16ul | PRI_DNS_4<<24ul;
    AppConfig.SecondaryDNSServer.Val = SEC_DNS_1 | SEC_DNS_2<<8ul | SEC_DNS_3<<16ul | SEC_DNS_4<<24ul;
    memcpypgm2ram(AppConfig.NetBIOSName, (ROM void*)HOST_NAME, 16);
    FormatNetBIOSName(AppConfig.NetBIOSName);

    StackInit();    //setup the stack
}


void lcd_display_ip(IP_ADDR ip)
{
    lcd_2x16_position (LCD_LINE_2, 1);
    lcd_2x16_write ('I', 1);
    lcd_2x16_write ('P', 1);
    lcd_2x16_write (':', 1);
    lcd_2x16_write (' ', 1);
    lcd_2x16_write_u8(ip.v[0]);
    lcd_2x16_write ('.', 1);
    lcd_2x16_write_u8(ip.v[1]);
    lcd_2x16_write ('.', 1);
    lcd_2x16_write_u8(ip.v[2]);
    lcd_2x16_write ('.', 1);
    lcd_2x16_write_u8(ip.v[3]);
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//--------------------- Init all IO of the MCU ------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void io_config()
{
#if defined(__PIC24FJ64GB002__)

    //digital pins
    AD1PCFG = 0xFFFE;

    // ENC28J60 I/O pins
    _SDI1R = 15;            //SDI1 = RP15   entrée données SPI
    _RP13R = RPO_SCK1OUT;   //RP13 = SCK1   sortie horloge SPI
    _RP14R = RPO_SDO1;      //RP14 = SDO1   sortie données SPI

    // gpio
    TRISAbits.TRISA4 = 0;   // LED Verte
    TRISBbits.TRISB7 = 0;   // LED Jaune
    TRISBbits.TRISB0 = 1;   // entrée analogique
    TRISBbits.TRISB1 = 1;   // entrée switch
    TRISBbits.TRISB2 = 0;   // SDA
    TRISBbits.TRISB3 = 0;   // SCL

#elif defined(__PIC24FJ256GB210__)

    //digital pins
    ANSA = 0x0000;
    ANSB = 0x0000;
    ANSC = 0x0000;
    ANSD = 0x0000;
    ANSE = 0x0000;
    ANSF = 0x0000;
    ANSG = 0x0000;

    // set pin direction
    LED1_TRIS = 0;
    LED2_TRIS = 0;
    LED3_TRIS = 0;
    LED4_TRIS = 0;
    LED5_TRIS = 0;
    LED6_TRIS = 0;
    LED7_TRIS = 0;
    LED8_TRIS = 0;

    SW1_TRIS = 1;
    SW2_TRIS = 1;
    SW3_TRIS = 1;
    SW4_TRIS = 1;

    // ENC28J60 I/O pins
    _SDI1R = 4;              //SDI1 = RP4    entrée données SPI
    _RP3R = RPO_SCK1OUT;     //RP13 = SCK1   sortie horloge SPI
    _RP15R = RPO_SDO1;       //RP15 = SDO1   sortie données SPI

#elif defined(__dsPIC33FJ256MC710__)

    AD1PCFGL = 0xFFFF;

    TRISA = 0x0000;
    TRISB = 0x0000;
    TRISC = 0x0000;
    TRISD = 0x0000;
    TRISE = 0x0000;
    TRISF = 0x0000;
    TRISG = 0x0000;

    // set pin direction
    LED1_TRIS = 0;
    LED2_TRIS = 0;
    LED3_TRIS = 0;
    LED4_TRIS = 0;
    LED5_TRIS = 0;
    LED6_TRIS = 0;
    LED7_TRIS = 0;
    LED8_TRIS = 0;

    U1RX_TRIS = IO_IN;
    U1TX_TRIS = IO_OUT;

    SW1_TRIS = IO_IN;
    SW2_TRIS = IO_IN;
    SW3_TRIS = IO_IN;
    SW4_TRIS = IO_IN;

#else
    #error -- processor ID not specified in generic header file
#endif
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//--------------- stack overslow interrupt vectors --------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void _ISR __attribute__((__no_auto_psv__)) _AddressError(void)
{
    Nop();
    Nop();
}
void _ISR __attribute__((__no_auto_psv__)) _StackError(void)
{
    Nop();
    Nop();
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//--------------------- Uart 1 Interrupt Sub Routine --------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void uart_isr ()
{
    if (U1STAbits.URXDA)                // si donnée dans buffer RX alors :
    {

    }
}


// Le um canal do adc
int readADC1(int ch)
{
    return  temperature[0];
//    return adc_convert(2);
}



// Le o sensor do pot
int readPot(void)
{
//    return temperature[0];
    return  temperature[0];
//    return adc_convert(2);
}



// Lire la Temperature
int readTemp(void)
{
    return  temperature[0];
}

