#ifndef __wtw__sw_h__
#define __wtw__sw_h__

#include "wtwPlugin.h"
#include "wtwProtocol.h"

struct wtwStatusWndParams 
{
	__wtwStdStructDefs(wtwStatusWndParams);

	int				structSize;
	
	const wchar_t * windowCaption;	// naglowek okna ustawiania stanu
	int			*	pStatus;	// tablica z integerami zawierajacymi obslugiwane stany
	int				iStatus;	// ilosc stanow w tablicy
	
	int				descritionLimit; // limit dlugosci opisu

	const wchar_t * netClass;
	int				netId;

	WTWFUNCTION		callback;	// funkcja ktora bedzie otrzymywala info o tym co user nabazgral w oknie
	void		  * cbData;

};

struct wtwStatusWndShow 
{
	__wtwStdStructDefs(wtwStatusWndShow);

	int				structSize;

	const wchar_t * currentDesc;
	int				currentStatus;

	const wchar_t * netClass;
	int				netId;

	DWORD			protectDescEnable;
	DWORD			protectDesc;

};

struct wtwStatusWndEvent 
{
	__wtwStdStructDefs(wtwStatusWndEvent);

	int				structSize;

	int				event;
	wtwPresenceDef  statusInfo;
	DWORD			protectDesc;	// pole "chron opis" zaznaczone
	void *			wndPtr;			// do zmiany napisów
};

#define WTW_STATUS_WND_PREPARE		L"WTW/StatusWND/Prepare"	// wP - wtwStatusWndParams *, 
																// przygotowuje okno do uzytku
#define WTW_STATUS_WND_SHOW			L"WTW/StatusWND/Show"		// pokazuje przygotowane wczesniej okno
																// wP - wtwStatusWndShow *

#define WTW_STATUS_WND_EVENT_OK		0x0001
#define WTW_STATUS_WND_EVENT_CANCEL	0x0002
#define WTW_STATUS_WND_EVENT_ERROR	0x0003
#define WTW_STATUS_WND_EVENT_SHOW	0x0004

struct wtwStatusWndText 
{
	__wtwStdStructDefs(wtwStatusWndText);

	int				structSize;

	const wchar_t * caption;
	const wchar_t * header;
	const wchar_t * subHeader;

	void *			wndPtr;
};

#define WTW_STATUS_WND_SET_TEXTS	L"WTW/StatusWND/SetTexts"	// wP - wtwStatusWndText* 

#endif