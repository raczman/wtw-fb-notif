WTW-fb-notif
============

Kompilacja
----------

* Najpierw potrzebujesz fejsbukowy token, weŸ to [st¹d](https://www.facebook.com/dialog/oauth?client_id=291081334239552&response_type=token&redirect_uri=http://wtw-notif.herokuapp.com&scope=offline_access,manage_notifications,friends_birthday)
* Otwórz plik fb.h i wklej swój token do ACCESS_TOKEN
* Teraz mo¿esz kompilowaæ.

Prywatnoœæ
----------

Aplikacja WTW-notif nie przechowuje waszych tokenów, i istnieje tylko po to ¿eby móc wygodnie pobraæ token bez babrania siê w tworzenie tokenów w³asnorêcznie. Je¿eli jednak uwa¿asz ¿e chcê ukraœæ Twoje konto, mo¿esz u¿ywaæ wtw-fb-notif bez dawania zezwoleñ WTW-notif. Musisz jedynie utworzyæ swoj¹ aplikacjê na FB, i w analogiczny sposób pobraæ dla niej token z nastêpuj¹cymi uprawnieniami:

* offline_access (¿eby token nie wygasa³)
* manage_notifications (czytanie notyfikacji)
* friends_birthday (urodziny znajomych)