#ifndef __wtw__protocol_h__
#define __wtw__protocol_h__

#include "wtwPlugin.h"
#include "wtwCaps.h"
#include "wtwContact.h"

struct wtwMessageExtInfo 
{
	__wtwStdStructDefs(wtwMessageExtInfo);

	int				structSize;

	const wchar_t * name;
	const wchar_t * value;
};

struct wtwMessageDef 
{
	__wtwStdStructDefs(wtwMessageDef);

	int				structSize;

	wtwContactDef	contactData;

	const wchar_t * msgSubject;
	const wchar_t * msgMessage;

	DWORD			msgFlags;
	QWORD			msgTime;

	const wtwMessageExtInfo *extInfo;
	int				extInfoCount;

	wtwResourceInfo * exResource;

	void *			ownerData;

};

struct wtwAvatarDef
{
	__wtwStdStructDefs(wtwAvatarDef);

	int				structSize;

	wtwContactDef	contactData;

	const wchar_t * avPath;
	DWORD			avType;
};

struct wtwAvatarEvent 
{
	__wtwStdStructDefs(wtwAvatarEvent);

	int				structSize;

	const wchar_t * avFile;		// zlokalizowany w folderze profilu, typowo _avatar

	const wchar_t *	sha1;
	const wchar_t *	md5;

	DWORD			event;
};

#define WTW_AVATAR_EVENT_DELETE		0x0001
#define WTW_AVATAR_EVENT_SETUP		0x0002

#define WTW_EVENT_AVATAR_CHANGED	L"WTW/OnAvatarChanged"

#define WTW_MESSAGE_FLAG_INCOMING		0x00000001
#define WTW_MESSAGE_FLAG_OUTGOING		0x00000002
#define WTW_MESSAGE_FLAG_CHAT_MSG		0x00000004
#define WTW_MESSAGE_FLAG_SPECIAL		0x00000008
#define WTW_MESSAGE_FLAG_CONFERENCE		0x00000010
#define WTW_MESSAGE_FLAG_PICTURE		0x00000040
#define WTW_MESSAGE_FLAG_NOHTMLESC		0x00000080
#define WTW_MESSAGE_FLAG_NOARCHIVE		0x00001000	// do not store in archive
#define WTW_MESSAGE_FLAG_MONOSPACE		0x00002000
#define WTW_MESSAGE_FLAG_FORCEDISP		0x00004000
#define WTW_MESSAGE_FLAG_NOAUTOLINK		0x00008000
#define WTW_MESSAGE_FLAG_NOTHEME		0x00010000
#define WTW_MESSAGE_FLAG_NOWRITETRIG	0x00020000	// nie zapisuj do arch, dodaj tylko do kolejki do zapisania
#define WTW_MESSAGE_FLAG_NOAUTORECV		0x00040000	// do not route message to chatwindow after hook calls

#define WTW_MESSAGE_FLAG_UTF8_MARK		0x10000000	// do not use, internal
#define WTW_MESSAGE_FLAG_DEFLATED		0x20000000	// do not use, internal

#define WTW_MESSAGE_FLAG_WARNING		0x00000100
#define WTW_MESSAGE_FLAG_ERROR			0x00000200
#define WTW_MESSAGE_FLAG_INFO			0x00000400

#define WTW_MESSAGE_FLAG_MASK_STATE		0x00000F00 

#define WTW_TRIGGER_ARCHIVE_WRITE	L"WTW/TriggerArchiveWrite"

struct wtwPresenceDef 
{
	__wtwStdStructDefs(wtwPresenceDef);

	int				structSize;

	wtwContactDef *	pContactData;

	int				curStatus;		// obecny stan
	const wchar_t * curDescription;	// NULL - brak opisu
	QWORD			curTimeStamp;	// obecny czas

	const void	  * exInfo;			// cos doczepione przez plugin protoko³u, prawidlowe tylko dla pierwszego przejscia
									// przez hook;

	wtwResourceInfo * exResource;

	DWORD			flags;
};

