#include <Servo.h>


int flameSensor = A0;
int flameValue = 0;
int X = 45;
int Y = 45;
int pumpWater = 8;

int fire;

Servo ServoX;
Servo ServoY;

void setup() {
  Serial.begin(9600);
  pinMode(pumpWater, OUTPUT);
  digitalWrite(pumpWater, LOW);

  ServoX.attach(10);
  ServoY.attach(11);
}

void loop() {
 flameValue = analogRead(flameSensor);

 switch(fire){
 case 0:

 if(flameValue <= 200){
  fire = 1;
 }

 if (X >= 135){
  X = 60;
  Y += 25;
 }
else{
  X += 25;
}

if(Y >= 150){
  Y = 60;
}

Serial.print(X);
Serial.print(" | ");
Serial.print(Y);
Serial.print(" | Analog Value: ");
Serial.println(flameValue);

ServoX.write(X);
ServoY.write(Y);

delay(1000);

break;

case 1:
Serial.print(" | Analog Value: ");
Serial.print(flameValue);
Serial.println(" | Fire Detected | ");
digitalWrite(pumpWater, HIGH);

delay(1000);

digitalWrite(pumpWater, LOW);


if(flameValue >= 100){
  fire = 0;
}

break;

}

}
