#include "main.h"
/**
 * strprint - prints str element of a linked list.
 * @head: pointer to first node.
 * Return: size.
 */
size_t strprint(const node_t *head)
{
	size_t i = 0;

	while (head)
	{
		_puts(head->str ? head->str : "(nil)");
		_puts("\n");
		head = head->link;
		i++;
	}
	return (i);
}
/**
 * listprint - prints all elements of a list_t.
 * @head: pointer to first node.
 * Return: size.
 */
size_t listprint(const node_t *head)
{
	size_t i = 0;

	while (head)
	{
		_puts(atoa_clone(head->n, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(head->str ? head->str : "(nil)");
		_puts("\n");
		head = head->link;
		i++;
	}
	return (i);
}
/**
 * str_alias_print - prints alias string.
 * @node: alias node.
 * Return: 0 Always(success), 1 (error).
 */
int str_alias_print(node_t *node)
{
	char *ptr = NULL, *b = NULL;

	if (node)
	{
		ptr = _strchr(node->str, '=');
		for (b = node->str; b <= ptr; b++)
			_putchar(*b);
		_putchar('\'');
		_puts(ptr + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}
/**
 * write_file_d - print characters to file descriptor.
 * @chars: character.
 * @file_d: file descriptor.
 * Return: 1 (success), -1 (error).
 */
int write_file_d(char chars, int file_d)
{
	static int i;
	static char buffer[1024];

	if (chars == -1|| i >= 1024)
	{
		write(file_d, buffer, i);
		i = 0;
	}
	if (chars != -1)
		buffer[i++] = chars;
	return (1);
}
/**
 *str_inp_print - write input string.
 * @str: the string to be printed
 * @file_d: file descriptor.
 * Return: number of chars.
 */
int str_inp_print(char *str, int file_d)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += write_file_d(*str++, file_d);
	}
	return (i);
}