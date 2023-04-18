#define F_CPU 8000000
#define SEL_BAUD 9600
#define CALC_UBRR (F_CPU / (16 * (SEL_BAUD)) - 1)		//	ubrr	->	52.0836

#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

bool ALL_LED_HIGH = false;

void usart_init(unsigned char);
void uartsend_int(unsigned int);
void uartsend_char(unsigned char);
void uartrcv_int(void);
void led_on(void);

int main(void)
{
	usart_init(CALC_UBRR);	//12bits	0010 0101 1000 0000
	_delay_us(1000);
	
// 	/*master node operation*/
// 	uartsend_int(122);
// 	_delay_ms(2000);
// 	uartsend_int(142);
// 	_delay_ms(2000);
// 	uartsend_int(152);
// 	_delay_ms(2000);
	
	/*slave node operation*/
	DDRB |= (1 << 0)|(1 << 1)|(1 << 2);
	while (!(ALL_LED_HIGH))
	{
		uartrcv_int();
		_delay_ms(1000);
	}
	uartsend_int(188);
	
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
	
	switch (temp)
	{
	case 122:
		PORTB |= (1 << 0);
		break;
		
	case 142:
		PORTB |= (1 << 1);
		break;
	
	case 152:
		PORTB |= (1 << 2);
		ALL_LED_HIGH = true;
		break;
	}
}

void led_on()
{
	DDRB |= (1 << 1);
	PORTB |= (1 << 1);
}