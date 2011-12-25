#ifndef _wtw_pl_caps_h_
#define _wtw_pl_caps_h_

#define WTW_CAPS_UNKNOWN	0x0000

#define WTW_CLASS_UNKNOWN	0x0000
#define WTW_CLASS_PROTOCOL	0x0001
#define WTW_CLASS_OTHER		0x0002
#define WTW_CLASS_SMS		0x0003
#define WTW_CLASS_UTILITY	0x0004
#define WTW_CLASS_ARCHIVE	0x0005
#define WTW_CLASS_VOIP		0x0006
#define WTW_CLASS_PROTO_EXT	0x0007
#define WTW_CLASS_MAIL		0x0008	// e-mail support
#define WTW_CLASS_PANEL		0x0009
#define WTW_CLASS_FEED		0x000A	// rss, news feeds, etc, mail notify

#define WTW_CLASS_LAST		0x000B // do not use ;)

#define WTW_PROTO_CAPS2_ENCRYPTION		0x10000000	// szyfrowanie
#define WTW_PROTO_CAPS1_AUTHORIZE		0x00000001	// autoryzacja (logowanie do siecie haslem)
#define WTW_PROTO_CAPS1_MESSAGE			0x00000002	// przesylanie WIADOMOSCI (NIE chat)
#define WTW_PROTO_CAPS1_CHAT			0x00000004	// stream messages, aka chat
#define WTW_PROTO_CAPS1_PRESENCE		0x00000008	// informacje o obesnosci
#define WTW_PROTO_CAPS1_DESCR			0x00000010	// opis do stanu

#define WTW_PROTO_CAPS2_AVATARS			0x20000000	// avatary
#define WTW_PROTO_CAPS2_FT_TRANS		0x40000000	// przesylanie plikow
#define WTW_PROTO_CAPS2_PC_TRANS		0x80000000	// przesylanie obrazkow
#define WTW_PROTO_CAPS2_MSG_FORMAT		0x01000000	// formatowania tekstu
#define WTW_PROTO_CAPS2_TYNT			0x02000000	// powiadomeinei o pisaniu
#define WTW_PROTO_CAPS2_ALERT			0x04000000	// alerty
#define WTW_PROTO_CAPS2_CT_AUTH			0x08000000	// autoryzacja kontaktow
#define WTW_PROTO_CAPS2_SEARCH			0x00100000	// wyszukiwanie / wizytowka

#define WTW_PROTO_CAPS2_INJECT_UTF8		0x00001000	// data injection, UTF8 text
#define WTW_PROTO_CAPS2_INJECT_MBCS		0x00002000	// or in mbcs
#define WTW_PROTO_CAPS2_INJECT_WCHAR	0x00004000	// or as wchars
#define WTW_PROTO_CAPS2_INJECT_BIN		0x00008000	// or as binary data

#define WTW_PROTO_CAPS1_MASK_BASIC		0xFFFFFFFF	// podstawowe
#define WTW_PROTO_CAPS2_MASK_ADVANCED	0xFFFF0000  // zaawansowane funkcje
#define WTW_PROTO_CAPS2_MASK_SPECIAL	0x0000FFFF	// specjalne

#define WTW_PROTO_CAPS2_UTF				0x00200000	// obsluga UTF/Unicode

#endif