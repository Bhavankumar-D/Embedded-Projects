#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2,Green=A1;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int day=0;
int unit=0;
int temp=0,total=0;
void setup() {
  lcd.begin(16, 2);
}

void loop() {
  while(1){
  int sensorValue1 = analogRead(A0);
  int sensorValue2 = analogRead(A1);
  int sensorValue3 = analogRead(A2);
  float voltage1 = sensorValue1 * (5.0 / 1023.0);
  float voltage2 = sensorValue2 * (5.0 / 1023.0);
  float voltage3 = sensorValue3 * (5.0 / 1023.0);
   float power1 = (voltage1 * 46);
   float power2 = (voltage2 * 46);
   float power3 = (voltage3 * 46);
   total=voltage1+voltage2+voltage3;
    if(digitalRead(A3)==HIGH){
      day++;
    }
        if(total==5){
          unit+=1;
        }
        else if(total==10){
          unit+=2;
        }
        else{
          unit+=3;
        }
       
      
    lcd.println("Day");
    lcd.println(day);
    delay(500);
    lcd.clear();
     lcd.println("Unit");
    lcd.println(unit);
        delay(500);
  } 
   }
