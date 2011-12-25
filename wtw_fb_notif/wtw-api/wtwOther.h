#pragma once

/*******************************************************************************
**
** Function: 
**		WTW_IS_FULLSCREEN_ACTIVE - checks if any fullscreen application is active
**
** Should return: 
**		S_OK (it is), S_FALSE (it is not)
**
** Parameters:
**		wP - NULL
**		lP - NULL
**
*/

#define WTW_IS_FULLSCREEN_ACTIVE		L"WTW/IsFullscreenActive"

/*******************************************************************************
**
** Function: 
**		WTW_IS_SAFE_TO_DISTURB - checks if it's safe to show any notifications
**			takes into account: 
**				* user serrings (to show whatify if any app is in fullscreen mode or not);
**				* if silent mode is active
**
** Should return: 
**		S_OK (safe), S_FALSE (unsafe)
**
** Parameters:
**		wP - NULL
**		lP - NULL
**
*/

#define WTW_IS_SAFE_TO_DISTURB			L"WTW/IsSafeToDisturb"		// returns S_OK (it is safe) or S_FALSE (it's not safe)

#define WTW_DEFAULT_IMAGES_FITER		L"Obrazki|*.jpg;*.jpeg;*.jpe;*.png;*.gif;*.mng|JPEG|*.jpg;*.jpeg;*.jpe|PNG|*.png;*.mng|GIF|*.gif|Wszystkie pliki|*.*||"
#define WTW_DEFAULT_USER_AGENT			L"Mozilla/6.0 (compatile; WTW Network Agent 1.0; U;)"
#define WTW_DEFAULT_CT_GROUP			L"Kontakty"
#define WTW_DEFAULT_CT_OFFLIST_GROUP	L"Spoza listy"

#define WTW_GET_PROFILE_DIR_PTR			L"WTW/GetProfileDirPtr"

#define WTW_GET_UAC_LEVEL				L"WTW/GetUACStatus"

#define UAC_LEVEL_UNKNOWN	0
#define UAC_LEVEL_DISABLED	1
#define UAC_LEVEL_STANDARD	2
#define UAC_LEVEL_ELEVATED	3

#define WTW_QUIT						L"WTW/Quit" // jako wP podajemy QUIT_*

/**
	RESTART i START_CUSTOM s¹ "mutally exclusive", jeœ³i uzyjesz obu to "RESTART" ma priorytet
**/

#define QUIT_RESTART		0x01		// jako wP podane do QUIT spowoduje restart
#define QUIT_START_CUSTOM	0x02		// jako lP podajemy wtedy const wchar_t* zawierajacy sciezke do programu,ktory odpalic po zamknieciu


#define WTW_GET_MAIN_HWND				L"WTW/GetMainHWND"

#define WTW_GET_THEME_COLOR				L"WTW/GetThemeColor"

#define THEME_COLOR_CONTACT_LIST_BG			1

#define THEME_COLOR_CONTACT_NORMAL_BORDER	2
#define THEME_COLOR_CONTACT_NORMAL_BG_START	3
#define THEME_COLOR_CONTACT_NORMAL_BG_END	4
#define THEME_COLOR_CONTACT_NORMAL_TEXT		5
#define THEME_COLOR_CONTACT_NORMAL_TEXT_DSC	6

#define THEME_COLOR_CONTACT_SELECTED_BORDER		7
#define THEME_COLOR_CONTACT_SELECTED_BG_START	8
#define THEME_COLOR_CONTACT_SELECTED_BG_END		9
#define THEME_COLOR_CONTACT_SELECTED_TEXT		10
#define THEME_COLOR_CONTACT_SELECTED_TEXT_DSC	11