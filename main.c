#include "main.h"

/**
 * main - Entry point for the program.
 *
 * Return: Always 0 (success).
 */
int main(void)
{
	_printf("Let's try to printf a simple sentence.\n");
	_printf("Let's try to printf a simple sentence.\n");

	_printf("Length:[%d, %i]\n", 39, 39);
	_printf("Length:[%d, %i]\n", 39, 39);

	_printf("Negative:[%d]\n", -762534);
	_printf("Negative:[%d]\n", -762534);

	_printf("Unsigned:[%u]\n", 2147484671);
	_printf("Unsigned:[%u]\n", 2147484671);

	_printf("Unsigned octal:[%o]\n", 20000001777);
	_printf("Unsigned octal:[%o]\n", 20000001777);

	_printf("Unsigned hexadecimal:[%x, %X]\n", 2147484671, 2147484671);
	_printf("Unsigned hexadecimal:[%x, %X]\n", 2147484671, 2147484671);

	_printf("Character:[%c]\n", 'H');
	_printf("Character:[%c]\n", 'H');

	_printf("String:[%s]\n", "I am a string !");
	_printf("String:[%s]\n", "I am a string !");

	_printf("Address:[%p]\n", (void *)0x7ffe637541f0);
	_printf("Address:[%p]\n", (void *)0x7ffe637541f0);

	_printf("Percent:[%%]\n");
	_printf("Percent:[%%]\n");

	_printf("Len:[%d]\n", 12);
	_printf("Len:[%d]\n", 12);

	_printf("Unknown:[%r]\n");
	_printf("Unknown:[%r]\n");

	return (0);
}
