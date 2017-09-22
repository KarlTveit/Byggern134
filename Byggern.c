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
#include "IO/ADC.h"
#include "IO/JOY.h"
#define F_CPU 4915200 // clock frequency in Hz
#define BAUD 9600
#define UBRR F_CPU/16/BAUD-1
#include <util/delay.h>
#include "SRAM/SRAM.h"
#include "OLED/OLED.h"



uint8_t RECEIVED = 0;

ISR(USART0_RXC_vect)
{
	RECEIVED = 1;
	
	unsigned char temp = UDR0;
	UART_Transmit(temp); // for å teste at det funker
}






int main(void)
{

	DDRA = 0xFF;
	//unsigned long ubrr = (F_CPU/(16*BAUD))-1;//31;
	UART_Init(UBRR);
	fdevopen(&UART_Transmit, &UART_Recieve);
	printf("Hello world\n");
	init_SRAM();
	
	
	OLED_init();
	OLED_clear_display();

	while(1);
	/*ADC_init();*/
	JOY_init();
	
	//volatile char *adc = (char *) 0x1800; // Start address for the SRAM
	//while(1){
		//adc[0] = 0x1800;
	//}
	
	//SRAM_test();
	
	/**ext_oled_cmd = 0xb0;
	*ext_oled_cmd = 0x10;
	*ext_oled_cmd = 0x00;
	
	for (int i = 0; i < 8; i++) {
		*ext_oled_data = font8[51][i];
	}
	*/
	while(1) {
		/*JOY_calibrate();*/	//DENNE KLIKKER HJELP HVA SKJER
		/*_delay_ms(1000);
		printf("(%d,%d)\n", ADC_read(joyX),ADC_read(joyY));
		printf("(%d,%d)\n", JOY_getPosition().X,JOY_getPosition().Y);
		
		JOY_getDirectionString();*/
		
		
		//OLED_test();
		//printf("(%d)\n", ADC_read(joyX));	
	}

    /*while(1)
    {
		//_delay_ms(500);
			//PORTA = 0xFF;
			//PORTA &= ~(1 << 1);
			printf("hey man");
			
		_delay_ms(500);
		
			//PORTA |= (1 << 1);
		
		
    }
	*/
}