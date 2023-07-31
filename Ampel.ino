#define LED_rot 13
#define LED_gelb 12
#define LED_gruen 11
#define LED_fuss 10
#define button A1
//0b ROT GELB GRÜN FUßGÄNGER 0000
const byte REIHENFOLGE[][2] = {
                              {0b0010,0},
                              {0b0100,2}, 
                              {0b1000,2}, 
                              {0b1001,5}, 
                              {0b1000,2}, 
                              {0b1100,2}
                              };

void setup() {
  pinMode(LED_rot, OUTPUT);
  pinMode(LED_gelb, OUTPUT);
  pinMode(LED_gruen, OUTPUT);
  pinMode(LED_fuss, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  ledManager(REIHENFOLGE[0][0]);
  while (!digitalRead(button));
  while (digitalRead(button));
  for (byte i=1; i<=5;i++)
  {
    ledManager(REIHENFOLGE[i][0]);
    delay(REIHENFOLGE[i][1]*1000);
  }
}

void ledManager(byte value)
{
  digitalWrite(LED_rot,value&0b1000);
  digitalWrite(LED_gelb,value&0b0100);
  digitalWrite(LED_gruen,value&0b0010);
  digitalWrite(LED_fuss,value&0b0001);
}


/*
   Auto: Grün
   (Knopf druck)
   Auto: Gelb -> 2s
   Auto: Rot -> 2s
   Fußgänger: Grün -> 5s
   Fußgänger: Rot -> 2s
   Auto: Rot Gelb -> 2s
   Auto: Grün
*/
