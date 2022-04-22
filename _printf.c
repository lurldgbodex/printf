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
	int (*pfunc)(va_list, flags_t *);
	va_list ap;
	const char *p;
	flags_t flags = {0, 0, 0};

	register int count = 0;

	va_start(ap, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%');
			{
				count += _putchar (*p);
				continue;
			}
			while (get_flag(*p, &flags))
				p++;
			pfunc = get_print(*p);
			count += (pfunc)
				? pfunc(ap, &flags)
				: _printf("%%%c", *p);
		}
		else
			count += _putchar(*p);
	}
	_putchar(-1);
	va_end(ap);
	return (count);
}
