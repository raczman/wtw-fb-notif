#ifndef __wtw__graph_h__
#define __wtw__graph_h__

#include "wtwPlugin.h"

#define	WTW_GRAPH_LOAD		L"WTW/Graph/Load"		// wP = wtwGraphics *


#define WTW_GRAPH_FLAG_RELATIVE_DEF_PATH 0x0008	// w filePath nie podalismy pelnej sciezki
												// a tylko nazwe pliku, WTW bedzie chcial
												// najpeirw zaladowac ten plik z "componnets\Theme"
												// a potem z "userTheme"

#define WTW_GRAPH_GET_IMAGE	L"WTW/Graph/GetImage"	// wP = wtwGraphics * z podanym graph ID

#define WTW_GRAPH_FLAG_GENERATE_HICON	0x0001	// jesli nie wiesz jak sie dobrac do gPointer 
												// to wtw wygeneruje Ci hIcon ;)
												// flaga do GET

#define WTW_GRAPH_FLAG_GENERATE_HBITMAP	0x0004	// jesli nie wiesz jak sie dobrac do gPointer 
												// to wtw wygeneruje Ci HBITMAP
												// flaga do GET

#define WTW_GRAPH_FLAG_GENERATE_GENERIC		0x0010	// nuffn interesting
#define WTW_GRAPH_FLAG_GENERATE_GENERIC32	0x0020	// nuffn interesting

#define WTW_ICSET_LOAD_FLAG_DEFLOC		0x0002	// zamiast sciezki podajesz nazwe protokolu, 
												// tj ID "XMPP" na przyklad, i z aktualnego 
												// themka wtw zaladuje set ikonek dla sieci
												// tylko loadIconSet

#define WTW_ICSET_LOAD_FLAG_DEFLOC_EXT	0x0020	// zamiast sciezki podajesz nazwe protokolu, 
												// tj ID "XMPP" na przyklad, i z aktualnego 
												// themka wtw zaladuje set ikonek dla sieci
												// tylko loadIconSet

#define WTW_ICSET_CREATE	L"WTW/Graph/ICCreate"
#define WTW_ICSET_ADD_IMG	L"WTW/Graph/AddIC"

//////////////////////////////////////////////////////////////////////////////////
//
// ICSET_LOAD_PNG
// Funkcja wygenetuje takie oto  ID dla ikonek:
// <netClass>/Icon/<statusID>
//
// gdzie <statusID> to odpowiednio do stanow:
// available, unavailable, invisible, blocked, unknown, chat, away, xa, dnd
// costam jeszcze dopisalem wpliku repo.xml w folderze "theme"
//
///

#define WTW_ICSET_LOAD_PNG		L"WTW/Graph/LoadIS"	 // only PNG (z obsluga alphy)

//////////////////////////////////////////////////////////////////////////////////

struct wtwGraphics 
{
	__wtwStdStructDefs(wtwGraphics);

	int				structSize;

	const wchar_t * graphID;					// to wype³niamy przy load graph
	
	DWORD			cx;							// to wypalnia nam wtw
	DWORD			cy;							// to tez

	void		  * gPointer;					// i to, ale tego nei wiecie jak uzywac
	const wchar_t *	defaultPluginDir;

	const wchar_t * filePath;					// to tez wypelniamy przy load
												// ALBO
	const wchar_t * resourceId;					// zaladowac z zasobow (tylko typ "PNG")
	HINSTANCE		hInst;						// z tej instancji

	int				flags;						// opcje

	int				imageType;					// 0 - png, 1 - jpg
};

struct wtwLoadIconSet 
{
	__wtwStdStructDefs(wtwLoadIconSet);

	int				structSize;					// wiadomo

	const wchar_t * setPath;					// sciezka do folderu w ktorym jest folder setu (wtw\theme)
	int				flags;						// opcje
	
	int			  * pStates;					// stany ktore zaladowac
	int				iStates;					// ile tych stanów

	int			  * pOverlay;					// nakladki na ikonki ktore chcemy
	int				iOverlay;					// ile tych nakladek

	int				iType;						// flagi,ponizej
	const wchar_t * setID;						// ID ikonek
	const wchar_t * netClass;					// id sieci
	const wchar_t * setDirExt;
};

