#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>


int _printf(const char *format, ...);
int print_formatted_output(const char *format, va_list args);
int print_char(int c);
int print_string(char *str);

#endif /* MAIN_H */
