#ifndef MONTY_H
#define MONTY_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ctype.h>
#define MAX_LEN 1024
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


void free_tokens(char **tokens);
char **tokenize(char *buffer, char *delim);
char *reduce_spaces(char *str);
char *trim_whitespace(char *str);
int get_argument(char *str);
int get_func(char **tokens);
char *get_opcode(char *line);
void print_all(stack_t **stack, unsigned int line_number);
void push_to_stack(stack_t **stack, unsigned int line_number);
void pop_from_stack(stack_t **stack, unsigned int line_number);
void print_top(stack_t **stack, unsigned int line_number);
void swap_top_two(stack_t **stack, unsigned int line_number);
void add_top_two(stack_t **stack, unsigned int line_number);
void do_nothing(stack_t **stack, unsigned int line_number);
void check_seven(int j, char *opcode, int idx);
void check_for_null(char *opcode);
void check_null_tokens(char **tokens, int file_descriptor, char *buffer);
#endif
