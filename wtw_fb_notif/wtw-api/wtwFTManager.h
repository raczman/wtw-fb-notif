#ifndef __wtw__ft_h__
#define __wtw__ft_h__

#include "wtwPlugin.h"
#include "wtwContact.h"

struct wtwFTInit 
{
	int				structSize;
	
	WTWFUNCTION		fnCallback;		// start, stop, addfiles, remove
	void		  * fnCallbackData;// a to podac jako "void *od"
	
	const wchar_t * statusText;
	const wchar_t * dialogTitle;

	const wchar_t * headerMain;
	const wchar_t * headerDesc;

	WTWFUNCTION		fnUpdateWindow;	// po dodaniu, wo³aæ to celem update'u
	void		  * fnOwnerData;// a to podac jako "void *od"

	wtwContactDef * pContact;		// który kontakt, jesli tego uzywamy to header* nie ma znaczenia nawet jesli jest ustawione

	const wchar_t * linkText;		// <a>link</a> do czegoœ
	const wchar_t * linkTarget;		// to coœ

	HINSTANCE		hInst;

};

#define FTF_UPDATE_STATUS			0x00000001
#define FTF_UPDATE_HEADER			0x00000002
#define FTF_UPDATE_FILE_LABEL		0x00000004
#define FTF_UPDATE_TOTAL_SENT_BYTES 0x00000008
#define FTF_UPDATE_TOTAL_BYTES		0x00000010
#define FTF_UPDATE_FILE_BYTES		0x00000020
#define FTF_UPDATE_FILE_SENT_BYTES	0x00000040
#define FTF_UPDATE_PROGR_FILE		0x00000080
#define FTF_UPDATE_PROGR_TOTAL		0x00000100
#define FTF_UPDATE_ENABLE_ABORT		0x00000200
#define FTF_UPDATE_ENABLE_CLOSE		0x00000400
#define FTF_UPDATE_STATUS_TEXT		0x00000800
#define FTF_UPDATE_OPEN_LABEL		0x00001000
#define FTF_UPDATE_OPEN_TARGET		0x00002000
#define FTF_AUTO_PROGR_FILE			0x01000000
#define FTF_AUTO_PROGR_TOTAL		0x02000000

#define	WTW_FT_STATE_NONE		0x0000
#define	WTW_FT_STATE_ACTIVE		0x0001
#define	WTW_FT_STATE_ERROR		0x0002
#define	WTW_FT_STATE_UNDEF		0x0003

struct wtwFTState 
{
	int				structSize;
	
	DWORD			flags;

	const wchar_t * statusText;
	const wchar_t * headerDesc;
	const wchar_t * fileLabel;
	const wchar_t * fileOpenLabel;
	const wchar_t * fileOpenTarget;
	
	ULONGLONG		iTotalBytesSend;
	ULONGLONG		iTotalBytes;

	ULONGLONG		iFileBytesSend;
	ULONGLONG		iFileBytes;

	DWORD			transferState;

	int				nProgress1;		// (0-1000)
	int				nProgress2;		// (0-1000)

	int				bEnableAbort;
	int				bEnableClose;

	void *			windowHandle;
};

#define FT_EVENT_CLOSE				0x0001	// kliknieto "zamknij"
#define FT_EVENT_ABORT				0x0002  // kliknieto "przerwij"

struct wtwFTEvent 
{
	int				structSize;

	int				eventId;
	void	*		windowPtr;
	wtwContactDef * contactInfo;
};

#define WTW_FT_INIT		L"WTW/FTInitWindow"		// zwraca handle do okna
#define WTW_FT_KILL		L"WTW/FTKillWindow"		// pozbywa sie handla okna
#define WTW_FT_DROP		L"WTW/FTDropWindow"

struct wtwFTQuestion 
{
	int				structSize;
	const wchar_t * statusText;

	wchar_t		  * pBuffer;		// poczatkowy folder,przy OK tu skopiowane zostanie co wybral user
	DWORD			iBuffer;		// rozmiar calego bufora

	wtwContactDef * from;			// do zastapienia %from%

	int				iOptions;		// ilosc wskaznikow w ponizeszej
	const wchar_t **sOptions;		// nazwy opcji
	const wchar_t * sOptionsName;	// label pola opcji
	
	int				iSelectedOption;// na poczatku - to co domyslniejest zaznaczone, przy wyjsciu co user wybral
};

#define WTW_FT_ASK_FOR_CONFIRMATION L"WTW/FTAskForConfirmation"

#endif