#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>


/**
 * struct node - singly linked list.
 * @n: number.
 * @str: string.
 * @link: points to the next node.
 */
typedef struct node
{
	int n;
	char *str;
	struct node *link;
} node_t;

/**
 *struct - arguments for function.
 *@data001: string of arguements.
 *@data002: strings make from args.
 *@data003: path of string.
 *@data004: argument count.
 *@data005: error count.
 *@data006: error code.
 *@data007: count line of input.
 *@data008: filename.
 *@data009: list of environ.
 *@data012: environ.
 *@data010: history linked list.
 *@data011: alias linked list.
 *@data013: changed env.
 *@data014: last command.
 *@data015: pointer address if chaining.
 *@data016: logical operators.
 *@data017: file descriptor.
 *@data018: line count of hist.
 */
typedef struct get_data
{
	char *data001;
	char **data002;
	char *data003;
	int data004;
	unsigned int data005;
	int data006;
	int data007;
	char *data008;
	node_t *data009;
	node_t *data010;
	node_t *data011;
	char **data012;
	int data013;
	int data014;
	char **data015;
	int data016;
	int data017;
	int data018;
} data_t;

#define DATA_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, 0, 0, 0}

/**
 *struct builtin - hold a builtin string.
 *@t: builtin flag.
 *@f: function.
 */
typedef struct builtin
{
	char *t;
	int (*f)(data_t *);
} built_sheet;

int main(int argc, char **argv);
void print_err_str(char *str);
int print_err_chars(char chars);
int env_list(data_t *data);
node_t *add_node_end(node_t **head, const char *str, int n);
char *my_memset(char *ptr, char value, unsigned int num);
char *_strdup(const char *str);
int get_history(data_t *data);
int create_hist_list(data_t *data, char *buffer, int n_line);
int relist_history(data_t *data);
int del_node_index(node_t **head, unsigned int n);
char *_getenv(data_t *data, const char *env_name);
char *if_starts(const char *str, const char *substr);
int _strlen(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
void kill_data(data_t *data);
int shell_loop(data_t *data, char **argv);
ssize_t read_line(data_t *data);
ssize_t input_cmd(data_t *data, char **buffer, size_t *length);
int nextline(data_t *data, char **ptr, size_t *length);
ssize_t gets_line_buff(data_t *data, char *buffer, size_t *i_size);
void remp_sharp(char *buffer);
void *_realloc(void *ptr, unsigned int prev_size, unsigned int next_size);
int imode(data_t *data);
void _puts(char *str);
int _putchar(char chars);
char *_strchr(char *str, char chars);
char *_strncpy(char *dest, char *src, int n);
char *_strncat(char *dest, char *src, int n);
int search_built(data_t *data);
int _strcmp(char *str1, char *str2);
int _quit(data_t *data);
void errprint(data_t *data, char *strerro);
size_t strprint(const node_t *head);
int _environ(data_t *data);
int _dir_change(data_t *data);
int _his_display(data_t *data);
size_t listprint(const node_t *head);
char *atoa_clone(long int n, int b, int f);
int init_new_env(data_t *data);
int init_new_env2(data_t *data, char *varb, char *vstr);
int rm_new_env(data_t *data);
int rm_new_env2(data_t *data, char *varb);
int _cd_dir(data_t *data);
int str_alias_print(node_t *node);
node_t *node_with_prefix(node_t *node, char *prefix, char chars);
int alias_puts(node_t *node);
int mimi_alias(data_t *data);
int delim_check(char chars, char *dm);
int command_check(data_t *data, char *p);
char *chars_cp(char *str, int start_idx, int stop_idx);
char *get_cmd_path(data_t *data, char *str, char *cmd);
char **str_of_list(node_t *head);
char **arr_cp_env(data_t *data);
void kill_data_struct(data_t *data, int secc);
void _fork(data_t *data);
void get_commands(data_t *data);
char *bring_hist(data_t *data);
int write_file_d(char chars, int file_d);
int create_hist_file(data_t *data);
ssize_t index_of_node(node_t *head, node_t *node);
int errconv(char *str);
void str_of_str_free(char **strstr);
void free_nodes(node_t **ptr);
int ptr_free_addr(void **ptr);
int str_inp_print(char *str, int file_d);
void if_chaining(data_t *data, char *buffer, size_t *pos, size_t start, size_t length);
int check_chaining(data_t *data, char *buffer, size_t *pos);
void ctrl_c(__attribute__((unused))int signal);
size_t length_of_list(const node_t *head);
int alias_to_str(data_t *data, char *str);
int decimal_print(int num, int file_d);
char **string_to_word(char *str, char *delim);
int alias_to_token(data_t *data);
int str_change(char **str1, char *str2);
int var_to_token(data_t *data);
void data_init(data_t *data, char **arg_v);

#endif