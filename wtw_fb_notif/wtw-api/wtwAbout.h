#pragma once

#include "wtwPlugin.h"

struct wtwAboutDlg {
	int				structSize;		// wiadomo
	
	const wchar_t *	dialogTitle;	// tytul okienka
	
	const wchar_t *	headerLine1;	// ierwsza linijka nag³owka
	const wchar_t *	headerLine2;	// druga
	const wchar_t *	headerLine3;	// trzecia

	const wchar_t *	mainText;		// tekst pod nag³owkiem

	HICON			hIcon;			// ikonka, 48x48, zostanei automatycznie usunieta po zamknieciu okna

	int				hIconIsBitmap;	// hIcon to HBITMAP a nie hIcon
};

#define WTW_ABOUT_SHOW L"WTW/AboutShow"	// wParam = wtwAboutDlg *
