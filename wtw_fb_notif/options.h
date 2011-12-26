#include <wtwOptions.h>

static const wchar_t* page_id = L"FB/Options";

WTW_PTR settings_callback(WTW_PARAM, WTW_PARAM);
void init_settings();
void remove_settings();

/*
		ShellExecute(0,L"https://www.facebook.com/dialog/oauth?client_id=291081334239552&response_type=token&redirect_uri=http://wtw-notif.herokuapp.com&scope=offline_access,manage_notifications,friends_birthday",0,0,0,0);
		*/