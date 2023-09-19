#include "main.h"
/**
 * _environ - display current environment.
 * @data: arguments.
 * Return: Always 0.
 */
int _environ(data_t *data)
{
	strprint(data->data009);
	return (0);
}
/**
 * _dir_change - changes current directory.
 * @data: arguments.
 *  Return: Always 0.
 */
int _dir_change(data_t *data)
{
	char **arr;

	arr = data->data002;
	_puts("zankomaster \n");
	if (0)
		_puts(*arr);
	return (0);
}
/**
 * init_new_env - Initialize a new environment variable.
 * @dara: arguments.
 * Return: Always 0.
 */
int init_new_env(data_t *data)
{
	if (data->data004 != 3)
	{
		print_err_str("zankomaster\n");
		return (1);
	}
	if (init_new_env2(data, data->data002[1], data->data002[2]))
		return (0);
	return (1);
}
/**
 * rm_new_env - unset environment.
 * @data: arguments.
 * Return: Always 0.
 */
int rm_new_env(data_t *data)
{
	int i;

	if (data->data004 == 1)
	{
		print_err_str("zankomaster.\n");
		return (1);
	}
	for (i = 1; i <= data->data004; i++)
		rm_new_env2(data, data->data002[i]);

	return (0);
}
/**
 * _cd_dir - changes the directory.
 * @data: arguments.
 * Return: Always 0.
 */
int _cd_dir(data_t *data)
{
	char *str, *d, buf[1024];
	int dir_change;

	str = getcwd(buf, 1024);
	if (!str)
		_puts("failure\n");
	if (!data->data002[1])
	{
		d = _getenv(data, "HOME=");
		if (!d)
			dir_change = /* */
				chdir((d = _getenv(data, "PWD=")) ? d : "/");
		else
			dir_change = chdir(d);
	}
	else if (_strcmp(data->data002[1], "-") == 0)
	{
		if (!_getenv(data, "OLDPWD="))
		{
			_puts(str);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(data, "OLDPWD=")), _putchar('\n');
		dir_change = /* */
			chdir((d = _getenv(data, "OLDPWD=")) ? d : "/");
	}
	else
		dir_change = chdir(data->data002[1]);
	if (dir_change == -1)
	{
		errprint(data, "can't cd to ");
		print_err_str(data->data002[1]), print_err_chars('\n');
	}
	else
	{
		init_new_env2(data, "OLDPWD", _getenv(data, "PWD="));
		init_new_env2(data, "PWD", getcwd(buf, 1024));
	}
	return (0);
}