/*
  Datei Name:BlinkModifikation 
  Name:Mehmedovik Benjamin  
  Datum: 21.12.2021
  
  Aufgabenstellung: Blinkfrequenz soll durch eine Globale Variable"blinkfrequenz" verändert werden können f=0.2Hz, 1Hz,5Hz,10Hz
  Der Name des digitale I/O an dem die LED 13 betrieben wird soll durch eine KonstanteNamens "LED_PIN"ersetzt werden. (constint...)
  Programmbeschreibung: Lässt LED 13 auleuchten mit x Hz
  History:
  Blink_V1=Variablen deklariert& initalisiert,delay verändert 
  modifiziert am 21.12.2021
  von Benjamin Mehmedovik
  
*/

//----------Globale Variable--------
float Blinkfrequenz=2.0; //Blinkfrequenz in Hz (Initialisieren)
unsigned long pausenzeit; //Zeit für die Pause in ms (Deklaration)
int PinNr=13;

// the setup function runs once when you press reset or power the board

//------------------------------------------------------------------------------------
//zum Initialsieren der Pin & Variablen
void setup() {
  pinMode(PinNr, OUTPUT);  //setzt interne LED(LED_BUILTIN) (Nr 13)als Ausgang
  pausenzeit=1000/(Blinkfrequenz*2); //Berechnung der Pausenzeit "Pausenzeit = 1000/(2*Frequenz)"
}
//------------------------------------------------------------------------------------

//Hauptprogramm die (Endlos Loop)
//Die Schleife läuft unendlich lang

void loop() {
  digitalWrite(PinNr, HIGH);   // schaltet LED_BUILTIN ein  (HIGH ist die Größe der Volt Größe)
  delay(pausenzeit);                       // Wartet 1000ms / in dem Fall "pausenzeit"
  digitalWrite(PinNr, LOW);    // schaltet LED_BUILTIN aus
  delay(pausenzeit);                       // Wartet für 1000ms/in dem Fall "pausenzeit"
}
