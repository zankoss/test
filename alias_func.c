#include "main.h"
/**
 * alias_no_str - alias to string, unset.
 * @data: parameter.
 * @str: string alias.
 * Return: Always 0 (success), 1 (error).
 */
int alias_no_str(data_t *data, char *str)
{
	char *ptr, chars;
	int string;

	ptr = _strchr(str, '=');
	if (!ptr)
		return (1);
	chars = *ptr;
	*ptr = 0;
	string = del_node_index(&(data->data011),
		index_of_node(data->data011, node_with_prefix(data->data011, str, -1)));
	*ptr = chars;
	return (string);
}
/**
 * alias_to_str - alias to string, set.
 * @data: parameter.
 * @str: string alias.
 * Return: Always 0 (success), 1 (error).
 */
int alias_to_str(data_t *data, char *str)
{
	char *ptr;

	ptr = _strchr(str, '=');
	if (!ptr)
		return (1);
	if (!*++ptr)
		return (alias_no_str(data, str));

	alias_no_str(data, str);
	return (add_node_end(&(data->data011), str, 0) == NULL);
}
/**
 * alias_puts - puts alias string.
 * @node: node of alias.
 * Return: Always 0 (success), 1 (error).
 */
int alias_puts(node_t *node)
{
	char *ptr = NULL, *al_str = NULL;

	if (node)
	{
		ptr = _strchr(node->str, '=');
		for (al_str = node->str; al_str <= ptr; al_str++)
			_putchar(*al_str);
		_putchar('\'');
		_puts(ptr + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}
/**
 * alias_to_token - chanage alias to toekn in string.
 * @data: parameter.
 * Return: 1 (seccess), 0 (failure).
 */
int alias_to_token(data_t *data)
{
	int i;
	node_t *node;
	char *ptr;

	for (i = 0; i < 10; i++)
	{
		node = node_with_prefix(data->data011, data->data002[0], '=');
		if (!node)
			return (0);
		free(data->data002[0]);
		ptr = _strchr(node->str, '=');
		if (!ptr)
			return (0);
		ptr = _strdup(ptr + 1);
		if (!ptr)
			return (0);
		data->data002[0] = ptr;
	}
	return (1);
}
/**
 * mimi_alias - mimics the alias.
 * @info: arguments.
 * Return: Always 0.
 */
int mimi_alias(data_t *data)
{
	int i = 0;
	char *ptr = NULL;
	node_t *node = NULL;

	if (data->data004 == 1)
	{
		node = data->data011;
		while (node)
		{
			str_alias_print(node);
			node = node->link;
		}
		return (0);
	}
	for (i = 1; data->data002[i]; i++)
	{
		ptr = _strchr(data->data002[i], '=');
		if (ptr)
			alias_to_str(data, data->data002[i]);
		else
			alias_puts(node_with_prefix(data->data011, data->data002[i], '='));
	}

	return (0);
}