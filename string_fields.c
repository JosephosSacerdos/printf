#include "main.h"

/**
 * get_precision - gets the precision from the format string
 * @p: the format string
 * @params: the parameters structure
 * @ap: the argument pointer to be used 
 * Return: new pointer to be used
 */
char *get_precision(char *p, params_t *params, va_list ap)
{
	int w = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		w = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			w = w * 10 + (*p++ - '0');
	}
	params->precision = w;
	return (p);
}
