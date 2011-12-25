#ifndef __wtw_plugin_settings_h__
#define __wtw_plugin_settings_h__

#include "wtwPlugin.h"
#include <wchar.h>

#pragma warning(disable:4311)
#pragma warning(disable:4312)
#pragma warning(disable:4267)

struct wtwBuffer 
{
	__wtwStdStructDefs(wtwBuffer);

	int		structSize;
	wchar_t *pBuffer;
	int		bufferSize;			// in chars (including space for null charter)!
};

/*******************************************************************************
**
** Function: 
**		WTW_GET_DIRECTORY_LOCATION
**
** Return value: 
**		S_OK, E_*
**
** Parameters:
**		wP - wtwDirectoryInfo*
**		lP - NULL
**
*/

#define WTW_GET_DIRECTORY_LOCATION L"WTW/GetDirectoryLocation"

struct wtwDirectoryInfo
{
	__wtwStdStructDefs(wtwDirectoryInfo);

	int				structSize;

	DWORD			flags;		// WTW_DIRECTORY_FLAG_*
	DWORD			dirType;	// WTW_DIRECTORY_*

	wtwBuffer		bi;			// if bufferSize is -1 (and pBuffer is NULL) 
								// then bufferSize will be updated with required buffer size (in chars + terminator)
};

#define WTW_DIRECTORY_PROFILE		0x0001
#define WTW_DIRECTORY_EXE			0x0002
#define WTW_DIRECTORY_THEME			0x0003
#define WTW_DIRECTORY_USERTHEME		0x0004
#define WTW_DIRECTORY_CACHE			0x0005
#define WTW_DIRECTORY_ARCHIVE		0x0006
#define WTW_DIRECTORY_PLUGINDATA	0x0007
#define WTW_DIRECTORY_SCRIPTS		0x0008
#define WTW_DIRECTORY_LIBRARIES		0x0009

#define WTW_DIRECTORY_FLAG_FULLPATH	0x0001	// C:\Users\User\AppData\Roaming\.wtw\Profiles\Profile\.cache\ - for example
#define WTW_DIRECTORY_FLAG_RELPATH	0x0002	// .cache\

/*******************************************************************************
**
** Function: 
**		WTW_INFO_GET_INSTANCE
**
** Return value: 
**		S_OK, E_* (or if wP is NULL - hInstance of the application)
**
** Parameters:
**		wP - HINSTANCE* - out, pointer to variable which will receive hInst
**		lP - NULL
**
*/

#define WTW_INFO_GET_INSTANCE L"WTW/Info/GetInstance"

/*******************************************************************************
**
** Function: 
**		WTW_SETTINGS_GET_MY_CONFIG_FILE
**
** Return value: 
**		E_* or copied path length in chars 
**
** Parameters:
**		wP - wtwMyConfigFile*
**		lP - plugin's hInstance
**
*/

#define WTW_SETTINGS_GET_MY_CONFIG_FILE L"WTW/Settings/GetMyConfigFile"

struct wtwMyConfigFile 
{
	__wtwStdStructDefs(wtwMyConfigFile);

	int		structSize;
	wchar_t *pBuffer;
	int		bufferSize;
	const wchar_t * desiredExt; // this can be null
};

/*******************************************************************************
**
** Function: 
**		WTW_SETTINGS_INIT_EX - initializes settings interface
**
** Return value: 
**		S_OK/E_*
**
** Parameters:
**		wP - const wchar_t * - path to the file where you want to store settings
**		lP - void** - pointer to pointer which receive settings ptr on success
**
*/

#define WTW_SETTINGS_INIT_EX	L"WTW/Settings/InitEx"

/*******************************************************************************
**
** Function: 
**		WTW_SETTINGS_DESTROY - destroys initialized interface
**
** Return value: 
**		S_OK, E_* 
**
** Parameters:
**		wP - (void *) pSettings - settings interface pointer
**		lP - NULL
**
*/

#define WTW_SETTINGS_DESTROY	L"WTW/Settings/Destroy"

/////////////////////////////////////////////////////////////////////////////////
//
// WTW_SETTINGS_GET_VALUE
// 
// wParam - wtwSettingDef*
// lParam - NULL
// 
// zwraca 1 jesli znaleziono wartosc, 0 jesli nie, -1 buffer too small 
// (w takim wypadku paramValueLen bedzie zawieralo minimalny rozmiar bufora
// taki sam efekt (-1) uzyskamy ustawiajac paramValue na NULL)
//

#define WTW_SETTINGS_GET_VALUE	L"WTW/Settings/Get"

/////////////////////////////////////////////////////////////////////////////////
//
// WTW_SETTINGS_SET_VALUE
// 
// wParam - wtwSettingDef*
// lParam - NULL
// 
// 1 jesli ok, 0 przy bledzie
//

