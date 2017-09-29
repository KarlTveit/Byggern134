/*
 * MENU.h
 *
 * Created: 27.09.2017 14:19:38
 *  Author: tonjaj
 */ 


#ifndef MENU_H_
#define MENU_H_

#define MAX_SUBMENUS 6

typedef struct{
	char title[20];
	void (*item)();
	uint8_t number_of_submenus;
	menu_t* submenus[5];
	menu_t* parent;
} menu_t; 




void MENU_display_menu();

/*

void MENU_add_submenu(uint8_t elements, char title, menu_t* parent);

void MENU_back();
void MENU_choose();*/


#endif /* MENU_H_ */