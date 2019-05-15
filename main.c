/*
 * GccApplication3.c
 *
 * Created: 15-May-19 3:44:23 PM
 * Author : JAYASREE
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <avr/io.h>
#include <util/delay.h>
void PWM_init()
{
	/*set fast PWM mode with non-inverting o/p*/
	TCCR0=(1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS00);
	DDRB|=(1<<PB3);/*set OC0 pin as o/p*/
}

int main(void)
{
	DDRA=0XFF;
	DDRB=0X00;
	DDRD&=~(1<<PD0);
	DDRD&=~(1<<PD1);
	PWM_init();
    /* Replace with your application code */
	PORTB=0<<PB0;
    while (1) 
    {
		if((PIND&(1<<PD0))==0)
		{
			OCR0=150;
			_delay_ms(1000);
		}
		if((PIND&(1<<PD1))==0)
		{
			OCR0=250;
			_delay_ms(1000);
		}
    }
}

