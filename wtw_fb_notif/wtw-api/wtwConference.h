#ifndef __wtw__cwin_h__
#define __wtw__cwin_h__

#include "wtwPlugin.h"
#include "wtwProtocol.h"

struct wtwConferenceWindowCreate 
{
	__wtwStdStructDefs(wtwConferenceWindowCreate);

	int				structSize;
	const wchar_t * windowID;

	WTWFUNCTION		windowCallback;
	void *			userData;
	DWORD			flags;

	const wchar_t * chatTabName;
	const wchar_t * logTabName;

	HINSTANCE		hInst; // tego podawac niby nei trzebe, chyba, ze chcemy uzyc destroyall

	const wchar_t * roomMenuID;		// id menu la przycisku "menu"
	const wchar_t * contactMenuID;	// id menu dla kontaktu
};

#define CONFERENCE_FLAG_STATUS_TAB		0x00000001
#define CONFERENCE_FLAG_CONFERENCE_TAB	0x00000002

#define CONFERENCE_FLAG_STANDARD		(CONFERENCE_FLAG_STATUS_TAB | CONFERENCE_FLAG_CONFERENCE_TAB)

struct wtwConferenceWindowCallback // wparam w callbacku
{
	__wtwStdStructDefs(wtwConferenceWindowCallback);

	int				structSize;
	DWORD			event;
	const wchar_t *	windowID;
	WTW_PTR			windowPtr;
	POINT			pt; // do klikow myszonem, screen coords
};

#define CONFERENCE_EVENT_SEND_MESSAGE		1 // lparam - wtwMessageDef*
#define CONFERENCE_EVENT_WND_CLOSED			2 // lparam - NULL
#define CONFERENCE_EVENT_CT_LDBLCLK			3 // lparam - wtwConferenceContact* lub NULL
#define CONFERENCE_EVENT_CT_RCLICK			4 // lparam - wtwConferenceContact* lub NULL
#define CONFERENCE_EVENT_CT_LCLICK			5 // lparam - wtwConferenceContact* lub NULL
#define CONFERENCE_EVENT_TAB_CLOSED			6 // lparam - // nie zaimplementowane
#define CONFERENCE_EVENT_CMD_LCLICK			7 // lparam - wtwConferenceCommandInfo *
#define CONFERENCE_EVENT_CMD_RCLICK			8 // lparam - wtwConferenceCommandInfo *

#define WTW_CONFERENCE_WINDOW_CREATE		L"WTW/Conf/Create"		// zwraca handle nowego okna, wparam - wtwconfwindowcreate*
#define WTW_CONFERENCE_WINDOW_DESTROY		L"WTW/Conf/Destroy"		// wparam - to co zwrocilo create
#define WTW_CONFERENCE_WINDOW_DESTROY_ALL	L"WTW/Conf/DestroyAll"	// wparam - hInstance
#define WTW_CONFERENCE_WINDOW_SET_TITLE		L"WTW/Conf/SetTitle"	// wparam, to co zwrocilo create, lparam - tekst
#define WTW_CONFERENCE_WINDOW_SET_ICON		L"WTW/Conf/SetIcon"		// wparam, to co zwrocilo create, lparam - iconid
#define WTW_CONFERENCE_WINDOW_FIND			L"WTW/Conf/Find"		// wparam - const wchar_t * - id, zwraca to co create lub null
#define WTW_CONFERENCE_WINDOW_ADD_PRIV		L"WTW/Conf/AddPriv"		// wparam - to co podalo create, lparam - wtwConferencePriv, zwraca 0, 1 lub 2

/************************************************************
/*
/*	WTW_CONFERENCE_WINDOW_SHOWWINDOW
/*
/*	wparam - what "Create" returned
/*	lparam - CWSW_*
/*
/*	return value:
/*		E_*, S_OK
/*
/***********************************************************/

#define CWSW_HIDE				0x000000
#define CWSW_SHOW_NORMAL		0x000001
#define CWSW_SHOW_BACKGROUND	0x000002
#define CWSW_SHOW_MINIMZED		0x000003

#define WTW_CONFERENCE_WINDOW_SHOWWINDOW	L"WTW/Conf/ShowWindow"	// wparam - to co zwrocilo create, lparam - 1/0, pokazac/ukryc

#define WTW_CONFERENCE_WINDOW_HWNDFROMPTR	L"WTW/Conf/HWNDFromPtr"	// wparam - to co zwrocilo create, zwraca hwnd
#define WTW_CONFERENCE_WINDOW_ADD_CT		L"WTW/Conf/AddCT"		// wparam - to co podalo create, lparam - wtwConferenceContact* - dziala takze jako mod, jesli znajdzie juz kontakt o identycznym id

