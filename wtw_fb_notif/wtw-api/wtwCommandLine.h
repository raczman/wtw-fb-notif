#ifndef __wtw__cmdline_h__
#define __wtw__cmdline_h__

#include "wtwPlugin.h"

#define WTW_TEST_COMMAND_ARGUMENT L"WTW/TestCommandArg" // wparam wtwTestCmdLineParameter*

struct wtwTestCmdLineParameter 
{
	__wtwStdStructDefs(wtwTestCmdLineParameter);

	int				structSize;
	const wchar_t *	parameter;	// bez spacji i -, nazwa parametru
	wchar_t *		argument;	// zwracane, trza zaalokowac odpowiedni bufor, can be null
	int				argumentLen;
};

#endif