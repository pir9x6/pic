//
//HTTP2 Server
//
#include "TCPIPConfig.h"
#include "main.h"

#if defined(STACK_USE_HTTP2_SERVER)

#include "TCPIP.h"

extern HTTP_CONN curHTTP;
extern HTTP_STUB httpStubs[MAX_HTTP_CONNECTIONS];
extern u8 curHTTPID;


/*****************************************************************************
  Function:
    u8 HTTPNeedsAuth(u8* cFile)

  Internal:
    See documentation in the TCP/IP Stack API or HTTP2.h for details.
  ***************************************************************************/
#if defined(HTTP_USE_AUTHENTICATION)
u8 HTTPNeedsAuth(u8* cFile)
{
    // No authentication is defined yet.

    return 0x80;
}
#endif

/*****************************************************************************
  Function:
    u8 HTTPCheckAuth(u8* cUser, u8* cPass)

  Internal:
    See documentation in the TCP/IP Stack API or HTTP2.h for details.
  ***************************************************************************/
#if defined(HTTP_USE_AUTHENTICATION)
u8 HTTPCheckAuth(u8* cUser, u8* cPass)
{
    // No authentication is defined yet.

    return 0x80;
}
#endif

/*********************************************************************
 * Function:        HTTP_IO_RESULT HTTPExecuteGet(void)
 *
 * PreCondition:    curHTTP is loaded
 *
 * Input:           None
 *
 * Output:          HTTP_IO_DONE on success
 *                  HTTP_IO_WAITING if waiting for asynchronous process
 *
 * Side Effects:    None
 *
 * Overview:        This function is called if data was read from the
 *                  HTTP request from either the GET arguments, or
 *                  any cookies sent.  curHTTP.data contains
 *                  sequential pairs of strings representing the
 *                  data received.  Any required authentication has
 *                  already been validated.
 *
 * Note:            Custom implementation for WebVend Application
 ********************************************************************/
HTTP_IO_RESULT HTTPExecuteGet(void)
{
    u8 *ptr, name[16];

    // Load the file name
    // Make sure u8 filename[] above is large enough for your longest name
    MPFSGetFilename(curHTTP.file, name, 16);

    // Make sure it's the index.htm page
    if(strcmppgm2ram((char*)name, (const char*)"index.htm") != 0)
        return HTTP_IO_DONE;

    #if defined USE_UART
        uart_write_string("\r\n\r\nIndex File");
    #endif

    // Find the new light state value
    ptr = HTTPGetROMArg(curHTTP.data, (const u8 *)"led");
    if(ptr) // Make sure ptr is not NULL
    {// Set the new lights state
        #if defined USE_UART
            uart_write_string("\r\nled pointer found");
        #endif
        if(strcmppgm2ram((char*)ptr, (const char*)"on") == 0)
        {
            #if defined USE_UART
                uart_write_string("\r\nLED ON");
            #endif
            LED1 = 1;
        }
        else
        {
            #if defined USE_UART
                uart_write_string("\r\nLED OFF");
            #endif
            LED1 = 0;
        }
    }

    // Indicate that we're finished
    return HTTP_IO_DONE;
}

#if defined(HTTP_USE_POST)

/*********************************************************************
 * Function:        HTTP_IO_RESULT HTTPExecutePost(void)
 *
 * PreCondition:    curHTTP is loaded
 *
 * Input:           None
 *
 * Output:          HTTP_IO_DONE on success
 *                  HTTP_IO_NEED_DATA if more data is requested
 *                  HTTP_IO_WAITING if waiting for asynchronous process
 *
 * Side Effects:    None
 *
 * Overview:        This function is called if the request method was
 *                  POST.  It is called after HTTPExecuteGet and
 *                  after any required authentication has been validated.
 *
 * Note:            Custom implementation for WebVend Application
 ********************************************************************/
HTTP_IO_RESULT HTTPExecutePost(void)
{
    // No POST functionality is defined

    return HTTP_IO_DONE;
}

#endif //(use_post)

