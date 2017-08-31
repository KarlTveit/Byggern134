/*
 * Byggern134.c
 *
 * Created: 30.08.2017 10:04:34
 *  Author: karlmt
 */ 

#include <avr/io.h>
//#include "IncFile1.h"
#include "stdio.h"
#include <avr/interrupt.h>
#include <avr/sleep.h>
#define F_CPU 4915200 // clock frequency in Hz
#define BAUD 9600
#include <util/delay.h>


int UART_Init(unsigned int ubrr) {
	// Set baud rate
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	// Enable receiver and transmitter
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	// Set frame format: 8data, 2 stop bit
	UCSR0A &= ~(_BV(U2X0));
	return 1;
}

unsigned char UART_Recieve(void) {
	while ( !(UCSR0A & (1<<RXC0)));
	
	return UDR0;
	
};

int UART_Transmit(unsigned char data) {
	while (!(UCSR0A & (1<<UDRE0) )){}
	
	UDR0 = data;
	return 3;
};

int main(void)
{

	DDRA = 0xFF;
    while(1)
    {
		_delay_ms(500);
			//PORTA = 0xFF;
			PORTA &= ~(1 << 1);
		
		_delay_ms(500);
		
			PORTA |= (1 << 1);

		unsigned int ubrr = 31;
		UART_Init(ubrr);
		UART_Transmit('h');
		UART_Transmit('\n');
		
		unsigned char post = UART_Recieve();
		fdevopen(UART_Transmit('a'), UART_Recieve());
		printf(post);
    }
	
}