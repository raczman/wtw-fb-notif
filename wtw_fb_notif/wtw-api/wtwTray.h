#ifndef __wtw__tray_h__
#define __wtw__tray_h__

#include "wtwPlugin.h"

/////////////////////////////////////////////////////////
//
// Ikonki w trayu
//
//

#define WTW_TRAYICON_FUNC_ADDICON L"WTW/Tray/Add"
#define WTW_TRAYICON_FUNC_CHANGE  L"WTW/Tray/Change"
#define WTW_TRAYICON_FUNC_REMOVE  L"WTW/Tray/Delete"

#define WTW_TRAYICON_FLAG_MASK_ICONHINT		0x10000000
#define WTW_TRAYICON_FLAG_MASK_MENU 		0x20000000
#define WTW_TRAYICON_FLAG_MASK_ICON 		0x40000000
#define WTW_TRAYICON_FLAG_MASK_CALLBACK 	0x01000000
#define WTW_TRAYICON_FLAG_MASK_FLAGS	 	0x02000000
#define WTW_TRAYICON_FLAG_MASK_GUID		 	0x08000000
#define WTW_TRAYICON_FLAG_MASK_NOTIFY	 	0x80000000

#define WTW_TRAYICON_FLAG_MASK_ALL		 	0xFF000000

#define WTW_TRAYICON_FLAG_MASK_TOOLTIP	 	0x04000000 // wyklucza uzycie ICONHINT, sami musimy obslugiwac tipa, do tego mamy MOUSEHOVER/LEAVE
#define WTW_TRAYICON_FLAG_ANIMATE_BLINK	 	0x00000100


#define WTW_TRAYICON_FLAG_AUTO_ICON		 	0x00000010
#define WTW_TRAYICON_FLAG_AUTO_MENUMANAGE 	0x00000020
#define WTW_TRAYICON_FLAG_AUTO_WINDOW	 	0x00000040
#define WTW_TRAYICON_FLAG_AUTO_ALL		 	0x000000F0

struct wtwTrayIconDef
{
	__wtwStdStructDefs(wtwTrayIconDef);

	int				structSize;
	int				flags;

	const wchar_t * trayId;		// jakis wlasny ID, jest konieczne

	const wchar_t * iconHint;
	const wchar_t * notifyText;
	const wchar_t * notifyTitle;
	const wchar_t * menuID;		// id menu
	const wchar_t * iconID;		// id ikonki do pokazania

	WTWFUNCTION		callback;

	const wchar_t * netClass;		// tylko do auto_menu i auto_icon
	int				netId;

	void		  * ownerData;

	GUID		    iconGUID;

};

struct wtwTrayIconCallbackDef
{
	__wtwStdStructDefs(wtwTrayIconCallbackDef);

	int				structSize;

	int				iconMessage; //WM_MOUSEHOVER, WM_MOUSELEAVE, WM_LBUTTON*, WM_RBUTTON*
	const wchar_t *	trayId;
	POINT			mousePos;

	const wchar_t *	netClass;
	int				netId;

	void		  * ownerData;

	RECT			iconRect;
	GUID			iconGUID;
};


#endif