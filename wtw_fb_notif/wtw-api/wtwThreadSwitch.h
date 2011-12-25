#pragma once

#include "wtwPlugin.h"

/*
 * To jest do wywo�ywania W�ASNYCH funkcji, tylko spod g�ownego w�tku
 *
*/

struct wtwFuncCall
{
	__wtwStdStructDefs(wtwFuncCall);

	int				structSize;
	WTWFUNCTION		fnToCall;
	WTW_PARAM		wP;
	WTW_PARAM		lP;
	void		*	ownerData;
};

#define WTW_SWITCH_THREAD L"WTW/SwitchThread"	// prze��czy wykonanie do g�ownego w�tku (UI) i 
												// wywo�a fnToCall z naszymi parametrami

WTW_PTR _inline _switchThreadAndCall(WTWFUNCTIONS *pF, WTWFUNCTION _fn, WTW_PARAM wP, WTW_PARAM lP, void *oD)
{
	wtwFuncCall i;
	initStruct(i);

	i.fnToCall	= _fn;
	i.lP		= lP;
	i.ownerData	= oD;
	i.wP		= wP;

	return pF->fnCall(WTW_SWITCH_THREAD, (WTW_PARAM)&i, 0);
}