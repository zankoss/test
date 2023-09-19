#include "main.h"
/**
 * get_commands - find command.
 * @data: parameter.
 */
void get_commands(data_t *data)
{
	char *path = NULL;
	int a, b;

	data->data003 = data->data002[0];
	if (data->data007 == 1)
	{
		data->data005++;
		data->data007 = 0;
	}
	for (a = 0, b = 0; data->data001[a]; a++)
		if (!delim_check(data->data001[a], " \t\n"))
			b++;
	if (!b)
		return;

	path = get_cmd_path(data, _getenv(data, "PATH="), data->data002[0]);
	if (path)
	{
		data->data003 = path;
		_fork(data);
	}
	else
	{
		if ((imode(data) || _getenv(data, "PATH=")
			|| data->data002[0][0] == '/') && command_check(data, data->data002[0]))
			_fork(data);
		else if (*(data->data001) != '\n')
		{
			data->data014 = 127;
			errprint(data, "not accessible\n");
		}
	}
}
/**
 * delim_check - verify if character is a delimeter.
 * @chars: character to check.
 * @dm: delimeter.
 * Return: 1 (seccess), 0 (failure)
 */
int delim_check(char chars, char *dm)
{
	while (*dm)
		if (*dm++ == chars)
			return (1);
	return (0);
}
/**
 * command_check - check if is exe cmd.
 * @data: argument.
 * @p: path.
 * Return: 1 (seccess), 0 (not).
 */
int command_check(data_t *data, char *p)
{
	struct stat st;

	(void)data;
	if (!p || stat(p, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}
/**
 * chars_cp - copy characters.
 * @str: string.
 * @start_idx: beginning index.
 * @stop_idx: stopping index.
 * Return: buffer.
 */
char *chars_cp(char *str, int start_idx, int stop_idx)
{
	static char buffer[1024];
	int a = 0, b = 0;

	for (b = 0, a = start_idx; a < stop_idx; a++)
		if (str[a] != ':')
			buffer[b++] = str[a];
	buffer[b] = 0;
	return (buffer);
}
/**
 * get_cmd_path - lock up for cmd in the PATH.
 * @data: argument.
 * @str: string.
 * @cmd: the command.
 * Return: full path or NULL.
 */
char *get_cmd_path(data_t *data, char *str, char *cmd)
{
	int i = 0, curr = 0;
	char *p;

	if (!str)
		return (NULL);
	if ((_strlen(cmd) > 2) && if_starts(cmd, "./"))
	{
		if (command_check(data, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!str[i] || str[i] == ':')
		{
			p = chars_cp(str, curr, i);
			if (!*p)
				_strcat(p, cmd);
			else
			{
				_strcat(p, "/");
				_strcat(p, cmd);
			}
			if (command_check(data, p))
				return (p);
			if (!str[i])
				break;
			curr = i;
		}
		i++;
	}
	return (NULL);
}