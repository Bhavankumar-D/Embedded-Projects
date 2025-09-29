#include <16f887.h>
#fuses hs,nowdt,nocpd,nolvp,noprotect
#use delay(clock=20m)
#include <flex_lcdk1.c>
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)

#define TRIGGER_PIN PIN_c3
#define ECHO_PIN PIN_c4

float distance;
int a;
signed int16 s=0,s1;
void main()
{
 lcd_init();
     printf(lcd_putc,"\fUltrasonic Sensor\n Test");
     delay_ms(1500);
 setup_timer_1(T1_INTERNAL | T1_DIV_BY_1); // Timer1 setup
    setup_adc(ADC_OFF); // ADC setup
    setup_ccp1(CCP_CAPTURE_RE); // CCP1 setup
   
    //pwm
     output_low(PIN_C1);   // Set CCP2 output low
      setup_ccp1(CCP_PWM);  // Configure CCP1 as a PWM
      setup_timer_2(T2_DIV_BY_16, 311, 1);
 
    while (TRUE)
    {
        output_high(TRIGGER_PIN);
        delay_us(10);
        output_low(TRIGGER_PIN);

        while (!input(ECHO_PIN)); // Wait for the pulse to start
        set_timer1(0);
        while (input(ECHO_PIN)); // Wait for the pulse to end
        distance = get_timer1() * 0.0017; // Convert time to distance (in cm), assuming speed of sound is 343 m/s

        printf(lcd_putc,"\fDistance: %.2f cm\nS=%ld", distance,s1);
         delay_ms(100); // Delay before next measurement
       // set_pwm1_duty(s);
       
        //intensity
      if((distance<45) && (distance>35))
      {
      s=100;
        printf(lcd_putc,"\fsmall");
      delay_ms(300);
      output_high(pin_d1);
      delay_ms(3000);
      output_low(pin_d1);
      delay_ms(3000);
      }
      if((distance<35) && (distance>25))
      {
      s=200;
       printf(lcd_putc,"\fmedium");
      delay_ms(300);
      output_high(pin_d2);
      delay_ms(3000);
      output_low(pin_d2);
      delay_ms(3000);
     
      }
     if((distance<25) && (distance>15))
      {
      s=250;
       printf(lcd_putc,"\flarge");
      delay_ms(300);
      output_high(pin_d3);
      delay_ms(3000);
      output_low(pin_d3);
      delay_ms(3000);
      }
    
  
}
}
