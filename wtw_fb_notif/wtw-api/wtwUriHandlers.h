#pragma once

#include "wtwPlugin.h"

struct wtwSchemeBinding
{
	__wtwStdStructDefs(wtwSchemeBinding);

	int				structSize;

	const wchar_t * uriScheme;	// to jest wymagne (dla http://www.costam tu pdajemy "http"
	const wchar_t * netClass;	// to nie jest wymagane jesli podalismy callback, jesli callbacka niema to tu podajemy protokol z ktorym rozpocac rozmowe jak cos

	WTWFUNCTION		callback;	// callback, moze byc null jesli podalismy netId a scheme jest "normalny", aka "cos://cosinnego?parametr=cos" jak jest nienormalny, to wtedy powinnismy zareagowac na ever _FORMAT
	void *			cbData;		// trzeci parametr do callbacka
};

#define SB_EVENT_NEW_URI	0x01

#define SBE_FORMATTED		0x01
#define SBE_BLOCKED			0x02
#define SBE_INVALID			0x03

struct wtwSchemeEvent
{
	__wtwStdStructDefs(wtwSchemeEvent);

	int				structSize;

	int				event;

	const wchar_t * uriProtocolPart;
	const wchar_t * uriScheme;

	const wchar_t * netClass;

	wchar_t			contactId[255];	// tu podajemy kontakt,z ktorym okno rozmowy mabyc otwarte, jesli to jest potrzebneno i zwracamy _FORMATTED
	
};

#define WTW_SCHEME_REGISTER		L"WTW/RegisterScheme"		// wP - wtwSchemeBinding*
#define WTW_SCHEME_UNREGISTER	L"WTW/UnregisterScheme"		// wP - const wchar_t* - scheme