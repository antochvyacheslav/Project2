#include "MyByte.h"
extern MyByte my_byte;

void print_concrete() {
	printf("Input byte type: %d - oct, %d - hex: ", OCT_TYPE, HEX_TYPE);
	int type = 0;
	scanf("%d", &type);
	switch (type) {
	case OCT_TYPE: return print_concrete_oct();
	case HEX_TYPE: return print_concrete_hex();
	}
	printf("Error! Wrong type!\n");
}

void print_concrete_oct() {
	printf("Input numeral of position (0-2) oct number for print: ");
	int pos = 0;
	scanf("%d", &pos);
	switch (pos) {
	case 0: printf("%d-[%d]\n", pos, my_byte.oct_st.a); return;
	case 1: printf("%d-[%d]\n", pos, my_byte.oct_st.b); return;
	case 2: printf("%d-[%d]\n", pos, my_byte.oct_st.c); return;
	}
	printf("Error! Wrong position!\n");
}

void print_concrete_hex() {
	printf("Input numeral of position (0-1) hex number for print: ");
	int pos = 0;
	scanf("%d", &pos);
	switch (pos) {
	case 0: printf("%d-[%d]\n", pos, my_byte.hex_st.a); return;
	case 1: printf("%d-[%d]\n", pos, my_byte.hex_st.b); return;
	}
	printf("Error! Wrong position!\n");
}
