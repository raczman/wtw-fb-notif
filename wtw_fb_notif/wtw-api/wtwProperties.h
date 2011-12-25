#ifndef __wtw_prop_wnd_def__
#define __wtw_prop_wnd_def__

#include "wtwContact.h"

struct wtwPropertiesWindowInfo 
{
	__wtwStdStructDefs(wtwPropertiesWindowInfo);

	int				structSize;

	HANDLE			handle;

	const wchar_t	*	windowCaption;
	const wchar_t	*	windowIcon;

	int				windowType;

	const wchar_t *	defaultPageID;
	int				flags;

	wtwContactDef *	pContactData;
	const wchar_t *	pContactName;

	void			*	ownerData;
};

#define WTW_PW_TYPE_PROPERTIES     1
#define WTW_PW_TYPE_ADDCONTACT     2

#define WTW_PW_FLAG_OKBUTTON             0x0001
#define WTW_PW_FLAG_APPLYBUTTON          0x0002
#define WTW_PW_FLAG_CANCELBUTTON         0x0004
#define WTW_PW_FLAG_ADDBUTTON            0x0010
#define WTW_PW_FLAG_USE_STATIC           0x0020

struct wtwPropertiesPage 
{
	__wtwStdStructDefs(wtwPropertiesPage);

	int				structSize;

	const wchar_t *	pageID;
	const wchar_t *	parentID;

	const wchar_t *	caption;

	int				flags;

	int				position;
	HICON			icon;		// albo, albo
	const wchar_t *	iconID;		// albo

	WTWFUNCTION		callback;
	void			*	cbData;

	void			*	ownerData;

	const wchar_t	*	netClass;		// to uzywane tylko do static protocol page
	int				netId;		// j/w a i jesli uzywamy static_page_add, to wtedy
								// pageID powinien miec postac:
								// NETID/NETSID/Properties - po to aby te
								// karte domyslnie wybrac przy zaladowaniu okienka

};

#define WTW_PP_FLAG_AS_GROUP	0x0001
#define WTW_PP_FLAG_ALLOW_ADD	0x0002	// tylko przy static
#define WTW_PP_FLAG_ALLOW_EDT	0x0004	// jw

struct wtwPropertiesPageShowInfo
{
	__wtwStdStructDefs(wtwPropertiesPageShowInfo);

	int						structSize;

	wtwPropertiesPage *		page;
	wtwPropertiesWindowInfo *	info;

	int						action;

	HWND						handle;
	int						x;
	int						y;
	int						cx;
	int						cy;
	COLORREF					bgColor;

	int						flags;

	wchar_t					wndCaption[128];
	wchar_t					wndDescrip[512];

	HICON					icon;
	const wchar_t *			iconID;

	int						userFlag;

	void *					pHandle;

};

#define WTW_PP_CB_EVENT_SHOW           0x0001
#define WTW_PP_CB_EVENT_HIDE           0x0002
#define WTW_PP_CB_EVENT_DESTROY        0x0003
#define WTW_PP_CB_EVENT_OK             0x0004
#define WTW_PP_CB_EVENT_APPLY          0x0005
#define WTW_PP_CB_EVENT_CANCEL         0x0006
#define WTW_PP_CB_EVENT_ADD            0x0007
#define WTW_PP_CB_EVENT_SEARCH         0x0008
#define WTW_PP_CB_EVENT_MOVE           0x000A

#define WTW_ON_PROPERTY_PAGE_REQUEST	L"WTW/PropertiesAddPages"

#define WTW_PROPERTIES_WND_PAGE_ADD			L"WTW/PropertiesPageAdd"
//wP: wtwPropertiesPageDef *
//lP: void * pHandle - z Hooka

#define WTW_PROPERTIES_WND_ADD_STATIC_PROTO_PAGE	L"WTW/PropertiesStaticPageAdd"
// ta strona zostanie dodana automatycznie do okna edycji naszych kontaktow, 
// jesli oczywiscienei rejestrowalismy funcji PFInitEdit, bo wtedy to nasza dzia³ka ;p
// wP: wtwPropertiesPageDef *
// lP: NULL

#define WTW_PROPERTIES_WND_PERFORM_ACTION	L"WTW/PropertiesPerformAction"
//wP: WTW_PROPERTIES_ACTION_*

#define WTW_PROPERTIES_ACTION_SHOW           1
//lP: TlenPropertiesWindowInfoDef *

#endif
