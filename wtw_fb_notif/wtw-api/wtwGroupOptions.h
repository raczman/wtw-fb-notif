#pragma once

#include "wtwPlugin.h"

struct wtwGroupEntry 
{
	__wtwStdStructDefs(wtwGroupEntry);

	int				structSize;
	const wchar_t * entryName;
	const wchar_t * entryID;

	const wchar_t * netClass; // nieuzywane, ale ustawic
};

#define WTW_ADD_GROUP_SETTING L"WTW/AddGroupSetting" // wParam - wtwGroupEntry*

struct wtwGroupEntryStatus 
{
	__wtwStdStructDefs(wtwGroupEntryStatus);

	int				structSize;

	wtwContactDef	contactData;
	const wchar_t * entryID;
	int				returnStatus;
};

#define WTW_GET_GROUP_SETTING L"WTW/GetGroupSetting"	// wParam - wtwGroupEntryStatus*, 
														// zwraca 1 jesli ustawiono "override" lub 0;
														// stan opcji jest zwracany w returnStatus;
