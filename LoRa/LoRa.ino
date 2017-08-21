#include <LoRaShield.h>

LoRaShield LoRa(10, 11);
String s, m;
void setup() {
  Serial.begin(115200);
  LoRa.begin(38400);
}

void loop() {
  while (LoRa.available())
   {
    s = LoRa.ReadLine();
    Serial.print("LoRa.ReadLine() = ");
    Serial.println(s);

    m = LoRa.GetMessage();
    if(m != ""){
      Serial.println("Recv from LoRa : " + m);
     }
     //LoRa 수신확인용 코드/////
     if(m == "26")
     {
     // servo.write(OPEN);
      Serial.println("CHECK");
      delay(100);
     // servo.write(CLOSE);
     }
     /////////////////////////
   }
}
