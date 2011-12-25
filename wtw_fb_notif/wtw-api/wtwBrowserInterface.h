#pragma once

#include "wtwPlugin.h"

// ponizej mamy funkcjektorepozalajanam na dostanie
// wskanikow do interfaceu z cpp/BrowserInterface.h

#define WTW_BROWSER_INT_ALLOCATE	L"WTW/ReqBrIntPtr"

// fukcjeponizj trzeba zarejestrowac z wtyczki jesli chcemy zastapicwbudowany engine wlasnym
// z racji logicznosci, wtyczkapodmieniajacaengine htmlmoze byc tylko jedna

#define EXT_BROWSER_INT_ALLOCATE	L"Browser/Allocate"	// zwracac powinna new wtw::CBrowserInterface


#define WTW_BROWSER_LOCATION_UNKNOWN		0x0000L // as wp in EXT_BROWSER_INT...
#define WTW_BROWSER_LOCATION_CHATWND		0x0001L
#define WTW_BROWSER_LOCATION_CONFERENCE_TAB 0x0002L
#define WTW_BROWSER_LOCATION_CONFERENCE_LOG 0x0003L
#define WTW_BROWSER_LOCATION_PROTO_CONSOLE	0x0004L
#define WTW_BROWSER_LOCATION_ARCH_WND		0x0005L
#define WTW_BROWSER_LOCATION_SYS_MSG_WND	0x0006L
#define WTW_BROWSER_LOCATION_PLUGIN_WND		0x0007L
#define WTW_BROWSER_LOCATION_OPTIONS_PLUG	0x0008L