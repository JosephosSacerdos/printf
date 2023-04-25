#include "main.h"

/**
 * _puts - prints a string with newline
 * @str: the string to print
 * Return: void
 */
int _puts(char *str)
{
	char *b = str;

	while (*str)
		_putchar(*str++);
	return (str - b);
}

/**
 * _putchar - writes the character c to stdout
 * @c: the character to print
 * Return: On success it gives 1
 * On error: it gives -1 as a return and errno is set appropriately
 */
int _putchar(int c)
{
	static int j;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || j >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, j);
		j = 0;
	}
	if (c != BUF_FLUSH)
		buf[j++] = c;
	return (1);
}
