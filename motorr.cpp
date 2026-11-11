#include <Stepper.h>
int trigger=7;
int echo=6;
long dauer=0;
long entfernung=0;
int LEDG=3;
int LEDB=4;
int LEDR=5;
int SPU = 2048; // Schritte pro Umdrehung.
Stepper Motor(SPU, 10,8,11,9); 
void setup()
{
Serial.begin (9600);
pinMode(trigger, OUTPUT);
pinMode(echo, INPUT);
pinMode(LEDG, OUTPUT);
pinMode(LEDB, OUTPUT);
pinMode(LEDR, OUTPUT);
Motor.setSpeed(10); //Angabe der Geschwindigkeit in Umdrehungen pro 
}
void loop()
{
digitalWrite(trigger, LOW);
delay(5);
digitalWrite(trigger, HIGH);
delay(10);
digitalWrite(trigger, LOW);
dauer = pulseIn(echo, HIGH);
entfernung = (dauer/2) * 0.03432;
if (entfernung >= 500 || entfernung <= 0)
{
Serial.println("Kein Messwert");
}
else
{
Serial.print(entfernung);
Serial.println(" cm");

if (entfernung <= 10){
 digitalWrite(LEDR, HIGH);
 digitalWrite(LEDB, LOW);
 digitalWrite(LEDG, LOW);
 Motor.step(-60);
}

else if (entfernung <= 20){
 digitalWrite(LEDR, HIGH);
 digitalWrite(LEDB, LOW);
 digitalWrite(LEDG, LOW);
 Motor.step(0);
}

else if (entfernung <= 50){
 digitalWrite(LEDR, LOW);
 digitalWrite(LEDB, HIGH);
 digitalWrite(LEDG, LOW);
 Motor.step(20);
 delay(100);
}

else {
 digitalWrite(LEDR, LOW);
 digitalWrite(LEDB, LOW);
 digitalWrite(LEDG, HIGH);
 Motor.step(60);
}
}
}