#define WTW_PRESENCE_FLAG_MENU			0x00000001L	// wywolane menu
#define WTW_PRESENCE_FLAG_PREDEF		0x00000002L	// predefiniowany opis
#define WTW_PRESENCE_FLAG_USER			0x00000004L	// opis uzytkownika
#define WTW_PRESENCE_FLAG_PLUGIN		0x00000008L	// wywolanie z pluga
#define WTW_PRESENCE_FLAG_EXIT			0x00000010L	// komunikator jest zamykany
#define WTW_PRESENCE_FLAG_AUTO			0x00000020L	// przy starcie automatyczne polaczenie
#define WTW_PRESENCE_FLAG_NO_NOTIFY		0x00000040L	// nie generowac automatycznego powiadomienia przy tray'u
#define WTW_PRESENCE_FLAG_NO_ARSM		0x00000080L	// wy³¹czyæ automatyczny wybór stanu po zasobach (No Automated Resource Status Management)
#define WTW_PRESENCE_FLAG_AA_ENTER		0x10000000L	// wejscie w tryb AA
#define WTW_PRESENCE_FLAG_AA_EXIT		0x20000000L	// wyjscie z AA
#define WTW_PRESENCE_FLAG_LOCK_ENTER	0x40000000L	// komputer zablokowany
#define WTW_PRESENCE_FLAG_LOCK_EXIT		0x80000000L	// komputer odblokowany
#define WTW_PRESENCE_FLAG_SUSPEND		0x01000000L	// komputer wchodzi w tryb uspienia, automagiczne rozlaczenie
#define WTW_PRESENCE_FLAG_RESET			0x02000000L	// reset po³¹czenia z jakiegos powodu
#define WTW_PRESENCE_FLAG_RESUME		0x04000000L	// resume after suspend
#define WTW_PRESENCE_FLAG_EX_ICONID		0x00000100L	

#define WTW_PRESENCE_UNDEF		0x8000L
#define WTW_PRESENCE_ONLINE		0x0001L
#define WTW_PRESENCE_CHAT		0x0002L
#define WTW_PRESENCE_DND		0x0003L
#define WTW_PRESENCE_AWAY		0x0004L
#define WTW_PRESENCE_XA			0x0005L
#define WTW_PRESENCE_INV		0x0006L
#define WTW_PRESENCE_OFFLINE	0x0007L
#define WTW_PRESENCE_ERROR		0x0008L
#define WTW_PRESENCE_BLOCK		0x0009L
#define WTW_PRESENCE_NO_CHANGE	0xFFFFFFFFL

#define WTW_PRESENCE_OVL_NONE	0x0000L	// brak nakladki
#define WTW_PRESENCE_OVL_DESC	0x0001L	// ustawiony opis XMPPdesc.png
#define WTW_PRESENCE_OVL_NOL	0x0002L	// nie ma ns na liscie XMPPnol.png

struct wtwRawDataDef 
{
	__wtwStdStructDefs(wtwRawDataDef);

	int				structSize;
	const char *	pData;
	int				pDataLen;
	DWORD			flags;
};

#define WTW_RAW_FLAG_TEXT	0x0001 // C-String, tj null terminated najlepiej jesli pData jest o 1 wieksze niz pDataLen (Wlasnie na null)
#define WTW_RAW_FLAG_BIN	0x0002 // dane binarne
#define WTW_RAW_FLAG_UTF	0x0004 // tekst zakodowany w UTF
#define WTW_RAW_FLAG_UNI	0x0008 // tekst, ale jako const wchar_t*
#define WTW_RAW_FLAG_OOB	0x0010 // OOB, Out Of band Data
#define WTW_RAW_FLAG_EXT	0x0020 // zewnetrzene dane, wstrzykniete - przez wtyczke na przyklad
#define WTW_RAW_FLAG_PRIV	0x0040 
#define WTW_RAW_FLAG_USER	0x0080 // data sent from xml console

struct wtwProtocolInterface 
{
	__wtwStdStructDefs(wtwProtocolInterface);

