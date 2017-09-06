/*
 * Byggern134.c
 *
 * Created: 30.08.2017 10:04:34
 *  Author: karlmt
 */ 
#include "UART/UART.h"
#include <avr/io.h>
//#include "IncFile1.h"
#include "stdio.h"
#include <avr/interrupt.h>
#include <avr/sleep.h>
#define F_CPU 4915200 // clock frequency in Hz
#define BAUD 9600
#define UBRR F_CPU/16/BAUD-1
#include <util/delay.h>
#include "SRAM/SRAM.h"


uint8_t RECEIVED = 0;

ISR(USART0_RXC_vect)
{
	RECEIVED = 1;
	
	unsigned char temp = UDR0;
	UART_Transmit(temp); // for � teste at det funker
}






int main(void)
{

	DDRA = 0xFF;
	//unsigned long ubrr = (F_CPU/(16*BAUD))-1;//31;
	UART_Init(UBRR);
	fdevopen(&UART_Transmit, &UART_Recieve);
	printf("Hello world\n");
	init_SRAM();
	SRAM_test();
    while(1)
    {
		_delay_ms(500);
			//PORTA = 0xFF;
			PORTA &= ~(1 << 1);
		
		_delay_ms(500);
		
			PORTA |= (1 << 1);
		
		
    }
	
}