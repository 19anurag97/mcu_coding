/*
 * avr_01.c
 *
 * Created: 11-02-2023 11:46:01
 * Author : 19anu
 */ 

#define F_CPU 8000000UL
#define direction_D		*((volatile uint8_t*)0x2A)
#define port_D			*((volatile uint8_t*)0x2B)


#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

void function1(void);	//blink using delay in util/delay.h
void function2(void);
void function3(void);	//MACROS define

int main(void)
{
	//function1();
	//function2();
	function3();
}

void function1(void)
{
	DDRD |= (1 << 0);//0xFF;
	while (1)
	{
		PORTD |= (1 << 0);
		_delay_ms(1000);
		PORTD &= ~(1 << 0);
		_delay_ms(1000);
	}
}

void function2(void)
{	//artificial delay()
	
	DDRD |= (1 << 0);//0xFF;
	while (1)
	{
		for (long i=0; i<100000; i++)
		{
			PORTD |= (1 << 0);
		}
		for (long i=0; i<100000; i++)
		{
			PORTD &= ~(1 << 0);
		}	
	}	
}

void function3(void)
{
	direction_D = 1;
	while (1)
	{
		port_D = 1;
		_delay_ms(100);
		port_D = 0;
		_delay_ms(100);
	}
}
