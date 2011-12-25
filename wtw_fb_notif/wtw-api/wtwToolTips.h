#pragma once

#include "wtwPlugin.h"

#define WTW_TTIP_INITIALIZE L"WTW/TTip/Initialize"	// wP = HWND okna g³ownego
#define WTW_TTIP_TERMINATE	L"WTW/TTip/Terminate"	// wP = HWND okna g³ownego

#define WTW_TTIP_ADD_TOOL	L"WTW/TTip/AddTool"

struct wtwToolTipAdd 
{
	__wtwStdStructDefs(wtwToolTipAdd);

	int			structSize;

	const wchar_t * tipText;

	HWND			hTipWindow;
	HWND			hMainWnd;
	DWORD			ctrlId;
	DWORD			flags;
};

struct wtwToolTipCreateInfo
{
	__wtwStdStructDefs(wtwToolTipCreateInfo);

	int			structSize;

	DWORD			flags;
};

#define		WTW_TTCREATE_FLAG_SET_NOTIFY	0x00000001

WTW_PTR inline wtwTipInitialize(WTWFUNCTIONS *f, HWND hMainWnd, DWORD flags = 0)
{
	wtwToolTipCreateInfo nfo;
	nfo.flags = flags;
	return f->fnCall(WTW_TTIP_INITIALIZE, (WTW_PARAM)hMainWnd, nfo);
};

WTW_PTR inline wtwTipTerminate(WTWFUNCTIONS *f, HWND hMainWnd)
{
	return f->fnCall(WTW_TTIP_TERMINATE, (WTW_PARAM)hMainWnd, 0);
};

WTW_PTR inline wtwTipAddTool(WTWFUNCTIONS *f, HWND hMainWnd, DWORD ctrlId, const wchar_t *text)
{
	wtwToolTipAdd ti;

	ti.hMainWnd		= hMainWnd;
	ti.hTipWindow	= ::GetDlgItem(hMainWnd, ctrlId);
	ti.tipText		= text;
	ti.ctrlId		= ctrlId;

	return f->fnCall(WTW_TTIP_ADD_TOOL, ti, 0);
};

WTW_PTR inline wtwTipAddTool(WTWFUNCTIONS *f, HWND hMainWnd, HWND hCtrl, const wchar_t *text)
{
	wtwToolTipAdd ti;

	ti.hMainWnd		= hMainWnd;
	ti.hTipWindow	= hCtrl;
	ti.tipText		= text;

	return f->fnCall(WTW_TTIP_ADD_TOOL, ti, 0);
};