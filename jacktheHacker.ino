
#include <Wire.h>

#include "rgb_lcd.h"

//Servo myservo;
rgb_lcd lcd;
const int analogInPin = A0;
const int analogMois = A2;
const int LightIntensity = A3;
int y,a,b,z,c;

void setup()
{
  Serial.begin(9600);
  /// FOR LCD 
  // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
  ////
//  myservo.attach(6); 
pinMode(7,OUTPUT);
pinMode(6,OUTPUT);
}

void loop()
{
  a =  analogRead(analogInPin);
  b = analogRead(analogMois);
  c = analogRead(LightIntensity);
  z = map(b,15,380,0,90);
  y = map(a,560,670,20,40);
  tempRangeColor(y);
  if(z+17>=99) z = 99-17;
  if(z+17 <10) z = 99-17;
  
  printMessage(y,z+17);
  
  
  //Serial.print(c);
  // Serial.print(b);
  //Serial.print(y);
  //Serial.print("\n");
 // LightCondition(c);
 
  if(c<400)digitalWrite(7,HIGH);
  else digitalWrite(7,LOW);


// analogWrite(6,800);
 

  if(z+17 > 80) stopTap();
  else startTap();
 
  
  delay(200);
}

  
void printMessage(int temp,int humidity)
{
  lcd.clear();
  lcd.print("Temp:");
  lcd.print(temp);
  lcd.print(" Humid:");
  lcd.print(humidity);
}


void startTap()
{
  digitalWrite(6,HIGH);
}

void stopTap()
{
  digitalWrite(6,LOW);
}

void tempRangeColor(int x)
{
  if(x>20 && x<25) lcd.setRGB(100,125,150);
  else if(x>25 && x<30) lcd.setRGB(175,100,100);
  else if(x>30 && x<35) lcd.setRGB(225,50,80);
  else if(x>35) lcd.setRGB(255,0,0);
}

void LightCondition(int val)
{
  if(val<400) digitalWrite(7,HIGH);
  if(val>400) digitalWrite(7,LOW);
}
 
