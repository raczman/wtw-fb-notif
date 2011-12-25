#pragma once

#include "wtwPlugin.h"

/********************************************************************************
** 
** Basic flow:
**	Create
**	Register
**	Register
**	Execute
**	Execute
**	Destroy
**	
**	Albo, czego jeszcze nie ma a moze bedzie, a moze nie:
**
**	Create
**	Register
**	Register
**	Compile
**	Call
**	Call
**	Call
**	Destroy
**	
*/

#define WTW_JS_CREATE		L"JS/Create"	// zwraca WTW_PTR, do uzycia dalej
#define WTW_JS_DESTROY		L"JS/Destroy"	// zwalnia zwrocony wyzej WTW_PTR (@wP)

#define rPTR	void*

struct wtwJSExecute
{
	__wtwStdStructDefs(wtwJSExecute);

	int				structSize;
	const wchar_t *	filePath;
	
	const char *	mainFunctionName;	// funkcja ktora chcemy wywolac, trzeba podac
	const wchar_t** argv;				// argumenty dla niej
	int				argc;				// ilosc powyzszych, mozemy podac zero, wtedy wyej podajemy null (jesli funkcja nie ma argumentow)

	wchar_t **		retPtr;				// wskaznik do zmiennej, ktora otrzyma to co funkcja zwrocila, zwolnic to potem

	DWORD			flags;

	WTW_PTR			context;
};

#define WTW_JS_EXECUTE_FLAG_FILE_IS_CODE	0x000001	// filePath to nie jest sciezka do pliku a kod js
#define WTW_JS_EXECUTE_FLAG_CODE_IS_UTF8	0x000002	// jesli podajemy kod, to jesli jest w utf8 a nie w utf16 ustawiamy to
#define WTW_JS_EXECUTE_FLAG_NO_ERROR_UI		0x000004	// czy raportowac bledy wykonania/kompilacji do uzytkownika

#define WTW_JS_STATUS_OK		0	// all ok
#define WTW_JS_STATUS_EOTHER	1	// jakis blad
#define WTW_JS_STATUS_ECOMPILE	2	// blad kompilacji skryptu
#define WTW_JS_STATUS_ENOMAIN	3	// brak funkcji podanej w mainFunctionName
#define WTW_JS_STATUS_ECALL		4	// blad wywolania funkcji
#define WTW_JS_STATUS_EFILE		5	// cos nie tak z plikiem

#define WTW_JS_EXECUTE			L"JS/Execute"		// wP = wtwJSExecute*
#define WTW_JS_FREE				L"JS/Free"			// wP = rPTR*
#define WTW_JS_ALLOC			L"JS/Alloc"			// wP = rozmiar potrzebnego bufora w BAJTACH, zwraca rPTR

struct wtwJSArguments
{
	__wtwStdStructDefs(wtwJSArguments);

	int				structSize;

	const wchar_t** argv;				// argumenty dla naszej funkcji, to moze byc null
	int				argc;				// ilosc powyzszych

	rPTR			returnValue;		// jesli cos chcemy zwrocic to têdy, uzywajac JS_ALLOC, nie zwalniamy tego. komunikator sam to zrobi jak bedzie zbedne;
	DWORD			returnType;
};

#define WTW_JS_RETURN_TYPE_STRING	1	// wchar_t*
#define WTW_JS_RETURN_TYPE_UTF8		2	// char* w utf8
#define WTW_JS_RETURN_TYPE_NUMBER	3	// double* (8b)
#define WTW_JS_RETURN_TYPE_INT32	4	// int32* (4b)

#define WTW_JS_FUNC_CALL_OK			0	// zwracamy z naszej funkcji jesli wszystko poszlo ok
#define WTW_JS_FUNC_CALL_ARGERR		1	// jesli na przyklad brakowalo argumentow, mozemy wtedyuzyc returnValue aby poinformowac usera o bledzie
#define WTW_JS_FUNC_CALL_ERROR		2	// jw. z tym returnValue

struct wtwJSFunction
{
	__wtwStdStructDefs(wtwJSFunction);

	int				structSize;

	WTWFUNCTION		funcPtr;			// nasza funkcja
	const char *	funcName;			// nazwa pod jaka bedzie dostepna z poziomu JS
	void *			cbData;				// dane dla naszej funkcji

	WTW_PTR			context;			// to co zwrocilo CREATE
};

#define WTW_JS_REGISTER_FUNCTION	L"JS/Register"	// wP = wtwJSFunction*
//#define WTW_JS_UNREGISTER_FUNCTION	L"JS/Unregister"// wP = const char* - funkcjado usuniecia