/*
 * MENU.h
 *
 * Created: 27.09.2017 14:19:38
 *  Author: tonjaj
 */ 


#ifndef MENU_H_
#define MENU_H_

#define MAX_SUBMENUS 6
#define NULL_PTR (void*)0

#include "stdint.h"

struct menu_t{
	char* title;
	void (*item)();
	uint8_t number_of_submenus;
	struct menu_t** submenus;
	struct menu_t* parent;
}; 

typedef struct menu_t menu_t;



void MENU_display_menu();

void MENU_create_menu();




void MENU_add_submenu(char* t, void(*func)(), uint8_t num, /*menu_t** sub,*/ menu_t* p);

/*
void MENU_back();
void MENU_choose();*/


#endif /* MENU_H_ */