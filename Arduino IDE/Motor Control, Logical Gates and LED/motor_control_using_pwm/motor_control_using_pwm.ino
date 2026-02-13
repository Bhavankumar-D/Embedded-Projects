

             
int brightness = 0;   
int fadeAmount = 5;    


void setup() {
  
  pinMode(9, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(4,INPUT);
  pinMode(3,INPUT);
  pinMode(2,INPUT);
}


void loop() {
  
  analogWrite(9, brightness);
  if(digitalRead(2)==HIGH){
  brightness = brightness + fadeAmount;

  
  if (brightness <= 0 || brightness >= 255) 
  {
    fadeAmount = -fadeAmount;
    delay(500);
  }
  }
  
 
  if(digitalRead(4)==HIGH)
  {
    digitalWrite(A0,HIGH);
       digitalWrite(A1,LOW);
    delay(500);
  }
  if(digitalRead(3)==HIGH)
  {
    digitalWrite(A1,HIGH);
     digitalWrite(A0,LOW);
    delay(500);
  }
  
  
}
