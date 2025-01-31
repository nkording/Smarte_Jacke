# Smarte Jacke

### Die Entwicklung und Konstruktion, sowie die Herstellung des Prototyps erfolgte im Rahnen einer Bachelorarbeit an der Hochschule Osnabrück.

Die Smarte Jacke erlaubt es jedem seine eigene Jacke in eine Smarte Jacke upzugraden. Zu den smarten Funktionen gehören eine Sturzerkennung, ein Panikknopf, ein visueller und akustischer Alarm und eine automatische SMS an einen Notfallkontakt. Diese Funktionen werden durch zwei Komponenten zur Verfügung gestellt: einer App und der Elektronik, die an der Jacke angebracht ist.

![Gesamt_System_angpasst](https://github.com/user-attachments/assets/09fd7166-fc83-4f94-bfb2-4c09d1a11bb1)

Die Komponenten für die Elektronik sind im Einzelhandel erhältlich. Zum Zusammenbau werden Grundkenntnisse in verschiedenen Bereichen benötigt: im Nähen, in der Programmierung und im Löten. Abseits davon ist der Zusammenbau durch einfache Mittel möglich. Zu den Komponenten gehören: ein Arduino Nano RP2040 Connect, ein Active Buzzer, eine High-Power LED und eine PMMA-Faser. 

Die smarte Jacke kann beim Gehen und Fahrradfahren einen Sturz erkennen und einen Alarm mit Licht und Lärm erzeugen sowie einem Notfallkontakt eine SMS schicken. Des Weiteren kann der Alarm auch über einen Taster aktiviert werden und so als Panikknopf verwendet werden.

![Open_Source](https://github.com/user-attachments/assets/ad399da7-2061-448f-ab3d-4f410a5f36d8)


# Montageanleitung

### Folgendes Werkzeug wird für den Zusammenbau der smarten Jacke benötigt: 

- Bohrmaschine mit Studenbohrer 4-20 mm, Spiralbohrer 4 mm, Spiralbohrer 8 mm
- Bleistift
- Lineal
- Seitenschneider
- Abisolierzange (Alternative: Messer, Schere)
- Lötkolben und Lötzinn
- Allesklaber
- Textilkleber
- Isolierband
- Nadel und Faden
- Schere
- Kreide
- Kreuzschlitz-Schraubenzieher PH 1x80 mm
- Präzisionsschraubenzieher PH 2.0
- Schleifpapier und Schlüsselpfeile Durchmesser < 4 mm
- USB-Kabel Mikro
### Aufbauanleitung:
Zusätzlich zu den Teilen aus der Teileliste wird eine Jacke gebraucht. Die Jacke benötigt Taschen, die groß genug sind, um den ABS-Kasten und den Batteriehal-ter zu beinhalten.

1.	Die App „Smarte_Jacke“ wird aus dem Github-Repository heruntergeladen und auf dem Handy installiert. Zudem werden der App beim ersten Starten die Berechtigungen für das Finden und Verbinden mit Bluetooth-Geräten, die Standorterfassung und das Versenden von SMS gegeben.

2.	Die Software „Arduino IDE“ wird von Arduino auf den PC heruntergeladen und das Board „Arduino Mbed OS Nano Boards“ mit dem Board Manager installiert. Zusätzlich müssen die Bibliotheken „ArduinoBLE“ und „Ardui-no_LSM6DSOX“ im Library Manager installiert werden. Danach kann das Arduino Programm „Smarte_Jacke_V4_Final“ aus dem Github-Repository heruntergeladen werden und mit dem USB-Kabel auf den Arduino Nano RP2040 Connect geladen werden.

![Löcher_Deckel_angepasst](https://github.com/user-attachments/assets/8fb28eca-336b-4476-9e23-2c978ca4853e)

3.  Der ABS-Kasten wird mit Löchern entsprechend den Bildern ausgestattet, dabei erfolgt die Längenangabe in Millimeter. Nach dem Bohren werden die Lochränder mit dem Schleifpapier und der Schlüsselpfeile geglättet. Die Löcher an der Seite wurden mit einem Spiralbohrer gebohrt und die Öff-nung zum oberen Rand mit demselben Bohrer gefräst, indem der Bohrer Der ABS-Kasten wird mit Löchern entsprechend den Bildern ausgestattet, dabei erfolgt die Längenangabe in Millimeter. Nach dem Bohren werden die Lochränder mit dem Schleifpapier und der Schlüsselpfeile geglättet. Die Löcher an der Seite wurden mit einem Spiralbohrer gebohrt und die Öff-nung zum oberen Rand mit demselben Bohrer gefräst, indem der Bohrer bei hoher Drehzahl zum oberen Rand gedrückt wurde. Die beiden großen linken Löcher auf dem Deckel sind für den Adapter und die Feststell-schraube, die kleineren Löcher unten rechts für den „Active Buzzer“ und den Widerstand. Die Schlitze an der kurzen Seite sind für die Kabel des Tasters und an der langen Seite für die Kabel der Stromversorgung. Die rechteckige Öffnung im Deckel ist für den MOSFET. Diese kann durch das Bohren von zwei Löchern mit je ø 4 mm und dem anschließenden Verbin-den der Löcher geschaffen werden. Alternativ kann der MOSFET auch durch ein Modell in kleinerem Gehäuse, wie z.B. TO-92, oder durch ein Modell mit 90° gebogenen Beinen ersetzt werden. Sollte der MOSFET durch einen anderen ersetzt werden, muss auf die richtigen Betriebspara-meter geachtet werden. Zu diesen gehören unter anderem ein komplettes Durchschalten des MOSFETs bei 3,3 V Steuerspannung und ein erlaubter Strom von min. 350 mA. Durch das Ersetzen des MOSFET würde keine rechteckige Öffnung mehr benötigt werden. Da die Löcher über gewisse elektronische Komponenten positioniert sein müssen, empfiehlt es sich die Leiterplatte mit den Komponenten zu bestücken und zu prüfen, ob die Positionen der Löcher passen.

![Löcher_Seite_angepasst](https://github.com/user-attachments/assets/a603af9e-bb8f-4258-a86f-26adfbad568a)

4.  Es wird ein Stoffband (Breite 2,6 cm) von außen parallel zur langen Seite des Kastens auf den Boden gelegt und so zugeschnitten, dass noch genug Stoff übersteht, damit an jedem Ende ein Druckknopf (ø 11 mm) angenäht werden kann. Eine mögliche Länge wären 16 cm. Dann werden die Druck-knopf-Hälften auf der Unterseite angenäht.

5.  Die anderen Druckknopf-Hälften werden in der rechten Tasche angenäht, sodass der Kasten beim geraden Hängen der Jacke senkrecht steht.

6.  Die Kastenhülle wird, wie zuvor beschrieben mit Alleskleber an den Stoff-streifen angeklebt. Zu diesen Zeitpunkt bietet sich an zu überprüfen, ob die Knöpfe beim Zusammenführen den Kasten fixieren. Sollten die Knöpfe in der Jackentasche zu weit auseinander oder zu nah beieinander liegen, müssen die Positionen dieser angepasst werden. Ideal ist eine Position der Knöpfe, bei der das Stoffband nicht zu stark gestreckt und auch nicht zu stark gestaucht ist. 

7.  Nun wird mit Kreide auf der Jacke die Positionen der Schlaufen markiert, die die PMMA-Faser führen. Die Strecke der Führung ist von den eigenen Wünschen abhängig. Eine mögliche Führung wäre: Beginn bei der rechten Jackentasche außen, gerade hoch zur Schulter, über die Schulter auf den Rücken, auf dem Rücken S-förmig runter und gespiegelt zur anderen Schulter hoch, über die linke Schulter wieder auf die Vorderseite und dann gerade runter zur linken Jackentasche. Diese Strecke ist auch im Bild zu sehen. Das Stoffband wird in 3 cm lange Streifen geschnitten, welche dann zu Schlaufen umgelegt werden. Die Menge an Schlaufen hängt von der gewählten Strecke und PMMA-Faser ab, hier waren es 15 Stück. Dann werden die Schlaufen an den markierten Stellen angenäht.

![PMMA-Faser_Jacke_angepasst](https://github.com/user-attachments/assets/31cb78a6-239d-4ddb-bc49-6d087d7a4300)

8.	Taster-Beinchen flach biegen und ihn so ausrichten, dass jeweils zwei Beinchen nach oben und zwei nach unten zeigen. Unten links wird eine ro-te Litze (+), unten rechts eine schwarze (-) und oben rechts wieder eine ro-te Litze (Pin) angelötet. Die Litzen sollten jeweils ca. 1 m lang sein. Die Stellen mit blankem Draht und die Beinchen des Tasters mit Isolierband abkleben.

9.	Einen 6 cm langen Stoffstreifen abschneiden, auf dem der Taster und zwei Druckknöpfe Platz haben. Druckknöpfe an beiden Enden annähen.

10. Im rechten Ärmel die anderen Hälften der Druckknöpfe annähen. Dabei sollte darauf geachtet werden, dass die Stelle mit den Fingern erreichbar ist, da hier später der Panikknopf sitzt. Es bietet sich die Position am inne-ren Ärmel an, wie im Bild zu sehen.

![Taster_am_Ärmel_angepasst](https://github.com/user-attachments/assets/dbe05513-2c3e-4d6d-8e07-e237f86fa11b)

11. Den Taster auf den Stoffstreifen mit Alleskleber befestigen. Die Kabel nach unten führen und mit Isolierband am Stoffstreifen fixieren. 

12.	Die „Female-to-Male“ Jumperkabel werden in der Mitte durchgeschnitten und an die anderen Enden der Taster Kabel werden die männlichen „Du-pont“-Stecker angelötet.

13.	Auf der Innenseite des rechten Ärmels und der Innenseite der Jacke wer-den drei Stoffstreifen mit je 9 cm senkrecht angenäht. Die Nähte sollen da-bei an den Rändern der langen Seiten gesetzt werden, sodass eine Art Tunnel von einer kurzen Seite zur anderen entsteht. Diese Tunnel dienen als Kabelführung der Kabel zum Kasten in der rechten Jackentasche. Da-bei ist darauf zu achten, dass die Kabelführungen nicht zu lang sind, da sonst das Durchführen der Kabel zu schwierig ist.

14. An den Arduino werden die Stiftleisten nach oben zeigend angelötet, also zeigen die Stifte auf den Betrachter, wenn dieser den Reset-Knopf sieht. Die beiden 16er Buchsenleisten werden um eine Buchse gekürzt.

![Schaltplan drawio](https://github.com/user-attachments/assets/649bd7c1-be0f-4872-b534-d5962d12311c)

15. Die Schaltung wird auf der Lochrasterplatine nach dem Schaltplan, bis auf die High-Power LED und den Taster angebracht. Dabei werden für die Lei-tungen des Tasters die Kabel der weiblichen Hälfte der Jumperkabel ange-lötet. Das andere Bild zeigt die Rückseite der Lochrasterplatine. Dabei steht jede Kreuzung im Gitternetz für ein Loch der Platine und die gestri-chelte Linie zeigt die äußerste Lochreihung der Platine. Die dicken Punkte stehen für angelötete Durchsteckkontakte und die durchgängigen schwar-zen Linien für Leitungen zwischen den Punkten, die durch den Silberdraht realisiert werden. Dabei bilden die beiden Reihen an schwarzen Punkten oben links im Bild den Sockel des Arduinos, welcher aus zwei 15er Buch-senleisten besteht. Die grauen Bauteile stehen für die Komponenten, die durch die Vorderseite durchgesteckt und angelötet wurden. Dabei stehen die kurvigen grauen Linien für die Kabel, welche von der Vorderseite aus durchgesteckt wurden.

![Leitungsplan drawio](https://github.com/user-attachments/assets/44c5d9c3-291b-4a95-9ee2-600de8d853c9)

16.	An Star-platine der High-Power LED werden eine rote (+) und schwarze (-) Litze angebracht, diese dienen der Stromversorgung. Die High-Power LED wird auf dem Kühlkörper mit dem Adapter mit dem Präzisionsschrauben-zieher angeschraubt. Dann werden die Litzen an die restliche Schaltung angebunden. Daraufhin wird die LED mit der Lochrasterplatine im Kasten untergebracht und der Deckel auf den Kasten gesetzt.

17. Es wird ein Stoffband für den Batteriehalter, ähnlich dem Kasten, auf eine Länge von 12 cm zugeschnitten. Dann werden Druckknopf-Hälften an den Enden des Stoffstreifens angebracht. Die anderen Hälften der Druckknöpfe werden neben dem Kasten in der rechten Jackentasche angebracht. Im Bild ist die Elektronik zu sehen, bevor sie in die Jacke eingebaut wird.

![Anleitung_Elektronik_angepasst](https://github.com/user-attachments/assets/812681c2-1083-41dd-a244-f2b48c28136a)

18.	Der Batteriehalter wird auf dem Stoffstreifen mit Alleskleber angeklebt.

19.	Für die Kabel des Tasters wird ein Loch auf der Innenseite der Jackenta-sche angebracht. Dann wird der Taster am Ärmel angebracht und die Ka-bel zur rechten Jackentasche auf der Innenseite geführt.

20.	Nun wird ein Loch auf der Außenseite der rechten Jackentasche ange-bracht. Die Position ist über dem Adapter, wenn der Kasten mit der Platine und der LED in Tasche untergebracht sind. Über dem Loch wird ein quad-ratisches Stück wasserabweisender Stoff angebracht, indem es mit Textil-kleber an der linken, rechten und oberen Seite angeklebt wird. 

21.	Der Kasten wird in die Tasche gesteckt und die Kabel für den Taster durch das innere Jackenloch gesteckt. Dann wird er mit den Knöpfen fixiert und der Batteriehalter mit eingelegten Batterien wird daneben angebracht. Die Kabel des Tasters werden mit den Steckern verbunden. Die PMMA-Faser wird durch die Schlaufen und das Loch in den Adapter geführt und mit ei-ner Schraube gesichert.

22.	Zum Schluss muss nur noch der Schalter am Batteriehalter auf On gestellt werden und der Arduino mit der App gekoppelt werden.

23.	Die Jacke ist jetzt einsatzbereit.

# Inbetriebnahme:
Zur Inbetriebnahme der smarten Jacke muss diese der Montageanleitung entsprechend zusammengebaut werden. Zudem muss auf den Arduino der Programm-code geladen und auf einen Bluetooth-fähigen Handy die App installiert werden. Die App benötigt gewisse Berechtigungen, damit diese richtig funktioniert. Zudem muss eine Notfallkontaktnummer abgespeichert werden, dabei wird die Berechtigung für das Versenden von SMS erteilt. Zusätzlich wird der App über die Berechtigungen erlaubt, nahe Bluetooth-Geräte zu finden und sich mit diesen zu verbinden. Außerdem wird das Ermitteln des Standorts erlaubt. Nun müssen in den Batteriehalter die Batterien eingelegt werden und der An/Aus-Schalter auf An gestellt werden. Jetzt wird die App über Bluetooth mit dem Arduino verbunden. Dies schließt die Inbetriebnahme ab.

# Funktionsweise:
Sobald über den Panikknopf oder der Sturzerkennung ein Alarm ausgelöst werden soll, startet ein 45 Sekunden Countdown, in dem der Alarm wieder deaktiviert werden kann. Dabei kann der Alarm über die App, den Power-Schalter oder den Panikknopf deaktiviert werden. Der Panikknopf kann dabei den Alarm auslösen oder deaktivieren. Hierbei entscheidet die Druckdauer welche Funktion er ausführt: ist die Druckdauer kürzer als 7 Sekunden wird der Alarm ausgelöst, ist die Druckdauer länger als 7 Sekunden wird der Alarm entschärft. Die Sturzerkennung löst erst 30 Sekunden nach einem Sturz aus, wenn innerhalb der 30 Sekunden keine Bewegung festgestellt wurde. Diese Bedingung ist notwendig, um Fehlalarme zu vermeiden.
