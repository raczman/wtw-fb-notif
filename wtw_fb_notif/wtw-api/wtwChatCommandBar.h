#pragma once

#include "wtwPlugin.h"

#define WTW_CCB_FUNCT_ADD		L"CCB/Add" // wP - wtwCommandEntry*
#define WTW_CCB_FUNCT_MOD		L"CCB/Mod" // wP - wtwCommandEntry*
#define WTW_CCB_FUNCT_DEL		L"CCB/Del" // wP - wtwCommandEntry*
#define WTW_CCB_FUNCT_CLEAR		L"CCB/Clear" // wP - hInstance

struct wtwCommandEntry 
{
	__wtwStdStructDefs(wtwCommandEntry);

	int				structSize;

	wtwContactDef * pContactData;// do identyfikacji okna uzywamy albo tego, albo tego ponzej
								// to ponizej jest szybsze, ale pWnd
								// jest "valid" tylko w eventach okien rozmowy,
								// z drugiej strony, contactInfo jest "invalid" w _CREATE

	void *			pWnd;		// 
	HANDLE			hInstance;	// do automatycznego usuniêcia przy wyladowaniu wtyczki

	const wchar_t*	itemID;

	WTWFUNCTION		callback;
	void *			cbData;
	
	const wchar_t*	caption;
	const wchar_t*  toolTip;
	const wchar_t*	graphID;

	DWORD			itemType;
	DWORD			itemFlags;
	void		*	itemData;
};

#define CCB_FLAG_CHANGECAPTION	0x00000001
#define CCB_FLAG_CHANGEICON		0x00000002
#define CCB_FLAG_CHANGETYPE		0x00000004
#define CCB_FLAG_CHANGETIP		0x00000008

#define CCB_TYPE_INACTIVE	0x01
#define CCB_TYPE_STANDARD	0x00
#define CCB_TYPE_SEPARATOR	0x02

struct wtwCommandCallback 
{
	__wtwStdStructDefs(wtwCommandCallback);

	int				structSize;

	const wchar_t * itemID;
	wtwContactDef * contactInfo;
	int				contactCount;
	int				selectedContact;
	POINT			pt; // gdzie pokazac menu na przyklad, screen coordinates

	int				action;
	void		*	doNotTouchPtr;
	void		*	itemData;

	HWND			hWnd;
	const void *	pWnd;
};

#define CCB_ACTION_LCLICK	0x01
#define CCB_ACTION_RCLICK	0x02