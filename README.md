WTW-fb-notif
============

Kompilacja
----------

* Najpierw potrzebujesz fejsbukowy token, we� to [st�d](https://www.facebook.com/dialog/oauth?client_id=291081334239552&response_type=token&redirect_uri=http://wtw-notif.herokuapp.com&scope=offline_access,manage_notifications,friends_birthday)
* Otw�rz plik fb.h i wklej sw�j token do ACCESS_TOKEN
* Teraz mo�esz kompilowa�.

Prywatno��
----------

Aplikacja WTW-notif nie przechowuje waszych token�w, i istnieje tylko po to �eby m�c wygodnie pobra� token bez babrania si� w tworzenie token�w w�asnor�cznie. Je�eli jednak uwa�asz �e chc� ukra�� Twoje konto, mo�esz u�ywa� wtw-fb-notif bez dawania zezwole� WTW-notif. Musisz jedynie utworzy� swoj� aplikacj� na FB, i w analogiczny spos�b pobra� dla niej token z nast�puj�cymi uprawnieniami:

* offline_access (�eby token nie wygasa�)
* manage_notifications (czytanie notyfikacji)
* friends_birthday (urodziny znajomych)