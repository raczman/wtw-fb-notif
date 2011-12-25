#ifndef __wtw__pad_h__
#define __wtw__pad_h__

#include "wtwPlugin.h"

#define WTW_GET_PAD				L"WTW/GetProcAddr"	// wparam - WTW_PAD_*

#define	WTW_PAD_SL_ADD			0x00000002
#define	WTW_PAD_SL_DELETE		0x00000003
#define	WTW_PAD_SL_CLEAR		0x00000004
#define	WTW_PAD_SL_GET_ITEM		0x00000005
#define	WTW_PAD_SL_GET_ITEM_COUNT 0x00000006
#define	WTW_PAD_SL_INTERFACE	0x00000007	// *stringListInterface

typedef void (__cdecl * pwfAddHintData)(void *hData, const wchar_t * pText);

typedef void (__cdecl *pwSLAdd)(void *hItems, const wchar_t * itemID);
typedef void (__cdecl *pwSLDelete)(void *hItems, const wchar_t * itemID);
typedef void (__cdecl *pwSLClear)(void *hItems);
typedef int  (__cdecl *pwSLGetItemCount)(void *hItems);
typedef const wchar_t * (__cdecl *pwSLGetItem)(void *hItems, DWORD iItem);

struct stringListInterface 
{
	__wtwStdStructDefs(stringListInterface);

	int			structSize;

	pwSLAdd				add;
	pwSLDelete			erase;
	pwSLClear			clear;
	pwSLGetItemCount	count;
	pwSLGetItem			get;
};

#endif