/*********************************************************************
 * Function:        void HTTPPrint_varname(TCP_SOCKET sktHTTP,
 *                          DWORD callbackPos, u8 *data)
 *
 * PreCondition:    None
 *
 * Input:           sktHTTP: the TCP socket to which to write
 *                  callbackPos: 0 initially
 *                      return value of last call for subsequent callbacks
 *                  data: this connection's data buffer
 *
 * Output:          0 if output is complete
 *                  application-defined otherwise
 *
 * Side Effects:    None
 *
 * Overview:        Outputs a variable to the HTTP client.
 *
 * Note:            Return zero to indicate that this callback function
 *                  has finished writing data to the TCP socket.  A
 *                  non-zero return value indicates that more data
 *                  remains to be written, and this callback should
 *                  be called again when more space is available in
 *                  the TCP TX FIFO.  This non-zero return value will
 *                  be the value of the parameter callbackPos for the
 *                  next call.
 ********************************************************************/

void HTTPPrint_version(void)
{
    TCPPutROMString(sktHTTP,(const void*)TCPIP_STACK_VERSION);
    return;
}

void HTTPPrint_builddate(void)
{
    TCPPutROMString(sktHTTP,(const void*)__DATE__" "__TIME__);
    return;
}

void HTTPPrint_myIP(u16 index)
{
    u8 Result[4];
    uitoa(AppConfig.MyIPAddr.v[index], Result);
    TCPPutROMString(sktHTTP,Result);
    return;
}

void HTTPPrint_myGate(u16 index)
{
    u8 Result[4];
    uitoa(AppConfig.MyGateway.v[index], Result);
    TCPPutROMString(sktHTTP,Result);
    return;
}

void HTTPPrint_myMask(u16 index)
{
    u8 Result[4];
    uitoa(AppConfig.MyMask.v[index], Result);
    TCPPutROMString(sktHTTP,Result);
    return;
}

void HTTPPrint_my1DNS(u16 index)
{
    u8 Result[4];
    uitoa(AppConfig.PrimaryDNSServer.v[index], Result);
    TCPPutROMString(sktHTTP,Result);
    return;
}

void HTTPPrint_my2DNS(u16 index)
{
    u8 Result[4];
    uitoa(AppConfig.SecondaryDNSServer.v[index], Result);
    TCPPutROMString(sktHTTP,Result);
    return;
}

void HTTPPrint_myDHCP(void)
{
    if( AppConfig.Flags.bIsDHCPEnabled )
        TCPPutROMString(sktHTTP,"enabled");
    else
        TCPPutROMString(sktHTTP,"disabled");
    return;
}

void HTTPPrint_myMAC(u16 index)
{
    u8 MACHex[3],temp;
    // Converte para HEX
    temp =(AppConfig.MyMACAddr.v[index] & 0xf0)>>4;
    temp+= (temp>9) ? '7': '0';
    MACHex[0] = temp;
    temp =(AppConfig.MyMACAddr.v[index] & 0x0f);
    temp+= (temp>9) ? '7': '0';
    MACHex[1] = temp;
    MACHex[2] = 0;
    TCPPutROMString(sktHTTP,MACHex);
}


void HTTPPrint_btn1(void)
{
    if (SW1_PIN)
        TCPPutROMString(sktHTTP,"ON");
    else
        TCPPutROMString(sktHTTP,"OFF");
    return;
}

void HTTPPrint_pot(void)
{
    u8 Result[5];

    uitoa((u16)readPot(),Result);
    TCPPutROMString(sktHTTP,Result);
    return;
}

void HTTPPrint_temp(void)
{
    u8 Result[5];

    uitoa((u16)readTemp(),Result);
    TCPPutROMString(sktHTTP,Result);
    return;
}

void HTTPPrint_LED_chk(u16 on)
{
    if(LED1 == on)
        TCPPutROMString(sktHTTP, (const u8*)"checked");
}

void HTTPPrint_tick(void)
{
    u8 Result[12];
    uitoa(TickGet()>>8,Result);
    TCPPutROMString(sktHTTP,Result );
}

void HTTPPrint_tickspsec(void)
{
    u8 Result[12];
    uitoa(TICK_SECOND>>8,Result);
    TCPPutROMString(sktHTTP,Result );
}
#endif

