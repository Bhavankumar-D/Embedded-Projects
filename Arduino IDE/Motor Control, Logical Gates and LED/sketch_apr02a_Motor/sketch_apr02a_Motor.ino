int a=11,b=12,c=13;
int out=10;
int Green=A0,Yellow=A1,Red=A2;
void setup() {
  pinMode(11,INPUT);
  pinMode(12,INPUT);
  pinMode(13,INPUT);
  pinMode(10,OUTPUT);
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(a)==HIGH){
    digitalWrite(A0,HIGH);
    }
    else{
      digitalWrite(A0,LOW);
    }
  if(digitalRead(b)==HIGH){
      digitalWrite(A0,LOW);
      digitalWrite(A1,HIGH);
      }
    if(digitalRead(c)==HIGH){
        digitalWrite(A0,LOW);
        digitalWrite(A1,LOW);
        digitalWrite(A2,HIGH);
        digitalWrite(10,HIGH);
      }
      if(digitalRead(c)==LOW && digitalRead(b)==LOW){
        digitalWrite(10,LOW);
        digitalWrite(A1,LOW);
        digitalWrite(A2,LOW);
      }

}
