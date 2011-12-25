#pragma once
#include "wtwPlugin.h"

struct wtwUPnPMapping
{
	__wtwStdStructDefs(wtwUPnPMapping);

	int				structSize;

	const wchar_t * description;		// mapping gescription
	
	wchar_t			intIp[32];			// internal ip, unless IPZEROCONF is specified
	int				intPort;			// internal port
	int				extPort;			// external port

	wchar_t 		extIp[32];			// buffer for our external IP

	DWORD			flags;				// flags
};

// for add mapping

#define WTW_UPNP_FLAG_IPZEROCONF	0x00000001 // autoconfiguration of internal Ip, bind socket to 0.0.0.0
#define WTW_UPNP_FLAG_PROTO_TCP		0x00000002 // forward tcp
#define WTW_UPNP_FLAG_PROTO_UDP		0x00000004 // forward udp

// for Get IPs

#define WTW_UPNP_FLAG_GET_EXT_IP	0x00000010 
#define WTW_UPNP_FLAG_GET_INT_IP	0x00000020 

#define WTW_UPNP_ADD_PORT_MAPPING	L"UPnP/AddPortMapping"	// wP - wtwUPnPMapping*, returns S_OK or E_* on error
#define WTW_UPNP_DEL_PORT_MAPPING	L"UPnP/DelPortMapping"	// wP - wtwUPnPMapping*, returns S_OK or E_* on error
#define WTW_UPNP_IS_AVAILABLE		L"UPnP/IsAvailable"		// returns non-zero if so
#define WTW_UPNP_GET_IPS			L"UPnP/GetExtIP"		// wP - wtwUPnPMapping* (extIp/intIp) will be filled, returns S_OK or E_* on error