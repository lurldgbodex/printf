#include "main.h"

/**
 * get_print_func - selects the right printing function
 * depending on the conversion specifier
 * @c: character that hold the conversion specifier 
 * Description: the function loops throught the structs array
 *
 * Return: a pointer to the matching printing function
 */
int (*get_print_func(char c))(va_list, int)
{
	forms specifics[] = {
		{'i', print_int},
		{'s', print_str},
		{'c', print_ch},
		{'d', print_int},
		{'x', print_hex},
		{'X', print_heX},
		{'S', print_Str},
		{'o', print_octal},
		{'R', print_rot13},
		{'u', print_unsigned},
		{'b', print_b}
	};

	int i;

	for (i = 0; specifics[i].spec; i++)
	{
		if (c == specifics[i].spec)
			return (specifics[i].fspec);
	}

	return (NULL);
}
