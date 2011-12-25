#pragma once

#include "wtwPlugin.h"

struct wtwACMInterface
{
	__wtwStdStructDefs(wtwACMInterface);

	int				structSize;
	
	WTWFUNCTION		eventCallback;
	void	*		cbData;

	const wchar_t * netClass;
	const wchar_t * netName;
	DWORD			flags;
};

struct wtwACMAccount
{
	__wtwStdStructDefs(wtwACMAccount);

	int				structSize;
	const wchar_t * accountName;
	const wchar_t * accountInfo;
	const wchar_t * iconId;
	
	const wchar_t * netClass;
	int				netId;

	DWORD			flags;

};

#define ACM_FLAG_ALLOW_DELETE 0x0001
#define ACM_FLAG_ALLOW_EDIT   0x0002
#define ACM_FLAG_ALLOW_INFO   0x0004

struct wtwACMEvent
{
	__wtwStdStructDefs(wtwACMEvent);

	int				structSize;
	
	int				event;
	const wchar_t * netClass;
	HWND			hOptionsWindow;
};

#define ACM_EVENT_LIST		0x0000 // lP - NULL, skorzystac z WTW_ACM_ACCOUNT_ADD
#define ACM_EVENT_EDIT		0x0001 // lP - wtwACMAccount*
#define ACM_EVENT_REMOVE	0x0002 // lP - wtwACMAccount*
#define ACM_EVENT_INFO		0x0003 // lP - wtwACMAccount*
#define ACM_EVENT_ADD		0x0004 // lP - NULL, potem pojdzie event "List"

#define WTW_ACM_ACCOUNT_ADD			L"ACM/AddAccount"		//wP - wtwACMAccount*

#define WTW_ACM_INTERFACE_ADD		L"ACM/InterfaceAdd"		// wP - wtwACMConnection *
#define WTW_ACM_INTERFACE_REMOVE	L"ACM/InterfaceRemove"	// wP - netClass*
