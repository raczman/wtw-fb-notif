#pragma once

#include "wtwPlugin.h"
#include "wtwContact.h"

#define WTW_EXECUTE_DEFAULT_ACTION L"WTW/ExecDefaultAction"

struct wtwDefaultAction
{
	__wtwStdStructDefs(wtwDefaultAction);

	int				structSize;
	int				action;

	wtwContactDef *	pContactData;
	int				contactCount;	// contact count in pointer above
};

#define WEDA_SHOW_CONTACT_PROPERTIES	0x0001 // pContactData must be filled, lP - wedaShowContactProperties*

struct wedaShowContactProperties
{
	__wtwStdStructDefs(wedaShowContactProperties);

	int		structSize;

	const wchar_t * defaultPageId;			// or null for defautls
};

#define WEDA_DELETE_CONTACTS				0x0002 // pContactData must be filled, lP - NULL
#define WEDA_SHOW_PRESENCE_CHANGE_WINDOW	0x0003 // lP - NULL
