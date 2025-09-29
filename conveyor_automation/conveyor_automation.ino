#include<LiquidCrystal.h>
#include <EEPROM.h>
const int rs=13,e=12,d4=11,d5=10,d6=9,d7=8;
LiquidCrystal lcd(rs,e,d4,d5,d6,d7);
int loadh=0;
int loadl=0;
int rd;
int volt;
int e1;
int e11=0 ;
int e2;
int e22=1 ;
void valueh(){
   e1=EEPROM.read(e11);

  if(digitalRead(6)==HIGH)
  {
    e1=EEPROM.read(e11);  
    loadh=e1;
    loadh=loadh+10; 
    e1=loadh;
     EEPROM.write(e11, e1);
  } 

}
void valuel(){
   e2=EEPROM.read(e22);
  if(digitalRead(7)==HIGH)
  {
     e2=EEPROM.read(e22); 
      loadl=e2; 
    loadl=loadl+10; 
    e2=loadl;
    EEPROM.write(e22, e2);
  } 
}

void load(){
  if((volt>=220)&&(e2<=rd)&&(rd<=e1)) {
    digitalWrite(5,LOW);
    delay(200);
 
  }
  else{
    digitalWrite(5,HIGH);
    delay(200);
  }
}
void rese(){
  if(digitalRead(4)==HIGH){
    EEPROM.update(e11, 0);
    EEPROM.update(e22, 0);
  }
  }
  void ind(){
    if(rd>=(e1-2)){
    digitalWrite(3,HIGH);
    delay(200);
    digitalWrite(3,LOW);
    delay(200);
  }
   if(rd<=(e2-2)){
    digitalWrite(3,HIGH);
    delay(200);
    digitalWrite(3,LOW);
    delay(200);
  }
}

void setup(){
  lcd.begin(16,2);
  //lcd.print("hello");
  //delay(200);
  pinMode(7,INPUT);
   pinMode(6,INPUT);
    pinMode(5,OUTPUT);
    pinMode(3,OUTPUT);
  pinMode(A0,INPUT); 
   
}
void loop(){
  lcd.clear();
  rd=analogRead(A0);
  rd=rd/10.2;
  volt=analogRead(A1);
  volt=volt/4.43;
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("volt:");
  lcd.print(volt);
  
  lcd.setCursor(9,0);
  lcd.print("load:");
  lcd.print(rd);
  delay(200);
  
  lcd.setCursor(0,1);
  lcd.print("maxl:");
  lcd.print(e1);
    delay(200);

    lcd.setCursor(9,1);
    lcd.print("minl:");
    lcd.print(e2);
    delay(200);
  valueh();
  valuel();
  load();
  rese();
  ind();
  
}
