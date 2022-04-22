#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: input
 *
 * Return: number of characters printed excluding the null byte used
 */
int _printf(const char *format, ...)
{
	va_list ap;
	char *p, *sval;
	int ival;
	double dval;
	register int count = 0;

	va_start(ap, format);
	for (p = format; *p; p++)
	{
		if (*p != '%')
		{
			_putchar (*p);
			continue;
		}
		switch (*++p)
		{
			case 'c':
				cval = va_arg(ap, char);
				_printf("%c", cval);
				break;
			case 's':
				for (sval = va_arg(ap, char *); *sval; sval++)
					_putchar(*sval);
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
