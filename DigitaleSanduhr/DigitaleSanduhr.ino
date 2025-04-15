/*
 *Dateiname:DigitaleSanduhr
 *Geschrieben am 18.01.2022
 *Von Benjamin Mehmedovik
 *Aufgabenstellung: Eine Digitale Sanduhr mithilfe Leuchtdioden bauen,
 *die Leuchtdioden leuchten auf in einem Interval von  einer Sekunde
 */

//-------------Globale Variablen--------------

const int switchpin = 8;               // Wir legen einen Pin fest womit wir danach die Sanduhr "Drehen" können
unsigned long AltZeit = 0;             //
int SwitchStatus = 0;
int prevswitchState=0;
int LED = 2;                           //Die erste LED die aufleuchtet 
long interval = 60000;                 //Wir legen das Interval fest indem die LED leuchten werden 



void setup()
{
  for (int i = 2; i < 8; i++)          //Wir laufen eine Schleife durch,die Schleife geht so lang durch bis der 7te Pin erreicht wurder
  {
    pinMode(i, OUTPUT);                //Wir setzen die Pins als Ausgabe
  }
  pinMode(switchpin, INPUT);           //Der 8 Pin wird als Input benutzt, die Sanduhr dreht sich um

}


void loop()
{
  unsigned long TimeJetzt = millis();  //

  if (TimeJetzt - AltZeit > interval)
  {
    AltZeit = TimeJetzt;
    digitalWrite(LED, HIGH);
    LED++;
    if (LED == 7) {}
  }
  SwitchStatus = digitalRead(switchpin);

    if (SwitchStatus != prevswitchState)
  {
    for (int i = 2; i < 8; i++)
    {
      digitalWrite(i, LOW);
    }
    LED = 2;
    AltZeit = TimeJetzt;
  }
   prevswitchState = SwitchStatus;
}
