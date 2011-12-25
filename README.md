WTW-fb-notif
============

Kompilacja
----------

* Najpierw potrzebujesz fejsbukowy token, weź to [stąd](https://www.facebook.com/dialog/oauth?client_id=291081334239552&response_type=token&redirect_uri=http://wtw-notif.herokuapp.com&scope=offline_access,manage_notifications,friends_birthday)
* Otwórz plik fb.h i wklej swój token do ACCESS_TOKEN
* Teraz możesz kompilować.

Prywatność
----------

Aplikacja WTW-notif nie przechowuje waszych tokenów, i istnieje tylko po to żeby móc wygodnie pobrać token bez babrania się w tworzenie tokenów własnoręcznie. Jeżeli jednak uważasz że chcę ukraść Twoje konto, możesz używać wtw-fb-notif bez dawania zezwoleń aplikacji WTW-notif. Musisz jedynie utworzyć swoją aplikację na FB, i w analogiczny sposób pobrać dla niej token z następującymi uprawnieniami:

* offline_access (żeby token nie wygasał)
* manage_notifications (czytanie notyfikacji)
* friends_birthday (urodziny znajomych)

Jak utworzyć aplikację i pobrać dla niej token, zostawiam jako ćwiczenie dla czytającego.

Bugi
----

W cholerę i jeszcze trochę. Jako że API WTW ma swoje zawiłości, są rzeczy które nie działają, albo mogą wysypywać komunikator. Z dziką rozkoszą przyjmę patche.

Licencja
--------

Róbcie z tym co chcecie, nie zezwalam tylko na sprzedaż pluginu, kodu źródłowego, oraz produktów pochodnych. 