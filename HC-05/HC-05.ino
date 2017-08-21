#include <SoftwareSerial.h>
 
SoftwareSerial mySerial(4, 7); // RX, TX
 
void setup()  
{
  // Open serial communications and wait for port to open:
  Serial.begin(38400);
  mySerial.begin(38400);
}
void loop() // run over and over
{
  if (mySerial.available())
    Serial.write(mySerial.read());
  if (Serial.available())
    mySerial.write(Serial.read());
}
