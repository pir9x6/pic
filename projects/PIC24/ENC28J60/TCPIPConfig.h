/*********************************************************************
 *
 *  Microchip TCP/IP Stack Demo Application Configuration Header
 *
 ********************************************************************/
#ifndef __TCPIPCONFIG_H
#define __TCPIPCONFIG_H

#include "GenericTypeDefs.h"
#include "pic_compiler.h"
#define GENERATED_BY_TCPIPCONFIG "Version 1.0.3937.25080"

// =======================================================================
//   Application Options
// =======================================================================


//#define STACK_USE_UART                    // Application demo using UART for IP address display and stack configuration
#define STACK_USE_ICMP_SERVER           // Ping query and response capability
#define STACK_USE_HTTP2_SERVER          // New HTTP server with POST, Cookies, Authentication, etc.
#define STACK_USE_DHCP_CLIENT           // Dynamic Host Configuration Protocol client for obtaining IP address and other parameters
#define STACK_USE_ANNOUNCE              // Microchip Embedded Ethernet Device Discoverer server/client
#define STACK_USE_NBNS                  // NetBIOS Name Service Server for repsonding to NBNS hostname broadcast queries
#define STACK_USE_TELNET_SERVER         // Telnet server
#define STACK_USE_TCP_PERFORMANCE_TEST
#define STACK_USE_MPFS2
#define MPFS_RESERVE_BLOCK              (64ul)
#define MAX_MPFS_HANDLES                (7ul)


// =======================================================================
//   Network Addressing Options
// =======================================================================
#define HOST_NAME       "ENC_2"

#define MAC_1           0x00    // Use the default of 00-04-A3-00-00-00
#define MAC_2           0x04    // if using an ENCX24J600, MRF24WB0M, or
#define MAC_3           0xA3    // PIC32MX6XX/7XX internal Ethernet
#define MAC_4           0x00    // controller and wish to use the
#define MAC_5           0x00    // internal factory programmed MAC
#define MAC_6           0x02    // address instead.

#define IP_1            192ul   //169ul
#define IP_2            168ul   //254ul
#define IP_3            1ul
#define IP_4            20ul

#define MASK_1          255ul
#define MASK_2          255ul
#define MASK_3          255ul   //0ul
#define MASK_4          0ul

#define GATE_1          192ul   //169ul
#define GATE_2          168ul   //254ul
#define GATE_3          1ul
#define GATE_4          20ul

#define PRI_DNS_1       192ul   //169ul
#define PRI_DNS_2       168ul   //254ul
#define PRI_DNS_3       1ul
#define PRI_DNS_4       20ul

#define SEC_DNS_1       0ul
#define SEC_DNS_2       0ul
#define SEC_DNS_3       0ul
#define SEC_DNS_4       0ul


// =======================================================================
//   Transport Layer Options
// =======================================================================
#define STACK_CLIENT_MODE

