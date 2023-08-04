#include <Pixy2.h>
#include <Pixy2CCC.h>
#include <Braccio.h>
#include <Servo.h>

Servo base;
Servo shoulder;
Servo elbow;
Servo wrist_rot;
Servo wrist_ver;
Servo gripper;
Pixy2 pixy;

void setup()
{
  Serial.begin(115200);
  Serial.print("Starting...\n");
  Braccio.begin();
  pixy.init();
}

void loop()
{  
  Braccio.ServoMovement(20,90,55,150,180,180,55); //starting position @ 90 degrees
  delay(1000);

  Braccio.ServoMovement(20,0,45,180,180,180,55); //looks at object using camera 

  int position = 0;
  while(pixy.ccc.blocks[0].m_x>151 && pixy.ccc.blocks[0].m_y>100) // adjusts position to right if object is further right
    {
      position++;
      Braccio.ServoMovement(20,position,45,180,180,180,55);
      delay(500);
      pixy.ccc.getBlocks(false, 3, 1); // re-scans object to see if it is now in the correct position

      Serial.print("Detected "); // prints position (x and y) to serial monitor
      Serial.println(pixy.ccc.numBlocks);
      for (i=0; i<pixy.ccc.numBlocks; i++)
      {
      Serial.print("  block ");
      Serial.print(i);
      Serial.print(": ");
      pixy.ccc.blocks[i].print();
      }
    }


  delay(1000);
  pixy.ccc.getBlocks(false, 3, 1); // robotic arm scans for objects (false means don't wait, 3 means detect green and red objects, 1 means only detects one object)

  if(pixy.ccc.blocks[0].m_y>100 && pixy.ccc.blocks[0].m_x<200 && pixy.ccc.blocks[0].m_x>100) // only picks up objects if they're in a certain position (prevents background noise)
  {
  Braccio.ServoMovement(20,position,115,150,180,180,55); //moves over to object (extends arm to begin grabbing object)

  int i; // used to sort objects by color 
  if(pixy.ccc.blocks[0].m_signature == 1) // if object is green
  {
    i = 180;
  }
  if(pixy.ccc.blocks[0].m_signature == 2) // if object is red
  {
    i = 90;
  }

  Braccio.ServoMovement(20,position,115,150,180,180,73); //grips object
  delay(1000);

  Braccio.ServoMovement(20,position,55,150,180,180,73); //picks up object
  delay(1000);

  Braccio.ServoMovement(20,i,55,150,180,180,73); //turns around with object
  delay(1000);

  Braccio.ServoMovement(20,i,90,180,180,180,73); //goes to i (i is different based on color, so the arm is able to sort different colored objects)

  Braccio.ServoMovement(20,i,90,180,180,180,55); //drops object
  Braccio.ServoMovement(20,i,55,150,180,180,55); 
  }
}
