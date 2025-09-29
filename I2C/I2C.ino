#include <SPI.h>

/*Define the pins we are using on the Arduino Board and
  cross reference them with the pins on the Shift register
  so you can give them appropriate names*/
int latchpin = 10;
int datapin = 11;
int clockpin = 13;

//Define a Variable to use for the data we are going to send,
byte data = 0;



void setup() {

  SPI.begin();                              //Start the SPI library
  SPI.setBitOrder(LSBFIRST);                //Set LSB as bit order, this means we will send the least significant bit first and it will be written to Q7 = Register Pin 7 with the most significant bit being written last to Q0 or Pin 15
  /*Configure the Arduino pins we use as OUTPUT, so they can send
     data to the Shift Register
  */
  pinMode(latchpin, OUTPUT);
  pinMode(datapin, OUTPUT);
  pinMode(clockpin, OUTPUT);

  delay(500);
}

void loop() {
  for (data = 0; data < 256; data  )        //For loop to set data = 0 then increase it by one for every iteration of the loop, when the counter reaches the condition (256) it will be reset
  {
    digitalWrite(latchpin, LOW);            //Write our Slave select low to enable the SHift register to begin listening for data
    SPI.transfer(data);                     //Transfer the 8-bit value of data to shift register, remembering that the least significant bit goes first
    digitalWrite(latchpin, HIGH);           //Once the transfer is complete, set the latch back to high to stop the shift register listening for data
    delay(500);                             //Delay program for 500ms
  }

}
