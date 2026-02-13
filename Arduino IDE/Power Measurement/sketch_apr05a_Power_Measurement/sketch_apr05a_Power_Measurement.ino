#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2,Green=A1;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  int sensorValue1 = analogRead(A0);
  int sensorValue2 = analogRead(A1);
  float voltage1 = sensorValue1 * (5.0 / 1023.0);
  float voltage2 = sensorValue2 * (5.0 / 1023.0);
   float power1 = (voltage1 * 46);
   float power2 = (voltage2 * 46);
  if(voltage1>0 && voltage2==0){
     lcd.clear();
     lcd.println("Lamp");
    lcd.print(power1);
    delay(500);
  }
  else{
    lcd.clear();
  }
  if(voltage2>0 && voltage1==0){
    lcd.clear();
    lcd.println("Motor");
    lcd.println(power2);
    delay(500);
  }
  else{
    lcd.clear();
  }
  if(voltage2>0 && voltage1>0){
    lcd.clear();
    lcd.println("Total");
    float power = (power1+power2);
    lcd.print(power);
    delay(500);
  
}
else{
    lcd.clear();
  }
}
