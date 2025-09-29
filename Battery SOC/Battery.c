#include <16f877a.h>
#FUSES hs,NOWDT,PUT,PROTECT,NOBROWNOUT,NOLVP,NOCPD
#device adc=10
#use delay(clock=20000000)
#include "flex_lcd.c"
float g,c,tem,a,b;
float i=0;
float sensorvalue=0;
float sensorvalue1=0;
void main()
 
{



setup_adc(ADC_CLOCK_INTERNAL); // initialize ADC with a sampling rate of Crystal/4 MHz
setup_adc_ports(ALL_ANALOG  );   // set PIN_A0 as analog input channel
delay_ms(5);
lcd_init();
delay_ms(1000);


  while(1)
  {
  set_adc_channel(0);
sensorvalue=read_adc();
delay_ms(100);
set_adc_channel(1);
sensorvalue1=read_adc();
delay_ms(100);
float v=(sensorvalue*(5.0/1023.0));
delay_ms(100);
float voltage=v*2.4;
delay_ms(100);
float r=(5*(sensorvalue1/1023.0));
delay_ms(100);
r=r/20;
delay_ms(100);
float i=voltage/r;
delay_ms(100);
float soc= 100.0 + (-i*6.0/500.0);
delay_ms(100);
printf(lcd_putc,"V:%f R:%f \nI:%f SOC:%f",voltage,r,i,soc);
delay_ms(500);
}
}













 
 
 
 
 
 
 
 
