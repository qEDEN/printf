#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Produces output according to a format.
 * @format: Format string.
 * Return: The number of characters printed or -1 on error.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	count = print_formatted_output(format, args);
	va_end(args);

	return (count);
}

/**
 * print_custom - Handle custom format specifier %r.
 * @args: Variable arguments.
 * Return: The number of characters printed or -1 on error.
 */
int print_custom(va_list args)
{
	char *message = "%r";

	write(1, message, strlen(message));
	return (strlen(message));
}

/**
 * print_formatted_output - Helper function to print formatted output.
 * @format: Format string.
 * @args: Variable arguments.
 * Return: The number of characters printed or -1 on error.
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
			else if (*format == 'r')
				count += print_custom(args);
			else if (*format == '%')
			{
				write(1, "%", 1);
				count++;
			}
			else
			{
				write(1, "%", 1);
				write(1, format, 1);
				count += 2;
			}
		}
		format++;
	}

	return (count);
}

