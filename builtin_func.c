#include "main.h"
/**
 * create_hist_file - makes a file, or appends.
 * @data: parameter.
 * Return: 1 (success), -1 (failure)
 */
int create_hist_file(data_t *data)
{
	ssize_t file_d;
	char *filename = bring_hist(data);
	node_t *node = NULL;

	if (!filename)
		return (-1);

	file_d = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (file_d == -1)
		return (-1);
	for (node = data->data010; node; node = node->link)
	{
		str_inp_print(node->str, file_d);
		write_file_d('\n', file_d);
	}
	write_file_d(-1, file_d);
	close(file_d);
	return (1);
}
/**
 * search_built - find builtin command.
 * @data: parameter.
 * Return: -1 if not found,
 *			0 if successfully,
 *			1 if found but not successful,
 *			-2 if signals exit().
 */
int search_built(data_t *data)
{
	int i, built = -1;
	built_sheet built_sh[] = {
		{"exit", _quit},
		{"env", _environ},
		{"help", _dir_change},
		{"history", _his_display},
		{"setenv", init_new_env},
		{"unsetenv", rm_new_env},
		{"cd", _cd_dir},
		{"alias", mimi_alias},
		{NULL, NULL}
	};

	for (i = 0; built_sh[i].t; i++)
		if (_strcmp(data->data002[0], built_sh[i].t) == 0)
		{
			data->data005++;
			built = built_sh[i].f(data);
			break;
		}
	return (built);
}
/**
 * imode - true if shell is interactive mode.
 * @data: data address.
 * Return: 1 true, 0 otherwise.
 */
int imode(data_t *data)
{
	return (isatty(STDIN_FILENO) && data->data017 <= 2);
}
/**
 * _fork - thread to run command.
 * @data: parameter.
 * Return: void.
 */
void _fork(data_t *data)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(data->data003, data->data002, arr_cp_env(data)) == -1)
		{
			kill_data_struct(data, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(data->data014));
		if (WIFEXITED(data->data014))
		{
			data->data014 = WEXITSTATUS(data->data014);
			if (data->data014 == 126)
				errprint(data, "Permission denied\n");
		}
	}
}
/**
 * var_to_token - change variables to token in string
 * @data: parameter.
 * Return: 1 (seccess), 0 (failure).
 */
int var_to_token(data_t *data)
{
	int i = 0;
	node_t *node;

	for (i = 0; data->data002[i]; i++)
	{
		if (data->data002[i][0] != '$' || !data->data002[i][1])
			continue;

		if (!_strcmp(data->data002[i], "$?"))
		{
			str_change(&(data->data002[i]),
				_strdup(atoa_clone(data->data014, 10, 0)));
			continue;
		}
		if (!_strcmp(data->data002[i], "$$"))
		{
			str_change(&(data->data002[i]),
				_strdup(atoa_clone(getpid(), 10, 0)));
			continue;
		}
		node = node_with_prefix(data->data009, &data->data002[i][1], '=');
		if (node)
		{
			str_change(&(data->data002[i]),
				_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		str_change(&data->data002[i], _strdup(""));

	}
	return (0);
}