#pragma once

//Создайте следующие структуры для различных представлений значений байта:
//Hex - для шестнадцатеричного представления;
//Oct - для восьмеричного представления.
//Подсказка 1: для удобства используйте битовые поля.
//Подсказка 2: структуры должны быть членами объединения(union).
//Посредством объединения MyByte предоставьте пользователю возможность манипулировать одним и тем же значением по - разному:
//А) выводить десятичное, шестнадцатеричное, восьмеричное значение байта, а также символ, соответствующий хранимому значению (если есть соответствие);
//Б) выводить отдельные(указанные посредством параметра) шестнадцатеричные или восьмеричные цифры;
//В) изменять отдельные восьмеричные или шестнадцатеричные цифры;

//отключение предупреждения компилятора (уровень 3) C4996
#pragma warning(disable : 4996)

#include <cstdio>
#include <cstdlib>
#include <cstring>

#define STR_LEN 16
#define STR_LEN_MAX 100

#define COUNT_DEC 3
#define COUNT_OCT 3 
#define COUNT_HEX 2 

#define FLAG_ERR 0xFF

#define MAX_VALUE 0xFF

#define CHAR_IN_DEC(ch) ((ch >= '0') && (ch <= '9'))
#define CHAR_IN_OCT(ch) ((ch >= '0') && (ch <= '7'))
#define CHAR_IN_OCT_FIRST(ch) ((ch >= '0') && (ch <= '3'))
#define CHAR_IN_HEX(ch) ( ((ch >= '0') && (ch <= '9')) || ((ch >= 'a') && (ch <= 'f')) || ((ch >= 'A') && (ch <= 'F')) )

using namespace std;

typedef unsigned char BYTE;

enum TYPE_NOTATION {
	OCT_TYPE, HEX_TYPE, DEC_TYPE, SYM_TYPE
};

enum MENU_ITEMS {
	MENU_EXIT, MENU_INPUT, MENU_PRINT, MENU_CONCRETE_PRINT, MENU_CONCRETE_CHANGE
};

union MyByte {
	//big endian
	struct HEX_ST {
		unsigned char a : 4;
		unsigned char b : 4;
	} hex_st;
	struct OCT_ST {
		unsigned char a : 3;
		unsigned char b : 3;
		unsigned char c : 2;
	} oct_st;
	BYTE value;
};

void init();
void main_process();

void input_byte();
void print_byte();
void print_concrete();
void change_byte();

void input_in_dec();
void input_in_oct();
void input_in_hex();
void input_in_sym();

char* get_str_dec();
char* get_str_hex();
char* get_str_oct();
char* get_str_sym();

void change_concrete_oct();
void change_concrete_hex();

void print_concrete_oct();
void print_concrete_hex();

bool check_count_number(char* str, unsigned int count);
bool check_char_in_dec(char c);
bool check_char_in_oct(char c, int pos);
bool check_char_in_hex(char c);

void fill_oct_from_mass(BYTE* b);
void fill_hex_from_mass(BYTE* b);

BYTE convert_ascii_to_num(char c);
char convert_num_to_ascii(BYTE num);
