#include<LiquidCrystal.h>  // including lcd library
#include <Servo.h> // including servo motor library

LiquidCrystal lcd (12,11,5,4,3,2);
int sensor = 10;
int val = 0;
int motor = 6;
Servo myservo;

void setup() {
  pinMode (sensor, INPUT);
  pinMode (motor, OUTPUT);
  pinMode (9, OUTPUT);
  pinMode (8, OUTPUT);
  lcd.begin (16,2);
  myservo.attach(motor, 500, 2500);
}

void  loop() {
  int analogSensor = analogRead(A1);
  val = digitalRead (sensor);
  
  lcd.setCursor(0,1);
  lcd.print("LDR value: ");
  lcd.print(analogSensor);
	  
  if (val == HIGH){ // when motion is detected
    lcd.setCursor(0,0);
    lcd.print("Motion Detected!");
    myservo.write(90);
    digitalWrite(9, HIGH);
    delay(2000);
    lcd.clear();
  }
  else { // when no motion is detected
    lcd.setCursor(0,0);
    lcd.print("Motion Stopped!");
    myservo.write(0);
    digitalWrite(9, LOW);
    delay(2000);
    lcd.clear();
  }
  
  if (analogSensor < 500) {
  	digitalWrite(8, HIGH);
  }
  else {
  	digitalWrite(8, LOW);
  }
}