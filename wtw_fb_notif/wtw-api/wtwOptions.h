#ifndef __wtw_plugin_options_h__
#define __wtw_plugin_options_h__

#include "wtwPlugin.h"

#define WTW_OPTIONS_GROUP_MAIN		L"WTW/Group/Main"		// to do parentID
#define WTW_OPTIONS_GROUP_INTERFACE L"WTW/Group/Interface"	// to tez
#define WTW_OPTIONS_GROUP_NETWORK	L"WTW/Group/Network"	// to tak¿e
#define WTW_OPTIONS_GROUP_SMS		L"WTW/Group/SMS"		// to tak¿e
#define WTW_OPTIONS_GROUP_PLUGINS	L"WTW/Group/Plugz"		// i to te¿, ale jak sie poda NULL, to bedzie i tak to

#define WTW_OPTIONS_PAGE_ID_CTL		L"WTW/OPage/CTL"		// opcje listy kontaktów
#define WTW_OPTIONS_PAGE_ID_ADV		L"WTW/OPage/Advanced"	// advanced
#define WTW_OPTIONS_PAGE_ID_AVATAR	L"WTW/OPage/Avatar"		// opcje avatarów
#define WTW_OPTIONS_PAGE_ID_VCARD	L"WTW/OPage/VCard"		// wizytówka
#define WTW_OPTIONS_PAGE_ID_INTGR	L"WTW/OPage/Intgr"		// Integracja z powloka

struct wtwOptionPageDef
{
	__wtwStdStructDefs(wtwOptionPageDef);

	int			structSize;		// wiadome, ne?

	const wchar_t *id;				// unikalny ID
	const wchar_t *parentID;		// ID opzycji pod któr¹ bedzie umieszczona nasza pozycja

	const wchar_t *caption;		// tresc na liscie zakladek w opcjach

	int			flags;			// opcje

	HICON			icon;			// ikonka, and i mean it IKONKA (nie bitmapka) 16x16
	const wchar_t *iconID;			// albo WTW_GRAPH_ID

	WTWFUNCTION	callback;		// callback do funkcji ktora naszeopcje obsluguje
	void		*	cbData;

	void		*	ownerData;		// jakies nasze dane

};

#define WTW_OPTIONS_PAGE_FLAG_GROUPSEC 0x01000000

struct wtwOptionPageShowInfo
{
	__wtwStdStructDefs(wtwOptionPageShowInfo);

	int				structSize;	// j/w

	wtwOptionPageDef  *page;		// w zasadzie to co przekazalismy do add
	int				action;		// co chce komunikator abysmy zrobili

	HWND			handle;		// to podajemy jako parent naszego okna opcji
	void *			pHandle;	// do u¿ytku wewnêtrznego

	int				x;			// przy _SHOW, x
	int				y;			
	int				cx;			// szerokosc
	int				cy;			// wysokosc

	COLORREF		bgColor;	// kolor tla okna

	int				flags;		// opcje

	wchar_t			windowCaption[256]; // Nazwa zak³adki
	wchar_t			windowDescrip[512]; // Opis danej zak³adki

	HICON			icon;       // Ikonka pokazywana przed nazw¹ i opisem (32x32)
	const wchar_t *	iconID;		// albo WTW_GRAPH_ID_
};

#define WTW_OPTIONS_PAGE_ACTION_SHOW           1	// Pokazac okienko
#define WTW_OPTIONS_PAGE_ACTION_HIDE           2	// Schowac okienko

#define WTW_OPTIONS_PAGE_ACTION_OK             3	// Kliknieto OK
#define WTW_OPTIONS_PAGE_ACTION_CANCEL         5	// Kliknieto Anuluj
													// ********************************
													// UWAGA: Po OK i Cancel, jesli
													// stworzylismy okno ustawien
													// to powinnismy je zniszczyc (!)
													// ********************************

#define WTW_OPTIONS_PAGE_ACTION_APPLY          4	// Kliknieto Zastosuj
#define WTW_OPTIONS_PAGE_ACTION_MOVE			 6	// Przesun¹æ okno

/////////////////////////////////////////////////////////////////////////////////
//
// WTW_OPTION_PAGE_ADD
// 
// wParam - hInstance
// lParam - wtwOptionpadeDef*
// 

#define WTW_OPTION_PAGE_ADD			L"WTW/AddOptionsPage"

/////////////////////////////////////////////////////////////////////////////////
//
// WTW_OPTION_PAGE_REMOVE
// 
// wParam - hInstance
// lParam - const wchar_t* - pageId
// 

#define WTW_OPTION_PAGE_REMOVE		L"WTW/RemoveOptionsPage"

/////////////////////////////////////////////////////////////////////////////////
//
// WTW_OPTION_PAGE_REMOVE_ALL
// 
// wParam - hInstance
// lParam - NULL
// 

#define WTW_OPTION_PAGE_REMOVE_ALL	L"WTW/RemoveOptionsPages"

#endif