#include "monty.h"
/**
 * push_to_stack - Pushes an element to the stack
 * @stack: Pointer to the top of the stack
 * @line_number: The current line number in the script file
 */
void push_to_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "L%d: Error: malloc failed\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node->n = line_number;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}

/**
 * print_all - prints all values on the stack
 * @stack: pointer to the top of the stack
 * @line_number: not used
 */
void print_all(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

