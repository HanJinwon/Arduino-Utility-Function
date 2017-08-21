#define cds A1
#define RED 10
#define GREEN 9
#define BLUE 8

int redVal = 0;
int greenVal = 0;
int blueVal = 0;
int fadeAmountR = 1;
int fadeAmountG = 1;
int fadeAmountB = 1;
bool flagG = false;
bool flagB = false;

void setup() {
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {
  int cdsValue = analogRead(cds);
  Serial.print("cds = ");
  Serial.println(cdsValue);
  delay(200);
  setColor(redVal, greenVal, blueVal);
  if(cdsValue > 500)
  {
       redVal = redVal + fadeAmountR;
    //if(flagG)
      greenVal = greenVal + fadeAmountG;
    //if(flagB)  
     // blueVal = blueVal + fadeAmountB;
    if(redVal == 0 || redVal == 20)
      fadeAmountR = -fadeAmountR;
    if(greenVal == 0 || greenVal == 20)
      fadeAmountG = -fadeAmountG;
    if(blueVal == 0 || blueVal == 50)
      fadeAmountB = -fadeAmountB;
  }
  else
  {
    setColor(0, 0, 0); // Off
    delay(50);
  }
}

void setColor(int red, int green, int blue)
{
  analogWrite(RED, red);
  analogWrite(GREEN, green);
  analogWrite(BLUE, blue);
}

