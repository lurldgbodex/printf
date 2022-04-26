#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct directives - holds format speicifiers and their functions
 * @spec: char
 * @fspec: function pointer
 */
typedef struct directives
{
	char spec;
	int (*fspec)(va_list, int);
} forms;

int _putchar(char c);
int _printf(const char *format, ...);
int (*get_print_func(char c))(va_list, int);
int print_ch(va_list, int);
int print_str(va_list, int);
int print_int(va_list, int);

#endif

