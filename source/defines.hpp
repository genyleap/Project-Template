/*!
 *
 * Copyright (c) 2021 Kambiz Asadzadeh
 * Copyright (c) 2023 Genyleap
 */


#ifndef PROJECT_DEFINES_HPP
#define PROJECT_DEFINES_HPP

namespace Defines {

#define OK          0x1
#define ON          0x1
#define CANCEL      0x0
#define FAILED      0x0
#define SUCCESS     0x0
#define OFF         0x0

#define ABSTRACTS 0x1 // Abstraction

#define MESSAGE_OK      "OK"
#define MESSAGE_FAILED  "FAILED"
#define MESSAGE_YES     "YES"
#define MESSAGE_NO      "NO"
#define MESSAGE_ERROR   "ERROR"

#define ERROR_NULL          10001
#define ERROR_HANDLER       10002
#define ERROR_SUBTRACK      10003
#define ERROR_REFRENCE      10004
#define ERROR_DLL           10005
#define ERROR_NETWORK       65102  // Message for Network Error.
#define ERROR_WINDOWS       12111
#define ERROR_SAVED         64511
#define ERROR_DB_CONNECT    64001
#define ERROR_LOADING       64522

//! Core defines.
#undef  KERNEL
#define KERNEL 0x1
#undef  BACKEND
#define BACKEND 0x1
#undef  VIEW
#define VIEW 0x1
#undef  TEMPLATES
#define TEMPLATES 0x1

#undef  MODULE
#define MODULE 0x1

#undef  PLUGIN
#define PLUGIN 0x1

/*---------------------Default ports------------------------*/
// Port numbers range from 0 to 65536, but only port numbers 0 to 1024 are
// reserved for privileged services and designated as well-known ports. This list
// of well-known port numbers specifies the port used by the server process as
// its contact port.

#define PORT_TCP           1             // TCP Port Service Multiplexer (TCPMUX)
#define PORT_RJE           5             // Remote Job Entry (RJE)
#define PORT_ECHO          7             // ECHO
#define PORT_MSP           18            // Message Send Protocol (MSP)
#define PORT_FTP           20            // FTP -- Data
#define PORT_FTP_CONTROL   21            // FTP Control
#define PORT_SSH           22            // SSH Remote Login Protocol
#define PORT_TELNET        23            // Telnet
#define PORT_SMTP          25            // Simple Mail Transfer Protocol (SMTP)
#define PORT_MGS_ICP       29            // MSG ICP
#define PORT_TIME_P        37            // Time
#define PORT_HNS           42            // Host Name Server (Nameserv)
#define PORT_WHOIS         43            // WhoIs
#define PORT_LHP           49            // Login Host Protocol (Login)
#define PORT_DNS           53            // Domain Name System (DNS)
#define PORT_TFTP          69            // Trivial File Transfer Protocol (TFTP)
#define PORT_GOPHER        70            // Gopher Services
#define PORT_FINGER        79            // Finger
#define PORT_APACHE        80            // Apache HTTP Server
#define PORT_HTTP          80            // HTTP
#define PORT_X400          103           // X.400 Standard
#define PORT_SNA           108           // SNA Gateway Access Server
#define PORT_POP2          109           // POP2
#define PORT_POP3          110           // POP3
#define PORT_SFTP          115           // Simple File Transfer Protocol (SFTP)
#define PORT_SQL_SERVICES  118           // SQL Services
#define PORT_NNTP          119           // Newsgroup (NNTP)
#define PORT_NET_BIOS      137           // NetBIOS Name Service
#define PORT_NET_BIOS_DS   139           // NetBIOS Datagram Service
#define PORT_IMAP          143           // Interim Mail Access Protocol (IMAP)
#define PORT_NET_BIOS_SS   150           // NetBIOS Session Service
#define PORT_SNMP          161           // SNMP
#define PORT_BGP           179           // Border Gateway Protocol (BGP)
#define PORT_GACP          190           // Gateway Access Control Protocol (GACP)
#define PORT_IRC           194           // Internet Relay Chat (IRC)
#define PORT_DLS           197           // Directory Location Service (DLS)
#define PORT_DLAP          389           // Lightweight Directory Access Protocol (LDAP)
#define PORT_NOVELL_IP     396           // Novell Netware over IP
#define PORT_HHTPS         443           // HTTPS
#define PORT_SNPP          444           // Simple Network Paging Protocol (SNPP)
#define PORT_MICORSOFT_DS  445           // Microsoft-DS
#define PORT_APPLE_Q_TIME  458           // Apple QuickTime
#define PORT_DHCP_CLIENT   546           // DHCP Client
#define PORT_DHCP_SERVER   547           // DHCP Server
#define PORT_SNEWS         563           // SNEWS
#define PORT_MSN           569           // MSN
#define PORT_VPP           4643          // Virtuosso Power Panel
#define PORT_SOCKS         1080          // Socks

//!Database drivers
#define PORT_MYSQL_DB      3306          // MySQL Database Server
#define PORT_POSTGRESQL_DB 5432          // PostgreSQL Database Server
#define PORT_SQL_SERVER_DB 156           // SQL Server

//!Server addresses
#define GENYLEAP_URL                   "http://genyleap.com"
#define GENYLEAP_SSL_URL               "https://genyleap.com"

#define MICROSOFT_URL                  "http://microsoft.com"
#define MICROSOFT_SSL_URL              "https://microsoft.com"

#define APPLE_NS_USA                   "104.154.51.7"
#define APPLE_NS_EUROPE                "104.155.28.90"
#define APPLE_NS_ASIA                  "104.155.220.58"
#define APPLE_NS_SOUTH_AMERICA         "35.199.88.219"
#define APPLE_NS_AUSTRALIA_OCEANIA     "35.189.47.23"

#define APPLE_URL                      "http://apple.com"
#define APPLE_SSL_URL                  "https://apple.com"
#define APPLE_NS_USA                   "104.154.51.7"
#define APPLE_NS_EUROPE                "104.155.28.90"
#define APPLE_NS_ASIA                  "104.155.220.58"
#define APPLE_NS_SOUTH_AMERICA         "35.199.88.219"
#define APPLE_NS_AUSTRALIA_OCEANIA     "35.189.47.23"

#define CLOUD_FLARE_NS1                "1.1.1.1"
#define CLOUD_FLARE_NS2                "1.0.0.1"

#define QUAD9_NS1                      "9.9.9.9"
#define QUAD9_NS2                      "149.112.112.112"

#define GOOGLE_URL                     "http://google.com"
#define GOOGLE_SSL_URL                 "https://google.com"
#define GOOGLE_NS1                     "8.8.8.8"
#define GOOGLE_NS2                     "8.8.4.4"

//! Protocols
#define PROTOCOL_HTTPS   "https://"      // SECURED PROTOCOL (USING SSL , 443-PORT)
#define PROTOCOL_HTTP    "http://"       // UNSECURTED PROTOCOL (USING PORT : 80)
#define PROTOCOL_FTP     "ftp://"        // FTP PTOTOCOL - FTP data transfer (USING PORT : 20)

//! System actions
#define EXIT 0;

}

#endif // PROJECT_DEFINES_HPP