/************************************************************
/*
/*	WTW_CONFERENCE_WINDOW_DEL_CT
/*
/*	wparam - what "Create" returned
/*	lparam - contactID, wchar_t *
/*
/*	return value:
/*		E_*, S_OK (deleted), S_FALSE (not on list)
/*
/***********************************************************/

#define WTW_CONFERENCE_WINDOW_DEL_CT		L"WTW/Conf/DelCT"

struct wtwConferenceContact 
{
	__wtwStdStructDefs(wtwConferenceContact);

	int				structSize;
	const wchar_t * id;
	const wchar_t * name;
	const wchar_t * hIconID;
	const wchar_t * contactHint;

	int				sortClass;
	void	*		userData;

	DWORD			flags;
};

#define WTW_CONFERENCE_CONTACT_FLAG_UPDATE_NAME 0x0001
#define WTW_CONFERENCE_CONTACT_FLAG_UPDATE_DATA 0x0002
#define WTW_CONFERENCE_CONTACT_FLAG_UPDATE_ICON 0x0004
#define WTW_CONFERENCE_CONTACT_FLAG_UPDATE_SCLS 0x0008

struct wtwConferenceContacts 
{
	__wtwStdStructDefs(wtwConferenceContacts);

	int						structSize;
	
	wtwConferenceContact *	pContacts;		// tyle struktur aby pomeiscic wszystkie kontaty
											// jesli bedzie za malo to po prostu nie skopiuje wszystkich
											// aby dostac ilosc potrzebych structow wywolac
											// _GET_USERS z contactCount = -1, fukcja zrwoci potrzebny rozmiar

	int						contactCount; 
};

#define WTW_CONFERENCE_WINDOW_GET_USERS		L"WTW/Conf/GetUsers"	// wparam - to co podalo create, lparam - wtwConferenceContacts *

struct wtwConferenceMessageDef 
{
	__wtwStdStructDefs(wtwConferenceMessageDef);

	int				structSize;
	wtwMessageDef   message;

	DWORD			type;
	const wchar_t * nick;

	DWORD			flags;
};

#define WTW_CONFERENCE_WINDOW_ADD_MESSAGE	L"WTW/Conf/AddMessage"  // dodaje wiadomsoc do okna, wparam - to co podalo create, lparam wtwconferencemessage

#define CONFERENCE_MESSAGE_TYPE_STATUS		0
#define CONFERENCE_MESSAGE_TYPE_MESSAGE		1
#define CONFERENCE_MESSAGE_TYPE_PRIVATE		2

#define CONFERENCE_MESSAGE_FLAG_FLASH		0x0001 // flash window when message is added
#define CONFERENCE_MESSAGE_FLAG_NO_SHOW		0x0002 // do not show window on message add

/************************************************************
/*
/*	WTW_CONFERENCE_WINDOW_IS_CT_PRESENT
/*
/*	wparam - what "Create" returned
/*	lparam - wtwConferenceContact * (with filled id field)
/*
/*	return value:
/*		E_*, S_OK (on list), S_FALSE (not on list)
/*
/***********************************************************/

#define WTW_CONFERENCE_WINDOW_IS_CT_PRESENT	L"WTW/Conf/IsUserPresent"	

/************************************************************
/*
/*	WTW_CONFERENCE_WINDOW_GET_CONTACT
/*
/*	wparam - what "Create" returned
/*	lparam - wtwConferenceContact * (with filled id field)
/*
/*	return value:
/*		E_* or S_OK
/*
/***********************************************************/

#define WTW_CONFERENCE_WINDOW_GET_CONTACT	L"WTW/Conf/GetContact"

#define WTW_CONFERENCE_CMD_ADD		L"Conference/CmdAdd"
#define WTW_CONFERENCE_CMD_MOD		L"Conference/CmdMod"
#define WTW_CONFERENCE_CMD_DEL		L"Conference/CmdDel"

struct wtwConferenceCmdEntry 
{
	__wtwStdStructDefs(wtwConferenceCmdEntry);

	int				structSize;

	WTW_PTR			pWnd;		

	const wchar_t*	itemID;
	
	const wchar_t*	caption;
	const wchar_t*  toolTip;
	const wchar_t*	graphID;

	DWORD			itemType;
	DWORD			itemFlags;
	void		*	itemData;
};

struct wtwConferenceCmdInfo
{
	int				structSize;

	const wchar_t * itemID;
	void		*	itemData;
};

#endif