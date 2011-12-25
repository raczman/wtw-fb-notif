#include <string>

using namespace std;

extern wchar_t *timer_id;

#define ACCESS_TOKEN L"PYSZNY TOKEN OM NOM NOM";
#define INTERVAL 60 * 1000;

WTW_PTR timer_expire(WTW_PARAM, WTW_PARAM);
DWORD WINAPI bday_thread(LPVOID);
void get_birthday();
void display_notif(wstring&, wstring&, wstring&);
wstring request(wchar_t*);

