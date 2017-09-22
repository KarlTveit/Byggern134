

#ifndef OLED_H_
#define OLED_H_

//#include "fonts.h"
#include <avr/pgmspace.h>
#include <util/delay.h>

#define ext_oled_cmd    ((volatile char*) 0x1000)
#define ext_oled_data ((volatile char*) 0x1200)

void OLED_test(void);
void OLED_clear_display(void);
void OLED_init(void);
void OLED_reset(void);
void OLED_home();
void OLED_goto_line(uint8_t line);
void OLED_clear_line(line);
void OLED_pos(row, column);
void OLED_print(char*);
void OLED_set_brightness(lvl);

#endif /* OLED_H_ */