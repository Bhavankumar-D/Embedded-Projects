int entry=7;
const int green=A0;
int c=0;
int x=0;
int n=0;
void setup() {
  pinMode(entry,INPUT);
  pinMode(A0,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(entry)==HIGH){
    x=1;
  }
  else{
    x=0;
  }
  while(x){
  c++ ;
  x=0;
  }
  for(int i=0;i<c;i++){
    digitalWrite(A0,HIGH);
    delay(1000);
    digitalWrite(A0,LOW);
    delay(1000);
  }

}
