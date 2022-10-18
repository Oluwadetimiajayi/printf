#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <ctype.h>

/**
 * struct vault - Struct token
 * Description: stores pointers to called functions
 * @id - identifies the type of argument
 * @format: format specifier
 * @f: pointer to called functions
 */

typedef struct vault
{
	char *id;
	int (*f)(va_list, char *, unsigned int);
} vault_t;

int _printf(const char *format, ...);
int _print_mod(va_list ls);
int _print_string(va_list ls);
int _print_int(va_list ls);
int width_func(va_list list);
int _putchar(char c);
int char_func(va_list list);
int print_char(va_list list);
int str_func(va_list list);
int stringupperCase_func(va_list list);
int rev_func(va_list list);
int rot13_func(va_list list);

int binary_func(va_list list)
{
	int b = va_arg(list, unsigned int);
	int a = convert(b, 2, 1, 0);

	return (a);
}

int unsig_int_func(va_list list)
{
	unsigned int n = va_arg(list, unsigned int);

	if (n > UINT_MAX)
		n = n - UINT_MAX - 1;

	print_number(n);
	return (0);
}


int hex_upper_func(va_list list)
{
	int num = va_arg(list, unsigned int);
	int a = convert(num, 16, 1, 0);

	return (a);
}

int hex_lower_func(va_list list)
{
	int num = va_arg(list, unsigned int);
	int a = convert(num, 16, 0, 0);

	return (a);
}

int octal_func(va_list list)
{
	int num = va_arg(list, unsigned int);
	int a = convert(num, 8, 0, 0);

	return (a);
}

int print_prg(va_list __attribute__((unused)), char *, unsigned int);
int print_chr(va_list arguments, char *buf, unsigned int ibuf);
int print_str(va_list arguments, char *buf, unsigned int ibuf);
int print_int(va_list arguments, char *buf, unsigned int ibuf);
int print_bnr(va_list arguments, char *buf, unsigned int ibuf);
int print_unt(va_list arguments, char *buf, unsigned int ibuf);
int print_oct(va_list arguments, char *buf, unsigned int ibuf);
int print_hex(va_list arguments, char *buf, unsigned int ibuf);
int print_upx(va_list arguments, char *buf, unsigned int ibuf);
int print_usr(va_list arguments, char *buf, unsigned int ibuf);
int print_add(va_list arguments, char *buf, unsigned int ibuf);
int print_rev(va_list arguments, char *buf, unsigned int ibuf);
int print_rot(va_list arguments, char *buf, unsigned int ibuf);
int prinlint(va_list arguments, char *buf, unsigned int ibuf);
int prinlunt(va_list arguments, char *buf, unsigned int ibuf);
int prinloct(va_list arguments, char *buf, unsigned int ibuf);
int prinlhex(va_list arguments, char *buf, unsigned int ibuf);
int prinlupx(va_list arguments, char *buf, unsigned int ibuf);
int prinhint(va_list arguments, char *buf, unsigned int ibuf);
int prinhunt(va_list arguments, char *buf, unsigned int ibuf);
int prinhoct(va_list arguments, char *buf, unsigned int ibuf);
int prinhhex(va_list arguments, char *buf, unsigned int ibuf);
int prinhupx(va_list arguments, char *buf, unsigned int ibuf);
int prinpint(va_list arguments, char *buf, unsigned int ibuf);
int prinnoct(va_list arguments, char *buf, unsigned int ibuf);
int prinnhex(va_list arguments, char *buf, unsigned int ibuf);
int prinnupx(va_list arguments, char *buf, unsigned int ibuf);
int prinsint(va_list arguments, char *buf, unsigned int ibuf);
int (*get_print_func(const char *s, int index))(va_list, char *, unsigned int);
int ev_print_func(const char *s, int index);
unsigned int handl_buf(char *buf, char c, unsigned int ibuf);
int print_buf(char *buf, unsigned int nbuf);
char *fill_binary_array(char *binary, long int int_in, int isneg, int limit);
char *fill_oct_array(char *bnr, char *oct);
char *fill_long_oct_array(char *bnr, char *oct);
char *fill_short_oct_array(char *bnr, char *oct);
char *fill_hex_array(char *bnr, char *hex, int isupp, int limit);

#endif
