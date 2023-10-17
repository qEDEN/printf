#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - Produces output according to a format.
 * @format: Format string.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	count = print_formatted_output(format, args);
	va_end(args);

	return (count);
}

/**
 * print_formatted_output - Helper function to print formatted output.
 * @format: Format string.
 * @args: Variable arguments.
 * Return: The number of characters printed.
 */
int print_formatted_output(const char *format, va_list args)
{
	int count = 0;

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
		}
		else
		{
			format++;
			if (*format == 'c')
				count += print_char(va_arg(args, int));
			else if (*format == 's')
				count += print_string(va_arg(args, char *));
			else if (*format == '%')
			{
				write(1, "%", 1);
				count++;
			}
		}
		format++;
	}

	return (count);
}

/**
 * print_char - Print a character and return the number of characters printed.
 * @c: Character to be printed.
 * Return: The number of characters printed.
 */
int print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

/**
 * print_string - Print a string and return the number of characters printed.
 * @str: String to be printed.
 * Return: The number of characters printed.
 */
int print_string(char *str)
{
	int count = 0;

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		write(1, str, 1);
		str++;
		count++;
	}

	return (count);
}
