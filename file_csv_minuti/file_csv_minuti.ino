// this example is public domain. enjoy!
// www.ladyada.net/learn/sensors/thermocouple

#include "max6675.h"

int thermoDO = 6;
int thermoCS = 5;
int thermoCLK = 4;

MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);
int vccPin = 3;
int gndPin = 2;

unsigned long old_millis=0;   //tempo di partenza per il conteggio del tempo in ms
//unsigned long delta=60000;  //incremento di tempo tra due letture in ms per stampare la temperatura ogni minuto
unsigned long delta=600;       //valore ridotto per debug
int minuti=1;                 //variabile utilzzata per identificare i minuti corrispondenti alla lettura
  
void setup() {
  Serial.begin(9600);
  // use Arduino pins 
  pinMode(vccPin, OUTPUT); digitalWrite(vccPin, HIGH);
  pinMode(gndPin, OUTPUT); digitalWrite(gndPin, LOW);
  
  // Serial.println("MAX6675 test");
  // wait for MAX chip to stabilize
  delay(500);  
}

void loop() {
  
unsigned long now=millis(); //variabile usata per gestire il tempo in ms

  if(now>=old_millis+delta){  //se il tempo attuale è maggiore dell'intervallo precedente stampa min e temperatura
   Serial.print(minuti);
   Serial.print(",");
   Serial.println(thermocouple.readCelsius());
   old_millis=now;   //terminato il ciclo pone il valore di old_millis uguale al tempo corrente
   minuti=minuti+1;  //incrementa il contatore dei minuti di 1 minuto
  }
   delay(1);  //da una pausa nell'esecuzione del ciclo
}
