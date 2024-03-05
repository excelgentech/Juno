#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver myServo = Adafruit_PWMServoDriver();

uint8_t servonum = 0;

void setup() {
  
  Serial.begin(9600);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  myServo.begin();
  myServo.setPWMFreq(60);
  delay(10);
}

void loop() {
  int pos;
  int i;
  for(i=0;i<3;i++){
  for(pos=60;pos<=300;pos++){
    myServo.setPWM(0, 0, pos);
    delay(15);
    digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  }
  for(pos=300;pos>=60;pos--){
    myServo.setPWM(0, 0, pos);
    delay(15);
  }
  
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
}
}