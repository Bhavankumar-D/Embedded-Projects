#include <LiquidCrystal.h>
int c=0;
int button=2;
int a=3;
int b=4;
int Green=A0;
const int rs = 12, en = 13, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void AND(){
  if(digitalRead(a)==HIGH && digitalRead(b)==HIGH){
    digitalWrite(Green,HIGH);
    lcd.println("\n1");
     delay(100);
  }
  else{
    digitalWrite(Green,LOW);
    lcd.println("\n0");
     delay(100);
  }
}
void OR(){
  if(digitalRead(a)==LOW && digitalRead(b)==LOW){
     digitalWrite(Green,LOW);
     lcd.println("\n0");
     delay(100);
  }
  else{
   digitalWrite(Green,HIGH);
   lcd.println("\n1");
   delay(100);
  }
}
void NOT(){
  if(digitalRead(a)==HIGH){
    digitalWrite(Green,LOW);
    lcd.println("\n0");
     delay(100);
  }
  else{
    digitalWrite(Green,HIGH);
    lcd.println("\n1");
     delay(100);
  }
} 
void setup() {
  pinMode(button,INPUT);
  pinMode(a,INPUT);
  pinMode(b,INPUT);
  pinMode(A0,OUTPUT);
  lcd.begin(16,2);
  Serial.begin(9600);
  delay(500);
}


void loop() {
  if(digitalRead(button)==HIGH){
    c++;
    delay(200);
  }
 
  if(c==1){
    AND();
    lcd.clear();
    lcd.println("AND gate");
    delay(100);
  }
  else if(c==2){
    OR();  
    lcd.clear();
    lcd.println("OR gate");
    delay(100);
  }
  else if(c==3){
    NOT();
    lcd.clear();
    lcd.println("NOT gate");
    delay(100);
    
  }
  else if(3<c)
  {
    c=1;
    delay(10);
    
  }
}
