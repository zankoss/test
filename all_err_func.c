#include "main.h"
/**
 * errconv - converts a string to an integer.
 * @str: string to be converted.
 * Return: 0 if no numbers, -1 on error.
 */
int errconv(char *str)
{
	int i = 0;
	unsigned long int res = 0;

	if (*str == '+')
		str++;
	for (i = 0;  str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			res *= 10;
			res += (str[i] - '0');
			if (res > 4096)
				return (-1);
		}
		else
			return (-1);
	}
	return (res);
}
/**
 * errprint - display error message.
 * @data: parameter.
 * @strerro: string containing error.
 * Return: 0 if no numbers, -1 on error.
 */
void errprint(data_t *data, char *strerro)
{
	print_err_str(data->data008);
	print_err_str(": ");
	decimal_print(data->data005, STDERR_FILENO);
	print_err_str(": ");
	print_err_str(data->data002[0]);
	print_err_str(": ");
	print_err_str(strerro);
}
/**
 * atoa_clone - a clone of itoa
 * @n: number.
 * @b: base.
 * @f: argument flags.
 * Return: string
 */
char *atoa_clone(long int n, int b, int f)
{
	static char *arr;
	static char buf[50];
	char s = 0;
	char *ptr;
	unsigned long a = n;

	if (!(f & 2) && n < 0)
	{
		a = -n;
		s = '-';

	}
	arr = f & 1 ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buf[49];
	*ptr = '\0';

	do	{
		*--ptr = arr[n % b];
		a /= b;
	} while (a != 0);

	if (s)
		*--ptr = s;
	return (ptr);
}