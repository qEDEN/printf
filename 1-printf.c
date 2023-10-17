#include <stdarg.h>
#include <unistd.h>
#include "main.h"  // Your header file should contain function prototypes

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format != '%')  // Regular character
        {
            write(1, format, 1);  // Print the character
            count++;
        }
        else  // Format specifier
        {
            format++;  // Move to the character after '%'

            if (*format == '\0')  // Check for incomplete format specifier
                break;

            if (*format == 'c')  // Character specifier
            {
                char c = va_arg(args, int);  // Fetch the character argument
                write(1, &c, 1);  // Print the character
                count++;
            }
            else if (*format == 's')  // String specifier
            {
                char *str = va_arg(args, char *);  // Fetch the string argument
                write(1, str, strlen(str));  // Print the string
                count += strlen(str);
            }
            else if (*format == '%')  // Literal '%' character
            {
                write(1, "%", 1);  // Print '%'
                count++;
            }
        }

        format++;
    }

    va_end(args);
    return count;
}
