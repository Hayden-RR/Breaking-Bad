#include <Servo.h>

Servo rvservo; //servo for the rv
Servo jessieservo; //servo for pushing jessie out of the house 
const int walterWipe = 2; //button for first interaction 
const int waltCar = 4; //button for the car moving to jessie
 

void setup() {
  rvservo.attach(3);
  pinMode(walterWipe, INPUT);
  jessieservo.attach(5);
  pinMode(waltCar, INPUT);

}

void loop() {
  if (digitalRead(walterWipe) == HIGH){
    rvservo.write(180);
  }else{
    rvservo.write(0);
  }
  
  if (digitalRead(waltCar) == HIGH){
    jessieservo.write(180);
  }else{
    jessieservo.write(0);
  }
  
}
