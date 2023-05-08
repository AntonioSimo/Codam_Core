/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 13:41:50 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/08 11:12:05 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_node *stack)
{
	t_node	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

int	number_of_elements(t_node *stack_a)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		i++;
		stack_a = stack_a->next;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		exit (EXIT_SUCCESS);
	if (argc == 2)
	{
		stack_a = input_quotes(argv);
		argc = number_of_elements(stack_a);
	}
	else
	{
		stack_a = input_without_quotes(argc, argv);
		argc--;
	}
	input_duplicate(&stack_a);
	sort_elements(&stack_a, &stack_b, argc);
	free_stack(stack_a);
	return (0);
}
