#include "monty.h"
/**
 * add_top_two - adds the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: current line number
 */
void add_top_two(stack_t **stack, unsigned int line_number)
{
	stack_t *top_node;
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: Error: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top_node = *stack;
	sum = top_node->n + top_node->next->n;

	pop_from_stack(stack, line_number);
	top_node = *stack;
	top_node->n = sum;
}
/**
 * do_nothing - literally does nothing
 * @stack: pointer to the top of the stack
 * @line_number: current line number
 */
void do_nothing(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
