

#include "OLED.h"
#include "fonts.h"


void OLED_clear_display() {
	*ext_oled_cmd = 0xb0;
	for(int i = 0; i < 8; i++) {
		ext_oled_data[i] = 0x00;
	}
}

void OLED_init ()
{
	volatile char *addresse = ext_oled_cmd;
	
	*addresse = 0xae;        //  display  off *(adresse+0xae)
	*addresse = 0xa1;        //segment  remap
	//*addresse = 00b;		 // Horizontal addressing??????
	*addresse = 0xda;        //common  pads  hardware:  alternative
	*addresse = 0x12;
	*addresse = 0xc8;        //common
	//output scan direction:com63~com0
	*addresse = 0xa8;        //multiplex  ration  mode:63
	*addresse = 0x3f;
	*addresse = 0xd5;        //display
	//divide ratio/osc. freq. mode
	*addresse = 0x80;
	*addresse = 0x81;        //contrast  control
	*addresse = 0x50;
	*addresse = 0xd9;        //set  pre-charge  period
	*addresse = 0x21;
	*addresse = 0x20;        //Set  Memory  Addressing  Mode
	*addresse = 0x02;
	*addresse = 0xdb;        //VCOM  deselect  level  mode
	*addresse = 0x30;
	*addresse = 0xad;        //master  configuration
	*addresse = 0x00;
	*addresse = 0xa4;        //out  follows  RAM  content
	*addresse = 0xa6;        //set  normal  display
	*addresse = 0xaf;        //  display  on
	
/*

	*addresse = 0x10;
	*addresse = 0x00;*/
}

void OLED_test(void){
	
 	_delay_ms(500);
 	*ext_oled_cmd = 0xb0;
 	*ext_oled_cmd = 0x10;
	*ext_oled_cmd = 0x00;
	for(int i = 0; i < 8; i++){
		*ext_oled_data = pgm_read_byte(&(font8[52][i]));
	}
	while(1) {
		//*ext_oled_data = 0x00;
		
		
	}

}

void OLED_reset(void){}
// void OLED_home(){}
// void OLED_goto_line(line){}
// void OLED_clear_line(line){}
// void OLED_pos(row, column){}
// void OLED_print(char*){}
// void OLED_set_brightness(lvl){}