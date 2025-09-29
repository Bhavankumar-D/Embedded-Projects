#include <ESP8266WiFi.h>
#include <Servo.h>
#define SOUND_VELOCITY 0.034
#define CM_TO_INCH 0.393701

const int trigPin = D3;
const int echoPin = D4;

Servo servo;  // create servo object to control a servo

long duration;
float distanceCm;
float distanceInch;

void setup() {
  // Initialize the Serial to communicate with the Serial Monitor.
  Serial.begin(115200);
  Serial.print("welcome");
   pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(D6,OUTPUT);
  servo.attach(D0);  // attaches the servo on pin D5 to the servo object
}

void loop()
{


 servo.write(90);
 delay(10);
 
   digitalWrite(D6, HIGH);

   
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
 
  // Calculate the distance
  distanceCm = duration * SOUND_VELOCITY/2;
 

 
  // Prints the distance on the Serial Monitor
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);
  delay(1000);


  // reads the value of the potentiometer (value between 0 and 1023

  // scales it to use it with the servo (value between 0 and 180)
 

 if(distanceCm<5)
 {
    Serial.print("Distance (cm): ");
   servo.write(30);
   digitalWrite(D6, LOW);
   delay(300);
    digitalWrite(D6, HIGH);
   delay(2000);
 }
}
