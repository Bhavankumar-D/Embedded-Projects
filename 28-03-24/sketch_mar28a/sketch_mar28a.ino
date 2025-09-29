int x,y;
int count=0,c=0;

void setup(){
  Serial.begin(9600);
pinMode(2,INPUT);
pinMode(3,INPUT);
delay(1000);
}
void loop()
{

      Serial.println("waiting for data");
    delay(100);
    
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

      if(digitalRead(3))
      {
       count++;
     Serial.println("enter person");
    Serial.println(count);
    delay(1000);
      x=0;
      }
      
    }
    
while(y){

      if(digitalRead(2) && count >0)
     {  count--;
     Serial.println("exit person");
    Serial.println(count);
    delay(1000);
      y=0;}
      
    }

  

}
