#include<LiquidCrystal.h>

#include <Servo.h>
int a;
int b;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int rs = D19, en =D23, d4 = D18, d5 = TX2, d6 = RX2, d7 = D15;

Servo myservo;  
int pos = 0;  
void setup(){
  lcd.begin(16,2);  
  lcd.print("welcome");
  delay(100);
 pinMode(D34,INPUT);
pinMode(D35,INPUT);
myservo.attach(2);  
}
void loop() {
  a=analogRead(D34);
  a=a/10.2;
 
  b=analogRead(D35);
  b=b/10.2;
 
  if(a>10){
    lcd.clear();
  lcd.print("forward");
  delay(100);  
  for (pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos);              
    delay(15);                      
  }
  }
  if(b>10){
    lcd.clear();
    lcd.print("reverse");
  delay(100);
  for (pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);          
    delay(15);                    
  }
}
