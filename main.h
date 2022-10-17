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
 * struct intermediary - Struct token
 * @id - identifies the type of argument
 * @format: format specifier
 * @f: pointer to function to call
 */

typedef struct intermediary
{
	char id;
	int (*f)(va_list list);
} intermediary;

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

#endif