#define WTW_SETTINGS_SET_VALUE	L"WTW/Settings/Set"

/////////////////////////////////////////////////////////////////////////////////
//
// WTW_SETTINGS_READ
// 
// wParam - (void*)pSettings
// lParam - NULL
// 
// 1 jesli ok, 0 przy bledzie
//

#define WTW_SETTINGS_READ	L"WTW/Settings/Read"

/////////////////////////////////////////////////////////////////////////////////
//
// WTW_SETTINGS_WRITE
// 
// wParam - (void*) pSettings
// lParam - NULL
// 
// 1 jesli ok, 0 przy bledzie
//

#define WTW_SETTINGS_WRITE	L"WTW/Settings/Write"

/////////////////////////////////////////////////////////////////////////////////
//
// WTW_SETTINGS_GET_LEN -	zwraca ilosc danych (w bajtach) w paramValueSize 
//							ktore siedza pod danym kluczem
// 
// wParam - (void*) pSettings
// lParam - NULL
// 
// 1 jesli ok, 0 przy bledzie
//

#define WTW_SETTINGS_GET_LEN	L"WTW/Settings/GetLen"

/////////////////////////////////////////////////////////////////////////////////
//
// WTW_SETTINGS_GET_TYPE -	zwraca typ danych danych  
//							ktore siedza pod danym kluczem (w paramValueType)
// 
// wParam - (void*) pSettings
// lParam - NULL
// 
// 0 - nie ma takiej wartosci, w innym wypadku 1
//

#define WTW_SETTINGS_GET_TYPE	L"WTW/Settings/GetType"

/////////////////////////////////////////////////////////////////////////////////
//
// WTW_SETTINGS_SET_KEY
// 
// wParam - (void*) pSettings
// lParam - (char*) char[64]
// 
// 1 jesli ok, 0 przy bledzie - ustawia klucz szyfrowania dla pliku ustawien
// szyfrowane sa jedynei wartosci _STR (AES, 512 bit)
// jesli nie zostanie ustawiony zostanie uzyty domyslny
//

#define WTW_SETTINGS_SET_KEY	L"WTW/Settings/SetKey"

/////////////////////////////////////////////////////////////////////////////////
//
// 

struct wtwSettingDef 
{
	__wtwStdStructDefs(wtwSettingDef);

	int				structSize;

	const wchar_t *	paramName;		//nazwa ustawienia, cos jak "WTW/ProxyAddres"

	int				paramValueType; // typ, int, sting, user
	void *			paramValue;		// wartosc
	int				paramValueSize;	// rozmiar takowej (tylko dla string i usr)

	void *			pSettings;		//to co zwrocilo INIT

};

#define WTW_SETTINGS_PVT_INT 0x01 // integer (int) == pvt
#define WTW_SETTINGS_PVT_STR 0x03 // string (wchar_t*) == pvt
#define WTW_SETTINGS_PVT_USR 0x02 // (void*) == pvt
#define WTW_SETTINGS_PVT_I64 0x04 // (long long*) == pvt

/////////////////////////////////////////////////////////////////////////////////
//
// Danych uzytkownika mozna zapisac max okolo 64k. Tj - na dysk zostanie 
// zapisane max 64k, dzieki kompresji pewnie wcisnie sie wiecej, ale ciezko
// powiedziec ile, dlatego limit 64k bedzie rozsadnym;
//

int __inline wtwGetInt(
					   WTWFUNCTIONS *pF, 
					   void *pSett,
					   const wchar_t * sName, 
					   int defValue)
{
	wtwSettingDef sDef;

	sDef.paramValueType = WTW_SETTINGS_PVT_INT;
	sDef.pSettings = pSett;
	sDef.paramName = sName;

	int ret = (int)pF->fnCall(WTW_SETTINGS_GET_VALUE, sDef, NULL);

	if (ret)
		ret = (int)sDef.paramValue;
	else
		ret = defValue;

	return ret;
}

int __inline wtwSetInt(
					   WTWFUNCTIONS *pF, 
					   void *pSett,
					   const wchar_t * sName, 
					   int value)
{
	wtwSettingDef sDef;

	sDef.paramValueType = WTW_SETTINGS_PVT_INT;
	sDef.pSettings = pSett;
	sDef.paramName = sName;
	sDef.paramValue= (void*)value;

	int ret = static_cast<int>(pF->fnCall(WTW_SETTINGS_SET_VALUE, sDef, NULL));

	if (ret)
		ret = value;
	else
		ret = -1;

	return ret;
}

