/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 13:41:50 by asimone       #+#    #+#                 */
/*   Updated: 2023/04/05 16:49:29 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*allocate_stack(int argc, char **numbers)
{
	int		i;
	t_node	*stack;

	i = 0;
	stack = NULL;
	while (i < argc)
	{
		lstadd_back(&stack, ft_atoi(numbers[i]));
		i++;
	}
	return (stack);
}

int	main(int argc, char **argv)
{
	t_node *stack_a;
	t_node *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		exit (EXIT_SUCCESS);
	else if (argc == 2)
		input_quotes(argc, argv);
	else
		input_without_quotes(argc, argv);
	stack_a = allocate_stack(argc, argv);
	sort_elements(&stack_a);
	print_stacks(stack_a, stack_b);
	return (0);
}
