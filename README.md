# Methods-of-Software-Engineering-2-HW1
homework 1, c++

Methoden der Spieleentwicklung I (100%)

Nach den ersten zwei Semestern Ihres DiBSE-Studiums wittern Sie das große Geld in der Spieleentwicklungs-Industrie. Nach einigen theoretischen Grundlagen aus den Vorlesungen Programmiertechnik und Methoden der Softwareentwicklung I fühlen Sie sich selbstsicher genug, um die Idee praktisch in die Tat umzusetzen. Bevor Sie allerdings Ihr eigenes, innovatives Projekt angehen können, versuchen Sie sich an einem Klassiker - einem Fantasy-Rollenspiel, welches im frühen Mittelalter spielt.
Sie haben gehört, dass viele Computerspiele in C++ programmiert wurden und wollen daher Ihr Spiel auch in C++ entwicklen. Da trifft es sich gerade gut, dass Sie in Methoden der Softwareentwicklung II C++ lernen.
Um Investoren von Ihrer Spieleidee begeistern zu können, brauchen Sie jetzt aber schnellstmöglichst einen Prototypen. Sie können nicht warten, bis Sie die grundlegenden Konzepte der objektorientierten Programmierung in C++ gelernt haben. Daher müssen Sie für diesen ersten Prototypen noch auf das in Methoden der Softwareentwicklung I erlernte Wissen aufbauen und den Prototypen quasi wie ein C-Programm implementieren. Erst für spätere Versionen können Sie dann auf objektorientierte Konzepte zurückgreifen.

Das Konzept des Spiels wird in den folgenden Absätzen genauer erörtert:
Eine Protagonistin (Heldin) erkundet im Alleingang das Land und erlebt dabei gefährliche Abenteuer. Beispielsweise kämpft sie regelmäßig gegen feindlich gesinnte Charaktere. Der rundenbasierte Kampf dauert solange, bis eine(r) der Beteiligten keine Lebenspunkte übrig hat - also ohnmächtig wird. Die Heldin, wie auch gegnerische Charaktere besitzen einen Namen (Zeichenfolge), Lebenspunkte, einen bestimmten Betrag an Gold und ein Inventar, welches aus bis zu 10 (zehn) Gegenständen besteht. Jeder Gegenstand besitzt eine Bezeichnung (Zeichenfolge) und einen Wert (in Gold), für den unsere Heldin den Gegenstand verkaufen kann.


Erstellen Sie in einem ersten, rudimentären Prototyp drei structs für:
	• Hero_t: Repräsentiert die Heldin und besitzt einen Namen, Lebenspunkte, Gold, ein Inventar aus Gegenständen (max. 10) und eine Ausrüstung aus Gegenständen (max. 2).
	• Character_t: Repräsentiert andere Charaktere und besitzt einen Namen, Lebenspunkte, Gold und ein Inventar aus Gegenständen (max. 10).
	• Item_t: Repräsentiert einen Gegenstand und besitzt eine Bezeichnung, sowie einen Wert. Außerdem soll ein Attribut boolean isValid hinzugefügt werden, welches anzeigt, ob eine Instanz dieser Struktur überhaupt einen gültigen Gegenstand repräsentiert - dies wird vor allem für die Initialisierung bzw. Löschung von Gegenständen benötigt (Löschung aus Inventar => isValid wird auf false gesetzt)!


Um dem Konzept Leben einzuhauchen sollen die verschiedenen Elemente des Spiels auch miteinander interagieren können. Implementieren Sie daher folgende Funktionen:
	• Für die Heldin:
		○ void attack(Hero_t* hero, Character_t* enemy): Die Heldin greift einen spezifizierten Gegner an und reduziert dessen Lebenspunkte zufällig um einen Wert zwischen 15 und 25 (siehe Funktion rand()).

		○ void sellItem(Hero_t* hero, int index): Verkauft einen Gegenstand an der spezifizierten Stelle im Inventar (überprüfen Sie, ob an dieser Stelle ein Gegenstand existiert! Hinweis: isValid) um dessen Wert. Dieser Betrag wird natürlich zum Gold der Heldin addiert.
		○ bool fight(Hero_t* hero, Character_t* enemy): Simuliert einen Kampf zwischen der Heldin und einem Feind, der aus mehreren Runden besteht. In jeder Runde wird zuerst die attack()-Funktion der Heldin und dann die entsprechende Funktion des Feindes aufgerufen, solange bis die Heldin oder der Feind keine Lebenspunkte mehr übrig hat. Der Rückgabewert ist true wenn die Heldin gewinnt, ansonsten false.
	• Für Charaktere:
		○ void attack(Character_t* character, Hero_t* hero): Der Charakter greift die spezifizierte Heldin an und reduziert deren Lebenspunkte zufällig um einen Wert zwischen 5 und 15.

