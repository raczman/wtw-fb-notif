#pragma once

#include "wtwPlugin.h"

#define WTW_EVENT_ON_IMPORT_MECH_REQUEST L"WTW/OnImportMechRequest" // wP - cos co trzeba przekazac do register

#define WTW_REGISTER_IMPORT_MECH L"WTW/RegisterImportMech"

struct wtwImportMech 
{
	__wtwStdStructDefs(wtwImportMech);

	int				structSize;

	const wchar_t * mechName;
	WTWFUNCTION		mechFunc;

	WTW_PARAM		callerData;	// MUSIMY podac tu to co podano w hooku jako wParam
};