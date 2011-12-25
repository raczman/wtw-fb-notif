#pragma once

/**
  * WMF - Window Message Filter - cos czym mozna przechwytywac wszelkie
  *			wiadomosci kierowane do dowolnego "naszego" (programu) okna
  *			W teorii zastepuje subclassing, ktory jak sie okazuje jest
  *			weri weri nasti idea;
  *
**/

#include "wtwPlugin.h"
#include <windows.h>

struct wtwWMF
{
	__wtwStdStructDefs(wtwWMF);

	int				structSize;
	HWND			hWindow;
	const wchar_t*	filterId;
	WTWFUNCTION		wndProc;
	void *			cbData;
};

struct wtwWndProcParam	// jako wP do wndProc
{
	__wtwStdStructDefs(wtwWndProcParam);

	int				structSize;
	
	HWND			hWnd;

	unsigned int	message;

	WPARAM			wParam;
	LPARAM			lParam;
	
	int				filterResult; // WMF_RESULT_*
};

#define WMF_RESULT_PROCEED		0 // przekaz wiadomosc dalej jak zwykle
#define WMF_RESULT_DEFWNDPROC	1 // nie puszczaj dalej do frameworka alepusc przez DefWindowProc
#define WMF_RESULT_EAT_IT		2 // nie puszczaj dalej i przez nic nie przepuszczaj

#define WTW_WMF_INSTALL		L"WMF/Install"		// wp - wtwWMF*, zwraca 0 przy bledzie parametrow, 1 jesli ok
#define WTW_WMF_UNINSTALL	L"WMF/Uninstall"	// wp - filterId, zwraca 0 jesli nie bylo takiego filtra, 1 jesli usunieto