#include <unistd.h>
#include "main.h"

/**
 * print_integer - Print an integer.
 * @n: Integer to be printed.
 *
 * Return: The number of characters printed.
 */
int print_integer(int n)
{
	char buffer[12];
	int count = 0;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		count++;
	}

	int i = 0;

	do {
		buffer[i] = '0' + (n % 10);
		n /= 10;
		i++;
	} while (n > 0);

	while (i > 0)
	{
		write(1, &buffer[i - 1], 1);
		i--;
		count++;
	}

	return (count);
}
