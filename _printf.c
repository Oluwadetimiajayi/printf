#include "main.h"

/**
 * _printf - prints formatted output
 * @format: initial string with no link to corresponding specifier
 * @...: varied list of args
 * Return: number of chars printed
 */

int _printf(const char *format, ...)
{
	int i, j;
	int count = 0;
	va_list ap;
	intermediary ids[] = { {'c', _print_char}, {'s', _print_string}, {'i', _print_int}, {'d', _print_int}, {'%', _print_mod}, {'\0', NULL} };

	va_start (ap, format);
	for (i = 0; format[i]; i++)
		if (format[i] == '%')
		{
			i++
			for (; format[i] != '\0'; i++)
			{
				for (j = 0; ids[j].id != '\0'; j++)
					if (format[i] == ids[j].id)
					{
						count += ids[j].f(ap);
						break;
					}
				if (ids[j].id)
					break;
			}
			if (format[i] == '\0')
				return (-1);
		}
		else
		{
			write(1, &format[i], 1);
			count += 1;
		}

	va_end(ap);
	return (count);
}
