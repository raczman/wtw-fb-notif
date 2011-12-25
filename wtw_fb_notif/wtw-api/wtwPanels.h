#pragma once

#include "wtwPlugin.h"

struct wtwPanelDef
{
	__wtwStdStructDefs(wtwPanelDef);

	int				structSize;

	const wchar_t *	panelText;			// text next to icon
	const wchar_t *	panelIcon;			// the icon itself, required
	const wchar_t *	panelIconOverlay;	// the icon itself, required
	const wchar_t * panelId;			//
	const wchar_t * panelHint;			// button hint

	DWORD			flags;		

	WTWFUNCTION		callback;	// event callback function 
	void *			cbData;		// ownerdata for callback (third param)
};

#define WTW_PANEL_FLAG_DISABLED		0x00010000	// button will not react to mouse events 
#define WTW_PANEL_FLAG_TEXT_LABEL	0x00020000	// not used for now
#define WTW_PANEL_FLAG_AS_BUTTON	0x00040000	// not a tab, but button, not switchable, ymm
#define WTW_PANEL_FLAG_CHECKED		0x00080000	// checked button
#define WTW_PANEL_FLAG_TEXT_UNSEL	0x00100000	// show text label only when unselected
#define WTW_PANEL_FLAG_GRAYED		0x00200000	// icon will be grayed 

#define WTW_PANEL_FLAG_MOD_TEXT		0x00000001
#define WTW_PANEL_FLAG_MOD_ICON		0x00000002
#define WTW_PANEL_FLAG_MOD_FLAG		0x00000004
#define WTW_PANEL_FLAG_MOD_CALLBACK	0x00000008
#define WTW_PANEL_FLAG_MOD_CBDATA	0x00000010
#define WTW_PANEL_FLAG_MOD_HINT		0x00000020
#define WTW_PANEL_FLAG_MOD_OVERLAY	0x00000040

#define WTW_PANEL_MASK_MOD_FLAGS	0x000000FF
#define WTW_PANEL_MASK_STATE_FLAGS	0x00FF0000

struct wtwPanelEvent
{
	__wtwStdStructDefs(wtwPanelEvent);

	int				structSize;
	const wchar_t * panelId;

	DWORD			event;
	POINT			pt;				// good point for showing menu, or smth (screen coords)
	RECT			rc;				// where to show/move window, client coords
	DWORD		*	pItemFlags;		// ptr to item flags, can be modified on fly

	HWND			hParent;
};

#define WTW_PANEL_EVENT_SHOW	0x0001
#define WTW_PANEL_EVENT_HIDE	0x0002
#define WTW_PANEL_EVENT_MOVE	0x0003
#define WTW_PANEL_EVENT_ADDED	0x0007	// your panel added has been
#define WTW_PANEL_EVENT_DELETED	0x0008	// deleted your panel was

#define WTW_PANEL_EVENT_LBUTTON	0x0004
#define WTW_PANEL_EVENT_RBUTTON	0x0005

/************************************************************
/*
/*	WTW_PANEL_ADD
/*
/*	wparam - wtwPanelDef*
/*	lparam - NULL
/*
/*	return value:
/*		E_*, S_OK
/*
/***********************************************************/

#define WTW_PANEL_ADD	L"WTW/PanelAdd"

/************************************************************
/*
/*	WTW_PANEL_DEL
/*
/*	wparam - wtwPanelDef* (with filled id)
/*	lparam - NULL
/*
/*	return value:
/*		E_*, S_OK (deleted), S_FALSE (no such panel)
/*
/***********************************************************/

#define WTW_PANEL_DEL	L"WTW/PanelDel"

/************************************************************
/*
/*	WTW_PANEL_MOD
/*
/*	wparam - wtwPanelDef*
/*	lparam - NULL
/*
/*	return value:
/*		E_*, S_OK
/*
/***********************************************************/

#define WTW_PANEL_MOD	L"WTW/PanelMod"

/************************************************************
/*
/*	WTW_PANEL_SWITCH
/*
/*	wparam - const wchar_t* (panelId)
/*	lparam - WPS_*
/*
/*	return value:
/*		E_*, S_OK (done), S_FALSE (no such panel)
/*
/***********************************************************/

#define WTW_PANEL_SWITCH	L"WTW/PanelSwitch"

#define WPS_NO_WINDOW_ACTIVATE 0x0001
