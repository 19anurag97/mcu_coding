/*
 * GccApplication1.c
 *
 * Created: 18-04-2023 21:54:05
 * Author : 19anu
 */ 
#define F_CPU 8000000
#define SEL_BAUD 9600
#define CALC_UBRR (F_CPU / (16 * (SEL_BAUD)) - 1)		//	ubrr	->	52.0836

#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

void usart_init(unsigned char);
void uartsend_int(unsigned int);
void uartsend_char(unsigned char);
void uartrcv_int(void);
void led_on(void);

int main(void)
{
	usart_init(CALC_UBRR);	//12bits	0010 0101 1000 0000
	_delay_us(1000);
	
	/*master node operation*/
	DDRB |= (1 << 1);
	uartsend_int(122);
	_delay_ms(2000);
	uartsend_int(142);
	_delay_ms(2000);
	uartsend_int(152);
	_delay_ms(2000);
	
	while (1)	//check if data received???
	{
		while(UCSR0A & (1 << RXC0))
		{
			uartrcv_int();
			_delay_us(100);
			UCSR0A &= ~(1 << RXC0);
		}
	}
	
	return 0;
}

void usart_init(unsigned char ubr)
{
	UBRR0L = ubr;					//52->0011 0100
	UCSR0C = 0x06;					//00000110
	UCSR0B = 24;
}

void uartsend_int(unsigned int data)
{
	UCSR0A |= (1 << 6);	//clear TXCn flag.
	while (UCSR0A & (1 << UDRE0))
	{
		UDR0 = data;		//send data.
	}
}

void uartrcv_int()
{
	int temp = (int)UDR0;
	if (temp == 188)
	{
		PORTB |= (1 << 1);
	}
}