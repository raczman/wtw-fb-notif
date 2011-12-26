#include "stdinc.h"
#include "options.h"
#include "resource.h"
#include <wtwSettings.h>
#include <string>

using namespace std;

HWND okno;
wtwMyConfigFile myCfg;
void* pCfg = 0;

void init_settings()
{
	wtwOptionPageDef d;
	initStruct(d);
	d.callback = (WTWFUNCTION)settings_callback;
	d.id = page_id;
	d.caption = L"Facebook";
	d.parentID = WTW_OPTIONS_GROUP_PLUGINS;
	d.iconID = 0;
	wtw->fnCall(WTW_OPTION_PAGE_ADD, (WTW_PARAM)ghInstance ,(WTW_PARAM)&d);

	myCfg.bufferSize= MAX_PATH + 1;
	myCfg.pBuffer = new wchar_t[myCfg.bufferSize];

	wtw->fnCall(WTW_SETTINGS_GET_MY_CONFIG_FILE, (WTW_PARAM)&myCfg, (WTW_PARAM)ghInstance);
	wtw->fnCall(WTW_SETTINGS_INIT_EX, (WTW_PARAM)myCfg.pBuffer, (WTW_PARAM)&pCfg);
	wtw->fnCall(WTW_SETTINGS_READ, (WTW_PARAM)pCfg, 0);
}

void remove_settings()
{
	wtw->fnCall(WTW_SETTINGS_WRITE, (WTW_PARAM)pCfg, 0);
	wtw->fnCall(WTW_OPTION_PAGE_REMOVE, (WTW_PARAM)ghInstance, (WTW_PARAM)page_id);
}

LRESULT CALLBACK wnd_proc(HWND h, UINT msg, WPARAM wp, LPARAM lp)
{
	if(msg == WM_COMMAND && HIWORD(wp) == BN_CLICKED && LOWORD(wp) == IDC_BUTTON1)
	{
		ShellExecute(0,0,L"https://www.facebook.com/dialog/oauth?client_id=291081334239552&response_type=token&redirect_uri=http://wtw-notif.herokuapp.com&scope=offline_access,manage_notifications,friends_birthday",0,0,0);
	}
	else if(msg == WM_ERASEBKGND)
	{
		RECT rect;
		GetClientRect(h, &rect);
		FillRect((HDC)wp,&rect, CreateSolidBrush(RGB(255,255,255)));
		UpdateWindow(h);
		return TRUE;
	}

	return DefDlgProc(h, msg, wp, lp);
}

wchar_t* get_token()
{
	wchar_t *ret;
	wtwGetStr(wtw, pCfg, tokenSetting, L"",&ret);
	return ret;
}

WTW_PTR settings_callback(WTW_PARAM wp, WTW_PARAM lp)
{
	wtwOptionPageShowInfo* pi = (wtwOptionPageShowInfo*)wp;
	wcscpy(pi->windowCaption, L"Ustawienia pluginu wtw-fb-notif");
	wcscpy(pi->windowDescrip, L"Dzieci jedzcie ��ty �nieg");

	switch(pi->action)
	{
	case WTW_OPTIONS_PAGE_ACTION_SHOW:
		{
		okno = CreateDialog((HINSTANCE)ghInstance, MAKEINTRESOURCE(IDD_DIALOG1), pi->handle, 0);
		MoveWindow(okno, pi->x, pi->y, pi->cx, pi->cy, TRUE);
		SetWindowLongPtr(okno, GWLP_WNDPROC, (LONG)wnd_proc);
		wchar_t* token = get_token();
		SetDlgItemText(okno, IDC_EDIT1, token);
		delete token;
		break;
		}
	case WTW_OPTIONS_PAGE_ACTION_HIDE:
		DestroyWindow(okno);
		break;
	case WTW_OPTIONS_PAGE_ACTION_OK:
	case WTW_OPTIONS_PAGE_ACTION_APPLY:
		{
		wchar_t* ptr = new wchar_t[MAX_PATH];
		GetDlgItemText(okno, IDC_EDIT1, ptr, MAX_PATH);
		wtwSetStr(wtw, pCfg, tokenSetting, ptr);
		wtw->fnCall(WTW_SETTINGS_WRITE, (WTW_PARAM)pCfg, 0);
		delete[] ptr;
		if(WTW_OPTIONS_PAGE_ACTION_OK == pi->action)
			DestroyWindow(okno);
		break;
		}
	default:
		break;
	}

	return 0;
}