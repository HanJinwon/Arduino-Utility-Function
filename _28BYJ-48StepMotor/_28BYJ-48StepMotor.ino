
#include <Stepper.h>
 
const int stepsPerRevolution = 2048/6; // 모터의 1회전당 스텝 수에 맞게 조정
 
// initialize the stepper library on pins 8 through 11:
// IN1, IN2, IN3, IN4 가 아두이노 D8, D9, D10, D11에 순서대로 연결되어 있다면
 
Stepper myStepper(stepsPerRevolution, 11,9,10,8); // Note 8 & 11 swapped
 
void setup() {
  myStepper.setSpeed(25);
}
 
void loop() {
   myStepper.step(stepsPerRevolution);
   delay(500);
   //myStepper.step(-stepsPerRevolution);
   //delay(1000);
}
