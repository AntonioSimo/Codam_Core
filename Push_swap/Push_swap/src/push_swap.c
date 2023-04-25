/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 13:41:50 by asimone       #+#    #+#                 */
/*   Updated: 2023/04/25 20:20:44 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node *stack_a;
	t_node *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		exit (EXIT_SUCCESS);
	if (argc == 2)
	{
		stack_a = input_quotes(argv);
		argc++;
	}
	else
	{
		stack_a = input_without_quotes(argc, argv);
		argc--;
	}
	input_duplicate(&stack_a);
	ft_printlst(&stack_a);
	printf("argc = %d\n", argc);
	sort_elements(&stack_a, &stack_b, argc);
	ft_printlst(&stack_a);
	return (0);
}
