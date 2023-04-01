/*
 * eeprom01.c
 *
 * Created: 28-02-2023 20:41:07
 * Author : 19anu
 */ 

/*
	eeprom address register.
	EEARH - 2BITS
	EEARL - 8BITS
	
	eeprom control register.
	EECR - 
	
	eeprom data register
	
	EEDR
*/
#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "lcd_4bitmode.h"
#include <avr/eeprom.h>

void EEPROM_write(unsigned int, unsigned char);
unsigned char EEPROM_read(unsigned int);

int main(void)
{
	LCD_Init();			/* Initialization of LCD*/
	LCD_String("Practice EEPROM 01");	/* Write string on 1st line of LCD*/
	char letter='A';
	
	for (int i=22; i<48; i++)
	{
		EEPROM_write(i, letter);
		LCD_Command(0xC0);		/* Go to 2nd line*/
		LCD_Char(EEPROM_read(i));	/* Write string on 2nd line	11*/
		_delay_ms(500);
		letter++;
	}
	return 0;
}

void EEPROM_write(unsigned int uiAddress, unsigned char ucData)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEPE));
	/* Set up address and Data Registers */
	EEAR = uiAddress;
	EEDR = ucData;
	/* Write logical one to EEMPE */
	EECR |= (1<<EEMPE);
	/* Start eeprom write by setting EEPE */
	EECR |= (1<<EEPE);
}

unsigned char EEPROM_read(unsigned int uiAddress)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEPE));
	/* Set up address register */
	EEAR = uiAddress;
	/* Start eeprom read by writing EERE */
	EECR |= (1<<EERE);
	/* Return data from Data Register */
	return EEDR;
}