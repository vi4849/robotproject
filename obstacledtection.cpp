#include <Servo.h>
Servo rightServo;
Servo leftServo;


const int bumperLeft = 7; //front button left, is 0 when pressed
const int bumperRight = 12;   //front button right, is 1 when pressed
const int bumperBack = 5;   // back button, is 0 when pressed


const int LED = 3;


int counter = 0; //used to count number of times button has been pressed


void setup() {
 rightServo.attach (9); //right
 leftServo.attach (11); //left
  pinMode(LED,OUTPUT);


 pinMode(bumperLeft, INPUT_PULLUP);
 pinMode(bumperRight, INPUT_PULLUP);
 pinMode(bumperBack, INPUT_PULLUP);


 Serial.begin(9600);
}


void loop() {
 forward();
}


void forward()
{
rightServo.write(75); //20
leftServo.write(110); //140
delay(500);
bump();
}


void forwardLeft() //used to reorient robot after the robot hits an obstacle
{
rightServo.write(85);
leftServo.write(120);
for(int i=0;i<=5;i++)
{
 bump();
 delay(500);
}
}


void backward()   //used to reorient robot after the robot hits an obstacle
{
rightServo.write(110);
leftServo.write(75);
delay(1000);
bumpBack();
}


void bump()
{
 if(digitalRead(bumperLeft)==0 || digitalRead(bumperBack)==0 || digitalRead(bumperRight)==0) //button returns 0 if pressed
 {
   digitalWrite(LED, HIGH); //turns on LED connected to digital 2
   delay(500);
   counter++;
   digitalWrite(LED, LOW);
   Serial.println(counter);
   if(counter>=3)
   {
     stop(); //robot stops moving
     for(int i=0; i<=5; i++)
     {
     digitalWrite(LED,HIGH); // button blinks a couple times to signal robot has hit obstacle 3 times
     delay(300);
     digitalWrite(LED,LOW);
     delay(500);
     }
     exit(0); // exits loop
   }
   backward();
   forwardLeft();
 }
 else
 {
   digitalWrite(LED,LOW); // LED does not turn on if the button is not pressed
 }
}


void bumpBack()
{
if(digitalRead(bumperLeft)==0 || digitalRead(bumperBack)==0 || digitalRead(bumperRight)==0) //button returns 0 if pressed
 {
   digitalWrite(LED, HIGH); //turns on LED connected to digital 2
   delay(500);
   counter++;
   digitalWrite(LED, LOW);
   Serial.println(counter);
   if(counter>=3)
   {
     stop(); //robot stops moving
     for(int i=0; i<=5; i++)
     {
     digitalWrite(LED,HIGH); // button blinks a couple times to signal robot has hit obstacle 3 times
     delay(300);
     digitalWrite(LED,LOW);
     delay(500);
     }
     exit(0); // exits loop
   }
   forward();
   forwardLeft();
 }
 else
 {
   digitalWrite(LED,LOW); // LED does not turn on if the button is not pressed
 }
}


void stop()
{
 rightServo.write(90);
 leftServo.write(90);
}