	int			structSize;
	WTWFUNCTION pfAuthContact;	// wP - wtwContactDef, lP - WTW_AUTH_OPT...
	WTWFUNCTION pfDeleteContact;// wP - wtwContactDef
	WTWFUNCTION pfMoveContact;	// wP - wtwContactDef, lP - wtwMoveContactDef*
	void *		cbData;
};

struct wtwMoveContactDef
{
	__wtwStdStructDefs(wtwMoveContactDef);

	int				structSize;
	const wchar_t * currectGroupName;
	const wchar_t * newGroupName;
};

#define WTW_AUTH_OPTION_ADD_TO_LIST 0x00000001
#define WTW_AUTH_OPTION_AUTH_GRANT	0x00000002
#define WTW_AUTH_OPTION_NO_AUTH		0x00000004
#define WTW_AUTH_OPTION_CANCEL		0x00000008 // do nothing

#define WTW_PF_UPDATE_PROTO_INFO	L"WTW/PFSetInfo" // wP - protocolLoginInfo*

struct protocolLoginInfo 
{
	__wtwStdStructDefs(protocolLoginInfo);

	int				structSize;
	const wchar_t * loginID;
	const wchar_t * loginName;

	const wchar_t * netClass;
	int				netId;
};

WTW_PTR inline wtwSetProtoInfo(WTWFUNCTIONS *pF, 
							   const wchar_t * netClass, int netId, 
							   const wchar_t * lID, const wchar_t * lName)
{
	protocolLoginInfo pt;
	initStruct(pt);

	pt.loginID		= lID;
	pt.loginName	= lName;
	pt.netClass		= netClass;
	pt.netId		= netId;

	return pF->fnCall(WTW_PF_UPDATE_PROTO_INFO, (WTW_PARAM)&pt, 0);
}

struct wtwProtocolDef 
{
	__wtwStdStructDefs(wtwProtocolDef);

	int				structSize;

	const wchar_t * netClass;		// ID protoko³u, GG, TLEN, XMPP ...
	const wchar_t * protoName;		// nazwa
	const wchar_t * protoDescr;		// opis

	int				netId;		// second ID, to jest parametr _zwracany_ dzieki 
									// temu mozna miec wiele wtyczek o tym samym ID protokolu;
									// kontakty, etc, etc ... sa identyfikowane w/g sID i ID;

	const wchar_t * netGUID;		// cos co generujemy i zapisujemy do konfiguracji,
									// tak aby nawet jesli SID sie zmieni mozna bylo
									// rozpoznac ten protokol po czyms;
									// powinno byc globalnie unikalne, z tym laczone sa informacje
									// dodatkowe, jak telefon, notka, adres, metakontakty, etc.

	DWORD			protoCaps1;		// to co potrafimy robic;
	DWORD			protoCaps2;		// to co potrafimy robic;
	DWORD			flags;

	wtwProtocolInterface pInterface;

	DWORD		  * protoState;		// wskaznik do DWORDa ktory trzyma informacje
									// o aktualnym stanie protoko³u;

	const wchar_t * protoIconId;	// NULL jesli chcemy "<netClass>/Icon"

};

#define WTW_PROTO_STATE_CONNECTED	0x00000001
#define WTW_PROTO_STATE_ENCRYPTED	0x00000002
#define WTW_PROTO_STATE_CONNECTING	0x00000004
#define WTW_PROTO_STATE_AUTH_OK		0x00000008
#define WTW_PROTO_STATE_COMPRESSED	0x00000010
#define WTW_PROTO_STATE_ROSTER_OK	0x00000020

int __inline isConConnected(const DWORD & s)
{
	return s & WTW_PROTO_STATE_CONNECTED;
}

int __inline isConRosterValid(const DWORD & s)
{
	return s & WTW_PROTO_STATE_ROSTER_OK;
}

int __inline isConConnecting(const DWORD & s)
{
	return s & WTW_PROTO_STATE_CONNECTING;
}

int __inline isConAuthed(const DWORD & s)
{
	return s & WTW_PROTO_STATE_AUTH_OK;
}

