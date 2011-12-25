#ifndef __wtw__ctl_h__
#define __wtw__ctl_h__

#include "wtwPlugin.h"
#include "wtwContact.h"
#include "wtwGraph.h"
#include "wtwProtocol.h"

#define WTW_CTL_ADD_CONTACT L"WTW/CTL/AddContact"	// wP - wtwContactListItem*, lP - jesli wP zawiera wiecej niz 1 strukture - ich ilosc
#define WTW_CTL_FND_CONTACT L"WTW/CTL/FndContact"	// wP - wtwContactDef*, zwraca itemhandle lub NULL
#define WTW_CTL_DEL_CONTACT L"WTW/CTL/DelContact"	// wP - itemHandle
#define WTW_CTL_MOD_CONTACT L"WTW/CTL/ModContact"	// wP - itemhandle, lP - ContactListItem*
#define WTW_CTL_ENU_CONTACT L"WTW/CTL/EnContacts"	// wP - contactListEnum
#define WTW_CTL_GET_CONTACT L"WTW/CTL/GetContact"	// wP - itemhandle, lP - ContactListItem*

#define WTW_CTL_GET_PRESENCE L"WTW/CTL/GetPresence"	
									// wP - wtwPresenceDef*, jesli podajemy lP to nie musimy wypemiac contactData
									// lP - itemhandle,moze byc null, ale wtedy musimy wypelnic contactData z presenceDef
									// zwraca 1 jesliposzlo ok, lub 0

#define WTW_EVENT_ON_CONTACT_ADD L"WTW/OnContactAdd" // wP - wtwContactListItem*, lP - itemHandle
#define WTW_EVENT_ON_CONTACT_DEL L"WTW/OnContactDel" // wP - NULL, lP - itemHandle
#define WTW_EVENT_ON_CONTACT_MOD L"WTW/OnContactMod" // wP - NULL, lP - itemHandle (after modify)

#define WTW_CTL_ADD_CONTACT_ICON L"WTW/CTL/AddContactIcon" // wP - itemhandle, lP - wtwIconSetDef*
#define WTW_CTL_DEL_CONTACT_ICON L"WTW/CTL/DelContactIcon" // wP - itemhandle, lP - wtwIconSetDef*
#define WTW_CTL_MOD_CONTACT_ICON L"WTW/CTL/M0dContactIcon" // wP - itemhandle, lP - wtwIconSetDef*

#define WTW_CTL_ENABLE_DRAWING	L"WTW/CTL/EnableDrawing" // w param 1 - enable, 0 - disable

#define WTW_CTL_SET_CONTACT_STATE	L"WTW/CTL/SetContactState" // zamiast wolac caly czas Mod do ikonki 
															 // mozemy uzyc tego do uaktualnienia stanu
															 // ale wczesniej trzeba wywolac reg_mappng
															 // aby  WTW wiedzial ktory index ikonki 
															 // jest ktory, wparam - presencedef* z ct info,
															 // lparam mzoe byc null, to wtw sam poszuka kontaktu,
															 // w innym wypadku podajemy tam handle do kontaktu

#define WTW_CTL_SET_OVERLAY_STATE_MAP L"WTW/CTL/SetOverlayState" // wP - OVL_, lP = contactHandle

#define WTW_CTL_REGISTER_MAPPING	L"WTW/CTL/RegisterMapping"	// do tlumaczenia indexów ikonek na
																// stany i odwrotnie
																// mapka jest automagicznie
																// rejestrowana dla protkolu
																// jesli ladowalismy caly set,
																// ale jak chcemy mozmy zrobic wlasna

#define WTW_CTL_SET_ALL_OFFLINE		L"WTW/CTL/SetAllOffline"	// przydatne przy roz³¹czeniu ;)
																// wparam = netClass, lparam netId;
#define WTW_CTL_DELETE_ALL			L"WTW/CTL/DeleteAll"		// przydatne przy wylaczeniu pluga
																// wparam = netClass, lparam netId;