#define WTW_ICONSET_FLAG_MODIFY_CUR_IMAGE	0x00000001
#define WTW_ICONSET_FLAG_MODIFY_CALLBACK	0x00000002
#define WTW_ICONSET_FLAG_MODIFY_CUR_OVERLAY	0x00000004
#define WTW_ICONSET_FLAG_MODIFY_HINT		0x00000008
#define WTW_ICONSET_FLAG_MODIFY_BY_MAP		0x00000010

struct wtwIconSet 
{
	__wtwStdStructDefs(wtwIconSet);

	int				structSize;

	const wchar_t * iconSetID;					// id Ikonki

	wtwGraphics	  * pIcons;						// here goes the iconzzzz
	int				iIcons;						// wiela ikonek

	wtwGraphics	  * pOverlay;					// here goes the ovarlayyyz
	int				iOverlay;					// ile tych nakladek

	int				curImage;					// obecnie wybrana ikonka
	int				curOverlay;					// obecnie wybrana nakladka

	int				iType;						// typ ikonki, jesli ikonka jest preloaded, znaczy definiowana w komunikatorze
												// to jesli to ustawimy przy CTL_ICON_ADD, to zmieny jej typ domyslny
	int				flags;

	WTWFUNCTION		callback;					// Hist data request, click;
	const wchar_t * iconHint;					// reall _ICON_ADD to change it;
};

#define WTW_ICON_EVENT_HINT_REQUEST		0x0001	// dataptr, to samo zrobic co przy REQ_HINT_DATA dla kontaktu
#define WTW_ICON_EVENT_DBLCLK			0x0002	// doubleclick na ikonce;

struct wtwIconEventDef
{
	__wtwStdStructDefs(wtwIconEventDef);

	int structSize;

	DWORD			event;
	const wchar_t * iconSetID;
	wtwContactDef * contactData;

	void			*dataPtr;
};

#define WTW_ICS_FLAG_PRELOADED		0x0001		// przy dodawaniu do kontaktu, jesli podamy tylko to
												// wypelniamy tylko iconSetID;

#define WTW_ICSET_TYPE_PRE_TEXT		0x0001		// przzed nazwa
#define WTW_ICSET_TYPE_POST_TEXT	0x0002		// po nazie, do prawej wyrownane, maja priorytet nad "after"
#define WTW_ICSET_TYPE_AFTER_TEXT	0x0003		// zaraz po nazwie

#define WTW_GRAPH_ID_GROUP_OPENED	L"IC/Group/Opened"
#define WTW_GRAPH_ID_GROUP_CLOSED	L"IC/Group/Closed"
#define WTW_GRAPH_ID_META_OPENED	L"IC/Meta/Opened"
#define WTW_GRAPH_ID_META_CLOSED	L"IC/Meta/Closed"

#define WTW_GRAPH_ID_OLF_ACTIVE		L"IC/OLF/Active"
#define WTW_GRAPH_ID_OLF_INACTIVE	L"IC/OLF/Inactive"

#define WTW_GRAPH_ID_CONF_USER		L"IC/Conf/User"				// 0
#define WTW_GRAPH_ID_CONF_OWNER		L"IC/Conf/Owner"			// 1
#define WTW_GRAPH_ID_CONF_OP		L"IC/Conf/Operator"			// 2
#define WTW_GRAPH_ID_CONF_SU		L"IC/Conf/SuperUser"		// 3
#define WTW_GRAPH_ID_CONF_OTHER		L"IC/Conf/Other"			// 4

#define WTW_GRAPH_ID_ENCRYPTION		L"IC/Encryption"

#define WTW_GRAPH_ID_TN_ON	L"IC/Tn/On"
#define WTW_GRAPH_ID_TN_OFF	L"IC/Tn/Off"

#define WTW_GRAPH_ID_PHONE	L"IC/Phone"
#define WTW_GRAPH_ID_MOBILE	L"IC/Mobile"
#define WTW_GRAPH_ID_OPEN	L"IC/Open"

