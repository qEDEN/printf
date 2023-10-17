#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Print formatted output to stdout
 * @format: The format string containing directives
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')  /* Regular character */
		{
			write(1, format, 1);  /* Print the character */
			count++;
		}
		else  /* Format specifier */
		{
			format++;  /* Move to the character after '%' */

			if (*format == '\0')  /* Check for incomplete format specifier */
				break;

			if (*format == 'c')  /* Character specifier */
			{
				char c = va_arg(args, int);  /* Fetch the character argument */
				write(1, &c, 1);  /* Print the character */
				count++;
			}
			else if (*format == 's')  /* String specifier */
			{
				char *str = va_arg(args, char *);  /* Fetch the string argument */
				write(1, str, _strlen(str));  /* Print the string */
				count += _strlen(str);
			}
			else if (*format == '%')  /* Literal '%' character */
			{
				write(1, "%", 1);  /* Print '%' */
				count++;
			}
		}

		format++;
	}

	va_end(args);
	return count;
}

/**
 * _strlen - Calculate the length of a string
 * @s: The string to be measured
 *
 * Return: The length of the string
 */
int _strlen(char *s)
{
	int length = 0;

	while (s[length])
		length++;

	return (length);
}
