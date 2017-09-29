
#include "MENU.h"
#include "OLED.h"




 //static menu_t main_menu; /*= {.title = "Main Menu", .parent = NULL_PTR, .number_of_submenus = 5, ->item() = NULL_PTR, .submenu = malloc(main_menu.number_of_submenus)} ;*/



void MENU_create_menu() {
	/*static menu_t main_menu;
	
	main_menu.title = "Main Menu";
	main_menu.number_of_submenus = 5;
	main_menu.item = NULL_PTR;
	main_menu.parent = NULL_PTR;
	main_menu.submenus = malloc(main_menu.number_of_submenus);
	*/
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
		OLED_print_string("Are you sure you want to quit?");
	}
	
	
}