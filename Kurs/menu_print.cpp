#include "MyByte.h"
extern MyByte my_byte;

void print_byte() {
	printf("[%3s][%3s][%3s][%3s]\n", "Dec", "Hex", "Oct", "Sym");
	printf("[%3s][%3s][%3s][%3s]\n", get_str_dec(), get_str_hex(), get_str_oct(), get_str_sym());
	printf("[%3d][%3X][%3o][%3s]\n", my_byte.value, my_byte.value, my_byte.value, get_str_sym());
}

char* get_str_dec() {
	static char str[4];
	sprintf(str, "%d", my_byte.value);
	return str;
}

char* get_str_hex() {
	static char str[4];
	sprintf(str, "%c%c", convert_num_to_ascii(my_byte.hex_st.b), convert_num_to_ascii(my_byte.hex_st.a));
	return str;
}

char* get_str_oct() {
	static char str[4];
	sprintf(str, "%d%d%d", my_byte.oct_st.c, my_byte.oct_st.b, my_byte.oct_st.a);
	return str;
}

char* get_str_sym() {
	static char str[4];
	if (my_byte.value > 32)
		sprintf(str, "%c", my_byte.value);
	else
		sprintf(str, "%s", "---");
	return str;
}