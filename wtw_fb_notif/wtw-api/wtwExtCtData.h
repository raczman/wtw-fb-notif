#pragma once // jestem leniwy od dzis

#include "wtwContact.h"

struct wtwExtData 
{
	__wtwStdStructDefs(wtwExtData);

	int					structSize;

	wtwContactDef		contactData;		// id, nID, nSID - musza byc podane

	const	wchar_t *	fieldName;
			wchar_t *	fieldValue; // to wlasciwie i tak jest const jesli to zwracane 
	DWORD				fieldBufferLen; // przy pobieraniu, max rozmiar bufora (w znakach!)

};

#define WTW_EXTCTD_GET_FIELD	L"WTW/Extend/GetField"	// wP - wtwExtData
#define WTW_EXTCTD_SET_FIELD	L"WTW/Extend/SetField"	// wP - wtwExtData
#define WTW_EXTCTD_DEL_FIELD	L"WTW/Extend/DelField"	// wP - wtwExtData

#define WTW_EXTCTC_FIELD_NAME_CELL_PHONE	L"cell"
#define WTW_EXTCTC_FIELD_NAME_STD_PHONE		L"phone"
#define WTW_EXTCTC_FIELD_NAME_MAIL			L"mail"
#define WTW_EXTCTC_FIELD_NAME_ADDRESS		L"address"
#define WTW_EXTCTC_FIELD_NAME_NAME			L"name"
#define WTW_EXTCTC_FIELD_NAME_SURNAME		L"surname"
#define WTW_EXTCTC_FIELD_NAME_BIRTH			L"birth"

#define WTW_ENGINE_FUNCTION_CALL_PREPARE L"EXT/Phone/Prepare"	// zarejestrowac taka funcke jesli chemy przejac
																// reakcje na dblclk na ikonce odpowiendniej
#define WTW_ENGINE_FUNCTION_SMS_PREPARE L"EXT/Cell/Prepare"		// 