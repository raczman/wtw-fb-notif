#include "stdinc.h"
#include "fb.h"
#include "options.h"
#include <wtwTimer.h>

WTWPLUGINFO plugInfo = {
	sizeof(WTWPLUGINFO),
	L"wtw_fb_notif",
	L"Wyœwietlanie powiadomieñ z FB",
	L"2011",
	L"Krzysztof \"raczman\" Raczyñski",
	L"raczman@mentlegen.com",
	L"",
	0,
	PLUGIN_API_VERSION,
	MAKE_QWORD(0, 1, 0, 0),
	WTW_CLASS_UTILITY,
	NULL,
	L"{92c36fe0-85e7-417c-afcb-23447b538aeb}",
	0,
	0,
	0,
	0,0
};

WTWFUNCTIONS* wtw;
HANDLE ghInstance;
wtwTimerDef timer;

bool __stdcall DllMain(HANDLE hInst, DWORD reason, LPVOID /*reserved*/) {
	switch(reason) {
	case DLL_PROCESS_ATTACH: {
		ghInstance = (HINSTANCE)hInst;
		break;
							 }
	case DLL_PROCESS_DETACH: {
#ifdef _DEBUG
		_CrtDumpMemoryLeaks();
#endif
		ghInstance = 0;
		break;
							 }
	default: break;
	}
	return true;
}

WTW_PLUGIN_API_ENTRY(WTWPLUGINFO*) queryPlugInfo(DWORD /*apiVersion*/, DWORD /*masterVersion*/) {
	return &plugInfo;
}

WTW_PLUGIN_API_ENTRY(int) pluginLoad(DWORD /*callReason*/, WTWFUNCTIONS* f) {
	wtw = f;
	InitCommonControls();
	timer.callback = (WTWFUNCTION)timer_expire;
	timer.sleepTime = INTERVAL;
	timer.id = timer_id;
	init_settings();
	wtw->fnCall(WTW_TIMER_CREATE,(WTW_PARAM)&timer,0);
	_beginthreadex(0, 0, bday_thread, 0, 0, 0);
	return 0;
}

WTW_PLUGIN_API_ENTRY(int) pluginUnload(DWORD /*callReason*/) {
	wtw->fnCall(WTW_TIMER_DESTROY, (WTW_PARAM)timer_id, 0);
	WaitForSingleObject(thr, INFINITE);
	remove_settings();
	wtw = 0;
	return 0;
}

