#pragma once

#include "wtwPlugin.h"
#include <winsock2.h>

/*******************************************************************************
**
** Function: 
**		WTW_NETLIB_CREATE
**
** Return value: 
**		S_OK, E_*
**
** Parameters:
**		wP - netLibCreateDef*
**		lP - NULL
**
*/

#define WTW_NETLIB_CREATE  L"NetLib/Create"		

/*******************************************************************************
**
** Function: 
**		WTW_NETLIB_DESTROY
**
** Return value: 
**		S_OK, E_*
**
** Parameters:
**		wP - const wchar_t* socketId;
**		lP - NULL;
**
** Remarks:
**		Do NOT call this function from socket callback function
**		It will most likely explode in your face
**
*/

#define WTW_NETLIB_DESTROY L"NetLib/Destroy"

/*******************************************************************************
**
** Function: 
**		WTW_NETLIB_CONNECT
**
** Return value: 
**		S_OK, E_*
**
** Parameters:
**		wP - netLibConnectDef*
**		lP - NULL
**
*/

#define WTW_NETLIB_CONNECT L"NetLib/Connect"

/*******************************************************************************
**
** Function: 
**		WTW_NETLIB_CONNECT_SERVICE
**
** Return value: 
**		S_OK, E_*
**
** Parameters:
**		wP - netLibConnectServiceDef*
**		lP - NULL
**
*/

#define WTW_NETLIB_CONNECT_SERVICE L"NetLib/ConnectService"

/*******************************************************************************
**
** Function: 
**		WTW_NETLIB_CLOSE
**
** Return value: 
**		S_OK, E_*
**
** Parameters:
**		wP - const wchar_t* socketId
**		lP - NULL
**
*/

#define WTW_NETLIB_CLOSE   L"NetLib/Close"

/*******************************************************************************
**
** Function: 
**		WTW_NETLIB_SEND
**
** Return value: 
**		E_*, or count of bytes loaded into send buffer 
**
** Parameters:
**		wP - netLibSendDef*
**		lP - NULL
**
*/

#define WTW_NETLIB_SEND	L"NetLib/Send"

/*******************************************************************************
**
** Function: 
**		WTW_NETLIB_INITSSL
**
** Return value: 
**		S_OK, E_*
**
** Parameters:
**		wP - const wchar_t* socketId
**		lP - NL_SSL_MECH_*
**
*/

#define WTW_NETLIB_INITSSL	L"NetLib/InitSSL"

#define NL_SSL_MECH_AUTO		0x00FF0000
#define NL_SSL_MECH_SSLv30		0x00010000
#define NL_SSL_MECH_TLSv10		0x00020000
#define NL_SSL_MECH_TLSv11		0x00040000
#define NL_SSL_MECH_TLSv12		0x00080000

////////////////////////////////////////////////////////////////////////
//
// Events
//

#define WTW_NETLIB_EVENT_DESTROY 0x0001	// socket is being destroyed
#define WTW_NETLIB_EVENT_CONNECT 0x0002 // connected (or connection error)
#define WTW_NETLIB_EVENT_CLOSE   0x0003 // connection closed
#define WTW_NETLIB_EVENT_DATA    0x0004 // data received
#define WTW_NETLIB_EVENT_ACCEPT  0x0005 // incominng connection
#define WTW_NETLIB_EVENT_CLOSED  0x0006 // Well, umm, dunno what for is it
#define WTW_NETLIB_EVENT_SSL	 0x0008 // Informations about SSL connection status
#define WTW_NETLIB_EVENT_SSLOVR	 0x000A // Override SSL certificate check
#define WTW_NETLIB_EVENT_ERROR	 0x0009 // Connection other error
#define WTW_NETLIB_EVENT_SENDC	 0x0010 // Sent when all data from output buffer was sent 
#define WTW_NETLIB_EVENT_COMPR	 0x0011 // lP = SSL Compression enabled = 1, 0 - compression unavailable
#define WTW_NETLIB_EVENT_CONINFO 0x0012 // lP = netLibConInfo* - sent after connection was accepted on target sock

////////////////////////////////////////////////////////////////////////
//
// Constants
//

#define WTW_NETLIB_PROXYTYPE_SOCKS5		0x01
#define WTW_NETLIB_PROXYTYPE_HTTP11		0x02

#define WTW_NETLIB_FLAG_PROXY		0x00000001	// Enable proxy layer
#define WTW_NETLIB_FLAG_SSL			0x00000002	// Enable TLS layer, call SSLINIT to send handshake 
#define WTW_NETLIB_FLAG_LISTEN		0x00000004	// Listening socket
#define WTW_NETLIB_FLAG_ACCEPT		0x00000010	// Accept incoming connection, "fromSocket" has to be filled

