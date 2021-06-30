#include "MyByte.h"
extern MyByte my_byte;

void main_process() {
	while (true) {
		printf("\nMenu for MyBite! Input item number: %d - exit, %d - input, %d - print, %d - print concrete, %d - change.\n",
			MENU_EXIT, MENU_INPUT, MENU_PRINT, MENU_CONCRETE_PRINT, MENU_CONCRETE_CHANGE);
		printf("Input number of menu: ");
		int item = 0;
		scanf("%d", &item);
		switch (item) {
		case MENU_EXIT: {
			printf("Menu exit.\n");
			return;
		}
		case MENU_INPUT: {
			printf("Menu input.\n");
			input_byte();
			break;
		}
		case MENU_PRINT: {
			printf("Menu print.\n");
			print_byte();
			break;
		}
		case MENU_CONCRETE_PRINT: {
			printf("Menu concrete print.\n");
			print_concrete();
			break;
		}
		case MENU_CONCRETE_CHANGE: {
			printf("Menu concrete change.\n");
			change_byte();
			break;
		}
		default: {
			printf("Error! Menu unknown item number!\n");
			break;
		}
		}
	}
}