#include "main.h"
#include <string.h>

/**
 * _printf - produces output according to a format
 * @format: input
 *
 * Return: number of characters printed excluding the null byte used
 */
int _printf(const char *format, ...)
{
	va_list ap;
	const char *p;
	char *sval;
	char cval;
	register int count = 0;

	va_start(ap, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	for (p = format; *p; p++)
	{
		if (*p != '%')
		{
			count += _putchar (*p);
			continue;
		}
		switch (*++p)
		{
			case 'c':
				cval = (char)va_arg(ap, int);
				_putchar('c'); 
				break;
			case 's':
				for (sval = va_arg(ap, char *); *sval; sval++)
					count += _putchar(*sval);
				break;
			case '%':
				_putchar('%');
				break;
			default:
				_putchar(*p);
				break;
		}
		count += _putchar(*p);
	}
	_putchar(-1);
	va_end(ap);
	return (count);
}