int __inline isConEncrypted(const DWORD & s)
{
	return s & WTW_PROTO_STATE_ENCRYPTED;
}

int __inline isConCompressed(const DWORD & s)
{
	return s & WTW_PROTO_STATE_COMPRESSED;
}

void __inline protoModifyFlag(DWORD & status, DWORD stateAdd, DWORD stateRemove)
{
	status |= stateAdd;
	status &= ~stateRemove;
}

#define WTW_PROTO_FLAG_NO_MENU		0x0001	// nie dodawac menu stanów
#define WTW_PROTO_FLAG_PSEUDO		0x0002	// pseudo protokol, wtw bedzie olewal jego stany, etc ...
#define WTW_PROTO_FLAG_NO_PUBDIR	0x0004	// nie dodawac zakladku "katalog" do wlasciwosci kontaktu
#define WTW_PROTO_FLAG_FILE_AUTOS	0x0008	// zezwalamy na automatyzaje odbierania plikow
#define WTW_PROTO_FLAG_NO_RAW_DATA	0x0010	// zezwalamy na automatyzaje odbierania plikow

#define WTW_PROTO_FUNC_ADD		L"WTW/ProtocolAdd" // wParam = wtwProtocolDef*
#define WTW_PROTO_FUNC_DEL		L"WTW/ProtocolDel" // wP - netClass, lP - SID

#define WTW_PROTO_EVENT_ON_ADD	L"WTW/OnProtocolAdd" // wParam = wtwProtocolDef*
#define WTW_PROTO_EVENT_ON_DEL	L"WTW/OnProtocolDel" // wP - netClass, lP - SID

#define WTW_ON_PROTOCOL_EVENT	L"WTW/OnProtocolEvent" // to jest event kochani, hook it

struct wtwProtocolInfo 
{
	__wtwStdStructDefs(wtwProtocolInfo);

	int				structSize;

	const wchar_t *	netClass;
	int				netId;
	const wchar_t *	guid;
	const wchar_t *	name;
	const wchar_t *	info;
	const wchar_t *	protoIconId;

	DWORD			flags;
};

///////////////////////////////////////////////////////////////////
//
//		WTW_PROTO_FUNC_ENUM
//
//		wP - wtwProtocolInfo* or NULL
//		lP - sizeofarray(wP) lub -1 jesli chcemy znac potrzebny rozmiar;
//
//		return value:
//			on error:
//				E_OUTOFMEMORY, E_INVALIDARG 
//			on success:
//				> 0 (number of returned)

#define WTW_PROTO_FUNC_ENUM		L"WTW/ProtocolEnum" 

///////////////////////////////////////////////////////////////////
//
//		WTW_PROTO_FUNC_GET
//
//		wP - (const wchar_t*) - GUID 
//		lP - (wtwProtocolInfo*) 
//		
//		return value:
//			on error:
//				E_* 
//			on success:
//				S_OK

#define WTW_PROTO_FUNC_GET		L"WTW/ProtocolGet"		// wP - wchar_t* - GUID, lP - wtwProtocolInfo*; zwraca E_*/S_OK

///////////////////////////////////////////////////////////////////
//
//		WTW_PROTO_FUNC_GET_GUID
//
//		wP - (const wchar_t*) - netClass
//		lP - (int) - netId
//		
//		return value:
//			on error:
//				NULL
//			on success:
//				const wchar_t* - protocol GUID

#define WTW_PROTO_FUNC_GET_GUID	L"WTW/ProtocolGetGUID"	// wP - wchar_t* - netClass, lP - netId; zwraca const wchar_t * lub NULL

struct wtwProtocolEvent 
{
	__wtwStdStructDefs(wtwProtocolEvent);

	int				structSize;

	const wchar_t * netClass;		// protocol ID
	int				netId;			// protocol Second ID

	int				event;			// rodzaj zdarzenia
	int				type;			// typ

	wtwContactDef * pContactData;			// jesli s¹ dostepne sparsowane informacje o kontakcie inaczej NULL
	const wchar_t * metaGUID;		// jest kontakt jest w metakontakcie to tu jest id meta, jesli nie - null;
};


