#pragma once

#include "wtwPlugin.h"
#include <wininet.h>

#define WTW_WININET_GET_INTERNET L"WinInet/GetHandle"

HINTERNET __inline wtwGetInet(WTWFUNCTIONS *pFunc)
{
	return (HINTERNET)pFunc->fnCall(WTW_WININET_GET_INTERNET, 0, 0);
}