WTW_PTR __inline wtwGetStr(
					   WTWFUNCTIONS *pF, 
					   void *pSett,
					   const wchar_t * sName, 
					   const wchar_t * defValue,
					   wchar_t **value)
{
	wtwSettingDef sDef;
	initStruct(sDef);

	const int buffSize = 1024 * 4;

	sDef.paramValueType = WTW_SETTINGS_PVT_STR;
	sDef.pSettings = pSett;
	sDef.paramName = sName;

	sDef.paramValueSize = buffSize;
	sDef.paramValue     = (void*) new wchar_t [buffSize];
	
	WTW_PTR ret = pF->fnCall(WTW_SETTINGS_GET_VALUE, sDef, NULL);

	if (!ret) {
		wcsncpy((wchar_t*)sDef.paramValue, defValue, buffSize - 1);
	}

	*value = (wchar_t*)sDef.paramValue;

	return ret; 
}

WTW_PTR __inline wtwSetStr(
					   WTWFUNCTIONS *pF, 
					   void *pSett,
					   const wchar_t * sName, 
					   const wchar_t * value)
{
	wtwSettingDef sDef;

	sDef.paramValueType = WTW_SETTINGS_PVT_STR;
	sDef.pSettings = pSett;
	sDef.paramName = sName;

	sDef.paramValueSize = wcslen(value);
	sDef.paramValue     = (void*)value;
	
	return pF->fnCall(WTW_SETTINGS_SET_VALUE, sDef, NULL);
}

long long __inline wtwGetInt64(
					   WTWFUNCTIONS *pF, 
					   void *pSett,
					   const wchar_t * sName, 
					   long long defValue)
{
	wtwSettingDef sDef;

	long long tmp = 0;

	sDef.paramValueType = WTW_SETTINGS_PVT_I64;
	sDef.pSettings = pSett;
	sDef.paramName = sName;
	sDef.paramValue= &tmp;

	long long ret = (long long)pF->fnCall(WTW_SETTINGS_GET_VALUE, sDef, NULL);

	if (ret)
		ret = tmp;
	else
		ret = defValue;

	return ret;
}

long long __inline wtwSetInt64(
					   WTWFUNCTIONS *pF, 
					   void *pSett,
					   const wchar_t * sName, 
					   long long value)
{
	wtwSettingDef sDef;
	initStruct(sDef);

	sDef.paramValueType = WTW_SETTINGS_PVT_I64;
	sDef.pSettings = pSett;
	sDef.paramName = sName;
	sDef.paramValue= &value;

	long long ret = static_cast<long long>(pF->fnCall(WTW_SETTINGS_SET_VALUE, sDef, NULL));

	if (ret)
		ret = value;
	else
		ret = -1;

	return ret;
}

WTW_PTR __inline wtwGetUsr(
					   WTWFUNCTIONS *pF, 
					   void *pSett,
					   const wchar_t * sName, 
					   void *buffer,
					   int	bufferLen)
{
	wtwSettingDef sDef;

	sDef.paramValueType = WTW_SETTINGS_PVT_USR;
	sDef.pSettings = pSett;
	sDef.paramName = sName;

	sDef.paramValueSize = bufferLen;
	sDef.paramValue     = (void*) buffer;
	
	return pF->fnCall(WTW_SETTINGS_GET_VALUE, sDef, NULL);
}

WTW_PTR __inline wtwSetUsr(
					   WTWFUNCTIONS *pF, 
					   void *pSett,
					   const wchar_t * sName, 
					   void *	buffer,
					   int		bufferLen
					   )
{
	wtwSettingDef sDef;

	sDef.paramValueType = WTW_SETTINGS_PVT_USR;
	sDef.pSettings = pSett;
	sDef.paramName = sName;

	sDef.paramValueSize = bufferLen;
	sDef.paramValue     = buffer;
	
	return pF->fnCall(WTW_SETTINGS_SET_VALUE, sDef, NULL);
}

int __inline wtwGetDataLen(
					   WTWFUNCTIONS *pF, 
					   void *pSett,
					   const wchar_t * sName
					   )
{
	wtwSettingDef sDef;

	sDef.paramValueType = -1;
	sDef.pSettings = pSett;
	sDef.paramName = sName;

	pF->fnCall(WTW_SETTINGS_GET_LEN, sDef, NULL);

	return sDef.paramValueSize;
}

int __inline wtwGetDataType(
					   WTWFUNCTIONS *pF, 
					   void *pSett,
					   const wchar_t * sName
					   )
{
	wtwSettingDef sDef;

	sDef.pSettings = pSett;
	sDef.paramName = sName;

	pF->fnCall(WTW_SETTINGS_GET_TYPE, sDef, NULL);

	return sDef.paramValueType;
}


/////////////////////////////////////////////////////////////////////////////////
//
// WTW_GET_PROFILE_NAME
// 
// wP - wtwBuffer*
// lP - NULL
// 
// zwraca d³ugosc nazwy profilu skopiowanej do bufora lub -1 jesli bufor byl za
// maly.
//

#define WTW_GET_PROFILE_NAME	L"WTW/Profile/GetName"

#endif