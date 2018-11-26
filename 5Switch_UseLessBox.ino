// My youtube video: https://www.youtube.com/watch?v=b71fbL6G5fs
// https://majsterkowo.pl/bezuzyteczne-pudelko-wersja-zaaansowana/
// https://www.youtube.com/watch?time_continue=1&v=QDWSbA0mdQk
// https://www.youtube.com/watch?annotation_id=annotation_1338334733&feature=iv&src_vid=QDWSbA0mdQk&v=gUw4Bogj7fA

#include <Servo.h>

#define arm 9
#define lid 10

#define P1 2
#define P2 3
#define P3 4
#define P4 5
#define P5 6
//#define P6 5
//#define P7 6

#define S1 7
#define S2 8
#define S3 11
#define S4 12

#define Home 13

Servo servoArm;               // Arm Servo
Servo servoLid;               // Lid Servo

int motorPosition = 0;        // motor position
int Loop = 0;                 // Loop to position 0
int Delay = 2500;             // delay
int steps = 14;              // number of steps
bool Arm_Position = 0;

void setup() {
  Serial.begin(9600);
  pinMode(arm, OUTPUT);
  pinMode(lid, OUTPUT);

  servoArm.attach(arm);
  servoLid.attach(lid);
  servoArm.write(0);
  servoLid.write(75);

  delay(700);

  servoArm.detach();
  servoLid.detach();

  pinMode(P1, INPUT_PULLUP);
  pinMode(P2, INPUT_PULLUP);
  pinMode(P3, INPUT_PULLUP);
  pinMode(P4, INPUT_PULLUP);
  pinMode(P5, INPUT_PULLUP);
  //  pinMode(P6, INPUT);
  //  pinMode(P7, INPUT);

  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(S4, OUTPUT);

  pinMode(Home, INPUT_PULLUP);

  digitalWrite(S1, LOW);
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  digitalWrite(S4, LOW);

  while (digitalRead(Home) < HIGH) {    //return to the initial position
    left(1);
  }
  motorOFF();
}
//*******************************RAISED THE ARM*********************************
void arm_High() {  // Raised the Arm
  servoArm.attach(arm);
  servoArm.write(140);
  if (Arm_Position == 0) {
    delay(400);
  }
  else {
    delay(200);
  }
}

void arm_Middle()  {//Lower the Arm
  servoArm.write(75);
  delay(200);
  Arm_Position = 1;
}

void arm_Low() {
  servoArm.write(0);
  delay(200);
  servoArm.detach();
  Arm_Position = 0;
}

//***************************** OPEN LID ************************************
void openLid() {
  servoLid.attach(lid);
  servoLid.write(135);
  delay(300);
}
//*************************** CLOSE LID **************************************
void closeLid() {
  servoLid.write(75);
  delay(300);
  servoLid.detach();
}

//************************ CALIBRATION *********************************
void correctPositionRight() {
  switch (motorPosition) {
    case 3:
      right(1);
      break;
    case 6:
      right(1);
      break;
    case 7:
      right(1);
      break;
  }
}

void correctPositionLeft() {
  switch (motorPosition) {
    case 3:
      left(1);
      break;
    case 6:
      left(1);
      break;
    case 7:
      left(1);
      break;
  }
}

//****************************** MOVE RIGHT ******************************************
int right(int xp)  {    // RIGH
  for (int j = 0; j < xp; j++) {
    digitalWrite(S1, HIGH);
    digitalWrite(S2, LOW);
    digitalWrite(S3, HIGH);
    digitalWrite(S4, LOW);
    delayMicroseconds(Delay);
    digitalWrite(S1, LOW);
    digitalWrite(S2, HIGH);
    digitalWrite(S3, HIGH);
    digitalWrite(S4, LOW);
    delayMicroseconds(Delay);
    digitalWrite(S1, LOW);
    digitalWrite(S2, HIGH);
    digitalWrite(S3, LOW);
    digitalWrite(S4, HIGH);
    delayMicroseconds(Delay);
    digitalWrite(S1, HIGH);
    digitalWrite(S2, LOW);
    digitalWrite(S3, LOW);
    digitalWrite(S4, HIGH);
    delayMicroseconds(Delay);
  }
}

