/*
  Datei Name:BlinkWithOutDelayNeu
  Benjamin Mehmedovik
  18.02.2022

*/

//-----------Const Variablen---------------
//const int ledPin =  LED_BUILTIN/ the number of the LED pin
#define LED_pin 13               //Textersatz LED_Pin=13
unsigned long interval;           // interval (Pausenzeit), 1/2 Periodendauer
boolean ledState = LOW;             // nur on/off

//-------------Globale Variable--------------------
unsigned long previousMillis = 0;        // setzt die vorherigen Millis gleich 0
unsigned long AktMillis;                 //Variable wird deklariert
float Blinkfrequenz = 1.0;

//------------------------------------------------------------------------------------
void setup() {
  // Der Pin wird als Output gesetzt
  pinMode(LED_pin, OUTPUT);
  interval = 1000 / (Blinkfrequenz * 2);
  Serial.begin(9600); //Initialisierung der seriellen Schnittstelle mit 9600 baud
}


//------------------------------------------------------------------------------------
void loop() {

  //unsigned long currentMillis = millis(); //liest aktuelle Zeit seit Program start aus und zwar in msm
  AktMillis = millis();
  //Serial.print("Zeit: "); Serial.print(AktMillis);Serial.println("ms");
  //Überprüfung ob Timer Interval abgelaufen ist
  if (AktMillis - previousMillis >= interval) {
    Serial.print("Changezeit: "); Serial.print(AktMillis);
    previousMillis = AktMillis;  // Restartet Timer    
    if (ledState == LOW) {                // Wenn die LED aus ist mach sie an, wenn an dann aus
      Serial.println(" LED An");
      ledState = HIGH;
      } else {
      Serial.println(" LED Aus");
      ledState = LOW;
      }
    /*ledState = ! ledState*/
  }

  digitalWrite(LED_pin, ledState);       // set the LED with the ledState of the variable:
}
