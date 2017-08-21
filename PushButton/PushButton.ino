#include <Servo.h>

Servo servo;
int servoPin = 5;
int led=13; //LED 디지털 IO핀 설정(우노보드에 장착된 LED)
int pushButton = A5;
byte buffer[1024];
int bufferPosition;
int angle = 0; // servo position in degress
void setup()
{
  Serial.begin(9600);
  //pinMode(led,OUTPUT);//디지털IO를 출력으로 설정
  servo.attach(servoPin);
  pinMode(led, OUTPUT);
}
void loop()
{
  int i;//변수 선언
  while(1)
  {
    i=analogRead(5);//A5 아날로그 입력으로부터 전압을 읽어옴
    if(i>1000 || data == '1') { //전압값이 1000보다 크면（약 4.88V）
      servo.write(60);
      digitalWrite(led, HIGH);
    }//디지털IO 13번을 HIGH로 하여 LED 점등
    else if(i<1000 || data == '0'){
      servo.write(0);
      digitalWrite(led, LOW);
    }//디지털IO 13번을 LOW로 하여 LED 소등 
  }
}
