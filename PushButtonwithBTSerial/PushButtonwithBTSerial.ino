#include <SoftwareSerial.h>

#define Rx 1
#define Tx 0
#define Button 8
boolean pushCnt = false;
SoftwareSerial BTSerial(Tx, Rx);
byte buffer[1024]; // 데이터를 수신 받을 버퍼
int bufferPosition; // 버퍼에 데이타를 저장할 때 기록할 위치
boolean temp = 0;

void setup()
{
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(Button, INPUT);
  pinMode(13, OUTPUT);
  bufferPosition = 0; // 버퍼 위치 초기화
}

void loop()
{
  int i = digitalRead(Button);
  //if (BTSerial.available()) 
  //{
    if(!i) 
    {
      pushCnt = true;
      digitalWrite(13, HIGH);
    }
    else
    {
      if(pushCnt)
      {
        digitalWrite(13, LOW);
        Serial.println("1"); // 시리얼 확인용 1
        //BTSerial.println("1"); 블루투스로 전달된 문자1을 출력시키는건데 필요하면 쓰도록
        BTSerial.write(49); //문자 "1" ASCII값 데이터 전송 
        pushCnt = false;
      }
    }
 // }
}

