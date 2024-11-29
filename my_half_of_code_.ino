


#include <Servo.h>

Servo rvservo; //servo for the rv
Servo jessieservo; //servo for pushing jessie out of the house 
Servo waltFaint; //servo for walter fainting 
const int waltParty = 13; //button for the tv lights
const int walterWipe = 2; //button for first interaction 
const int waltCar = 4; //button for the car moving to jessie
const int tvLED = 6;
const int lungCancer = 11; //lung cancer diagnosis switch
const int boysLab = 7; //walter and jessie lab light
const int waltjessieLED = 9;
const int labTable = 8;
const int labLED = 12;

void setup() { 

  
  rvservo.attach(3);
  rvservo.write(90);
  jessieservo.attach(5);
  pinMode(waltCar, INPUT);
  waltFaint.attach(10);
  pinMode(walterWipe,INPUT);
  pinMode(lungCancer, INPUT);
  pinMode(waltParty, INPUT);
  pinMode(tvLED, OUTPUT);
  pinMode(boysLab, INPUT);
  pinMode(waltjessieLED, OUTPUT);
  pinMode(labTable, INPUT);
  pinMode(labLED, OUTPUT);
}

void loop() {
  //walter fainting
if (digitalRead(walterWipe) == HIGH){
    waltFaint.write (10);
  }else{
    waltFaint.write(0);
  }

//reading lung cancer
if (digitalRead(lungCancer) == HIGH){
  rvservo.write(135);
  delay(10000);

  rvservo.write(90);
  while(true);
}


// tv lights
if (digitalRead (waltParty) == HIGH){
  digitalWrite(tvLED, HIGH);
}else{
  digitalWrite(tvLED, LOW);
}



// jessie falling out of a house
if (digitalRead(waltCar) == HIGH){
    jessieservo.write(10);
  }else{
    jessieservo.write(0);
  }

//walt and jessie lab lights 
if (digitalRead(boysLab) == HIGH){
  digitalWrite(waltjessieLED, HIGH);
}else{
  digitalWrite(waltjessieLED, LOW);
}

//lab table lights 
if (digitalRead(labTable) == HIGH){
  digitalWrite(labLED, HIGH);
}else{
  digitalWrite(labLED, LOW);
}




}
