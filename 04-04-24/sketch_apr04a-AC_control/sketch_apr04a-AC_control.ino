#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int t=15;
int a=6;
int b=7;
void setup() {
  lcd.begin(16, 2);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  lcd.print("WELCOME");
  delay(200);
  
}

void loop() {
  if(analogRead(6==HIGH)){
    t++;
  }
  if(analogRead(7==HIGH)){
    t--;
  }
  lcd.clear();
  lcd.print(t);
  delay(500);
  if(t>=18 && t<=28){
    digitalWrite(A2,HIGH);
  }
  }
