#pragma once

#include "wtwPlugin.h"

/*
	All functions, except for GET_CURRENT_LNG return S_OK, E_FAIL, 
		E_INVALIDARD, S_FALSE or something like E_*
*/

#define WTW_I18N_TRANSLATE_WND		L"I18N/TranslateWnd"
#define WTW_I18N_DUMP_WND_XML		L"I18N/DumpWndXml"
#define WTW_I18N_GET_TEXT			L"I18N/GetText"
#define WTW_I18N_IS_LNG_AVAILABLE	L"I18N/IsLngAvailable"	// wP = wchar_t*, lang iso code. ret - S_OK ir S_FALSE
#define WTW_I18N_GET_CURRENT_LNG	L"I18N/GetCurrentLng"	// ret = const wchar_t* - current lang iso code

struct wtwI18NGetText
{
	__wtwStdStructDefs(wtwI18NGetText);

	int				structSize;
	const wchar_t *	isoLng; // NULL
	const wchar_t * module; // jesl plik tlumczenia to "wtwOther.xml" to tu podajemy "wtwOther"
	DWORD			textId; // id komunikatu <text/> w "module"
	const wchar_t * defaultText; // tekstktory zwrocic jesli nie odszukamy komunikatu/pliku

	const wchar_t * text;		// zwrocony tekst, nie zwalniamy, nie trzymamy tego wskanizka
};

struct wtwI18NDumpWindowXml
{
	__wtwStdStructDefs(wtwI18NDumpWindowXml);

	int				structSize;
	const wchar_t * filePath;	// pelna sciezka dopliku
	HWND			hWnd;		// handleokna z ktoregotemplate chcemy zrobic
};

struct wtwI18NTranslateWnd
{
	__wtwStdStructDefs(wtwI18NTranslateWnd);

	int				structSize;
	const wchar_t *	isoLng;		// NULL
	const wchar_t * module;		// 
	DWORD			windowId;	// 
	HWND			hWnd;		// handle okna
};