#include <Servo.h>
int servoPin = 9;

Servo servo; 

int angle = 0; // servo position in degrees 
int JoyStick_X = 0; //x 
int JoyStick_Y = 1; //y 
int JoyStick_Z = 3; //key 
void setup()  
 {  
  pinMode(JoyStick_X, INPUT);  
  pinMode(JoyStick_Y, INPUT);  
  pinMode(JoyStick_Z, INPUT);  
  Serial.begin(9600); // 9600 bps 
  servo.attach(servoPin);
} 
void loop()  
{ 
      int x,y,z; 
      x=analogRead(JoyStick_X); 
      y=analogRead(JoyStick_Y); 
      z=digitalRead(JoyStick_Z); 
      

  
       // scan from 0 to 180 degrees
    int diff = 0;
    diff = x-500;
    int a = diff/100;
    
    angle = (angle + (diff/120));
    if(angle > 75) 
    {
      angle = 75;
    }
    else if(angle < 0)
    {
      angle = 0;
    }
    
      servo.write(angle); 
     
   
  // now scan back from 180 to 0 degrees
      Serial.print(x ,DEC); 
      Serial.print(","); 
      Serial.print(y ,DEC); 
      Serial.print(","); 
      Serial.println(z ,DEC);
      Serial.println(angle); 
            delay(100); 

 
}
