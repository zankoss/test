#include "main.h"
/**
 *print_err_str - prints an input string.
 * @str: the string to be printed.
 * Return: Nothing.
 */
void print_err_str(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		print_err_chars(str[i]);
		i++;
	}
}
/**
 * print_err_chars - prints the character to stderr.
 * @chars: character to print.
 * Return: (1) success, (-1) error.
 */
int print_err_chars(char chars)
{
	static int i;
	static char buffer[1024];

	if (chars == -1 || i >= 1024)
	{
		write(2, buffer, i);
		i = 0;
	}
	if (chars != -1)
		buffer[i++] = chars;
	return (1);
}
/**
 *_puts - prints an input string
 *@str: the string to be printed
 * Return: Nothing
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}
/**
 * _putchar - writes the character c to stdout.
 * @chars: The character to print.
 * Return: 1 (success) -1 (error).
 */
int _putchar(char chars)
{
	static int i;
	static char buffer[1024];

	if (chars == -1 || i >= 1024)
	{
		write(1, buffer, i);
		i = 0;
	}
	if (chars != -1)
		buffer[i++] = chars;
	return (1);
}
/**
 * decimal_print - prints a decimal number.
 * @num: the input
 * @file_d: the filedescriptor to write to
 * Return: number of characters printed
 */
int decimal_print(int num, int file_d)
{
	int (*__putchar)(char) = _putchar;
	int i, n = 0;
	unsigned int a, b;

	if (file_d == STDERR_FILENO)
		__putchar = print_err_chars;
	if (num < 0)
	{
		a = -num;
		__putchar('-');
		n++;
	}
	else
		a = num;
	b = a;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (a / i)
		{
			__putchar('0' + b / i);
			n++;
		}
		b %= i;
	}
	__putchar('0' + b);
	n++;

	return (n);
}