#pragma once

#include "wtwPlugin.h"
#include <wchar.h>

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#define WTW_LOG_LEVEL_CRITICAL	-2
#define WTW_LOG_LEVEL_ERROR		-1
#define WTW_LOG_LEVEL_INFO		0
#define WTW_LOG_LEVEL_NORMAL	1
#define WTW_LOG_LEVEL_DEBUG		5
#define WTW_LOG_LEVEL_DEBUG_X	6	// tylko widoczne jesli w³aczony jest "debug messages" i program wystartowa³
									// z parametrem --debug

#pragma warning(disable: 4311)

struct wtwLogDef {

	__wtwStdStructDefs(wtwLogDef);

	int				structSize;

	int				logLevel; // domyslnie 1

	const wchar_t * pModName; //4 znaki
	const wchar_t * pMessage; //co pokazac

	const wchar_t * graphID;  // tylko dla -2, 32x32
	
	void*			reserved;

};

#define WTW_LOG_FUNCTION L"WTW/Log"

void __inline __LOG(
					WTWFUNCTIONS *pF, 
					const wchar_t *mdl, 
					const wchar_t *msg, 
					int lvl = WTW_LOG_LEVEL_NORMAL
					)
{

	wtwLogDef p;
	initStruct(p);

	p.logLevel = lvl;
	p.pMessage = msg;
	p.pModName = mdl;

	pF->fnCall(
		WTW_LOG_FUNCTION, 
		reinterpret_cast<WTW_PARAM>(&p), 
		NULL
		);

}

void __inline __LOG_C(
					WTWFUNCTIONS *pF, 
					const wchar_t *msg, const wchar_t * graphID = NULL
					)
{
	wtwLogDef p;
	initStruct(p);

	p.logLevel	= -2;
	p.pMessage	= msg;
	p.pModName	= NULL;
	p.graphID	= graphID;

	pF->fnCall(
		WTW_LOG_FUNCTION, 
		reinterpret_cast<WTW_PARAM>(&p), 
		NULL
		);
}

void __inline __LOG_F(WTWFUNCTIONS* pF, 
					  int lvl, 
					  const wchar_t* mdl, 
					  const wchar_t* format, ...
					  )
{
	va_list args; 
	va_start(args, format); 
	wchar_t buf[2048] = { 0 }; 
	_vsnwprintf(buf, sizeof(buf) / sizeof(wchar_t), format, args); 
	__LOG(pF, mdl, buf, lvl); 
} 