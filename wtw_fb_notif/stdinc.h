#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif
#include <Windows.h>
#include <process.h>
#include <wtwPlugin.h>

extern WTWFUNCTIONS* wtw;
extern HANDLE thr;
#define LOG(a) __LOG(wtw, L"FBPL", a)