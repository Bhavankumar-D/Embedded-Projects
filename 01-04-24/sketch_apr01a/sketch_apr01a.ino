
#include <LiquidCrystal.h>
int x,y;
int count=0;
const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup(){
  Serial.begin(9600);
pinMode(2,INPUT);
pinMode(3,INPUT);


}
void loop()
{
lcd.begin(16, 2);
lcd.setCursor(1,1);
lcd.print("hello");
delay(1000);
lcd.clear();  
if(digitalRead(2)){
   x=1;
   delay(100);
}
else{
  x=0;
}
  if(digitalRead(3)){ 
    y=1;
     delay(100);
  }
  
  else{
    y=0;
  }
  
    while(x){

      if(digitalRead(3)==HIGH && count<10)
      {
       
       if(count<11){
        count++;
       }
     lcd.print("enter person");
    lcd.print(count);
    lcd.clear();
    delay(100);
      x=0;
      }
      
    }
    
while(y){

      if(digitalRead(2)==HIGH && count>0)
     {  
      count--;
     lcd.print("exit person");
    lcd.print(count);
    lcd.clear();
    delay(100);
      y=0;}
      
    }

  

}