/* TCP Socket Memory Allocation
 *   TCP needs memory to buffer incoming and outgoing data.  The
 *   amount and medium of storage can be allocated on a per-socket
 *   basis using the example below as a guide.
 */
    // Allocate how much total RAM (in bytes) you want to allocate
    // for use by your TCP TCBs, RX FIFOs, and TX FIFOs.
    #define TCP_ETH_RAM_SIZE                    (3900ul)
    #define TCP_PIC_RAM_SIZE                    (0ul)
    #define TCP_SPI_RAM_SIZE                    (0ul)
    #define TCP_SPI_RAM_BASE_ADDRESS            (0x00)

    // Define names of socket types
    #define TCP_SOCKET_TYPES
        #define TCP_PURPOSE_GENERIC_TCP_CLIENT 0
        #define TCP_PURPOSE_GENERIC_TCP_SERVER 1
        #define TCP_PURPOSE_TELNET 2
        #define TCP_PURPOSE_FTP_COMMAND 3
        #define TCP_PURPOSE_FTP_DATA 4
        #define TCP_PURPOSE_TCP_PERFORMANCE_TX 5
        #define TCP_PURPOSE_TCP_PERFORMANCE_RX 6
        #define TCP_PURPOSE_UART_2_TCP_BRIDGE 7
        #define TCP_PURPOSE_HTTP_SERVER 8
        #define TCP_PURPOSE_DEFAULT 9
        #define TCP_PURPOSE_BERKELEY_SERVER 10
        #define TCP_PURPOSE_BERKELEY_CLIENT 11
    #define END_OF_TCP_SOCKET_TYPES

    #if defined(__TCP_C)
        // Define what types of sockets are needed, how many of
        // each to include, where their TCB, TX FIFO, and RX FIFO
        // should be stored, and how big the RX and TX FIFOs should
        // be.  Making this initializer bigger or smaller defines
        // how many total TCP sockets are available.
        //
        // Each socket requires up to 56 bytes of PIC RAM and
        // 48+(TX FIFO size)+(RX FIFO size) bytes of TCP_*_RAM each.
        //
        // Note: The RX FIFO must be at least 1 byte in order to
        // receive SYN and FIN messages required by TCP.  The TX
        // FIFO can be zero if desired.
        #define TCP_CONFIGURATION
        const struct
        {
            u8 vSocketPurpose;
            u8 vMemoryMedium;
            u16 wTXBufferSize;
            u16 wRXBufferSize;
        } TCPSocketInitializer[] =
        {
            //{TCP_PURPOSE_GENERIC_TCP_CLIENT, TCP_ETH_RAM, 125, 100},
            //{TCP_PURPOSE_GENERIC_TCP_SERVER, TCP_ETH_RAM, 20, 20},
            {TCP_PURPOSE_TELNET, TCP_ETH_RAM, 200, 150},
            //{TCP_PURPOSE_TELNET, TCP_ETH_RAM, 200, 150},
            //{TCP_PURPOSE_TELNET, TCP_ETH_RAM, 200, 150},
            //{TCP_PURPOSE_FTP_COMMAND, TCP_ETH_RAM, 100, 40},
            //{TCP_PURPOSE_FTP_DATA, TCP_ETH_RAM, 0, 128},
            {TCP_PURPOSE_TCP_PERFORMANCE_TX, TCP_ETH_RAM, 200, 1},
            {TCP_PURPOSE_TCP_PERFORMANCE_RX, TCP_ETH_RAM, 40, 1500},
            //{TCP_PURPOSE_UART_2_TCP_BRIDGE, TCP_ETH_RAM, 256, 256},
            {TCP_PURPOSE_HTTP_SERVER, TCP_ETH_RAM, 200, 200},
            {TCP_PURPOSE_HTTP_SERVER, TCP_ETH_RAM, 200, 200},
            //{TCP_PURPOSE_DEFAULT, TCP_ETH_RAM, 200, 200},
            //{TCP_PURPOSE_BERKELEY_SERVER, TCP_ETH_RAM, 25, 20},
            //{TCP_PURPOSE_BERKELEY_SERVER, TCP_ETH_RAM, 25, 20},
            //{TCP_PURPOSE_BERKELEY_SERVER, TCP_ETH_RAM, 25, 20},
            //{TCP_PURPOSE_BERKELEY_CLIENT, TCP_ETH_RAM, 125, 100},
        };
        #define END_OF_TCP_CONFIGURATION
    #endif

/* UDP Socket Configuration
 *   Define the maximum number of available UDP Sockets, and whether
 *   or not to include a checksum on packets being transmitted.
 */
#define MAX_UDP_SOCKETS     (9u)
#define UDP_USE_TX_CHECKSUM     // This slows UDP TX performance by nearly 50%, except when using the ENCX24J600 or PIC32MX6XX/7XX, which have a super fast DMA and incurs virtually no speed pentalty.




// =======================================================================
//   Application-Specific Options
// =======================================================================

// -- HTTP2 Server options -----------------------------------------------

    // Maximum numbers of simultaneous HTTP connections allowed.
    // Each connection consumes 2 bytes of RAM and a TCP socket
    #define MAX_HTTP_CONNECTIONS    (2u)

    // Optional setting to use PIC RAM instead of Ethernet/Wi-Fi RAM for
    // storing HTTP Connection Context variables (HTTP_CONN structure for each
    // HTTP connection).  Undefining this macro results in the Ethernet/Wi-Fi
    // RAM being used (minimum PIC RAM usage, lower performance).  Defining
    // this macro results in PIC RAM getting used (higher performance, but uses
    // PIC RAM).  This option should not be enabled on PIC18 devices.  The
    // performance increase of having this option defined is only apparent when
    // the HTTP server is servicing multiple connections simultaneously.
    //#define HTTP_SAVE_CONTEXT_IN_PIC_RAM

    // Indicate what file to serve when no specific one is requested
    #define HTTP_DEFAULT_FILE       "index.htm"
    #define HTTPS_DEFAULT_FILE      "index.htm"
    #define HTTP_DEFAULT_LEN        (10u)       // For buffer overrun protection.
                                                // Set to longest length of above two strings.

    // Configure MPFS over HTTP updating
    // Comment this line to disable updating via HTTP
//  #define HTTP_MPFS_UPLOAD        "mpfsupload"
    //#define HTTP_MPFS_UPLOAD_REQUIRES_AUTH    // Require password for MPFS uploads
        // Certain firewall and router combinations cause the MPFS2 Utility to fail
        // when uploading.  If this happens, comment out this definition.

    // Define which HTTP modules to use
    // If not using a specific module, comment it to save resources
