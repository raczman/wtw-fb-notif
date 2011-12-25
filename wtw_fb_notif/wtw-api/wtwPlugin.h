#ifndef _wtwPlugin_h_
#define _wtwPlugin_h_

#ifndef _WINDOWS_
#error Include "windows.h" before including this header (plInterface.h/wtwPlugin.h)
#endif

#define _MIN_SAFE_TIME_T	30 * 365 * 24 * 3600 // ~y2000

#include "wtwCaps.h"

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#if (_MFC_VER == 0x900 || _MSC_VER == 1500) && defined(_DLL) && !defined(_BIND_TO_CURRENT_VCLIBS_VERSION)
#error "_BIND_TO_CURRENT_VCLIBS_VERSION" is not defined, please add this macro to project settings
#endif

#if !defined(_DLL) && defined(_MSC_VER) && _MSC_VER == 1500
#pragma message ("You are using MSVC 9.0, please consider linking against 'Multithreaded DLL' runtime ( SP1 !!! )")
#endif

#define WTW_CALL_REASON_AUTO		1	// automatic load at program start
#define WTW_CALL_REASON_MANUAL		2	// manual start by user command
#define WTW_CALL_REASON_AUTOADD		3	// automatic, but newly added, so called "first start"
#define WTW_CALL_REASON_EXIT		4	// program will be terminated in a moment
#define WTW_CALL_REASON_UNINSTALL   5	// plugin uninstall
#define WTW_CALL_REASON_ERROR		-1	// plugin is being unloaded cuz it caused an error

#ifdef _M_X64
#define WTW_PTR __int64
#define WTW_PARAM unsigned __int64
#elif _M_IX86
#define WTW_PTR int
#define WTW_PARAM unsigned long
#else
#error No Valid Architecture?
#endif

#ifdef _MFC_VER
#define QWORD unsigned __int64
#else
#define QWORD unsigned long long
#endif

#define WTW_HWND_PRETRANS_REG				L"WTW/PreTransReg"
#define WTW_HWND_PRETRANS_UNREG				L"WTW/PreTransUnreg"

#define WTW_SET_FUNCT_THREADSAFE			L"WTW/SetFunctThreadSafe"	// wP - functHandle, lP - 1/0*

#define WTW_SET_HOOK_PRIORITY				L"WTW/SetEventPriority"		// wP - hookHandle (what evHook returned), lP - priority (-65k -> 65k, int)
#define WTW_SET_HOOK_EVENT_NONBLOCKABILITY	L"WTW/SetEventBlockable"	// wP - hookHandle (what evCreate returned), lP - WTW_EV_*

#define WTW_EVENT_NON_BLOCKABLE		1
#define WTW_EVENT_BLOCKABLE			0

#define MAKE_DWORD(a,b,c,d) ((DWORD)a&0xFF)<<24|((DWORD)b&0xFF)<<16|((DWORD)c&0xFF)<<8|((DWORD)d&0xFF)
#define MAKE_QWORD(a,b,c,d) ((QWORD)a&0xFFFF)<<48|((QWORD)b&0xFFFF)<<32|((QWORD)c&0xFFFF)<<16|((QWORD)d&0xFFFF)

#define PLUGIN_API_VERSION MAKE_QWORD(2,0,0,1200)

#define V_GET_MAJOR(a)		(DWORD)(((QWORD)a&0xFFFF000000000000) >> 48) 
#define V_GET_MINOR(a)		(DWORD)(((QWORD)a&0x0000FFFF00000000) >> 32)
#define V_GET_REVISION(a)	(DWORD)(((QWORD)a&0x00000000FFFF0000) >> 16)
#define V_GET_BUILD(a)		(DWORD)(((QWORD)a&0x000000000000FFFF))

#define initStruct(st) {memset(&st,0,sizeof(st));st.structSize=sizeof(st);};

#ifdef __cplusplus
#define __wtwStdStructDefs(s) \
	s() {_initStruct();}; \
	int checkSize() {if(sizeof(s) != structSize)return 0; else return 1;}; \
	operator WTW_PARAM () { return (WTW_PARAM)this; }; \
	void _initStruct() {memset(this, 0, sizeof(s)); structSize = sizeof(s);};
