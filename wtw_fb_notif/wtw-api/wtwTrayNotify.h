#ifndef __wtw__trayn_h__
#define __wtw__trayn_h__

#include "wtwPlugin.h"

/////////////////////////////////////////////////////////
//
// Tray Notify
//

#define WTW_EVENT_BEFORE_NOTIFY_SHOW	L"WTW/OnBeforeNotifyShow"	// wP - wywTrayNotifyDef *, lP - wtwContactDef* lub NULL

#define BNS_OK		0
#define BNS_CANCEL	1

#define WTW_SHOW_STANDARD_NOTIFY	L"WTW/ShowStandardNotify"	// wP - wywTrayNotifyDef *, a jeœli trzeba (do avatara?) to lP - wtwContactDef*
#define WTW_HIDE_STANDARD_NOTIFY	L"WTW/HideStandardNotify"	// wP - wywTrayNotifyDef *
#define WTW_GET_SILENT_MODE			L"WTW/GetSilentMode"		// zwraca 1 lub 0
#define WTW_SET_SILENT_MODE			L"WTW/SetSilentMode"		// wP = 0 - wylacz, 1 - wlacz, -1 - przelacz
#define WTW_REG_CLASS_COLOR			L"WTN/RegClassColor"		// wP - wtwTrayNotifyClassColor*

#define WTN_CLASS_PRESENCE 		0x01
#define WTN_CLASS_MESSAGE_TEXT 	0x02
#define WTN_CLASS_MESSAGES 		0x03
#define WTN_CLASS_WARNING 		0x04
#define WTN_CLASS_USERTUNE 		0x10
#define WTN_CLASS_USERMOOD 		0x11
#define WTN_CLASS_MAILINFO 		0x12

#define WTN_CLASSREG_FLAG_OVERWRITE_STYLE	0x0001
#define WTN_CLASSREG_FLAG_REMOVE			0x0002

#define WTW_TN_GRAPH_TYPE_INTERNAL	1
#define WTW_TN_GRAPH_TYPE_SKINID	3
#define WTW_TN_GRAPH_TYPE_NONE		0

#define WTW_TN_EVENT_LCLICKED		0x0001
#define WTW_TN_EVENT_RCLICKED		0x0002
#define WTW_TN_EVENT_MCLICKED		0x0003
#define WTW_TN_EVENT_DESTROYED		0x0004
#define WTW_TN_EVENT_UPDATED		0x0005

#define WTW_TN_FLAG_OVERRIDE_SHOW		0x00000001 // jesli nie pokazywac przy fullscrenie to zignorowac opcje i pokazac
#define WTW_TN_FLAG_OVERRIDE_TIME		0x00000002
#define WTW_TN_FLAG_HDR_MULTILINE		0x00000004
#define WTW_TN_FLAG_TXT_MULTILINE		0x00000008
#define WTW_TN_FLAG_DO_NOT_SLIDE		0x00000010

struct wtwTrayNotifyEvent 
{			// wparam w callbacku

	__wtwStdStructDefs(wtwTrayNotifyEvent);

	int				structSize;

	int				event;
	void *			ownerData;
};

struct wtwTrayNotifyClassColor 
{
	__wtwStdStructDefs(wtwTrayNotifyClassColor);

	int				structSize;

	DWORD			crStart;
	DWORD			crEnd;
	
	int				classType;

	DWORD			flags;
};

struct wtwTrayNotifyDef 
{
	__wtwStdStructDefs(wtwTrayNotifyDef);

	int				structSize;

	const wchar_t *	textLower;
	const wchar_t *	textMain;
	const wchar_t *	notifierId;
	
	void		*	iconID;
	int				graphType;
	DWORD			showTime;
	DWORD			classType;
	void		*	ownerData;

	int				flags;

	WTWFUNCTION		callback;		// lparam - wtwContactDef * albo NULL
	void		*	cbData;
	
};

#endif