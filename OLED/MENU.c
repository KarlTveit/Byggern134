
#include "MENU.h"
#include "OLED.h"













MENU_create_main_menu(void) {
	
	
	
}



void MENU_display_menu(menu_t menu, uint8_t curr_line ) {
	uint8_t line = 0;
	OLED_clear_display();
	OLED_print_string(menu.title);
	OLED_goto_line(++line);

	for (uint8_t i = 0; i < menu.number_of_submenus; i++) {
		if (line == curr_line) {
			OLED_print_inverted_string(menu.submenus[i]->title);
		}
		else {
			OLED_print_string(menu.submenus[i]->title);
		}
		OLED_goto_line(++line);
	}
	
	
	if (menu.parent == NULL_PTR) {
		OLED_print_string("QUIT");
	}
	else {
		OLED_print_string( "BACK");
	}
	
	
}


void MENU_add_submenu(char* t, void(*func)(), uint8_t num, /*menu_t** sub,*/ menu_t* p) {
	
	p->submenus[p->number_of_submenus] = malloc(sizeof(menu_t));
	menu_t* submenu = p->submenus[p->number_of_submenus];
	
	submenu->title = t;
	submenu->number_of_submenus = num;
	submenu->item = func;
	submenu->parent = p;
	
	
	p->number_of_submenus++;
	
	

}



void MENU_choose(menu_t choice) {
	
	/*OLED_emphasized_inverted_string(choice.title);*/
	_delay_ms(1000);
	
	if (choice.item == NULL_PTR) {
		MENU_display_menu(choice,0);
	}
	else {
		choice.item();
	}
	
}


void MENU_back(menu_t this) {
	
	if (this.parent != NULL_PTR) {
		MENU_display_menu(*this.parent,0);
	}
	else {
		OLED_clear_display();
		OLED_goto_line(4);
		OLED_goto_column(25);
		OLED_print_string("Q U I T");
	}
	
	
}