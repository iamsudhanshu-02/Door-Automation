#include<reg51f.h>
#include<reg51f.h>
#include"led1.h"
#include"delay.h"
#include"uart.h"
#include<string.h>
#include<stdio.h>

int i,j;
unsigned char temp_char = '\0';
sbit doorlock= P0^1;
sbit buzzer= P3^2;
void unlock();
//void Delays();
void lock();
void main(){
doorlock=0;
buzzer=1;
//DelayMs(1000);
//Delays();
buzzer=0;
uart_init();
LCD_init();
LCD_puts("Welcome");
lock();
while(1)
{
//buzzer=1;
temp_char=uart_getc();
if(temp_char == 'U')
{
LCD_clear();
LCD_puts("Unlock Command");
LCD_row2();
LCD_puts("Received");
unlock();
}if(temp_char == 'L')
{
LCD_clear();
LCD_row2();
LCD_puts("Received");
lock();
}
}
}
void lock()
{
doorlock=0;
buzzer=1;
//DelayMs(1000);
//Delays();
//buzzer=0;
return;
}
void unlock()
{
doorlock=1;
buzzer=1;
//DelayMs(1000);
//Delays();
buzzer=0;
return;
}
/*





 
LCD C FILE

#include<reg51.h>


sfr LCD_Port=0x90;

sbit rs=P1^0;

sbit rw=P1^1;

sbit en=P1^2;




void delay(unsigned int count)

{

int i,j;

for(i=0;i<count;i++)

for(j=0;j<112;j++);

}


void LCD_Command (char cmnd) /* LCD16x2 command funtion */ {

LCD_Port =(LCD_Port & 0x0F) | (cmnd & 0xF0);

rs=0;

rw=0;

en=1;

delay(1);

en=0;

delay(2);


LCD_Port = (LCD_Port & 0x0F) | (cmnd << 4);

en=1;

delay(1);

en=0;

delay(5);

}









 
void LCD_Char (char char_data)

{

LCD_Port =(LCD_Port & 0x0F) | (char_data & 0xF0);

rs=1;

rw=0;

en=1;

delay(1);

en=0;

delay(2);


LCD_Port = (LCD_Port & 0x0F) | (char_data << 4);

en=1;

delay(1);

en=0;

delay(5);


}


void LCD_String (char *str)

{

int i;

for(i=0;str[i]!=0;i++)

{

LCD_Char (str[i]);

}

}

void LCD_Init (void)

{

delay(20);


LCD_Command (0x02);

LCD_Command (0x28);

LCD_Command (0x0C);

LCD_Command (0x06);

LCD_Command (0x01);

LCD_Command (0x80);

}
 