//****************************** MOVE LEFT ******************************************
int left(int xl)   {       // LEFT
  for (int i = 0; i < xl; i++)  {
    digitalWrite(S1, LOW);
    digitalWrite(S2, HIGH);
    digitalWrite(S3, LOW);
    digitalWrite(S4, HIGH);
    delayMicroseconds(Delay);
    digitalWrite(S1, LOW);
    digitalWrite(S2, HIGH);
    digitalWrite(S3, HIGH);
    digitalWrite(S4, LOW);
    delayMicroseconds(Delay);
    digitalWrite(S1, HIGH);
    digitalWrite(S2, LOW);
    digitalWrite(S3, HIGH);
    digitalWrite(S4, LOW);
    delayMicroseconds(Delay);
    digitalWrite(S1, HIGH);
    digitalWrite(S2, LOW);
    digitalWrite(S3, LOW);
    digitalWrite(S4, HIGH);
    delayMicroseconds(Delay);
  }
}
//**************************************WYLACZ SILNIK  -- Turn the motor Off*********************************
void motorOFF()
{
  digitalWrite(S1, LOW);
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  digitalWrite(S4, LOW);
}

void action1()
{
  if (digitalRead(P1) == HIGH)
  {
    Loop = 0;
    button1();
  }
}
void action2()
{
  if (digitalRead(P2) == HIGH)
  {
    Loop = 0;
    button2();
  }
}
void action3()
{
  if (digitalRead(P3) == HIGH)
  {
    Loop = 0;
    button3();
  }
}
void action4()
{
  if (digitalRead(P4) == HIGH)
  {
    Loop = 0;
    button4();
  }
}
void action5()
{
  if (digitalRead(P5) == HIGH)
  {
    Loop = 0;
    button5();
  }
}
//void action6()
//{
//  if (digitalRead(P6) == HIGH)
//  {
//    Loop = 0;
//    button6();  // button6
//  }
//}
//void action7()
//{
//  if (digitalRead(P7) == HIGH)
//  {
//    Loop = 0;
//    button7();
//  }
//}
//*************************************START*******************************************
void start()
{
  if (motorPosition == 0)
  {
    right(5);
    motorPosition++;
  }
}
//1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
void button1()  // button1
{
  start();
  if (motorPosition < 1)
  {
    while (motorPosition < 1)
    {
      right(steps);
      motorPosition++;
      correctPositionRight();
    }
  }
  if (motorPosition > 1)
  {
    while (motorPosition > 1)
    {
      left(steps);
      correctPositionLeft();
      motorPosition--;
    }
  }
  if (motorPosition == 1)
  {
    if (servoLid.read() != 135)  //servo flaps
    {
      openLid();      //Openly
    }
    while (digitalRead(P1) != LOW)
    {
      arm_High();
      arm_Middle();  //Lower the Arm
    }
  }
}
//2222222222222222222222222222222222222222222222222222222222222222222222222222222222
void button2()  //button2
{
  start();
  if (motorPosition < 2)
  {
    while (motorPosition < 2)
    {
      right(steps);
      motorPosition++;
      correctPositionRight();
    }
  }
  if (motorPosition > 2)
  {
    while (motorPosition > 2)
    {
      left(steps);
      correctPositionLeft();
      motorPosition--;
    }
  }
  if (motorPosition == 2)
  {
    if (servoLid.read() != 135)  //Servo Flaps
    {
      openLid();
    }
    while (digitalRead(P2) != LOW)
    {
      arm_High();
      arm_Middle();
    }
  }
}
//33333333333333333333333333333333333333333333333333333333333333333333333333
void button3()
{
  start();
  if (motorPosition < 3)
  {
    while (motorPosition < 3)
    {
      right(steps);
      motorPosition++;
      correctPositionRight();
    }
  }
  if (motorPosition > 3)
  {
    while (motorPosition > 3)
    {
      left(steps);
      correctPositionLeft();
      motorPosition--;
    }
  }
  if (motorPosition == 3)
  {
    if (servoLid.read() != 135)
    {
      openLid();
    }
    while (digitalRead(P3) != LOW)
    {
      arm_High();
      arm_Middle();
    }
  }
}
//44444444444444444444444444444444444444444444444444444444444444444444444444444
void button4()
{
  start();
  if (motorPosition < 4)
  {
    while (motorPosition < 4)
    {
      right(steps);
      motorPosition++;
      correctPositionRight();
    }
  }
  if (motorPosition > 4)
  {
    while (motorPosition > 4)
    {
      left(steps);
      correctPositionLeft();
      motorPosition--;
    }
  }
  if (motorPosition == 4)
  {
    if (servoLid.read() != 135)
    {
      openLid();
    }
    while (digitalRead(P4) != LOW)
    {
      arm_High();
      arm_Middle();
    }
  }
}
//55555555555555555555555555555555555555555555555555555555555555
void button5()
{
  start();
  if (motorPosition < 5)
  {
    while (motorPosition < 5)
    {
      right(steps);
      motorPosition++;
      correctPositionRight();
    }
  }
  if (motorPosition > 5)
  {
    while (motorPosition > 5)
    {
      left(steps);
      correctPositionLeft();
      motorPosition--;
    }
  }
  if (motorPosition == 5)
  {
    if (servoLid.read() != 135)
    {
      openLid();
    }
    while (digitalRead(P5) != LOW)
    {
      arm_High();
      arm_Middle();
    }
  }
}
////666666666666666666666666666666666666666666666666666666666666666666666666
//void button6()
//{
//  start();
//  if (motorPosition < 6)
//  {
//    while (motorPosition < 6)
//    {
//      right(steps);
//      motorPosition++;
//      correctPositionRight();
//    }
//  }
//  if (motorPosition > 6)
//  {
//    while (motorPosition > 6)
//    {
//      left(steps);
//      correctPositionLeft();
//      motorPosition--;
//    }
//  }
//  if (motorPosition == 6)
//  {
//    if (servoLid.read() != 135)
//    {
//      openLid();
//    }
//    while (digitalRead(P6) != LOW)
//    {
//      arm_High();
//      arm_Middle();
//    }
//  }
//}
////7777777777777777777777777777777777777777777777777777777777777777777777777777
//void button7()
//{
//  start();
//  if (motorPosition < 7)
//  {
//    while (motorPosition < 7)
//    {
//      right(steps);
//      motorPosition++;
//      correctPositionRight();
//    }
//  }
//  if (motorPosition > 7)
//  {
//    while (motorPosition > 7)
//    {
//      left(steps);
//      correctPositionLeft();
//      motorPosition--;
//    }
//  }
//  if (motorPosition == 7)
//  {
//    if (servoLid.read() != 135)
//    {
//      openLid();
//    }
//    while (digitalRead(P7) != LOW)
//    {
//      arm_High();
//      arm_Middle();
//    }
//  }
//}
//****************************************LOOP******************************
void loop()
{
  //servoArm.detach();
  //servoLid.detach();
  //  action1();
  //  action2();
  //  action3();
  //  action4();
  //  action5();
  //  action6();
  //  action7();
  //  action6();
  //  action5();
  //  action4();
  //  action3();
  //  action2();
  //  action1();

  action1();
  action2();
  action3();
  action4();
  action5();
  action4();
  action3();
  action2();
  action1();
  Loop++;
  delay(2);
  if (Loop == 2)
  {
    arm_Low(); //Close the Arm to O
    closeLid();      //Close
  }
  if (Loop == 100) {
    while (digitalRead(Home) < HIGH) {
      left(1);
    }
    motorOFF();
    Loop = 0;
    motorPosition = 0;
  }
}
