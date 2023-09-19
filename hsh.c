#include "main.h"
/**
 * main - entry point.
 * @argc: count argument.
 * @argv: vector argument.
 * Return: 0 on success, 1 on error.
 */
int main(int argc, char **argv)
{
	data_t data[] = { DATA_INIT };
	int file_d = 5;

	if (argc == 2)
	{
		file_d = open(argv[1], O_RDONLY);
		if (file_d == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				print_err_str(argv[0]);
				print_err_str("cannot open");
				print_err_str(argv[1]);
				print_err_chars('\n');
				print_err_chars(-1);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		data->data017 = file_d;
	}
	env_list(data);
	get_history(data);
	shell_loop(data, argv);
	return (EXIT_SUCCESS);
}