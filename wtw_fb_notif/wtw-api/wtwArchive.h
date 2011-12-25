#pragma once

struct wtwArchiveEntrySms 
{
	__wtwStdStructDefs(wtwArchiveEntrySms);

	int				structSize;

	const wchar_t * body;
	const wchar_t * extra;
	const wchar_t * phone;

	DWORD			flags;
	QWORD			time;

	DWORD			writeFlags;
};

#define WTW_ARCH_WRITE_SMS		L"Ar/WriteSMS"
#define WTW_ARCH_WRITE_MESSAGE	L"Ar/WriteMessage"

struct wtwArchiveEntryMessage 
{
	__wtwStdStructDefs(wtwArchiveEntryMessage);

	int				structSize;
	int				chatID;			// to jest parametr in/out. Jesli potrzebujemy nowego ID
									// to ustawiamy na -1, wraz z pierwsza wypowiedzia w rozmowie;
									// program wygeneruje nowy ID i zwroci go nam przez ten parametr;
									// i tego ID uzywamy w pozniejszych wywolaniach funkcji, poki
									// nie rozpoczniemy nowej rozmowy; Takze, przy nowych -1;

	DWORD			flags;

	wtwMessageDef	message;
};

#define WTW_ARCH_MESSAGE_WFLAG_SYNCHRO	0x00000001	// normalnie zapis jest asynchroniczny,
													// jesli uzywamy transakcji to powinnismy
													// takze ustawic te flage

#define WTW_ARCH_TRANSACTION			L"Arch/Transaction" // wP - WATR_*

#define WATR_BEGIN		0x01
#define WATR_COMMIT		0x02
#define WATR_ROLLBACK	0x03

#define WTW_ARCH_PAGE_ACTION_SHOW           1	// Pokazac okienko (lP - wtwContactDef* or NULL)
#define WTW_ARCH_PAGE_ACTION_HIDE           2	// Schowac okienko

#define WTW_ARCH_PAGE_ACTION_DESTROY        5	// zniszczyc nasze okno arch, bo
												// okno archiwum jest zamykane
#define WTW_ARCH_PAGE_ACTION_MOVE           6	// Przesun¹æ okno

#define WTW_ARCH_PAGE_ACTION_FILTER         8	// lparam - wtwContactDef*, jesli trzeba 
												// odfiltrowac dane dlakonretnego kontaktu
												// lub NULL, ktory oznacza "pokaz wszystko"
												// event wysylany tylko jesli archiwum jest juz otwarte, dana
												// strona wyswietlona, i zachodzi potrzeba zmiany filtra
												// tj kliknieto "archiwum" na innym kontakcie;

/////////////////////////////////////////////////////////////////////////////////
//
// WTW_ADD_ARCH_PAGE
// 
// wParam - hInstance
// lParam - wtwOptionpadeDef*
// 

#define WTW_ADD_ARCH_PAGE                   L"WTW/AddArchPage"

/////////////////////////////////////////////////////////////////////////////////
//
// WTW_REMOVE_ARCH_PAGES
// 
// wParam - hInstance
// lParam - NULL
// 

#define WTW_REMOVE_ARCH_PAGES           L"WTW/RemoveArchPages"

#define WTW_ARCH_PAGE_ID_CHATS			L"WTW/ArchPage/Chats"
#define WTW_ARCH_PAGE_ID_MESSAGES		L"WTW/ArchPage/Msgs"
#define WTW_ARCH_PAGE_ID_CONFERENCE		L"WTW/ArchPage/Conf"
#define WTW_ARCH_PAGE_ID_SMS			L"WTW/ArchPage/SMS"
#define WTW_ARCH_PAGE_ID_MAINTENANCE	L"WTW/ArchPage/Maint"