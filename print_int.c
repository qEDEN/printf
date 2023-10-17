#include "main.h"

/**
 * print_int - Print an integer and return the number of characters printed.
 * @args: A va_list containing the integer to be printed.
 *
 * Return: The number of characters printed.
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;
	char buffer[12];
	int i = 0;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		count++;
	}

	do  {
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	} while (n);

	while (i > 0)
	{
		write(1, &buffer[--i], 1);
		count++;
	}

	return (count);
}
