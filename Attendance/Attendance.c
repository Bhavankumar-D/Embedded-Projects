#include <16F877a.h> 
#fuses HS,NOWDT,NOPROTECT,BROWNOUT,PUT
#use delay(clock=20000000)   

#include <flex1_lcd.c>
#use rs232(baud=9600, xmit=pin_c6, rcv=pin_c7, bits=8,parity=N, ERRORS)
int s=1;
int x=0;
int p=0;
char sp[5],sa[5],k;
char rcvchar;
char cbuff[4];
unsigned int16 sanb=0,sana=0,sanc=0,H=0;
unsigned int16 rp1=0,spd=1,san=360,sand=0,a,b;

void main() 
{  
lcd_init();
delay_ms(100);
printf(lcd_putc,"\fwelcome\nenter ip");

delay_ms(1000);
while(1) 
{ 
while(s)  
{
k=getch();
if(p<3)
{
sa[p]=k;
p++;  
}
else
{
s=0;
}
