#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: input
 *
 * Return: number of characters printed excluding the null byte used
 */
int _printf(const char *format, ...)
{
	int (*get_ptr)(va_list, int);
	va_list ap;
	int i, len;

	va_start(ap, format);
	if (!format)
		return (-1);
	i = 0, len = 0;

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
			{
				len += _putchar(format[i]);
				i++;
				continue;
			}
			if (format[i] == '\0')
				return (-1);
			get_ptr = get_print_func(format[i]);
			if (get_ptr != NULL)
				len = get_ptr(ap, len);
			else
			{
				len += _putchar(format[i - 1]);
				len += _putchar(format[i]);
			}
			i++;
		}
		else
		{
			len += _putchar(format[i]);
			i++;
		}
	}
	va_end(ap);
	return (len);
}
