#include <LiquidCrystal.h>
int entryPin = 2;
int exitPin = 3;
const int green=A0,yellow=A1, red=A2;
int studentCount = 0;
int x=0;
int y=0;
int count=0;
int z=0;
const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
   pinMode(entryPin, INPUT);
   pinMode(exitPin, INPUT);
   pinMode(A0, OUTPUT);
    pinMode(A1, OUTPUT);
   pinMode(A2, OUTPUT);
   lcd.begin(16, 2);
        lcd.setCursor(5,1);
        // print the letter:
        lcd.write("welcome");
        delay(200);
              Serial.begin(9600);
       }

  void loop()
 
{

     

  lcd.clear();
    lcd.setCursor(0,0);
     lcd.write("TOTAL COUNT");
        delay(100);
     lcd.setCursor(10,1);
     lcd.print(count);
       delay(100);
   
   
  if (digitalRead(entryPin) == HIGH ) {
     x=1;
     lcd.clear();
    lcd.setCursor(0,0);
     lcd.write(">>>>>>");
        delay(100);
     delay(100);
     delay(100);
  }

  else{
  x=0;
  }

    if (digitalRead(exitPin) ==HIGH ) {
     y=1;
       lcd.clear();
    lcd.setCursor(0,0);
     lcd.write("PERSON ENTERED");
        delay(100);
     delay(100);
     delay(100);
    }

    else{
      y=0;
    }

    while(x)
    {
      if (digitalRead(exitPin) == HIGH && count<=10)
      {
if(count<11)
      {
       
       count++;
 
      }
         lcd.clear();
    lcd.setCursor(0,0);
     lcd.write("PERSON ENTERED");
        delay(100);
     delay(100);
         Serial.print("total count =");
      Serial.println(count);
            delay(100);
          x=0;
      }
    }
    while(y)
    {
      if (digitalRead(entryPin) == HIGH && count>0) {
          lcd.clear();
    lcd.setCursor(0,0);
     lcd.write("PERSON EXIT");
        delay(100);
     delay(100);
       count--;
        Serial.print("total count =");
      Serial.println(count);
       
     y=0;
      }
    }
if(count>=0 && count<=4){
  digitalWrite(A0,HIGH);
}
else{
 digitalWrite(A0,LOW);
}
if(count>=5&& count<=8){
  digitalWrite(A1,HIGH);
}
else{
  digitalWrite(A1,LOW);
}
if(count>=9){
  digitalWrite(A2,HIGH);
}
else{
  digitalWrite(A2,LOW);
}
  }