#define NL_ADDR_FAMILY_UNSPEC	0x0000
#define NL_ADDR_FAMILY_IPV4		0x0001
#define NL_ADDR_FAMILY_IPV6		0x0002
#define NL_ADDR_FAMILY_BTH		0x0003 // hostAddr should be in format: "XXXXXXXXXXXX,{GUID}". Where XXX - target MAC, {GUID} - Service GUID

////////////////////////////////////////////////////////////////////////
//
// Structures
//

struct netLibEventDef
{
	__wtwStdStructDefs(netLibEventDef);

	int				structSize;
	int				eventID;		// event code
	void		 *	sockAddr;		// Internal, do not use 
	HANDLE			hSocket;		// Socket handle
	const wchar_t*	id;				// Socket id
	void		 *	ownerData;		// ptr from netLibCreateDef;
};

struct netLibConnectDef 
{
	__wtwStdStructDefs(netLibConnectDef);

	int				structSize;

	const wchar_t*	id;				// socket id

	const wchar_t*  hostAddr;		// server address
	int				hostPort;		// port
	int				hostAddrFamily;	// NL_ADDR_FAMILY_*

	const wchar_t *	proxyAddress;   // proxe address (if FLAG_PROXY is set)
	int				proxyType;		// proxy type
	int				proxyPort;		// proxy port

	const wchar_t *	proxyUser;		// NULL or user name for proxy auth
	const wchar_t *	proxyPass;		// NULL or password for proxy auth

	int				flags;			// flags/options

};

struct netLibConnectServiceDef
{
	__wtwStdStructDefs(netLibConnectServiceDef);

	int					structSize;

	netLibConnectDef	c;			// fallback data / proxy data
	const wchar_t *		serviceName;
};

struct netLibSendDef 
{
	__wtwStdStructDefs(netLibSendDef);

	int				structSize;
	const char *	pBuffer;		// buffer
	int				nBufferLen;		// size of data buffer in bytes
	const wchar_t *	id;				// socket id
};

struct netLibCreateDef 
{
	__wtwStdStructDefs(netLibCreateDef);

	int				structSize;
	
	const wchar_t *	bindAddress;	// NULL
	int				bindPort;		// 0
	int				bindAddrFamily;	// NL_ADDR_FAMILY_*

	DWORD			flags;			// options
	DWORD			timeout;		// Depricated, not used

	WTWFUNCTION		callback;		// callback function address for events, wP will contain netLibEventDef*, lP depends on event type
	void		*	cbData;			// callback user Data

	void		*	fromSocket;		// Not used, NULL

	const wchar_t *	id;				// unique socket Id
	void		*	ownerData;		// owner data
};

struct netLibDataDef
{
	__wtwStdStructDefs(netLibDataDef);

	int				structSize;
	int				dataLen;		// received data size
	void *			data;			// data ptr
};

#define WTW_SSL_FAILURE_UNKNOWN		0
#define WTW_SSL_FAILURE_ESTABLISH	1
#define WTW_SSL_FAILURE_INITSSL		4 

struct netLibSSLStatusDef 
{
	__wtwStdStructDefs(netLibSSLStatusDef);

	int				structSize;
	int				sslStatus;		// 1 - OK, 0 - Error
	int				sslInfo;		// WTW_SSL_FAIL...
	const wchar_t * pMessage;		// Extended error mesasge, can be NULL
};

struct netLibConInfo
{
	__wtwStdStructDefs(netLibConInfo);

	int				structSize;
	SOCKADDR		sockAddr;
	int				sockAddrLen;

	const wchar_t * printableAddr;
};

#define NETLIB_S_OK		1
#define NETLIB_S_ERROR	0

////////////////////////////////////////////////////////////////////////
//
// DNS Resolver
//

/*
struct netLibDNSQuery  {
	int				structSize;

	const wchar_t * service;		// xmpp-server
	const wchar_t * proto;			// tcp/udp

	const wchar_t * domain;			// 

	int				prefType;		// tylko 0x21

	WTWFUNCTION		callback;
	void *			cbData;
};

struct netLibDnsEntry {
	int				structSize;

	int				recordType;
	const wchar_t * serviceFQDN;
	int				servicePort;
	int				servicePrio;
};

struct netLibDNSResult  {
	int				structSize;

	int				resultCode;
	int				errorCode;

	int				resultsCount;
	netLibDnsEntry *pResults;
};

#define NL_DNS_S_OK		0
#define NL_DNS_S_ERROR	1
*/