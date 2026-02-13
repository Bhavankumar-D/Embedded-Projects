#include <16F886.h> 
#device adc=10
#fuses HS,NOWDT,NOPROTECT,BROWNOUT,PUT
#use delay(clock=20M)  
#use rs232(baud=9600,xmit=PIN_c6, rcv=PIN_C7, ERRORS)
#include <flex_lcd.c>

unsigned int16 value;
void main()
{
float speed=0;

  
lcd_init();
printf(lcd_putc,"\f   welcome");
 delay_ms(500);

while(1)
   {
setup_timer_1(t1_external | T1_DIV_BY_1);
      set_timer1(0);   
      delay_ms(1000);         // in protues, should be 1000/3
      setup_timer_1(T1_DISABLED);
      value=get_timer1();
      speed=value/3;
   
      printf(lcd_putc,"\fValue:%lu",value);
      printf(lcd_putc,"\nspeed:%fKM/hr",speed);
      delay_ms(1000);
      
   }
}
