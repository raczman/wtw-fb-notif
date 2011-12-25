#ifndef _wtw_chat_window_h_
#define _wtw_chat_window_h_

/* te dotycza poszczegolnych zakladek */
/* in case of metas, first contact in wP array is currently selected one */

#define WTW_EVENT_ON_CHATWND_CREATE		L"Chat/OnCreate"	// wP - wtwContactDef[], lP - * wtwChatInfo
#define WTW_EVENT_ON_CHATWND_SHOW		L"Chat/OnShow"		// wP - wtwContactDef[], lP - * wtwChatInfo
#define WTW_EVENT_ON_CHATWND_ACTIVATE	L"Chat/OnActivate"	// wP - wtwContactDef[], lP - * wtwChatInfo
#define WTW_EVENT_ON_CHATWND_DETACHED	L"Chat/OnDetached"	// wP - wtwContactDef[], lP - * wtwChatInfo
#define WTW_EVENT_ON_CHATWND_ATTACHED	L"Chat/OnAttached"	// wP - wtwContactDef[], lP - * wtwChatInfo
#define WTW_EVENT_ON_CHATWND_HIDE		L"Chat/OnHide"		// wP - wtwContactDef[], lP - * wtwChatInfo
#define WTW_EVENT_ON_CHATWND_DESTROY	L"Chat/OnDestroy"	// wP - wtwContactDef[], lP - * wtwChatInfo
#define WTW_EVENT_ON_CHATWND_MSG_SENT	L"Chat/OnMsgSend"	// wP - wtwContactDef[], lP - * wtwChatInfo - after message was sent, (edit cleared)
#define WTW_EVENT_ON_CHATWND_MCT_CHANGE	L"Chat/OnMctChange"	// wP - wtwContactDef[], lP - * wtwChatInfo - metacontact component was changed

/* te dotycza calego okna, uwaga (!!!) wp i lp moga tutaj byc null'ami (!) */

#define WTW_EVENT_ON_HOSTWND_ACTIVATE	L"Chat/OnHostActivate"	// wP - wtwContactDef[], lP - * wtwChatInfo
#define WTW_EVENT_ON_HOSTWND_SHOW		L"Chat/OnHostShow"		// wP - wtwContactDef[], lP - * wtwChatInfo
#define WTW_EVENT_ON_HOSTWND_HIDE		L"Chat/OnHostHide"		// wP - wtwContactDef[], lP - * wtwChatInfo
#define WTW_EVENT_ON_HOSTWND_TAB_CLOSE	L"Chat/OnHostTabClose"	// wP - wtwContactDef[], lP - * wtwChatInfo

/* a te roznie */

#define WTW_FUNCT_GET_CHATWND_ATTRIBUTES L"Chat/GetCWAttribs"	// wP - wtwChatWindowAttributes*, 
																// returns S_OK if ok/visible/active, S_FALSE if not or E_* on error 

struct wtwChatWindowAttributes
{
	__wtwStdStructDefs(wtwChatWindowAttributes);

	int					structSize;

	DWORD				flags;
	wtwContactDef	*	pContactData;
};

#define WTW_WA_FLAG_GET_ACTIVE_WINDOW_INFO	0x0002	// instead of checking if specified windows is active, 
													// get active window info, if pContactData is valid, will be filled by the program;
#define WTW_WA_FLAG_GET_VISIBLE_WINDOW_INFO	0x0004	// instead of checking if specified windows is visible, 
													// get first visible window info;
#define WTW_WA_FLAG_IS_WINDOW_VISIBLE		0x0008	// pContactData may be NULL = "ask about tab window, not specyfic contact window"
#define WTW_WA_FLAG_IS_WINDOW_ACTIVE		0x0010
#define WTW_WA_FLAG_IS_VISIBLE_OR_IN_TABS	0x0020


#define WTW_FUNCT_IS_CHATWND_ACTIVE		L"WTW/IsChatActive"	// zwraca 1 jesli tak, 0 jesli nie. 
															// jesli w wp podamy wskaznik
															// do wtwContactDef
															// to dostaniemy dane aktywnej zakladki o ile okno jest aktywne
															// jesli nie jest to wtw nie uzupelni danych

#define WTW_FUNCT_IS_CONTACT_CHAT_ACTIVE	L"WTW/IsContactChatActive"	// wP = wtwContactDef* (wypelniony)

/*
 * Jesli zastanawiacie czym sie rozni WTW_FUNCT_IS_CHATWND_ACTIVE od WTW_FUNCT_IS_CONTACT_CHAT_ACTIVE,
 * prawie niczym. Z tym ze druga ma dostac wypelniony contactDef a pierwsza samago wypelnia.
 *
 * Poza tym, pierwsza zwroci aktywny kontakt w meta, a druga zwroci 1 jesli
 * podany kontakt jest w meta okna, nawet jesli nie jest aktywnym kontaktem
 *
 */

