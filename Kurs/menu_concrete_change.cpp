#include "MyByte.h"
extern MyByte my_byte;

void change_byte() {
	printf("Input byte type: %d - oct, %d - hex: ", OCT_TYPE, HEX_TYPE);
	int type = 0;
	scanf("%d", &type);
	switch (type) {
	case OCT_TYPE: return change_concrete_oct();
	case HEX_TYPE: return change_concrete_hex();
	}
	printf("Error! Wrong type!\n");
}

void change_concrete_oct() {
	printf("Input numeral of position (0-2) oct number for change: ");
	int pos = 0;
	scanf("%d", &pos);
	printf("Input new number in oct system: ");
	char str[STR_LEN] = "";
	scanf("%s", str);
	if (!check_count_number(str, 1))
		return;
	if (!check_char_in_oct(str[0], 0))
		return;
	BYTE num = static_cast<BYTE>(atoi(str));
	switch (pos) {
	case 0: my_byte.oct_st.a = num; return;
	case 1: my_byte.oct_st.b = num; return;
	case 2: my_byte.oct_st.c = num; return;
	}
	printf("Error! Wrong position!\n");
}

void change_concrete_hex() {
	printf("Input numeral of position (0-1) hex number for change: ");
	int pos = 0;
	scanf("%d", &pos);
	printf("Input new number in oct system: ");
	char str[STR_LEN] = "";
	scanf("%s", str);
	if (!check_count_number(str, 1))
		return;
	if (!check_char_in_hex(str[0]))
		return;
	BYTE num = convert_ascii_to_num(str[0]);
	switch (pos) {
	case 0: my_byte.hex_st.a = num; return;
	case 1: my_byte.hex_st.b = num; return;
	}
	printf("Error! Wrong position!\n");
}