/*******************************************************************************
**
** Event types
**		Types come in packages, if one have _BEFORE type it has also _AFTER;
** 
** Remarks:
**	Events marked as _BEFORE can be blocked, if first plugin in chain will block 
**	the event, rest of the plugins will not receive it and _AFTER will not be fired;
**  This type of event should be used if plugin wants to change something/reject it;
**	Type _AFTER cannot be blocked and is "for information only", it's MUST NOT be blocked;
**  _UNDEFINED behaves retty much like _AFTER; 
**
*/

#define	WTW_PEV_TYPE_BEFORE		0x0001 // przed przetworzeniem, mozna zablokowac zwracajac 1
#define	WTW_PEV_TYPE_AFTER		0x0002 // po przetworzeniu
#define	WTW_PEV_TYPE_UNDEFINED	0x0000 // zjawisko nie majace typu

/*******************************************************************************
**
** Hook event: 
**		WTW_PEV_RAW_DATA_RECV - data received from the network
**		WTW_PEV_RAW_DATA_SEND - data about to send into the network
**
** Should return: 
**		S_OK if it's type is _AFTER or _UNDEFINED, or S_OK/S_FALSE if it's
**		type is "_BEFORE";
**
** Parameters:
**		wP - wtwProtocolEvent* (as in case of all protocol events)
**		lP - wtwRawDataDef*
**
*/

#define WTW_PEV_RAW_DATA_RECV	0x0001
#define WTW_PEV_RAW_DATA_SEND	0x0002

/*******************************************************************************
**
** Hook event: 
**		WTW_PEV_PRESENCE_RECV - contact presence info received
**		WTW_PEV_PRESENCE_SEND - our presence info before send
**
** Should return: 
**		S_OK if it's type is _AFTER or _UNDEFINED, or S_OK/S_FALSE if it's
**		type is "_BEFORE";
**
** Parameters:
**		wP - wtwProtocolEvent* (as in case of all protocol events)
**		lP - wtwPresenceDef*
**
*/

#define WTW_PEV_PRESENCE_RECV	0x0003 
#define WTW_PEV_PRESENCE_SEND	0x0004 

/*******************************************************************************
**
** Hook event: 
**		WTW_PEV_MESSAGE_RECV - message received
**		WTW_PEV_MESSAGE_SEND - message is about to be sent
**
** Should return: 
**		S_OK if it's type is _AFTER or _UNDEFINED, or S_OK/S_FALSE if it's
**		type is "_BEFORE";
**
** Parameters:
**		wP - wtwProtocolEvent* (as in case of all protocol events)
**		lP - wtwMessageDef*
**
*/

#define WTW_PEV_MESSAGE_RECV	0x0005
#define WTW_PEV_MESSAGE_SEND	0x0006

/*******************************************************************************
**
** Hook event: 
**		WTW_PEV_NETWORK_LOGIN  - network logged in
**		WTW_PEV_NETWORK_LOGOUT - guess
**
** Should return: 
**		S_OK (type is always _UNDEFINED);
**
** Parameters:
**		wP - wtwProtocolEvent* (as in case of all protocol events)
**		lP - wtwPresenceDef* or NULL
**
*/

#define WTW_PEV_NETWORK_LOGIN	0x0008
#define WTW_PEV_NETWORK_LOGOUT	0x0009

/*******************************************************************************
**
** Hook event: 
**		WTW_PEV_AUTH_REQUEST  - an contact requests presence auth
**
** Should return: 
**		S_OK if it's type is _AFTER, or S_OK/S_FALSE if it's
**		type is "_BEFORE";
**
** Parameters:
**		wP - wtwProtocolEvent* (as in case of all protocol events)
**		lP - wtwMessageDef* or NULL
**
*/

#define WTW_PEV_AUTH_REQUEST	0x000A

/*******************************************************************************
**
** Hook event: 
**		WTW_PEV_ROSTER_DLOADED  - contact list has been downloaded
**
** Should return: 
**		S_OK (type is always _UNDEFINED);
**
** Parameters:
**		wP - wtwProtocolEvent* (as in case of all protocol events)
**		lP - NULL
**
*/

