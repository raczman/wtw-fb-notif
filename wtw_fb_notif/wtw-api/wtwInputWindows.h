#pragma once

#include "wtwPlugin.h"

#define WTW_SHOW_MESSAGE_BOX		L"WTW/ShowMessageBox" //zwraca SMB_RESULT_*

//#define SMB_TYPE_MESSAGE_BOX	0x0001
#define SMB_TYPE_SIMPLE_INPUT	0x0002

//#define SMB_CLASS_BUTTON_OK		0x0001
//#define SMB_CLASS_BUTTON_YESNO	0x0002

struct wtwShowMessageWindow
{
	__wtwStdStructDefs(wtwShowMessageWindow);

	int				structSize;

	int				windowType;

	wchar_t		*	pRetBuffer;
	int				pRetBufferSize;

	const wchar_t * windowCaption;
	const wchar_t * windowTitle;
	const wchar_t * windowDescription;
	const wchar_t * windowMessage;
	const wchar_t * defaultInput;

	DWORD			windowClass;
};

#define SMB_RESULT_OK		IDOK
#define SMB_RESULT_YES		IDYES
#define SMB_RESULT_NO		IDNO
#define SMB_RESULT_CANCEL	IDCANCEL
#define SMB_RESULT_ERROR	-1L
