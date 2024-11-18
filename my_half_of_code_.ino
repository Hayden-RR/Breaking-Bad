#include <Servo.h>

Servo rvservo; //servo for the rv
Servo jessieservo; //servo for pushing jessie out of the house 
Servo waltFaint; //servo for walter fainting 
const int waltParty = 13; //button for the tv lights
const int walterWipe = 2; //button for first interaction 
const int waltCar = 4; //button for the car moving to jessie
const int tvLED = 6;
const int lungCancerPin = 11; //lung cancer diagnosis switch
  int lungCancerState = 0;
  int LastlungCancerState = 0;
  bool lungCancer = false; 
const int moneyBillPin = 12; //the bill switch
  int moneyBillState = 0;
  int LastmoneyBillState = 0;
  bool moneyBill = false; 
const int waltLabPin = 7; //walter in the lab light
  int waltLabState = 0;
  int LastwaltLabState = 0;
  bool waltLab = false;
const int jessieLabPin = 8; //jessie in the lab
  int jessieLabState = 0;
  int LastjessieLabState = 0;
  bool jessieLab = false;
const int waltjessieLED = 9;

void setup() {
  rvservo.attach(3);
  jessieservo.attach(5);
  pinMode(waltCar, INPUT);
  waltFaint.attach(10);
  pinMode(walterWipe,INPUT);
  pinMode(lungCancerPin, INPUT);
  pinMode(moneyBillPin, INPUT);
  pinMode(waltParty, INPUT);
  pinMode(tvLED, OUTPUT);
  pinMode(waltLabPin, INPUT);
  pinMode(jessieLabPin, INPUT);
  pinMode(waltjessieLED, OUTPUT);
}

void loop() {
  //walter fainting
if (digitalRead(walterWipe) == HIGH){
    waltFaint.write (180);
  }else{
    waltFaint.write(0);
  }

lungCancerState = digitalRead(lungCancerPin);
moneyBillState = digitalRead(moneyBillPin);
//reading lung cancer
if (lungCancerState != LastlungCancerState) {
  if (lungCancerState == HIGH){
    lungCancer = true;
  }
}

//reading money bill
if (moneyBillState != LastmoneyBillState) {
  if (moneyBillState == HIGH) {
    moneyBill = true;
  }
}
//rv should open
if (lungCancer && moneyBill) {
  rvservo.write(180);
}

LastlungCancerState = lungCancerState;
LastmoneyBillState = moneyBillState;
// tv lights
if (digitalRead(waltParty) == HIGH){
  digitalWrite(tvLED, HIGH);
}else{
  digitalWrite(tvLED, LOW);
}
// jessie falling out of a house
if (digitalRead(waltCar) == HIGH){
    jessieservo.write(180);
  }else{
    jessieservo.write(0);
  }
//walter and jessie getting into the lab
waltLabState = digitalRead(waltLabPin);
jessieLabState = digitalRead(jessieLabPin);

//reading walts location 
if (waltLabState != LastwaltLabState){
  if (waltLabState == HIGH){
    waltLab = true;
  }
}

//Reading jessies location 
if (jessieLabState != LastjessieLabState){
  if (jessieLabState == HIGH){
    jessieLab = true;
  }
}

if (waltLab && jessieLab) {
  digitalWrite(waltjessieLED, HIGH);
}else{
  digitalWrite(waltjessieLED, LOW);
}

LastwaltLabState = waltLabState;
LastjessieLabState = jessieLabState;



}
