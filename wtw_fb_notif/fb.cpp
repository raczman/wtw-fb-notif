#include "stdinc.h"
#include "fb.h"
#include "http.h"
#include <wtwTrayNotify.h>
#include <wtwLog.h>
#include <winhttp.h>
#include <string>
#include <sstream>
#include "JSON.h"

using namespace std;

HANDLE thr;
wchar_t *timer_id = L"FB_TIMER";

WTW_PTR click_notif_cb(WTW_PARAM wp, WTW_PARAM lp)
{
	wtwTrayNotifyEvent *evt = (wtwTrayNotifyEvent*)wp;
	switch(evt->event)
	{
	case WTW_TN_EVENT_LCLICKED:
		ShellExecute(NULL, L"open" ,((wstring*)(evt->ownerData))->c_str(), NULL, NULL, 0);
		break;
	case WTW_TN_EVENT_DESTROYED:
		//XXX: CRT dalej pluje o wyciek, nie wiem dlaczego.
		delete ((wstring*)evt->ownerData);
		break;
	default:
		break;
	}
	return 0;
}


JSONValue* fql_query(const wchar_t* query)
{
	wstring url = L"https://graph.facebook.com/fql?q=";
	url += query;
	url += L"&access_token=";
	url += ACCESS_TOKEN;

	WinHttpClient *cl = new WinHttpClient(url);
	cl->SendHttpRequest();
	LOG(url.c_str());
	LOG(cl->GetHttpResponse().c_str());
	JSONValue *j = JSON::Parse(cl->GetHttpResponse().c_str());

	delete cl;
	return j;
}

DWORD WINAPI notif_thread(LPVOID)
{
	JSONValue *j = fql_query(L"select+title_text%2c+href%2c+icon_url+from+notification+where+recipient_id+%3d+me()+and+is_unread");
	if(j && j->IsObject())
	{
		JSONObject obj = j->AsObject();
		JSONArray data = obj[L"data"]->AsArray();
		for(JSONArray::const_iterator i = data.begin();i != data.end();i++)
		{
			if(!((*i)->IsObject()))
				continue;
			JSONObject i_obj = (*i)->AsObject();
			wstring href, title_text;
			href = i_obj[L"href"]->AsString();
			title_text = i_obj[L"title_text"]->AsString();
			display_notif(wstring(L"Facebook Notification"), title_text, href);	
		}
		delete j;
	}
	return 0;
}

DWORD WINAPI bday_thread(LPVOID)
{
	SYSTEMTIME st;
	GetSystemTime(&st);
	wostringstream q;
	q << L"SELECT+name%2c+profile_url+from+user+where+uid+in+(select+uid2+from+friend+where+uid1+%3d+me())+and+strpos(birthday_date%2c%22";
	q << (st.wMonth);
	q << L"%2f";
	q << (st.wDay);
	q << L"%22)%3e%3d0";
	wstring fql = q.str();

	JSONValue *j = fql_query(fql.c_str());

	if(j)
	{
		
		JSONObject obj = j->AsObject();
		JSONArray data = obj[L"data"]->AsArray();
		for(JSONArray::const_iterator i = data.begin();i != data.end();i++)
		{
			JSONObject i_obj = (*i)->AsObject();
			wstring name = i_obj[L"name"]->AsString();
			name += L" ma urodziny!";
			wstring url = i_obj[L"profile_url"]->AsString();
			display_notif(wstring(L"Facebook Urodziny"), name, url);
		}
		delete j;
	}
	return 0;
}

WTW_PTR timer_expire(WTW_PARAM, WTW_PARAM)
{
	thr = CreateThread(NULL, 0, notif_thread,0,0,0);
	return 0;
}

void display_notif(wstring& main, wstring& lower, wstring& url)
{

	wtwTrayNotifyDef d;
	d.structSize = sizeof(wtwTrayNotifyDef);
	d.classType = WTN_CLASS_WARNING;
	d.textLower = lower.c_str();
	d.textMain = main.c_str();

	//XXX: cbData nie bangla, ale to dzia³a.
	d.ownerData = new wstring(url);
	d.callback = (WTWFUNCTION)click_notif_cb;
	wtw->fnCall(WTW_SHOW_STANDARD_NOTIFY, (WTW_PTR)&d, 0);
}