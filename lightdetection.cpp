#include <Servo.h>


Servo myServo1;
Servo myServo2;
const int LED = 3;
int lightVal;
const int photoPin = A1;


void setup() {
 pinMode(LED, OUTPUT);
 Serial.begin(9600);
 myServo1.attach(9);
 myServo2.attach(11);
}


void loop() {
 stop();
 lightVal = analogRead(photoPin);
 Serial.println(lightVal);
 while (lightVal <= 910) {
   turnLeft();
   lightVal = analogRead(photoPin);
   Serial.println(lightVal);
   delay(10);
 }
 forward();
 delay(2000);
}


void forward()
{
 myServo1.write(30);
 myServo2.write(120);
}


void turnRight()
{
 myServo1.write(80);
 myServo2.write(150);
 delay(3000);
}
void turnLeft()
{
 myServo1.write(50);
 //myServo2.write(105);
}


void stop()
{
 myServo1.write(90);
 myServo2.write(90);
}


