#ifndef __wtw__ns_h__
#define __wtw__ns_h__

#include "wtwPlugin.h"
#include "wtwNetLib.h"

struct wtwNetSettings 
{
	__wtwStdStructDefs(wtwNetSettings);

	int			structSize;
	
	wchar_t		proxyHost[256];	// host proxy
	wchar_t		proxyUser[256];	// nazwa uzytkownika jesli proxyAuth
	wchar_t		proxyPass[256];	// haslo usera jesli proxyAuth
	int			proxyPort;		// port do hosta
	int			useProxy;		// czy domyslnie uzywac proxy
	int			proxyType;		// typ serwera, zgodne z tym co jest w netlib.h
	int			proxyAuth;		// czy wymaga autoryzacji

};

#define WTW_NETLIB_GET_DEFAULT_SETTINGS	L"WTW/NL/GetDefaultSettings"

#endif