#define WTW_PEV_ROSTER_DLOADED	0x000B

#define WTW_PEV_XML_PROCESSED	0x0100	// it's blockable, it's internal, don't use ;)

/*******************************************************************************
**
** Hook event: 
**		WTW_PEV_ALERT_RECV
**		WTW_PEV_ALERT_SEND
**
** Should return: 
**		S_OK if it's type is _AFTER, or S_OK/S_FALSE if it's
**		type is "_BEFORE";
**
** Parameters:
**		wP - wtwProtocolEvent* (as in case of all protocol events)
**		lP - NULL
**
*/

#define WTW_PEV_ALERT_RECV			0x000D
#define WTW_PEV_ALERT_SEND			0x000F

/*******************************************************************************
**
** Hook event: 
**		WTW_PEV_TYPING_NOTIFY_RECV - guess
**		WTW_PEV_TYPING_NOTIFY_SEND - 
**
** Should return: 
**		S_OK if it's type is _AFTER, or S_OK/S_FALSE if it's
**		type is "_BEFORE";
**
** Parameters:
**		wP - wtwProtocolEvent* (as in case of all protocol events)
**		lP - NULL
**
*/

#define WTW_PEV_TYPING_NOTIFY_SEND	0x0010
#define WTW_PEV_TYPING_NOTIFY_RECV	0x000E

/*******************************************************************************
**
** Hook event: 
**		WTW_PEV_AVATAR_RECV - avatar received
**		WTW_PEV_AVATAR_SEND - (our) avatar is about to be sent
**
** Should return: 
**		S_OK if it's type is _AFTER, or S_OK/S_FALSE if it's
**		type is "_BEFORE";
**
** Parameters:
**		wP - wtwProtocolEvent* (as in case of all protocol events)
**		lP - wtwAvatarEvent*
**
*/

#define WTW_PEV_AVATAR_RECV			0x0011
#define WTW_PEV_AVATAR_SEND			0x0012

/*******************************************************************************
**
** Hook event: 
**		WTW_PEV_NEW_MAIL_NOTIFY - new mail notify
**
** Should return: 
**		S_OK if it's type is _AFTER or _UNDEFINED, or S_OK/S_FALSE if it's
**		type is "_BEFORE";
**
** Parameters:
**		wP - wtwProtocolEvent* (as in case of all protocol events)
**		lP - NULL
**
*/

#define WTW_PEV_NEW_MAIL_NOTIFY		0x0013

#define WTW_PEV_FILE_TRANSFER_REQ	0x0014 // lP - wtwProtocolFile*

struct wtwProtocolFile
{
	__wtwStdStructDefs(wtwProtocolFile);

	int				structSize;

	const wchar_t * fileName;	// moze byc NULL
	QWORD			fileSize;
};

/*******************************************************************************
**
** Hook event: 
**		WTW_PEV_CALL_RING	- incoming/outgoing call
**
** Should return: 
**		S_OK if it's type is _AFTER, or S_OK (user decides)/ S_FALSE (reject) if it's
**		type is "_BEFORE";
**
** Parameters:
**		wP - wtwProtocolEvent* (as in case of all protocol events)
**		lP - wtwProtocolCall*
**
** Remarks, flow:
**		_RING, _ACCEPT and maybe _END
**		if accepted: _START, _END
**		_END / _START can be called multiple times. For example when video stream can be started independly of audio stream;
**
*/

#define WTW_PEV_CALL_RING		0x0015

struct wtwProtocolCall
{
	__wtwStdStructDefs(wtwProtocolCall);

	int				structSize;

	DWORD			flags;
	
	DWORD			iContacts;
	wtwContactDef * pContacts;

	const wchar_t * callUniqueId;	// may be NULL

};

