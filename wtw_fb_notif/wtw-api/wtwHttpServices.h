#pragma once

#include "wtwPlugin.h"
#include "wtwProtocol.h"

struct wtwHttpGetFile
{
	__wtwStdStructDefs(wtwHttpGetFile);

	int				structSize;

	const wchar_t * fileId;	

	const wchar_t * uri;
	const wchar_t * method; // NULL = GET, or GET, POST, etc
	const wchar_t * headers; // can be NULL
	const void *	methodData; // can be NULL if you want to pass method data for GET, 
								// then this must be wchar_t null terminated string
	DWORD			methodDataSize; // sizeof(*methodData)

	const wchar_t * file;
	DWORD			flags;

	WTWFUNCTION		callback;	// required
	void	 *		cbData;

	void	*		hNetHandle;			// reserved, null
};

struct wtwHttpEvent
{
	__wtwStdStructDefs(wtwHttpEvent);

	int				structSize;

	int				event;
	const wchar_t * fileId;
};

struct wtwHttpStatus
{
	__wtwStdStructDefs(wtwHttpStatus);

	int				structSize;

	HRESULT			status; // S_OK/E_*
	int				responseCode;	// http response code
};

#define WTW_HTTP_SERVICE_ASYNCHRONOUS	0x00000001
#define WTW_HTTP_SERVICE_SYNCHRONOUS	0x00000002 // not implemented, besides mutally exclusive with "ASYNC"
#define WTW_HTTP_SERVICE_WRITE_TO_FILE	0x00000004 // 
#define WTW_HTTP_SERVICE_WRITE_TO_CB	0x00000008 // 
#define WTW_HTTP_SERVICE_NO_URI_ESCAPE	0x00000010 // 

#define WTW_HTTP_EVENT_DATA			0x0001 // lP - wtwRawDataDef*
#define WTW_HTTP_EVENT_COMPLETE		0x0002 // lP - wtwHttpStatus*

#define	WTW_HTTP_GET_FILE			L"WTW/HttpGetFile" // wP - wtwHttpGetFile*