#include <Servo.h>

Servo rvservo; //servo for the rv
const int walterWipe = 2;
 

void setup() {
  rvservo.attach(3);
  pinMode(walterWipe, INPUT);

}

void loop() {
  if (digitalRead(walterWipe) == HIGH){
    rvservo.write(180);
  }else{
    rvservo.write(0);
  }
  

}
