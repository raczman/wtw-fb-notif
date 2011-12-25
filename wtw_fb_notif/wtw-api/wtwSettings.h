#ifndef __wtw__settings_h__
#define __wtw__settings_h__

#include "wtwPlugin.h"
#include "wtwPluginSettings.h"

#define WTW_GET_SETTINGS_PTR	L"WTW/GetSettingsPtr"	// zwraca void*, uzywac tak samo 
														// jak wskaznika do opcji wtyczki
														// trzeba tylko znac key'e ktorych
														// uzywa WTW

#define WSK_ENABLE_SPELL_CHECK			L"Main/SpellCheck"
#define WSK_SPELL_CHECK_DEFAULT			0
#define WSK_SPELL_CHECK_LANG			L"Main/SpellCheckLang"
#define WSK_SPELL_CHECK_LANG_DEFAULT	L"pl_PL"
#define WSK_START_MINIMIZED				L"Main/StartMinimized"
#define WSK_START_MINIMIZED_DEFAULT		0
#define WSK_DISABLE_ARCHIVE				L"Main/DisableArch"
#define WSK_DISABLE_ARCHIVE_DEFAULT		0
#define WSK_DISABLE_AUTO_UPDATE			L"Update/Disable"
#define WSK_DISABLE_AUTO_UPDATE_DEFAULT	0
#define WSK_AUTO_UPDATE_ASK				L"Update/AskBeforeDownload"
#define WSK_AUTO_UPDATE_ASK_DEFAULT		0
#define WSK_DISABLE_SMS					L"SMS/Disable"
#define WSK_DISABLE_SMS_DEFAULT			0
#define WSK_AUTO_UPDATE_BETA			L"Update/BetaVersions"
#define WSK_AUTO_UPDATE_BETA_DEFAULT	0
#define WSK_NO_SYS_MESSAGES				L"SYS/NoSysMessages"
#define WSK_NO_SYS_MESSAGES_DEFAULT		0
#define WSK_ADD_WINFW_EXCEPTION			L"SYS/WinFWException"
#define WSK_ADD_WINFW_EXCEPTION_DEFAULT	1

#define WSK_ARCH_WRITE_INFO				L"SYS/ArchWriteInfo"
#define WSK_ARCH_WRITE_INFO_DEFAULT		0
#define WSK_ARCH_WRITE_WARNING			L"SYS/ArchWriteWarn"
#define WSK_ARCH_WRITE_WARNING_DEFAULT	0
#define WSK_ARCH_WRITE_ERRORS			L"SYS/ArchWriteErr"
#define WSK_ARCH_WRITE_ERRORS_DEFAULT	0


#define WSK_DEFAUT_RECV_FILE_PATH			L"P2P/Path"
#define WSK_DEFAUT_RECV_FILE_PATH_DEFAULT	L"%documents%\\Odebrane Pliki\\%from%\\"


#endif