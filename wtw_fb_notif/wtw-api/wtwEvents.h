#ifndef __wtw__events_h__
#define __wtw__events_h__

#include "wtwPlugin.h"
#include "wtwContact.h"
#include "wtwProcAddr.h"

/*******************************************************************************
**
** Event: 
**		WTW_EVENT_FULLSCREEN_STATUS - when (other) application enters or leaves 
**			fullscreen mode;
**
** Should return: 
**		S_OK
**
** Parameters:
**		wP - WTW_EFSS_*
**		lP - NULL
**
*/

#define WTW_EVENT_FULLSCREEN_STATUS			L"WTW/OnFullscreenStatus"

#define WTW_EFSS_ENTER	0x001
#define WTW_EFSS_LEAVE	0x000

/*******************************************************************************
**
** Event: 
**		WTW_EVENT_ALL_PLUGINS_LOADED - at startup, when all plugins were loaded
**
** You should return: 
**		S_OK
**
** Parameters:
**		wP - NULL
**		lP - NULL
**
*/

#define WTW_EVENT_ALL_PLUGINS_LOADED		L"WTW/OnPluginsLoaded"

/*******************************************************************************
**
** Event: 
**		WTW_EVENT_PLUGIN_STATUS_CHANGE - when plugin is loaded and unloaded
**
** You should return: 
**		S_OK
**
** Parameters:
**		wP - const wchar_t * - plugin GUID
**		lP - const wtwPluginStatus*
**
*/

#define WTW_EVENT_PLUGIN_STATUS_CHANGE		L"WTW/OnPluginStatusChange"

struct wtwPluginStatus
{
	__wtwStdStructDefs(wtwPluginStatus);

	int				structSize;

	int				callReason;
	int				status;
};

#define WTW_PLUGIN_STATUS_LOADED	1
#define WTW_PLUGIN_STATUS_UNLOAD	2
#define WTW_PLUGIN_STATUS_UNLOADED	3

/*******************************************************************************
**
** Event: 
**		WTW_EVENT_SETTINGS_SAVED - when main settings were written to disk
**
** You should return: 
**		S_OK
**
** Parameters:
**		wP - NULL
**		lP - NULL
**
*/

#define WTW_EVENT_SETTINGS_SAVED		L"WTW/OnSettingsSaved"

/*******************************************************************************
**
** Event: 
**		WTW_EVENT_HINT_DATA_REQUEST - contact list hint is about to be shown,
**			good place to add your own information to it
**
** You should return: 
**		S_OK
**
** Parameters:
**		wP - wtwHintDataDef*
**		lP - NULL
**
*/

#define WTW_EVENT_HINT_DATA_REQUEST		L"WTW/OnHintDataRequest"

struct wtwHintDataDef 
{
	int				structSize;
	const wchar_t * locationID;

	wtwContactDef * pContactInfo;			// info o kontakcie, jesli jego to dotyczy;
	void		  * hData;			// jesli mamy cos do dodania to toprzekazujemy do funcji
									// addhintdata

	pwfAddHintData  addFunc;
};

/*******************************************************************************
**
** Function: 
**		WTW_HINT_LOCATION_MAIN_WND - get main window HWND
**
** Return vaule: 
**		0 on failure
**		Main window's HWND on success 
**
** Parameters:
**		wP - NULL
**		lP - NULL
**
*/

#define WTW_HINT_LOCATION_MAIN_WND		L"HL/MainWnd"

#endif