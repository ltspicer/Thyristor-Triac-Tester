// https://github.com/olikraus/u8g2/wiki

#include <Arduino.h>
#include <U8g2lib.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

// sda = 12
// scl = 14

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0,14,12,U8X8_PIN_NONE);

// GPIOs definieren
const int RE1  =  3;           // Relais Ausgang 1
const int RE2  = 13;           // Relais Ausgang 2
const int RE3  = 15;           // Relais Ausgang 3

const int TAKT =  4;           // Takt        für Umpolung
const int takt =  5;           // Takt invers für Umpolung

const int Opto1  =  0;         // Opto1  mit PullUp
const int Opto2  = 16;         // Opto2  mit PullUp

const int debug = 2;           // Pin an GND schaltet DEBUG ein

// Diverse Koordinaten für Grafikausgabe
const int x_offset = 47;
const int oben = 17;
const int y_mitte = 27;
const int unten = 37;
const int triac1 = 23;
const int triac2 = 31;

const int zeile0 = 14;
const int zeile1 = 32;
const int zeile2 = 49;
const int zeile3 = 62;

// Diverse Variabeln
int gezuendet = 0;             // mA für Zündung
boolean positiv = false;       // Positive Halbwelle
boolean negativ = false;       // Negative Halbwelle
boolean DEBUG = false;         // Debug Status ein/aus

void setup() {
  Serial.begin(9600);

  u8g2.begin();
  // https://github.com/olikraus/u8g2/wiki/fntgrpx11#7x14b
  u8g2.setFont(u8g2_font_7x14B_tf);

  pinMode(RE1, OUTPUT);
  pinMode(RE2, OUTPUT);
  pinMode(RE3, OUTPUT);
  pinMode(TAKT, OUTPUT);
  pinMode(takt, OUTPUT);
  pinMode(Opto1, INPUT_PULLUP);
  pinMode(Opto2, INPUT_PULLUP);
  pinMode(debug, INPUT_PULLUP);

  digitalWrite(TAKT, LOW);
  digitalWrite(takt, LOW);
  digitalWrite(RE1,LOW);
  digitalWrite(RE2,LOW);
  digitalWrite(RE3,LOW);
}

