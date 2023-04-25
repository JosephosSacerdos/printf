#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: the format string
 * Return: number of bytes printed by the user
 */
int _printf(const char *format, ...)
{
	int sum = 0;
	va_list ap;
	char *P, *start;
	params_t params = PARAMS_INIT;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (P = (char *)format; *P; P++)
	{
		init_params(&params, ap);
		if (*P != '%')
		{
			sum += _putchar(*P);
			continue;
		}
		start = P;
		P++;
		while (get_flag(P, &params)) /* while char at P is flag char */
		{
			P++; /* increments the P */
		}
		P = get_width(P, &params, ap);
		P = get_precision(P, &params, ap);
		if (get_modifier(P, &params))
			P++;
		if (!get_specifier(P))
			sum += print_from_to(start, P,
				params.l_modifier || params.h_modifier ? P - 1 : 0);
		else
			sum += get_print_func(P, ap, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(ap);
	return (sum);
}
