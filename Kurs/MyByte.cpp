#include "MyByte.h"
extern MyByte my_byte;

void init() {
	my_byte.value = 0;
}

bool check_count_number(char* str, unsigned int count) {
	if (strlen(str) > count) {
		printf("Error! Too long number! Must be a %d number!\n", count);
		return false;
	}
	return true;
}

bool check_char_in_dec(char c) {
	if (!CHAR_IN_DEC(c)) {
		printf("Error! Number not in dec system!\n");
		return false;
	}
	return true;
}

bool check_char_in_oct(char c, int pos) {
	if ((pos == 0) && !(CHAR_IN_OCT_FIRST(c))) {
		printf("Error! Nnumber not in oct system! the first bit cannot be more than 3!\n");
		return false;
	}
	if (!(CHAR_IN_OCT(c))) {
		printf("Error! Nnumber not in oct system!\n");
		return false;
	}
	return true;
}

bool check_char_in_hex(char c) {
	if (!(CHAR_IN_HEX(c))) {
		printf("Error! Number not in hex system!\n");
		return false;
	}
	return true;
}

void fill_oct_from_mass(BYTE* b) {
	my_byte.oct_st.a = b[2];
	my_byte.oct_st.b = b[1];
	my_byte.oct_st.c = b[0];
}

void fill_hex_from_mass(BYTE* b) {
	my_byte.hex_st.a = b[1];
	my_byte.hex_st.b = b[0];
}

BYTE convert_ascii_to_num(char c) {
	switch (c) {
	case '0': return 0;
	case '1': return 1;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	case '9': return 9;
	case 'a': case 'A': return 10;
	case 'b': case 'B': return 11;
	case 'c': case 'C': return 12;
	case 'd': case 'D': return 13;
	case 'e': case 'E': return 14;
	case 'f': case 'F': return 15;
	}
}

char convert_num_to_ascii(BYTE num) {
	switch (num) {
	case 0: return '0';
	case 1: return '1';
	case 2: return '2';
	case 3: return '3';
	case 4: return '4';
	case 5: return '5';
	case 6: return '6';
	case 7: return '7';
	case 8: return '8';
	case 9: return '9';
	case 10: return 'A';
	case 11: return 'B';
	case 12: return 'C';
	case 13: return 'D';
	case 14: return 'E';
	case 15: return 'F';
	}
}
