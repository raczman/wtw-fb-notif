#pragma once

#define WTW_PF_GET_CONTACT_VCARD L"PFGetContactVCard" // wP - wtwVCardInfo*

struct wtwVCardInfo 
{
	__wtwStdStructDefs(wtwVCardInfo);

	int				structSize;

	void *			userPointer;
	wtwContactDef	contactData; // tylko dla vcardow userow
};

#define WTW_PF_GET_MY_VCARD		L"PFGetMyVCard" // wP - wtwVCardInfo*
#define WTW_PF_SET_MY_VCARD		L"PFSetMyVCard" // wP - wtwVCardInfo*

#define WTW_PF_GET_MY_AVATAR	L"PFGetMyAvatar" // wP - wtwVCardInfo*
#define WTW_PF_SET_MY_AVATAR	L"PFSetMyAvatar" // wP - wtwVCardInfo*

struct wtwVCardElement 
{
	__wtwStdStructDefs(wtwVCardElement);

	int				structSize;

	const wchar_t * name;
	const wchar_t * value;
	
	int				type;

	void		  * userPointer;
};

struct wtwVCardStatus 
{
	__wtwStdStructDefs(wtwVCardStatus);

	int				structSize;

	const wchar_t * statusText;
	int				statusMode; // 0/1
	
	void		  * userPointer;
};

#define VCT_STATIC_TEXT	0x00
#define VCT_SEPARATOR	0x01
#define VCT_PICTURE		0x02

#define WTW_VCARDWND_FUNC_ADDELEMENT	L"VCard/AddElement"
#define WTW_VCARDWND_FUNC_CLEAR			L"VCard/Clear"			// wP - userPointer
#define WTW_VCARDWND_FUNC_SETSTATUS		L"VCard/SetStatus"

/////////////////////////////////////////////////////////////

struct wtwMyVCardField 
{
	__wtwStdStructDefs(wtwMyVCardField);

	int				structSize;

	const wchar_t * name;
	wchar_t		*	value;
	int				maxSize;

	void		  * userPointer;
};

#define MVC_NAME_FIRST_NAME L"name"
#define MVC_NAME_SURNAME	L"surname"
#define MVC_NAME_NICK_NAME	L"nick"
#define MVC_NAME_WWW		L"www"
#define MVC_NAME_BIRTH		L"birth"
#define MVC_NAME_TITLE		L"title"
#define MVC_NAME_ROLE		L"role"
#define MVC_NAME_EMAIL		L"email"

#define WTW_MYVCARD_FUNC_GETFIELDVALUE		L"MyVCard/GetFieldValue"
#define WTW_MYVCARD_FUNC_SETFIELDVALUE		L"MyVCard/SetFieldValue"

struct wtwMyVCardStatus 
{
	__wtwStdStructDefs(wtwMyVCardStatus);

	int				structSize;

	const wchar_t * statusText;
	void		  * userPointer;

	const wchar_t * netClass;
	int				netId;
};


#define WTW_MYVCARD_FUNC_SETSTATUS			L"MyVCard/SetStatus"
#define WTW_MYVCARD_FUNC_SIGNAL_BUSYNESS	L"MyVCard/SignalBusyness" // wP = 1 zajety, 0 - wolny