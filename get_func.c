#include "monty.h"
/**
 * get_func - executes the appropriate opcode function
 * @tokens: tokenized lines from the file
 * Return: 1 on success 0 0n failure
 */
int get_func(char **tokens)
{
	instruction_t instruction_struct[] = { {"push", push_to_stack},
	{"pall", print_all}, {"pint", print_top}, {"pop", pop_from_stack},
	{"swap", swap_top_two}, {"add", add_top_two}, {"nop", do_nothing} };
	int j, argument, idx;
	char *opcode;
	stack_t *stack;

	idx = 0;
	stack = NULL;
	while (tokens[idx] != NULL)
	{
		j = 0;
		opcode = get_opcode(tokens[idx]);
		check_for_null(opcode);
		while (j < 7)
		{
			if (strcmp(instruction_struct[j].opcode, opcode) == 0)
			{
				if (strcmp(opcode, "push") == 0)
				{
					argument = get_argument(tokens[idx]);
					if (argument == -1)
					{
						free(opcode);
						return (0);
					}
					instruction_struct[j].f(&stack, argument);
				}
				else
					instruction_struct[j].f(&stack, idx + 1);
				free(opcode);
				break;
			}
			j++;
		}
		check_seven(j, opcode, idx);
		idx++;
	}
	return (1);
}
/**
 * get_opcode - gets the first opcode
 * @line: line from the file
 * Return: returns the pointer to the opcode
 */
char *get_opcode(char *line)
{
	int i, j;
	char *opcode = malloc(20);

	i = 0;
	j = 0;

	while (line[i] != '\0' && (line[i] == ' ' || line[i] == '\t'))
	{
		i++;
	}
	while (line[i] != '\0' && line[i] != ' ' && line[i] != '\t')
	{
		opcode[j] = line[i];
		j++;
		i++;
	}
	opcode[j] = '\0';
	return (opcode);
}
/**
 * get_argument - gets the argument for the opcode
 * @str: line from the file
 * Return: the argument integer or -1 0n failure
 */
int get_argument(char *str)
{
	int i, num;

	i = 0;

	while (str[i] != '\0' && !isdigit(str[i]))
	{
		i++;
	}
	if (!isdigit(str[i]))
	{
		return (-1);
	}

	num = 0;

	while (str[i] && isdigit(str[i]))
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}

	return (num);
}
/**
 * check_seven - checks if j is 7
 * @j: just j :)
 * @opcode: the opcode to be freed
 * @idx: index or line number for errors
 * Return: nothing
 */
void check_seven(int j, char *opcode, int idx)
{
	if (j == 7)
	{
		printf("L%d: unknown instruction %s\n", idx + 1, opcode);
		free(opcode);
		exit(EXIT_FAILURE);
	}
	else
	{
		return;
	}
}
/**
 * check_for_null - checks for null string
 * @opcode: opcode strring to be checked
 * Return: nothing
 */
void check_for_null(char *opcode)
{
	if (opcode == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}
