void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  float snk=analogRead(A0);
  snk=(snk/1023)*5;
  Serial.println(snk);
  delay(1500);

}
