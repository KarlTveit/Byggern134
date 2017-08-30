/*
 * Byggern134.c
 *
 * Created: 30.08.2017 10:04:34
 *  Author: karlmt
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#define F_CPU 1600000 // clock frequency in Hz
#include <util/delay.h>
int main(void)
{
	DDRA = 0xFF;
    while(1)
    {
		_delay_ms(500);
		
			PORTA &= ~(1 << 1);
		
		_delay_ms(500);
		
			PORTA |= (1 << 1);
        
    }
	
}