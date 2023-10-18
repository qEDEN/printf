#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: The format string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			printed_chars += _putchar(*format);
		}
		else
		{
			format++;
			if (*format == '\0')
				break;

			if (*format == 'c')
			{
				char c = va_arg(args, int);

				printed_chars += _putchar(c);
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);

				if (str == NULL)
					str = "(null)";
				printed_chars += _puts(str);
			}
			else if (*format == '%')
			{
				printed_chars += _putchar('%');
			}
		}
		format++;
	}
	va_end(args);
	return (printed_chars);
}

/**
 * _putchar - Write a character to standard output
 * @c: The character to print
 *
 * Return: Number of characters printed (always 1)
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - Write a string to standard output
 * @str: The string to print
 *
 * Return: Number of characters printed
 */
int _puts(char *str)
{
	int printed_chars = 0;

	while (*str)
	{
		printed_chars += _putchar(*str);
		str++;
	}
	return (printed_chars);
}
