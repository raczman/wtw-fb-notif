#include <wtwOptions.h>
#include <string>

using namespace std;

static const wchar_t* page_id = L"FB/Options";

WTW_PTR settings_callback(WTW_PARAM, WTW_PARAM);
void init_settings();
void remove_settings();

#define tokenSetting L"FB\\Token"
wstring& get_token();