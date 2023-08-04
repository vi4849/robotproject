#include <Servo.h>


Servo myServo1;
Servo myServo2;


void setup()
{
myServo1.attach (9); //right
myServo2.attach (11); //left
}


void loop()
{
 backRight();
 backLeft();
}


void forward() /*did not end up using during final figure eight (part of trial and error process) */
{
 myServo1.write(20);
 myServo2.write(140);
 delay(1000);
}


void forwardRight() /*did not end up using during final figure eight (part of trial and error process) */
{
 myServo1.write(80);
 myServo2.write(170);
 delay(17000);
}


void forwardLeft() /*did not end up using during final figure eight (part of trial and error process) */
{
 myServo1.write(30);
 myServo2.write(105);
 delay(17000);
}


void backLeft() //makes robot make a loop to the left, “backwards”
{
 myServo1.write(105);
 myServo2.write(20);
 delay(6000);
}


void backRight() //makes robot make a loop to the right, “backwards”
{
 myServo1.write(160);
 myServo2.write(82);
 delay(6500);
}


void backward() /*did not end up using during final figure eight (part of trial and error process) */
{
 myServo1.write(140);
 myServo2.write(20);
 delay(3000);
}


void turnRight() /*did not end up using during final figure eight (part of trial and error process) */
{
 myServo1.write(140);
 myServo2.write(140);
 delay(3200);
}
void turnLeft() /*did not end up using during final figure eight (part of trial and error process) */
{
 myServo1.write(20);
 myServo2.write(20);
 delay(3300);
}
