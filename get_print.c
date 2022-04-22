#include "main.h"

/**
 * get_print - selects the right printing function
 * depending on the conversion specifier
 * @s: character that hold the conversion specifier 
 * Description: the function loops throught the structs array
 *
 * Return: a pointer to the matching printing function
 */
int (*get_print(char s))(va_list, flags_t *)
{
	ph func_arr[] = {
		{'i', print_int},
		{'s', print_string},
		{'c', print_char},
		{'d', print_unsigned},
		{'x', print_hex},
		{'X', print_hex_big},
		{'%', print_percent},
		{'p', print_address},
		{'S', print_bigS},
		{'r', print_rev},
		{'o', print_octal},
		{'R', print_rot13},
		{'0', print_octal}
	};
	int flags = 14;

	register int i;

	for (i = 0; i < flags; i++)
		if (func_arr[i].c == s)
			return (func_arr[i].f);
	return (NULL);
}
