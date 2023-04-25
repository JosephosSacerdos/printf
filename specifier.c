#include "main.h"

/**
 * get_specifier - finds the format function
 * @s: the format string
 * Return: the number of bytes printed by yhe user
 */
int (*get_specifier(char *s))(va_list ap, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int j = 0;

	while (specifiers[j].specifier)
	{
		if (*s == specifiers[j].specifier[0])
		{
			return (specifiers[j].f);
		}
		j++;
	}
	return (NULL);
}

/**
 * get_print_func - finds the format function
 * @s: the format string
 * @ap: argument pointer
 * @params: the parameters structure
 * Return: the number of bytes printed by the user
 */
int get_print_func(char *s, va_list ap, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);

	if (f)
		return (f(ap, params));
	return (0);
}

/**
 * get_flag - finds the flag function
 * @s: the format string
 * @params: the parameters structure
 * Return: if flag was valid
 */
int get_flag(char *s, params_t *params)
{
	int j = 0;

	switch (*s)
	{
		case '+':
			j = params->plus_flag = 1;
			break;
		case ' ':
			j = params->space_flag = 1;
			break;
		case '#':
			j = params->hashtag_flag = 1;
			break;
		case '-':
			j = params->minus_flag = 1;
			break;
		case '0':
			j = params->zero_flag = 1;
			break;
	}
	return (j);
}

/**
 * get_modifier - finds the modifier function
 * @s: the format string
 * @params: the parameters structure
 * Return: if modifier was valid
 */
int get_modifier(char *s, params_t *params)
{
	int j = 0;

	switch (*s)
	{
	case 'h':
		j = params->h_modifier = 1;
		break;
	case 'l':
		j = params->l_modifier = 1;
		break;
	}
	return (j);
}

/**
 * get_width - gets the width from the format string
 * @s: the format string
 * @params: the parameters structure
 * @ap: the argument pointer
 * Return: new pointer to return
 */
char *get_width(char *s, params_t *params, va_list ap)
{
	int w = 0;

	if (*s == '*')
	{
		w = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			w = w * 10 + (*s++ - '0');
	}
	params->width = w;
	return (s);
}
