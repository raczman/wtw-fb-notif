#pragma once

#include "wtwPlugin.h"

#define WTW_CRYPTO_HASH_SIMPLE		L"Crypto/GenSimpleHash"

#define	WTW_CRYPTO_HASH_TYPE_MD5		0x0001	// req hash (len) = 16 for binary hash, 33 for UTF-8, and 66 for wchar_t*
#define	WTW_CRYPTO_HASH_TYPE_SHA1		0x0002	// req hash (len) = 20 for binary hash, 41 for UTF-8, and 82 for wchar_t*
#define	WTW_CRYPTO_HASH_TYPE_SHA256		0x0003	// req hash (len) = 32 for binary hash, 65 for UTF-8, and 130 for wchar_t*
#define	WTW_CRYPTO_HASH_TYPE_SHA512		0x0004	// req hash (len) = 64 for binary hash, 129 for UTF-8, and 258 for wchar_t*
#define	WTW_CRYPTO_HASH_TYPE_CRC32		0x0005	// req hash (len) = 4 for binary hash, 9 for UTF-8, and 18 for wchar_t*
#define	WTW_CRYPTO_HASH_TYPE_CRC64		0x0006	// req hash (len) = 8 for binary hash, 17 for UTF-8, and 34 for wchar_t*

#define WTW_CRYPTO_HASH_FLAG_OUT_BINARY		0x0001
#define WTW_CRYPTO_HASH_FLAG_OUT_UTF8		0x0002
#define WTW_CRYPTO_HASH_FLAG_OUT_WCHAR		0x0004

struct wtwHashData
{
	__wtwStdStructDefs(wtwHashData);

	int				structSize;

	const void *	pDataToHash;
	DWORD			nDataToHash;

	DWORD			hashType;

	void *			hash;
	DWORD			hashLen;

	DWORD			flags;
};

#define WTW_CRYPTO_AES_EXPAND_KEY	L"Crypto/ExpandAESKey"	// returns pointer to expanded key, has to be freed with AES_FREE_KEY
#define WTW_CRYPTO_AES_FREE_KEY		L"Crypto/FreeAESKey"
#define WTW_CRYPTO_AES_ENCRYPT		L"Crypto/AESEncrypt"
#define WTW_CRYPTO_AES_DECRYPT		L"Crypto/AESDecrypt"

struct wtwAESKeyInfo
{
	__wtwStdStructDefs(wtwAESKeyInfo);

	int				structSize;

	const BYTE	*	key;
	int				keySize;		// in BITS ! valid sizes are: 128 bits and 256 bits (16 bytes and 32 bytes)

	DWORD			flags;			// WTW_CRYPTO_AES_KEY_FLAG_*
};

#define WTW_CRYPTO_AES_KEY_FLAG_ENCRYPTION 0x0001
#define WTW_CRYPTO_AES_KEY_FLAG_DECRYPTION 0x0002

struct wtwCryptoData
{
	__wtwStdStructDefs(wtwCryptoData);

	int				structSize;

	const void *	pData;			// encrypted/decrypted in place, must be padded to 16 bytes
	DWORD			nData;

	void *			ivec;			// required for cbc mode (in/out, 16 bytes)

	void *			expandedKey;	// pointer to expanded key

	DWORD			flags;			// WTW_CRYPTO_AES_FLAG_*
};

#define WTW_CRYPTO_AES_FLAG_MODE_CBC	0x0001
#define WTW_CRYPTO_AES_FLAG_MODE_ECB	0x0002
#define WTW_CRYPTO_AES_FLAG_PADDING		0x0004 // not implemented