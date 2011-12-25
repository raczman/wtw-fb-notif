#ifndef __wtw__timer_h__
#define __wtw__timer_h__

#include "wtwPlugin.h"

struct wtwTimerDef 
{
	__wtwStdStructDefs(wtwTimerDef);

	int				structSize;

	const wchar_t	*id;
	DWORD			sleepTime;

	WTWFUNCTION		callback;
	void *			cbData;

	DWORD			flags;
};

#define WTW_TIMER_FLAG_ONE_TICK	0x00000001

struct wtwTimerEvent 
{
	__wtwStdStructDefs(wtwTimerEvent);

	int				structSize;

	const wchar_t * id;
	int				event;
};

/////////////////////////////////////////////////////////////////////////////////////////
//
// WTW_TIMER_CREATE
//
// wParam - wtwTimerDef*
// lParam - NULL
//
// Tworzy timer i go uruchamia; zwraca 1 jesli ok, 0 przy bledzie
//

#define WTW_TIMER_CREATE	L"WTW/Timer/Create"

/////////////////////////////////////////////////////////////////////////////////////////
//
// WTW_TIMER_DESTROY
//
// wParam - wchar_t* - id
// lParam - NULL
//
// Niszczy timer
//

#define WTW_TIMER_DESTROY	L"WTW/Timer/Destroy"

/////////////////////////////////////////////////////////////////////////////////////////
//
// wtwTimerEvent * przekazywane jako wParam do Callbacka
//

#define WTW_TIMER_EVENT_CREATED		0x0001
#define WTW_TIMER_EVENT_DESTROYED	0x0002
#define WTW_TIMER_EVENT_TICK		0x0003



#endif