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
#include "OLED/MENU.h"
//#include "OLED/fonts.h"


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

	UART_Init(UBRR);
	fdevopen(&UART_Transmit, &UART_Recieve);
	printf("Hello world\n");
	init_SRAM();
	
	
	OLED_init();
	OLED_clear_display();
	OLED_goto_line(0);
	OLED_goto_column(0);
	
	
	
		
	static menu_t main_menu;
	
	main_menu.title = "Main Menu";
	main_menu.number_of_submenus = 0;
	main_menu.item = NULL_PTR;
	main_menu.parent = NULL_PTR;
	main_menu.submenus = malloc(sizeof(menu_t)*5);
	
	//MENU_display_menu(main_menu);
	
	
	
	MENU_add_submenu("Settings", NULL_PTR, 3, &main_menu);
	printf("first submenu is %s\n", main_menu.submenus[0]->title);
	
	//_delay_ms(500);
	MENU_display_menu(main_menu,1);
	
	JOY_init();

	while(1) {
		//JOY_calibrate();	//DENNE KLIKKER HJELP HVA SKJER
		/*_delay_ms(1000);
		printf("(%d,%d)\n", ADC_read(joyX),ADC_read(joyY));
		printf("(%d,%d)\n", JOY_getPosition().X,JOY_getPosition().Y);
		
		JOY_getDirectionString();*/
		
		
		//OLED_test();
		//printf("(%d)\n", ADC_read(joyX));	
	}

 
}