#define WTW_ICON_ID_GROUP	L"IC/Group"
#define WTW_ICON_ID_META	L"IC/Meta"
#define WTW_ICON_ID_OLF		L"IC/OLF"
#define WTW_ICON_ID_BLOCKED	L"IC/Blocked"
#define WTW_ICON_ID_CALL	L"IC/Call"

#define WTW_ICON_PHONE		L"IC/Phone"
#define WTW_ICON_MOBILE		L"IC/Mobile"
#define WTW_ICON_OPEN		L"IC/Open"
#define WTW_ICON_CONF_USR	L"IC/ConfUserStatus"

#define WTW_GRAPH_ID_CTL_BACKGROUND L"Image/Background"
#define WTW_GRAPH_ID_MAIN_ICON_48	L"Image/IconMain48"
#define WTW_GRAPH_ID_MAIN_ICON_32	L"Image/IconMain32"
#define WTW_GRAPH_ID_MAIN_ICON_16	L"Image/IconMain16"

#define WTW_GRAPH_ID_TAB_NORMAL	L"Image/TabNormal"
#define WTW_GRAPH_ID_TAB_EVENT	L"Image/TabEvent"

#define WTW_GRAPH_ID_IP			L"Image/IP"
#define WTW_GRAPH_ID_NOL		L"Image/NOL" // not on list
#define WTW_GRAPH_ID_MAIL		L"Image/Mail"
#define WTW_GRAPH_ID_USER		L"Image/User"
#define WTW_GRAPH_ID_BLOCKED	L"Image/Blocked"
#define WTW_GRAPH_ID_AUDIO		L"Image/Audio"
#define WTW_GRAPH_ID_MOOD		L"Image/Mood"
#define WTW_GRAPH_ID_SETTINGS	L"Image/Settings"
#define WTW_GRAPH_ID_EXIT		L"Image/Exit"
#define WTW_GRAPH_ID_CONSOLE	L"Image/Console"
#define WTW_GRAPH_ID_WEB		L"Image/Web"
#define WTW_GRAPH_ID_ARCHIVE	L"Image/Archive"
#define WTW_GRAPH_ID_COPY		L"Image/Copy"
#define WTW_GRAPH_ID_WARNING32	L"Image/Warning32"
#define WTW_GRAPH_ID_ERROR32	L"Image/Error32"
#define WTW_GRAPH_ID_PLUGIN		L"Image/Plugin"
#define WTW_GRAPH_ID_PLUGIN32	L"Image/Plugin32"
#define WTW_GRAPH_ID_NETWORK	L"Image/Network"
#define WTW_GRAPH_ID_DONATE		L"Image/Donate"
#define WTW_GRAPH_ID_CLEAR		L"Image/Clear"
#define WTW_GRAPH_ID_TAB_CLOSE	L"Image/TabClose"
#define WTW_GRAPH_ID_DEF_AVA	L"Image/DefaultAvatar"
#define WTW_GRAPH_ID_CONNECTING	L"Image/Connecting"
#define WTW_GRAPH_ID_UPDATE		L"Image/Update"
#define WTW_GRAPH_ID_ADVANCED	L"Image/Advanced"
#define WTW_GRAPH_ID_INTERNET	L"Image/Internet"
#define WTW_GRAPH_ID_CHECKS		L"Image/Checks"
#define WTW_GRAPH_ID_CALL_VIDEO	L"Image/CallVideo"
#define WTW_GRAPH_ID_CALL_AUDIO	L"Image/CallAudio"
#define WTW_GRAPH_ID_CALL_END	L"Image/CallEnd"
#define WTW_GRAPH_ID_NUMPAD		L"Image/Numpad"

#define WTW_ICON_IP		L"IC/IP"
#define WTW_ICON_NOL	L"IC/NOL"

#define WTW_GRAPH_ID_CHAT			L"Image/Chat"
#define WTW_GRAPH_ID_CONFERENCE		L"Image/Conference"
#define WTW_GRAPH_ID_MESSAGE		L"Image/Message"
#define WTW_GRAPH_ID_NEWS			L"Image/News"
#define WTW_GRAPH_ID_RSS			L"Image/Rss"
#define WTW_GRAPH_ID_SEND_FILE		L"Image/SendFile"
#define WTW_GRAPH_ID_SEND_PICTURE	L"Image/SendPicture"

#endif