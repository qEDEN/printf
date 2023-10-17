#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'c')
            {
                char c = va_arg(args, int);
                putchar(c);
                printed_chars++;
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char *);
                while (*str)
                {
                    putchar(*str);
                    str++;
                    printed_chars++;
                }
            }
            else if (*format == '%')
            {
                putchar('%');
                printed_chars++;
            }
            else
            {
                putchar('%');
                printed_chars++;
                putchar(*format);
                printed_chars++;
            }
        }
        else
        {
            putchar(*format);
            printed_chars++;
        }
        format++;
    }

    va_end(args);

    return printed_chars;
}

int main()
{
    int count = _printf("Hello, %s! This is a %c test. This is a percent sign: %%\n", "world", 'C');
    printf("\nCharacters printed: %d\n", count);
    return 0;
}