#define WTW_PROTOCOL_CALL_FLAG_AUDIO		0x0001
#define WTW_PROTOCOL_CALL_FLAG_VIDEO		0x0002
#define WTW_PROTOCOL_CALL_FLAG_INCOMING		0x0004	// call, not stream
#define WTW_PROTOCOL_CALL_FLAG_OUTGOING		0x0008	// call, not stream
#define WTW_PROTOCOL_CALL_FLAG_AUTOACCEPT	0x0100	// set it if you want to accept the call on behalf the user
#define WTW_PROTOCOL_CALL_FLAG_ACCEPTED		0x0200
#define WTW_PROTOCOL_CALL_FLAG_REJECTED		0x0400
#define WTW_PROTOCOL_CALL_FLAG_BLOCKED		0x0800
#define WTW_PROTOCOL_CALL_FLAG_ERROR		0x1000

/*******************************************************************************
**
** Hook event: 
**		WTW_PEV_CALL_START		- call has been accepted
**		WTW_PEV_CALL_END		- call ended
**		WTW_PEV_CALL_ACCEPT		- call was accepted/rejected
**
** Should return: 
**		S_OK, type is always "undefined"
**
** Parameters:
**		wP - wtwProtocolEvent* (as in case of all protocol events)
**		lP - wtwProtocolCall*
**
*/

#define WTW_PEV_CALL_ACCEPT		0x0016
#define WTW_PEV_CALL_START		0x0017
#define WTW_PEV_CALL_END		0x0018


HANDLE __inline wtwInstProtoFunc(
						WTWFUNCTIONS *pF,		// interface funkcji
						const wchar_t * netClass,	// ID protokolu
						int				netId,	// SID protokolu
						const wchar_t * funcName,// nazwa funkcji
						WTWFUNCTION		funcAddr, // no wiadomo, ne ?
						void *			funcOwnerData
						)
{

	wchar_t fName[255] = {0};
	wsprintf(fName, L"%s/%d/%s", netClass, netId, funcName);
	return pF->fnCreate(fName, funcAddr, funcOwnerData);

}

//////////////////////////////////////////////////////////////////////
//
// Nazwy chyba mowia same za siebie, jesli czegos nie mozemy zrobic
// bo na przyklad nie ma polaczenia to zwracamy 1, w innym wypadku
// powinno to byc 0 (jak nie to wtw poszuka innej wtyczki mogacej
// zrealizowac zadanie
//
// Te funkcje sa wywolywane przez komunikator, w wiekszosci;
//
// Postac tych funkcji to:
// ID/sID/Funkcja, instalujemy je uzywajac wtwInstProtoFunc
// ale nic nie stoi na przeszkodzie aby sobie robic to po swojemu,
// byle format byl prawidlowy
//
///

#define WTW_PF_STATUS_SET		L"PFStatusSet"
#define WTW_PF_STATUS_GET		L"PFStatusGet"
#define WTW_PF_MESSAGE_SEND		L"PFMessageSend"
#define WTW_PF_ALERT_SEND		L"PFAlertSend"
#define WTW_PF_INIT_CALL_AUDIO	L"PFCallInitAudio"
#define WTW_PF_INIT_CALL_VIDEO	L"PFCallInitVideo"
#define WTW_PF_END_CALL			L"PFCallEnd"

#define WTW_PF_RAW_DATA_SEND	L"PFRawSend"
#define WTW_PF_RAW_DATA_FEED	L"PFRawFeed"

#define WTW_PF_TN_SEND			L"PFTNSend" // lP - WTW_TYPING_STATUS_*

#define WTW_TYPING_STATUS_STOP		0x00
#define WTW_TYPING_STATUS_START		0x01
#define WTW_TYPING_STATUS_PAUSE		0x02

#define WTW_PF_ASK_FOR_AUTH		L"WTW/PFAskForAuth" // wP - wtwContactDef*

#define WTW_PF_INIT_SEND_FILE	L"PFInitSendFile"

struct wtwPicture 
{
	__wtwStdStructDefs(wtwPicture);

	int				structSize;

	wtwContactDef	contactData;
	
	const wchar_t * fullFilePath;
};

#define SIS_OK					1
#define SIS_ERR					0
#define SIS_FILE_TOO_BIG		2