struct wtwContactListItem 
{
	__wtwStdStructDefs(wtwContactListItem);

	int				structSize;

	wtwContactDef	contactData;

	const wchar_t *	itemText;
	const wchar_t *	itemGroup;

	DWORD			itemType;
	DWORD			itemState;
	void		  * itemHandle;			// przy dodawaniu dostajemy to spowrotem;

	int				flags;

	void *			ownerData;			// nieuzywane

	WTWFUNCTION		drawCallback;		// nieuzywane
	void *			cbData;				// nieuzywane

	wtwIconSet	  * iconToAdd;
};

#define CTL_ITEM_EVENT_GET_HEIGHT	0x0001	// masz tylko obliczyc cy (y, x, cx sa podane)
#define CTL_ITEM_EVENT_DRAW_ITEM	0x0002	// narysowac, mieszczac sie w x,y,cx,cy
#define CTL_ITEM_EVENT_LCLICK		0x0003	// 
#define CTL_ITEM_EVENT_RCLICK		0x0004	// 
#define CTL_ITEM_EVENT_DBLCLICK		0x0005	// 
#define CTL_ITEM_EVENT_DELETED		0x0006	// 

#define CTL_ITEM_FLAG_SELECTED		0x0001	// pozycja jest zaznaczona

struct wtwContactListItemEvent
{
	__wtwStdStructDefs(wtwContactListItemEvent);

	int				structSize;
	int				event;
	HDC				hDC;		// zwrocic w stanie oryginalnym!
	DWORD			flags;
	int				y;
	int				x;
	int				cx;
	int				cy;			// przy get height obliczyc to, 
								// przy draw dostajemy to co obliczylismy

	wtwContactDef*	pContact;
	void *			ownerData;

	WTWFUNCTION		fnDrawStandardElement;
	void *			cbDataDrawStandardElement; // przekazac jako trzeci parametr do fnDrawStandardElement
	void *			pRenderer;	// nic co byloby Wam potrzebne ;P
};

struct wtwContactListStdDraw
{
	__wtwStdStructDefs(wtwContactListStdDraw);

	int				structSize;

	wtwContactListItemEvent *pEvent;

	int				whatToDraw;
};

struct wtwContactListStdElementText
{
	__wtwStdStructDefs(wtwContactListStdElementText);

	int				structSize;

	const wchar_t * text;

	DWORD			x;
	DWORD			y;

	DWORD			cx;
	DWORD			cy;

	DWORD			flags;
};

#define	CSE_TEXT_FLAG_CALC_ONLY 0x0001
#define	CSE_TEXT_FLAG_MULTILINE 0x0002
#define	CSE_TEXT_FLAG_VCENTER	0x0004

#define CTL_STD_ELEMENT_BACKGROUND	0x00000001	// wP - wtwContactListStdDraw*
#define CTL_STD_ELEMENT_MAIN_TEXT	0x00000002	// wP - wtwContactListStdDraw*, lP - wtwContactListStdElementText*
#define CTL_STD_ELEMENT_DESC_TEXT	0x00000003	// wP - wtwContactListStdDraw*, lP - wtwContactListStdElementText*

#define WTW_CTL_SET_CUSTOM_SORT_FUNCTION L"WTW/SetCustomCTLSort"// wParam - adres funcji typu 
																// _wtwFnCustomSortOperator, albo NULL jesli 
																// chcemy funkcjê usun¹æ (przy wy³adowaniu wtyczki)

struct wtwContactListSortParam 
{
	__wtwStdStructDefs(wtwContactListSortParam);

	int					structSize;
	wtwContactListItem	item;
	wtwPresenceDef		presence;
	int					sortPos;
};

typedef int (__stdcall *_wtwFnCustomSortOperator)(
	const wtwContactListSortParam *i1,
	const wtwContactListSortParam *i2);	// efektywnie jest to operator "<", czyli jesi i1 jest mniejsze
									// od i2 to zwracamy "true", w innym wypadku "false"

