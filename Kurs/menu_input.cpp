#include "MyByte.h"
extern MyByte my_byte;

void input_byte() {
	printf("Input byte type: %d - oct, %d - hex, %d - dec, %d - symbol: ", OCT_TYPE, HEX_TYPE, DEC_TYPE, SYM_TYPE);
	int type = 0;
	scanf("%d", &type);
	switch (type) {
	case DEC_TYPE: return input_in_dec();
	case OCT_TYPE: return input_in_oct();
	case HEX_TYPE: return input_in_hex();
	case SYM_TYPE: return input_in_sym();
	}
	printf("Error! Wrong type!\n");
}

void input_in_dec() {
	printf("Input byte in dec system: ");
	char str[STR_LEN] = "";
	scanf("%s", str);
	if (!check_count_number(str, COUNT_DEC))
		return;
	for (unsigned int i = 0; i < strlen(str); i++) {
		if (!check_char_in_dec(str[i]))
			return;
	}
	int num = atoi(str);
	if (num > MAX_VALUE) {
		printf("Error! Maximum value must be less %d!\n", MAX_VALUE);
		return;
	}
	my_byte.value = static_cast<BYTE>(num);
}

void input_in_oct() {
	printf("Input byte in oct system: ");
	char str[STR_LEN] = "";
	scanf("%s", str);
	if (!check_count_number(str, COUNT_OCT))
		return;
	BYTE num[COUNT_OCT] = { 0 };
	int first_num = COUNT_OCT - strlen(str);
	int j = 0;
	for (int i = first_num; i < COUNT_OCT; i++) {
		if (!check_char_in_oct(str[j], j))
			return;
		num[i] = convert_ascii_to_num(str[j]);
		j++;
	}
	fill_oct_from_mass(num);
}

void input_in_hex() {
	printf("Input byte in hex system: ");
	char str[STR_LEN] = "";
	scanf("%s", str);
	if (!check_count_number(str, COUNT_HEX))
		return;
	BYTE num[COUNT_HEX] = { 0 };
	int first_num = COUNT_HEX - strlen(str);
	int j = 0;
	for (int i = first_num; i < COUNT_HEX; i++) {
		if (!check_char_in_hex(str[j]))
			return;
		num[i] = convert_ascii_to_num(str[j]);
		j++;
	}
	fill_hex_from_mass(num);
}

void input_in_sym() {
	printf("Input byte in symbol: ");
	char str[STR_LEN] = "";
	scanf("%s", str);
	if (strlen(str) > 1) {
		printf("Error! Too long! Must be a one char!\n");
		return;
	}
	my_byte.value = static_cast<BYTE>(str[0]);
}