//  #define HTTP_USE_POST                   // Enable POST support
//  #define HTTP_USE_COOKIES                // Enable cookie support
//  #define HTTP_USE_AUTHENTICATION         // Enable basic authentication support

    //#define HTTP_NO_AUTH_WITHOUT_SSL      // Uncomment to require SSL before requesting a password

    // Define the listening port for the HTTP server
    #define HTTP_PORT               (80u)

    // Define the listening port for the HTTPS server (if STACK_USE_SSL_SERVER is enabled)
    #define HTTPS_PORT              (443u)

    // Define the maximum data length for reading cookie and GET/POST arguments (bytes)
    #define HTTP_MAX_DATA_LEN       (100u)

    // Define the minimum number of bytes free in the TX FIFO before executing callbacks
    #define HTTP_MIN_CALLBACK_FREE  (16u)

//  %STACK_USE_HTTP_APP_RECONFIG%#define STACK_USE_HTTP_APP_RECONFIG        // Use the AppConfig web page in the Demo App (~2.5kb ROM, ~0b RAM)
//  %STACK_USE_HTTP_MD5_DEMO%#define STACK_USE_HTTP_MD5_DEMO            // Use the MD5 Demo web page (~5kb ROM, ~160b RAM)
//  %STACK_USE_HTTP_EMAIL_DEMO%#define STACK_USE_HTTP_EMAIL_DEMO        // Use the e-mail demo web page


// -- Telnet Options -----------------------------------------------------

    // Number of simultaneously allowed Telnet sessions.  Note that you
    // must have an equal number of TCP_PURPOSE_TELNET type TCP sockets
    // declared in the TCPSocketInitializer[] array above for multiple
    // connections to work.  If fewer sockets are available than this
    // definition, then the the lesser of the two quantities will be the
    // actual limit.
    #define MAX_TELNET_CONNECTIONS  (1u)

    // Default local listening port for the Telnet server.  Port 23 is the
    // protocol default.
    #define TELNET_PORT             23

    // Default local listening port for the Telnet server when SSL secured.
    // Port 992 is the telnets protocol default.
    #define TELNETS_PORT            992

    // Force all connecting clients to be SSL secured and connected via
    // TELNETS_PORT.  Connections on port TELNET_PORT will be ignored.  If
    // STACK_USE_SSL_SERVER is undefined, this entire setting is ignored
    // (server will accept unsecured connections on TELNET_PORT and won't even
    // listen on TELNETS_PORT).
    //#define TELNET_REJECT_UNSECURED

    // Default username and password required to login to the Telnet server.
    #define TELNET_USERNAME         "admin"
    #define TELNET_PASSWORD         "microchip"

#endif


//#define STACK_USE_UART

//#define STACK_USE_UART2TCP_BRIDGE

//#define STACK_USE_IP_GLEANING

//#define STACK_USE_ICMP_CLIENT

//#define STACK_USE_SSL_SERVER

//#define STACK_USE_SSL_CLIENT

//#define STACK_USE_FTP_SERVER

//#define STACK_USE_SMTP_CLIENT

//#define STACK_USE_SNMP_SERVER

//#define STACK_USE_TFTP_CLIENT

//#define STACK_USE_GENERIC_TCP_CLIENT_EXAMPLE

//#define STACK_USE_GENERIC_TCP_SERVER_EXAMPLE

//#define STACK_USE_TELNET_SERVER

//#define STACK_USE_DNS

//#define STACK_USE_REBOOT_SERVER

//#define STACK_USE_SNTP_CLIENT


//#define STACK_USE_DYNAMICDNS_CLIENT

//#define MPFS_USE_EEPROM

//#define MPFS_USE_SPI_FLASH

//#define MPFS_USE_FAT

//#define STACK_USE_TCP

//#define STACK_USE_UDP

//#define HTTP_MPFS_UPLOAD      "mpfsupload"

//#define HTTP_USE_POST

//#define HTTP_USE_COOKIES

//#define HTTP_USE_AUTHENTICATION

//#define STACK_USE_HTTP_APP_RECONFIG

//#define STACK_USE_HTTP_MD5_DEMO

//#define STACK_USE_HTTP_EMAIL_DEMO

//#define STACK_USE_BERKELEY_API

#define SNMP_MAX_COMMUNITY_SUPPORT      (3u)

#define SNMP_COMMUNITY_MAX_LEN      (8u)

#define NOTIFY_COMMUNITY_LEN        SNMP_COMMUNITY_MAX_LEN

#define SSL_RSA_KEY_SIZE        (512ul)

#define MAX_SSL_CONNECTIONS     (1ul)

#define MAX_SSL_SESSIONS        (1ul)

#define MAX_SSL_BUFFERS     (2ul)

#define MAX_SSL_HASHES      (3ul)


//#define STACK_USE_AUTO_IP

#define MDD_ROOT_DIR_PATH       "\\"

#define SNMP_TRAP_DISABLED

#define SNMP_STACK_USE_V2_TRAP

//#define STACK_USE_SNMPV3_SERVER

#define BSD_SOCKET_COUNT        (5u)

#define SNMP_READ_COMMUNITIES        {"", "", ""}
    #define END_OF_SNMP_READ_COMMUNITIES

#define SNMP_WRITE_COMMUNITIES        {"", "", ""}
    #define END_OF_SNMP_WRITE_COMMUNITIES