#define WTW_FUNCT_CHATWND_CLEAR			L"WTW/ClearChat"	// wP - wtwContactDef*
#define	WTW_FUNCT_OPEN_CHAT_WINDOW		L"WTW/OpenChatWindow"// wP - wtwContactDef*

struct wtwChatWindowInfo 
{
	__wtwStdStructDefs(wtwChatWindowInfo);

	int		structSize;

	int		bKnownContact;	// kontakt na naszej liscie?
	HWND	hWindow;		// uchwyt okna chata;
	HWND	hHost;			// uchwyt okna zakladek;

	void *  pNode;			// wewnetrzne, nie uzywamy i tak ;p
	void *  pWnd;			// potrzebne przy dodawaniu elementow do command-bar'a

	int		iContacts;		// ilosc struktur wtwContactDef upchnieta w wP
							// zerowy index ma kontakt aktywny, reszta (jesli wystepuje)
							// to obecne pod danym metakontaktem kontakty;

	const wchar_t * metaId; // id meta okna, jesli jest dostepne;
	int		bIsActive;		// czy przy tym evencie okno jest aktywne?
	int		bIsDetached;	// okno w oknie z zakladkami czy samodzielne
};

#define WTW_EVENT_CHATWND_BEFORE_MSG_DISP1 L"Chat/BeforeDisplay1"	// wP - wtwMessageDef*
																	// nie u¿ywaæ tego do modyfikowania treœci wiadomoœci,
																	// do tego celu jest _BEFORE_MSG_DIPS2

#define BMD_OK				0x00 // ok, proceed
#define BMD_FORCE_NO_STORE	0x01 // ok, ale nie zapisuj doarchiwum (wstrzymuje dalsze hooki);
#define BMD_FORCE_NO_DISP	0x02 // ok, ale nie wyswietlaj (wstrzymuje dalsze inne hooki);

// powyzsze to flagi, mozna je ³¹czyæ;

#define WTW_EVENT_CHATWND_BEFORE_MSG_PROC L"Chat/BeforeProcess" // wP - wtwBmpStruct* (po pobraniu z edita, przed przegazaniem dalej)

typedef void (*t_pfnReplacePtrP)(const wchar_t *pTarget, void *pBmpStruct);

struct wtwBmpStruct 
{
	__wtwStdStructDefs(wtwBmpStruct);

	wtwMessageDef		message;
	int					structSize;		// dlaczego tu? bo dla kompatybilnosci wstecznej ;P
	t_pfnReplacePtrP	fnReplaceMsg;	// funkcja ktora podmienia tekst wiadomosci na nasz

	void			*	ud;				// wydaje mi sie, ze to wkaznik, jakis
};


#define BMP_OK				0x00 // ok, proceed
#define BMP_NO_PROCESS		0x01 // zjedliœmy tê wiadomoœæ, nie pojdzie dalej, czyœcimy edita

#define WTW_EVENT_CHATWND_BEFORE_MSG_DISP2 L"Chat/BeforeDisplay2" 

typedef void (*t_pfnReplacePtr)(const wchar_t *pTarget, void *pBmdStruct);

struct wtwBmd2Struct 
{
	__wtwStdStructDefs(wtwBmd2Struct);

	int				structSize;

	int				bmdResult;		// razultat pierwszej "BeforeDisplay"
	wtwMessageDef	*pMsg;

	t_pfnReplacePtr fnReplaceMsg;	// funkcja ktora podmienia tekst wiadomosci na nasz

	void			*ud;			// wydaje mi sie, ze to wkaznik
};

#define WTW_CHATWND_SHOW_MESSAGE		L"WTW/PFShowMessage"	// wP - wtwMessageDef*

#define WTW_CHATWND_INPUT_TEXT_SET		L"WTW/SetChatTextInput"	// wP - wtwChatWndText*	
																// ret - S_OK (or S_FALSE = text was set, but window is not visible), 
																// E_NOINTERFACE = chatwnd is not present
																// E_HANDLE = buffer too small
																// E_* - other errors
#define WTW_CHATWND_INPUT_TEXT_GET		L"WTW/GetChatTextInput"	// wP - wtwChatWndText* ret - S_OK, S_FALSE, E_*

struct wtwChatWndText
{
	__wtwStdStructDefs(wtwChatWndText);

	int				structSize;

	wtwBuffer		buffer;				// on GET, of buffer ins null, and bufferSize is -1, upon return bufferSize will contain needed buffer size (in chars)
	wtwContactDef	contactInfo;

	DWORD			flags;
};

#endif