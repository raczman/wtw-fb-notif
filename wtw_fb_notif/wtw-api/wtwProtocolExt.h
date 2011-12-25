#ifndef __wtw__protocol_ext_h__
#define __wtw__protocol_ext_h__

#include "wtwProtocol.h"

struct wtwGgExtInfoV1 
{
	__wtwStdStructDefs(wtwGgExtInfoV1);

	int		structSize;

	DWORD	features;
	DWORD	ipAddress;
	DWORD	imageSize;
	DWORD	ipPort;
	DWORD	flags;
};

struct wtwTlenExtInfoV1 
{
	__wtwStdStructDefs(wtwTlenExtInfoV1);

	int				structSize;

	int				possiblyHidden;
	const wchar_t * avatarHash;
};

struct wtwXMPPExtInfoV1 
{
	__wtwStdStructDefs(wtwXMPPExtInfoV1);

	int				structSize;

	int				priority;
	const wchar_t * avatarHash;
	const wchar_t * lang;
};

#endif