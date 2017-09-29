
#include "MENU.h"
#include "OLED.h"

#define NULL_PTR (void*)0


 //static menu_t main_menu = {.title = "Main Menu", .parent = 0, .number_of_submenus = 0. .option() = {}, .submenu = {}};



void MENU_display_menu(menu_t menu) {
	uint8_t line = 0;
	OLED_clear_display();
	OLED_print_string(menu.title);
	OLED_goto_line(++line);
	menu_t submenu;
	for (uint8_t i = 0; i < menu.number_of_submenus; i++) {
		OLED_print_string(submenu.title);
		OLED_goto_line(++line);
	}
	
	OLED_print_string( "BACK");
	if (menu.parent == NULL_PTR) {
		OLED_print_string("QUIT");
	}
	
}

/*

menu_t* MENU_add_submenu(menu_t* new_submenu) {
	
	
	uint8_t submenu_index = parent->number_of_submenus;
	
	new_submenu->parent->submenus = (menu_t**) realloc(new_submenu->parent->submenus, )
	
	parent->= malloc(parent->number_of_submenus + 1);
	
	parent->submenus[submenu_index] = newmenu;

}*/




