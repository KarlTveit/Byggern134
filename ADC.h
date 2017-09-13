

#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>
//#include "IncFile1.h"
#include "stdio.h"
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <util/delay.h>
typedef enum{
	joyY = 0x4,
	joyX = 0x5,
	}channel;

uint8_t ADC_read(channel joystick);
void ADC_init(void);

#endif /* ADC_H_ */