#define WTW_PF_SEND_PICT		L"PFSendPicture"		// wP - wtwPicture*

// ret - 0 - blad jakis, 1 - ok, 2 - za duzy obraz

#define WTW_PF_SEND_IMGH		L"PFSendPictureByURL"

#define WTW_PF_DELETE_CONTACT	L"PFDeleteContact"	// wP - wtwContactDef*
#define WTW_PF_MOVE_CONTACT		L"PFMoveContact"	// wP - wtwContactDef, lP - wtwMoveContactDef*


#include "wtwVCard.h"

//////////////////////////////////////////////////////////////////////
//
// Jesli funkcja z tej grupy nie zostanie zarejestrowana, 
// i jesli plug zdacydowal, ze przykladowo pokazac odpowiednia
// pozycje w menu, to ww wywola domyslna implementacje
//
// wParam - wtwContactInfo *
// lParam - NULL
//
///

#define WTW_PF_INIT_CHAT		L"PFInitChat"
#define WTW_PF_INIT_MESSAGE		L"PFInitSendMessage"
#define WTW_PF_INIT_EDIT		L"PFInitEdit"
#define WTW_PF_INIT_PUBDIR		L"PFInitPubDir"
#define WTW_PF_INIT_ADD			L"PFInitAdd"
#define WTW_PF_INIT_SEND_PICT	L"PFInitSendPicture"


//////////////////////////////////////////////////////////////////////
//
// dlaczego funkcja a nie hookiem?
// bo hook i tak zostanei wywolany automatycznie, ale ta funkcja jest
// do czegos jeszcze, "karmi" ona komunikator danymi, jesli wiadomosc 
// nie zostanie odrzucona w TYPE_BEFORE to w TYPE_AFTER zostanie
// przetrawiona przez wtw (czyli wyswietlona, etc ...)
//
// wParam - wtwProtoEventDef *
// lParam - w zaleznosci co to za event ...
//
///

#define WTW_PF_CALL_HOOKS		L"WTW/CallProtolHooks" //

//////////////////////////////////////////////////////////////////////
//
// W ramach informacji, jesli chcemy ustawic globalnie cos dla
// wszystkich protokolow to mozemy zrobic tu
//
///

#define WTW_PF_WTW_STATUS_GET	L"WTW/PFStatusGet"		// wP - wtwPresenceDef*
#define WTW_PF_WTW_STATUS_SET	L"WTW/PFStatusSet"		// wP - wtwPresenceDef*
#define WTW_PF_WTW_SETUP_TN		L"WTW/PFTNSet"			// wP - wtwContactDef, lP: 0 cancel, 1 set
														// autocancel po 20 sec

#define WTW_PF_WTW_SEND_MESSAGE L"WTW/PFSendMessage"	// tutaj w contactDef musimy podac UUID kontaktu!
														// UUID! WTW sam zdecyduje ktorym protokolem to poslac
														// jesli chcemy konkretny protokol to uzywamy 
														// ID/sID/PFMessageSend i tam podajemy contactID!


#define WTW_PF_GET_PROTOCOL_COUNT	L"WTW/PFGetCount"

// wewnêtrzna funkcja ;p

#define WTW_PF_GET_PROTOCOL_IPTR	L"WTW/PFGetIPtr"
#define WTW_PF_GET_PROTOCOL_GPTR	L"WTW/PFGetGPtr"

// cos do grzebania w opisach

#define WTW_ON_BEFORE_STATUS_SET	L"WTW/BeforeDescSet" // event (!)

typedef void (*_tReplaceDesc)(const wchar_t *pNewDesc, void *pWtwNewGlobalStatus);

struct wtwNewGlobalStatus // jako wP do WTW_GLOBAL_STATUS_SET
{
	__wtwStdStructDefs(wtwNewGlobalStatus);

	int				structSize;
	wtwPresenceDef	newStatus;

	_tReplaceDesc	replaceFunct;
	void *			pInternals;	// nic co by bylo interesuj¹ce ;P
};



#endif