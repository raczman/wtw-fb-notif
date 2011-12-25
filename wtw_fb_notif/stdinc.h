#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif
#include <Windows.h>
#include <wtwPlugin.h>

extern WTWFUNCTIONS* wtw;
extern HANDLE thr;
#define LOG(a) __LOG(wtw, L"FBPL", a)