Da sich die Initialisierung mehrerer Heldinnen, Charakere oder Gegenstände sehr mühsam gestaltet, sollen außerdem die vier Hilfsfunktionen erstellt werden:
	• void initHero(Hero_t* hero, char* name, int health, int gold): diese Funktion weist einer Heldin den übergebenen Namen, Lebenspunkte und Goldbetrag zu. Außerdem wird das Attribut isValid aller Inventar- und Ausrüstungsgegenstände auf false gesetzt.

	• void initCharacter(Character_t* character, char* name, int health, int gold): diese Funktion weist einem Charakter den übergebenen Namen, Lebenspunkte und Goldbetrag zu. Außerdem wird das Attribut isValid aller Inventargegenstände auf false gesetzt.

	• void initItem(Item_t* ITEM, char* name, int gold): diese Funktion weist einem übergebenen Gegenstand den übergebenen Namen und den übergebenen Wert zu. Außerdem wird das Attribut isValid auf true gesetzt!
	• void initItem(Item_t* gegenstand): diese Funktion setzt das Attribut isValid des übergebenen Gegenstands auf false.


Schreiben Sie nun ein kleines Testprogramm, bei welchem eine 

Heldin mit 300 Lebenspunkten erst gegen einen Charakter mit 50 Lebenspunkten und danach gegen einen Charakter mit 100 Lebenspunkten kämpft.

Nach jedem gewonnen Kampf fügen Sie einen beliebigen Gegenstand als Beute ins Inventar der Heldin ein.

Ganz am Ende verkauft die Heldin die gewonnenen Gegenstände, falls sie noch am Leben ist.

Verwenden Sie in Ihrem Programm bevorzugt C++ Konstrukte (z.B. std::cout anstatt printf). 

Verwenden Sie außerdem für jede struct und die dazugehörigen Funktionen eine eigene Quellcodedatei mit einer dazugehörigen Headerdatei. Der Name dieser Quellcodedateien sollte hero.{h, cpp}, character.{h, cpp} und item.{h, cpp} lauten. Die main-Funktion sollte in der Datei main.cpp zu finden sein.

Achtung: Erstellen Sie Ausgaben für alle Aktivitäten, ein beispielhafter Ablauf sollte in etwa so aussehen:
(Name der Heldin: Annina; Namen der Gegner: Matthias & Pascal)

Annina trifft Matthias fuer 20 Lebenspunkte! 
Matthias trifft Annina fuer 5 Lebenspunkte! 
Annina trifft Matthias fuer 20 Lebenspunkte! 
Matthias trifft Annina fuer 5 Lebenspunkte! 
Annina trifft Matthias fuer 20 Lebenspunkte! 
Matthias fiel in Ohnmacht! Annina hat noch 190 Lebenspunkte uebrig! 
Gegenstand Zaubertrank wurde zum Inventar der Heldin hinzugefügt. 
Annina trifft Pascal fuer 20 Lebenspunkte! 
Pascal trifft Annina fuer 5 Lebenspunkte!
Annina trifft Pascal fuer 20 Lebenspunkte! 
Pascal trifft Annina fuer 5 Lebenspunkte! 
Annina trifft Pascal fuer 20 Lebenspunkte! 
Pascal trifft Annina fuer 5 Lebenspunkte! 
Annina trifft Pascal fuer 20 Lebenspunkte! 
Pascal trifft Annina fuer 5 Lebenspunkte! 
Annina trifft Pascal fuer 20 Lebenspunkte! 
Pascal fiel in Ohnmacht! Annina hat noch 170 Lebenspunkte uebrig! 
Gegenstand Schwert wurde zum Inventar der Heldin hinzugefügt.
Gegenstand Zaubertrank wurde verkauft. Annina besitzt nun 250 Gold. 
Gegenstand Zaubertrank wurde verkauft. Annina besitzt nun 280 Gold.