#define WTW_CTL_FLAG_REPLACE_DUPLICATE	0x00000001 // przy tej fladze zastapi na liscie dane kontaktu o identycznym id, nid i nsid (poza stanem i opisem)
#define WTW_CTL_FLAG_DO_NOT_EXPAND		0x00000002
#define WTW_CTL_FLAG_UPDATE_STATE		0x00000004
#define WTW_CTL_FLAG_CLEAR_EXISTING		0x00000008

#define	WTW_CTL_TYPE_GROUP		0x00000001	// grupa
#define	WTW_CTL_TYPE_METAC		0x00000002	// metakontant
#define	WTW_CTL_TYPE_ELEMENT	0x00000003	// kontakt
#define	WTW_CTL_TYPE_USER		0x00000004	// niezaimplementowane
#define	WTW_CTL_TYPE_SEPARATOR	0x00000005	// j/w

#define	WTW_CTL_STATE_PINNED	0x00000100
#define	WTW_CTL_STATE_ONLINE	0x00000200
#define	WTW_CTL_STATE_OFFLINE	0x00000300
#define	WTW_CTL_STATE_OFFLIST	0x00000400
#define	WTW_CTL_STATE_WAITAUTH	0x00000500
#define	WTW_CTL_STATE_NOAUTH	0x00000600
#define	WTW_CTL_STATE_UNKNOWN	0x00000700

///////////////////////////////////////////////////////////////////////////////

struct wtwAvatarSet 
{
	__wtwStdStructDefs(wtwAvatarSet);

	int				structSize;
	
	const wchar_t * filePath;		// sciezka do pliku, pelna
	int				avatarType;		// typ grafiki
	
	void		  * contactHandle;	// handle kontaktu, jesli null to ustawiamy net id, SID i ctID w contact info, 
	wtwContactDef * pContactData;	// jesli cti null, to handle musi byc podany

	DWORD			flags;			// opcje
	DWORD			magic;			// coœ magicznego, jesli 0 to cokolwiek bedziemoglo 
									// ustawic awatar, jesli rozne od zera, totylko jesli 
									// ta wartosc sie zgdza to awatar bedzie mogl byc
									// ustawiony;
	DWORD			source;			// skad sie wzial;
};

#define WTW_AVATAR_TYPE_PNG	0x0001
#define WTW_AVATAR_TYPE_JPG	0x0002
#define WTW_AVATAR_TYPE_GIF	0x0003
#define WTW_AVATAR_TYPE_BMP	0x0004
#define WTW_AVATAR_TYPE_ICO	0x0005

#define	WTW_AVATAR_SET			L"WTW/CTL/SetAvatar"
#define	WTW_AVATAR_GET			L"WTW/CTL/GetAvatar"
#define	WTW_AVATAR_GET_SOURCE	L"WTW/CTL/GetAvatarSource" // wParam - wtwContactDef*

#define	WTW_ON_AVATAR_SET		L"WTW/Event/SetAvatar" // wP - wtwAvatarSet*

#define AV_SOURCE_DEFAULT	0	// lub "none"
#define AV_SOURCE_EXTERNAL	1
#define AV_SOURCE_LOCAL		2

#define WTW_CTL_ENUM_GROUPS_HWND L"WTW/CTL/EnumGroupsHWND" // wParam - HWND ComboBox'a

struct wtwContactListEnumerate 
{
	__wtwStdStructDefs(wtwContactListEnumerate);

	int				structSize;

	WTWFUNCTION		enumFunct;		// dostanie contactListItem jako *wP
	void *			cbData;

	DWORD			flags;			// WTW_CTL_ENUMERATE_*
};

#define WTW_CTL_ENUMERATE_ALL			0x0000
#define WTW_CTL_ENUMERATE_ONLINE_ONLY	0x0001

#endif