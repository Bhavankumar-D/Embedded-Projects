#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
float x=0.00;
void setup() {
  lcd.begin(16, 2);
}

void loop() {
  int s1 = analogRead(A0);
  int s2 = analogRead(A5);
  lcd.clear();
  float voltage=(s1*(5.0/1023.0));
  lcd.println(voltage);
  delay(500);
  float v=(s2*(5.0/1023.0));
  lcd.println(v);
  delay(500);
if(x<voltage){
  lcd.println("Vol UP");
  delay(300);
}
else if(x>voltage){
  lcd.println("Vol DOWN");
  delay("300");
}
  s1 = analogRead(A0);
  lcd.clear();
  voltage=(s1*(5.0/1023.0));
  lcd.print(voltage);
  delay(100);
  {
  if(voltage>=1.00){
    digitalWrite(A1,HIGH);
    x++;
    if(voltage>=2.00){
      digitalWrite(A2,HIGH);
      x++;
      if(voltage>=3.00){
          digitalWrite(A3,HIGH);
          x++;
          if(voltage>=4.00){
            digitalWrite(A4,HIGH);
            x++;
             if(voltage>=5.00){
             digitalWrite(9,HIGH);
             x++;
             }
             else{
              digitalWrite(9,LOW);
              x--;
             }
         }
         else{
          digitalWrite(A4,LOW);
          x--;
         }
     }
     else{
      digitalWrite(A3,LOW);
       x--;
     }
  }
  else{
    digitalWrite(A2,LOW);
     x--;
  }
  }
else{
    digitalWrite(A1,LOW);
     x--;
  }
  
  }
  x=voltage;
}
