#include <unistd.h>
#include <main.h>

/**
 * _putchar - writes a character to the standard output
 * @c: The character to print
 * Return: On success, x of characters written. On error, -1 is returned
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}

