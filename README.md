# Thyristor-Triac-Tester

![](https://github.com/ltspicer/Thyristor-Triac-Tester/blob/main/gehaeuse5.jpg)

![](https://github.com/ltspicer/Thyristor-Triac-Tester/blob/main/gehaeuse6.jpg)

![](https://github.com/ltspicer/Thyristor-Triac-Tester/blob/main/gehaeuse7.jpg)


![](https://github.com/ltspicer/Thyristor-Triac-Tester/blob/main/inbetrieb1.jpg)



## Original Text:

Dieses Testgerät kann Thyristoren und Triacs bis zu hohen Zündströmen testen.

Thyristoren und Triacs testen ist das Einzige, was der LCR-TC2 ( https://de.aliexpress.com/item/1005004205300336.html ) nicht kann.

Grösste Baustelle ist noch die Distanzerhöhung des IC Testsockels. Dieser sollte höher als das Display sein.
Leider greiffen die kurzen Beinchen nicht stabil genug in einem Pinheader.

Die Zwischenplatte ist nur, um den IC Testsockel auf ein Niveau höher als das Display zu bringen.
Ohne Gehäuse kann der IC Testsockel direkt auf das PCB gelötet werden.

Die Schaltkreise und PCB Layouts sind mit Target3001medium erstellt worden und können mit Target3001discover geöffnet werden. Target3001discover ist kostenlos!

Der StepUp ist auf **18V** zustellen!

Die ino Datei ist mittels **Arduino IDE** auf den ESP8266 zuschreiben.

Ich habe zwar noch rote PCBs V1.0 auf Lager (für Interessenten). Falls aber eine grössere Sammelbestellung zustande kommt, werde ich V1.1 PCBs in Auftrag geben. Ich werde dann auch die Zwischen-PCBs für den IC Testsockel bestellen.

Dieses Projekt ist hier zuhause: https://www.ltspiceusers.ch/threads/baue-mir-einen-thyristor-triac-tester-mit-einem-esp8266-mit-oled-display.2739/#post-5482

Die **2 zip** sind die **Gerber** Dateien.

Falls ein Triac als Thyristor erkannt wird, ist dieser Triac defekt!

## English (DeepL translator):

This tester can test thyristors and triacs up to high ignition currents.

Testing thyristors and triacs is the only thing the LCR-TC2 ( https://de.aliexpress.com/item/1005004205300336.html ) cannot do.

The biggest problem is increasing the distance of the IC test socket. This should be higher than the display.
Unfortunately, the short legs do not grip firmly enough in a pin header.

The intermediate plate is only to bring the IC test socket to a level higher than the display.
Without the housing, the IC test socket can be soldered directly onto the PCB.

The circuits and PCB layouts have been created with Target3001medium and can be opened with Target3001discover. Target3001discover is free!

The StepUp must be set to **18V**!

The ino file is to be written to the ESP8266 with **Arduino IDE**.

I still have red PCBs V1.0 in stock (for interested parties). However, if a larger collective order is placed, I will order V1.1 PCBs. I will then also order the intermediate PCBs for the IC test socket.

This project is here @home: https://www.ltspiceusers.ch/threads/baue-mir-einen-thyristor-triac-tester-mit-einem-esp8266-mit-oled-display.2739/#post-5482

The **2 zip** are the **Gerber** files.

If a triac is recognized as a thyristor, this triac is defective!

--------------------------------

## Stückliste:

1x  ESP8266 NodeMCU mit OLED        https://de.aliexpress.com/item/1005005470719229.html

1x  Gehäuse 125x80x32mm             https://de.aliexpress.com/item/1005005448610944.html

2x  Pinheader 15pol weiblich        https://de.aliexpress.com/item/1005001418544370.html

3x  Omron Relais G5V-1-5VDC         https://de.aliexpress.com/item/1005005743754968.html

1x  L293B H-Bridge                  https://de.aliexpress.com/item/1005006253986033.html

1x  StepUp MT3608                   https://de.aliexpress.com/item/1005006532445571.html

1x  14pin IC Testsockel             https://de.aliexpress.com/item/1005006117085994.html

2x  4N35 Optokoppler

1x  7805 5V Spannungsregler

5x  2N7000 Kleinleistungs-FET

3x  1N4007 Diode (oder ähnlich. Nur für Freilauf)

2x  IC Sockel DIP6

1x  IC Sockel DIP16

1x  Einbau Drucktaster (Schliesser)

1x  9V Batterie Anschlusskabel

1x  9V Batterie

2x  Elko 4.7µF 50V (mindestens 16V)

5x  Widerstand 100 kOhm

3x  Widerstand 10 kOhm

2x  Widerstand 2.2 kOhm

1x  Widerstand 510 Ohm

1x  Widerstand 470 Ohm

1x  Widerstand 270 Ohm

1x  Widerstand 60 Ohm

1x  Widerstand 22 Ohm

2x  Pinheader 7pol weiblich (für IC Testsockel)

Pinleiste 1 reihig zuschneidbar (für StepUp, IC Testsockel und optionale Testpins)


### Die Bauteile kosten keine 20€ (exkl Batterie. Die ist wohl das teuerste Bauteil)!