#else
#define __wtwStdStructDefs(st)
#endif

typedef WTW_PTR (*WTWHOOK)		(WTW_PARAM, WTW_PARAM, void*);
typedef WTW_PTR (*WTWFUNCTION)	(WTW_PARAM, WTW_PARAM, void*);

#define WTW_PLUGIN_OPTION_NO_MANUAL_UNLOAD		0x00000001
#define WTW_PLUGIN_OPTION_NO_MANUAL_LOAD		0x00000002
#define WTW_PLUGIN_OPTION_WARN_ON_LOCAL_COPY	0x00000004
#define WTW_PLUGIN_OPTION_NO_LOCAL_COPY			0x00000008

struct WTWPLUGINFO
{
	int				structSize;				// sizeof this struct

	const wchar_t * pluginName;				// plugin name

	const wchar_t * pluginDescription;		// plugin description
	const wchar_t * pluginCopyright;		// copyrights

	const wchar_t * pluginAuthor;			// author name
	const wchar_t * pluginAuthorEmail;		// author contact mail
	const wchar_t * pluginAuthorHomepage;	// website

	const wchar_t * pluginUpdateURL;		// URI for update XML (with http://)

    QWORD			pluginAPIVersion;		// api version
	QWORD			pluginVersion;			// plugin version

	DWORD			pluginClass;			// plugin class, needed only for correct group mapping in options panel

	void *			reservedPtr;

	const wchar_t * pluginGUID;				// GUID of this plugin

	const wchar_t **pluginDependencies;		// dependencies (GUIDs), terminated with NULL entry

	DWORD			pluginOptions;
	DWORD			Reserved3;
	DWORD			Reserved2;
	DWORD			Reserved1;
	
};

struct WTWFUNCTIONS
{
	HANDLE          (*fnCreate)		(const wchar_t *,	WTWFUNCTION, void*	);
	WTW_PTR         (*fnDestroy)	(HANDLE									);
	WTW_PTR         (*fnCall)		(const wchar_t *,	WTW_PARAM, WTW_PARAM);
	WTW_PTR         (*fnExists)		(const wchar_t *						);
	WTWFUNCTION     (*fnGet)		(const wchar_t *,	void **				);

	HANDLE			(*evCreate)		(const wchar_t *						);
	WTW_PTR			(*evDestroy)	(HANDLE									);
	WTW_PTR			(*evNotify)		(HANDLE,			WTW_PARAM, WTW_PARAM);
	HANDLE			(*evHook)		(const wchar_t *,	WTWHOOK, void*		);
	WTW_PTR			(*evUnhook)		(HANDLE									);

	WTW_PTR         (*fnDestroyAll)	(HANDLE	/* plugin hInstance */			);

};

/*

	Maj¹ byæ __stdcall (!) ;P

	//////////////////////////////////////////////////////////////////////////
	//
	// WTWPLUGINFO * queryPlugInfo(DWORD wtwVersionHi, DWORD wtwVersionLo);
	//
	// Wywo³ywane aby pobraæ informacje o wtyczce, 
	// 
	//  wtwVersionLo/Hi -	wersja programu
	//

	///////////////////////////////////////////////////////////////////////////	
	//
	// int pluginLoad(DWORD callReason, WTWFUNCTIONS *fC);
	//
	// Wywo³ane przy ³¹dowaniu wtyczki, 
	//
	//  callReason -	przyzyna wywo³ania funkcji tj czy ladowanie 
	//					automatyczne, czy zuytkownik recznie odpala wtyczke, etc
	//
	//	fC -			wksŸnik do funkcji interface'u programu
	//  

	///////////////////////////////////////////////////////////////////////////
	//
	// int pluginUnload(DWORD callReason)
	//
	// Wywo³ywane przy wy³¹dowaniu wtyczki
	//
	//  callReason -	podobnie jak w pluginLoad
	//

*/

#define WTW_PLUGIN_API_ENTRY(returnType) extern "C" __declspec(dllexport) returnType __stdcall

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#endif