void loop() {

  u8g2.clearBuffer();
  u8g2.drawUTF8(0, zeile0, "Prüfung läuft...");

  if (digitalRead(debug) == LOW) {
    DEBUG = true;
  } else {
    DEBUG = false;
  }

  // Bauteil Dauerzündung?
  u8g2.drawUTF8(0, zeile1, "Dauerzündung?");
  u8g2.sendBuffer();  
  delay(100);
  for (int d = 0; d < 2; d++) {
    if (gezuendet == 0 or gezuendet == 500) {
      umpolen();
      delay(200);
      if (OptosAbfragen()) {
        gezuendet = 500;
      }
    }
  }
  if (gezuendet == 500) {
    positiv = false;
    negativ = false;
    u8g2.clearBuffer();
    goto defekt;
  }

  // 30mA Zündung
  u8g2.clearBuffer();
  u8g2.drawUTF8(0, zeile0, "Prüfung läuft...");
  u8g2.drawUTF8(0, zeile1, "30mA Zündung");
  u8g2.sendBuffer();
  for (int d = 0; d < 2; d++) {
    if (gezuendet == 0 or gezuendet == 30) {
      umpolen();
      digitalWrite(RE1,HIGH);
      if (DEBUG) {
        Serial.println("RE1 HIGH");
      }  
      delay(200);
      digitalWrite(RE1,LOW);
      if (DEBUG) {
        Serial.println("RE1 LOW");
      }  
      delay(100);
      if (OptosAbfragen()) {
        gezuendet = 30;
      }
    }
  }
  if (gezuendet == 30) {
    goto fertig;
  }

  // 60mA Zündung
  u8g2.clearBuffer();
  u8g2.drawUTF8(0, zeile0, "Prüfung läuft...");
  u8g2.drawUTF8(0, zeile1, "60mA Zündung");
  u8g2.sendBuffer();  
  for (int d = 0; d < 2; d++) {
    if (gezuendet == 0 or gezuendet == 60) {
      umpolen();
      digitalWrite(RE2,HIGH);
      if (DEBUG) {
        Serial.println("RE2 HIGH");
      }  
      delay(200);
      digitalWrite(RE2,LOW);
      if (DEBUG) {
        Serial.println("RE2 LOW");
      }  
      delay(100);
      if (OptosAbfragen()) {
        gezuendet = 60;
      }
    }
  }
  if (gezuendet == 60) {
    goto fertig;
  }

  // 90mA Zündung
  u8g2.clearBuffer();
  u8g2.drawUTF8(0, zeile0, "Prüfung läuft...");
  u8g2.drawUTF8(0, zeile1, "90mA Zündung");
  u8g2.sendBuffer();
  for (int d = 0; d < 2; d++) {
    if (gezuendet == 0 or gezuendet == 90) {
      umpolen();
      digitalWrite(RE1,HIGH);
      digitalWrite(RE2,HIGH);
      if (DEBUG) {
        Serial.println("RE1 HIGH");
        Serial.println("RE2 HIGH");
      }  
      delay(200);
      digitalWrite(RE1,LOW);
      digitalWrite(RE2,LOW);
      if (DEBUG) {
        Serial.println("RE1 LOW");
        Serial.println("RE2 LOW");
      }  
      delay(100);
      if (OptosAbfragen()) {
        gezuendet = 90;
      }
    }
  }
  if (gezuendet == 90) {
    goto fertig;
  }

  // 189mA Zündung
  u8g2.clearBuffer();
  u8g2.drawUTF8(0, zeile0, "Prüfung läuft...");
  u8g2.drawUTF8(0, zeile1, "189mA Zündung");
  u8g2.sendBuffer();
  for (int d = 0; d < 2; d++) {
    if (gezuendet == 0 or gezuendet == 189) {
      umpolen();
      digitalWrite(RE3,HIGH);
      if (DEBUG) {
        Serial.println("RE3 HIGH");
      }  
      delay(200);
      digitalWrite(RE3,LOW);
      if (DEBUG) {
        Serial.println("RE3 LOW");
      }  
      delay(100);
      if (OptosAbfragen()) {
        gezuendet = 189;
      }
    }
  }
  if (gezuendet == 189) {
    goto fertig;
  }

  // 269mA Zündung
  u8g2.clearBuffer();
  u8g2.drawUTF8(0, zeile0, "Prüfung läuft...");
  u8g2.drawUTF8(0, zeile1, "269mA Zündung");
  u8g2.sendBuffer();
  for (int d = 0; d < 2; d++) {
    if (gezuendet == 0 or gezuendet == 269) {
      umpolen();
      digitalWrite(RE1,HIGH);
      digitalWrite(RE2,HIGH);
      digitalWrite(RE3,HIGH);
      if (DEBUG) {
        Serial.println("RE1 HIGH");
        Serial.println("RE2 HIGH");
        Serial.println("RE3 HIGH");
      }  
      delay(200);
      digitalWrite(RE1,LOW);
      digitalWrite(RE2,LOW);
      digitalWrite(RE3,LOW);
      if (DEBUG) {
        Serial.println("RE1 LOW");
        Serial.println("RE2 LOW");
        Serial.println("RE3 LOW");
      }  
      delay(100);
      if (OptosAbfragen()) {
        gezuendet = 269;
      }
    }
  }

  fertig:

  u8g2.clearBuffer();

  if (DEBUG) {
    if (!digitalRead(Opto1) == HIGH) {
      Serial.println("Opto1=1 (Positive Halbwelle)");
    }
    if (!digitalRead(Opto2) == HIGH) {
      Serial.println("Opto2=1 (Negative Halbwelle)");
    }
  }

  // Display Ausgabe

  // https://github.com/olikraus/u8g2/wiki/u8g2reference

  if (gezuendet > 0) {
    //u8g2.setCursor(0, zeile2);
    //u8g2.print("Zündpunkt: ");
    u8g2.drawUTF8(0, zeile3, "Zündpunkt: ");
    u8g2.setCursor(10*8, zeile3);
    u8g2.print(gezuendet);
    u8g2.print(" mA");
    u8g2.setCursor(0, zeile2);
    u8g2.print("Typ: ");
    if (positiv != negativ) {
      u8g2.print("Thyristor");

      u8g2.drawLine(x_offset   , y_mitte  , x_offset+10, y_mitte);
      u8g2.drawLine(x_offset+20, y_mitte  , x_offset+30, y_mitte);
      u8g2.drawLine(x_offset+20, oben+3   , x_offset+20, unten-3);
      u8g2.drawLine(x_offset+20, y_mitte+1, x_offset+25, y_mitte+4);
      u8g2.drawLine(x_offset+25, y_mitte+4, x_offset+25, unten-4);

      u8g2.drawTriangle(x_offset+10,oben+3, x_offset+10,unten-3, x_offset+20,y_mitte);

    } else {
      u8g2.print("Triac");

      u8g2.drawLine(x_offset   , y_mitte  , x_offset+10, y_mitte);
      u8g2.drawLine(x_offset+20, y_mitte  , x_offset+30, y_mitte);
      u8g2.drawLine(x_offset+20, oben     , x_offset+20, unten);
      u8g2.drawLine(x_offset+10, oben     , x_offset+10, unten);
      u8g2.drawLine(x_offset+20, y_mitte+1, x_offset+25, y_mitte+4);
      u8g2.drawLine(x_offset+25, y_mitte+4, x_offset+25, unten-2);

      u8g2.drawTriangle(x_offset+11,oben+1,    x_offset+11,y_mitte+1, x_offset+21,triac1);
      u8g2.drawTriangle(x_offset+20,y_mitte-1, x_offset+20,unten-1,   x_offset+10,triac2);

    }

    if (DEBUG) {
      Serial.print("Gezündet mit ");
      Serial.print(gezuendet);
      Serial.println(" mA");
      Serial.print("Typ: ");
      if (positiv != negativ) {
        Serial.println("Thyristor");
      } else {
        Serial.println("Triac");
      }
    }
  }

  defekt:

  digitalWrite(TAKT, LOW);
  digitalWrite(takt, LOW);
  if (positiv == false and negativ == false) {
    u8g2.setCursor(5*8, zeile1);
    u8g2.print("Bauteil");
    if (gezuendet == 500) {
      u8g2.drawUTF8(0, zeile2, " Dauerzündung oder");
      u8g2.setCursor(0, zeile3);
      u8g2.print("  falsch gesteckt");
    } else {
      u8g2.setCursor(0, zeile2);
      u8g2.print("defekt oder fehlt!");
    }  
    u8g2.setFont(u8g2_font_unifont_t_symbols);  // Zeichensatz für Kreuz
    u8g2.drawGlyph(56, 15, 0x2716);	            // Kreuz zeichnen
    u8g2.setFont(u8g2_font_7x14B_tf);    // Zeichensatz zurücksetzen

    if (DEBUG) {
      Serial.println("Kein Bauteil oder defekt");
    }
  } else {
    u8g2.setCursor(28, zeile0);
    u8g2.print("Bauteil OK!");
    if (DEBUG) {
      Serial.println("Bauteil OK!");
    }
  }
  u8g2.sendBuffer();
  if (DEBUG) {
    gezuendet = 0;                       // mA für Zündung
    positiv = false;                     // Positive Halbwelle
    negativ = false;                     // Negative Halbwelle
    delay(5000);
  } else {
    do {                                 // Endlosschleife
      delay(5000);
      if (digitalRead(debug) == LOW) {
        Serial.println("Debug eingeschaltet");
        break;
      }
    } while (true);    
  }  
}

boolean OptosAbfragen() {
  boolean Opto1in = !digitalRead(Opto1);
  boolean Opto2in = !digitalRead(Opto2);
  if (Opto1in == HIGH) {
    positiv = true;
  }
  if (Opto2in == HIGH) {  
    negativ = true;
  }
  if (Opto1in == HIGH or Opto2in == HIGH) {
    return true;
  }  
  return false;
}

void umpolen() {
  digitalWrite(TAKT, !digitalRead(TAKT));
  delay(90);
  digitalWrite(takt, !digitalRead(TAKT));
  delay(10);
}

