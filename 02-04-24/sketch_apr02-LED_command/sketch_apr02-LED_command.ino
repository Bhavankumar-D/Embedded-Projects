int c=0;
int count=3;
int trigger=2;
int Green=A0;
void setup() {
  pinMode(count,INPUT);
  pinMode(trigger,INPUT);
  pinMode(Green,OUTPUT);
  delay(100);
  Serial.begin(9600);
}

void loop() {
 if(digitalRead(count)==HIGH){
  c++;
  delay(500);
 }
 if(digitalRead(trigger)==HIGH){
  if(c>0){
    c--;
    digitalWrite(Green,HIGH);
    delay(500);
    digitalWrite(Green,LOW);
    delay(500);
  }
  else{
    digitalWrite(Green,LOW);
  }
 }

}
