#pragma once

#include "wtwPlugin.h"
#include "wtwContact.h"

struct wt7HttpFile 
{
	__wtwStdStructDefs(wt7HttpFile);

	int				structSize;

	const wchar_t * filePath;		// sciezka doplikunadysku,pelna
	wchar_t 		fileID[512];	// out, sam ID (tylko dla internal http)
	wchar_t			fileURL[512];	// out pelny URL do udostepnionego pliku
};

struct wt7HttpSendFile 
{
	__wtwStdStructDefs(wt7HttpSendFile);

	int				structSize;

	wtwContactDef * contact;	// do kogo wyslac link
	wt7HttpFile	*	file;		// dane pliku

	int				method;		// metoda ;p

	WTWFUNCTION		pNotifyFunc;// jesli method != 0 to ta funkcjazostanie wywolanana po zakonczeniu uploadu (uwaga, z innego w¹tku niz g³owny)
	void*			pNotifyFuncData;	

	DWORD			flags;

	WTWFUNCTION		_progressCallback; // wP - sent, lp = total to send
	void *			_fnProgressCBData;
};
 
#define WT7_PREPARE_FILE	L"WT7/PrepareFile" // wparam - wt7HttpSendFile * (tylko dodac do listy udostepnionych)
#define WT7_SEND_FILE		L"WT7/SendFile"    // wparam - wt7HttpSendFile * (dodacdolisty i wyslac link via chat)
#define WT7_IS_ENABLED		L"WT7/IsEnabled"

#define WT7_METHOD_INTERNAL_HTTP	0x0000
#define WT7_METHOD_IMAGESHACK		0x0001	// nieobslugiwane jeszcze
#define WT7_METHOD_WRZUTA_PL		0x0002	// nieobslugiwane jeszcze

#define WT7_FLAG_SHOW_PROGRESS		0x0001	// pokazac okienko uploadu


#define WT7_STATUS_SEND_OK			0x0001
#define WT7_STATUS_SEND_FAILED		0x0000
#define WT7_STATUS_SEND_BEGIN		0x0002