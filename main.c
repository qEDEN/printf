#include "main.h"
#include <stdio.h>

int main(void)
{
	int chars_printed;

	chars_printed = _printf("Hello, %s!\n", "world");
	printf("Characters printed: %d\n", chars_printed);

	return (0);
}
