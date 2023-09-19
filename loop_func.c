#include "main.h"
/**
 * shell_loop - shell loop function.
 * @data: return data.
 * @argv: argument.
 * Return: 0 (success), 1 (error code).
 */
int shell_loop(data_t *data, char **argv)
{
	ssize_t track = 0;
	int if_shell_cmd = 0;

	while (track != -1 && if_shell_cmd != -2)
	{
		kill_data(data);
		if (imode(data))
			_puts("$ ");
		print_err_chars(-1);
		track = read_line(data);
		if (track != -1)
		{
			data_init(data, argv);
			if_shell_cmd = search_built(data);
			if (if_shell_cmd == -1)
				get_commands(data);
		}
		else if (imode(data))
			_putchar('\n');
		kill_data_struct(data, 0);
	}
	create_hist_file(data);
	kill_data_struct(data, 1);
	if (!imode(data) && data->data014)
		exit(data->data014);
	if (if_shell_cmd == -2)
	{
		if (data->data006 == -1)
			exit(data->data014);
		exit(data->data006);
	}
	return (if_shell_cmd);
}
/**
 * string_to_word - convert a string to words.
 * @str: string.
 * @delim: the delimeter.
 * Return: array of strings, or NULL.
 */
char **string_to_word(char *str, char *delim)
{
	int i, j, a, b, count = 0;
	char **ptr;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!delim)
		delim = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!delim_check(str[i], delim) && (delim_check(str[i + 1], delim) || !str[i + 1]))
			count++;

	if (count == 0)
		return (NULL);
	ptr = malloc((1 + count) * sizeof(char *));
	if (!ptr)
		return (NULL);
	for (i = 0, j = 0; j < count; j++)
	{
		while (delim_check(str[i], delim))
			i++;
		a = 0;
		while (!delim_check(str[i + a], delim) && str[i + a])
			a++;
		ptr[j] = malloc((a + 1) * sizeof(char));
		if (!ptr[j])
		{
			for (a = 0; a < j; a++)
				free(ptr[a]);
			free(ptr);
			return (NULL);
		}
		for (b = 0; b < a; b++)
			ptr[j][b] = str[i++];
		ptr[j][b] = 0;
	}
	ptr[j] = NULL;
	return (ptr);
}
/**
 * if_starts - checks if pattern starts with larger data structure.
 * @str: string to search.
 * @substr: larger data structure to find.
 * Return: address of next char of larger data structure or NULL.
 */
char *if_starts(const char *str, const char *substr)
{
	while (*substr)
		if (*substr++ != *str++)
			return (NULL);
	return ((char *)str);
}
/**
 * _quit - quite the program.
 * @data: arguments.
 * Return: exits
 */
int _quit(data_t *data)
{
	int check;

	if (data->data002[1])
	{
		check = errconv(data->data002[1]);
		if (check == -1)
		{
			data->data014 = 2;
			errprint(data, "incorrect number: ");
			print_err_str(data->data002[1]);
			print_err_chars('\n');
			return (1);
		}
		data->data006 = errconv(data->data002[1]);
		return (-2);
	}
	data->data006 = -1;
	return (-2);
}
/**
 * ctrl_c - ctrl-C.
 * @signal: the signal.
 * Return: void.
 */
void ctrl_c(__attribute__((unused))int signal)
{
	_puts("\n");
	_puts("$ ");
	_putchar(-1);
}