#ifndef __wtwFile_h__
#define __wtwFile_h__

#pragma once

#include "wtwPlugin.h"

///////////////////////////////////////////////////////////////////
//
//		WTW_FILE_CREATE
//
//		wP - NULL
//		lP - NULL
//
//		return value:
//			on error:
//				NULL 
//			on success:
//				const void * - pointer to fileObject
//

#define WTW_FILE_CREATE		L"WTW/FileCreate"

///////////////////////////////////////////////////////////////////
//
//		WTW_FILE_DESTROY
//
//		wP - const void * - pointer to fileObject
//		lP - NULL
//
//		return value:
//			on error:
//				E_* 
//			on success:
//				S_OK
//

#define WTW_FILE_DESTROY	L"WTW/FileDestroy"

///////////////////////////////////////////////////////////////////
//
//		WTW_FILE_OPEN
//
//		wP - wtwFileOpen*
//		lP - NULL
//
//		return value:
//			on error:
//				E_*, E_NOT_SET (encryption enabled, file is encrypted, key is invalid)
//			on success:
//				S_OK
//

#define WTW_FILE_OPEN	L"WTW/FileOpen"

struct wtwFileOpen
{
	__wtwStdStructDefs(wtwFileOpen);

	int				structSize;

	void *			pFileObject;

	const wchar_t * filePath;

	int				bReadAccess;
	int				bWriteAccess;		// warning: if file encryption is enabled, write implies read
	int				bCreateifNotExists;
	int				bTruncate;

	DWORD			flags;
};

#define WTW_FILE_OPEN_FLAG_NO_UI	0x00000001

///////////////////////////////////////////////////////////////////
//
//		WTW_FILE_CLOSE
//
//		wP - const void* - pointer to fileObject
//		lP - NULL
//
//		return value:
//			on error:
//				E_* 
//			on success:
//				S_OK, or S_FALSE
//

#define WTW_FILE_CLOSE	L"WTW/FileClose"

///////////////////////////////////////////////////////////////////
//
//		WTW_FILE_READ & WTW_FILE_WRITE
//
//		wP - wtwFileData
//		lP - NULL
//
//		return value:
//			on error:
//				E_* 
//			on success:
//				S_OK
//

#define WTW_FILE_READ	L"WTW/FileRead"
#define WTW_FILE_WRITE	L"WTW/FileWrite"

struct wtwFileData
{
	__wtwStdStructDefs(wtwFileData);

	int				structSize;

	void		*	pFileObject;

	void *			pBuffer;
	DWORD			nBufferLen;

	DWORD			nBytesProcessed;
};

///////////////////////////////////////////////////////////////////
//
//		WTW_FILE_SEEK	- set internal file pointer
//		WTW_FILE_TRUNC	- truncate file to desired size
//		WTW_FILE_GET_SIZE
//
//		wP - wtwFileSize*
//		lP - NULL
//
//		return value:
//			on error:
//				E_* 
//			on success:
//				S_OK
//

#define WTW_FILE_SEEK		L"WTW/FileSeek"
#define WTW_FILE_GET_SIZE	L"WTW/FileGetSize"
#define WTW_FILE_TRUNC		L"WTW/FileTrunc"

struct wtwFileSize
{
	__wtwStdStructDefs(wtwFileSize);

	int				structSize;

	void		*	pFileObject;

	QWORD			size;		// in/out
	int				param;		// in case of "SEEK", WFS_*
};

#define WFS_BEGIN		0
#define WFS_CURRENT		1
#define WFS_END			2

///////////////////////////////////////////////////////////////////
//
//		WTW_FILE_DECRYPT
//		WTW_FILE_ENCRYPT
//
//		wP - const void* - pFileObject
//		lP - NULL
//
//		return value:
//			on error:
//				E_* 
//			on success:
//				S_OK, S_FALSE
//

#define WTW_FILE_ENCRYPT	L"WTW/FileEncrypt"
#define WTW_FILE_DECRYPT	L"WTW/FileDecrypt"	// not implemented

///////////////////////////////////////////////////////////////////
//
//		WTW_FILE_IS_ENCRYPTED
//
//		wP - const void* - pFileObject
//		lP - NULL
//
//		return value:
//			on error:
//				E_* 
//			on success:
//				S_OK (encrypted), S_FALSE (not encrypted)
//

#define WTW_FILE_IS_ENCRYPTED		L"WTW/FileEncrypt"

///////////////////////////////////////////////////////////////////
//
//		WTW_FILE_GET_SECTOR_SIZE - gets container sector size
//		WTW_FILE_SET_SECTOR_SIZE - sets container sector size (min 256b, max 64k), must be divisible by 16
//
//		wP - wtwFileSize*
//		lP - NULL
//
//		return value:
//			on error:
//				E_* 
//			on success:
//				S_OK, S_FALSE (ok, but encryption is not enabled)
//

#define WTW_FILE_GET_SECTOR_SIZE	L"WTW/FileGetSectSize"
#define WTW_FILE_SET_SECTOR_SIZE	L"WTW/FileSetSectSize"


#endif