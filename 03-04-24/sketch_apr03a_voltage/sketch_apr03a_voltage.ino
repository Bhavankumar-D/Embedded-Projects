#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2,Green=A1;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  pinMode(A1,OUTPUT);
  lcd.begin(16, 2);
}

void loop() {
  int sensorValue = analogRead(A0);
  lcd.clear();
  float voltage = sensorValue * (5.0 / 1023.0);
  lcd.print(voltage);
  delay(100);
  if(voltage>=2.50 && voltage<=3.00){
    digitalWrite(Green,HIGH);
  }
  else{
    digitalWrite(Green,LOW);
  }
}
