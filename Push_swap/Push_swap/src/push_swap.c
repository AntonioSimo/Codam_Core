/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 13:41:50 by asimone       #+#    #+#                 */
/*   Updated: 2023/04/24 19:17:05 by asimone       ########   odam.nl         */
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
	else if (argc == 2)
	{
		stack_a = input_quotes(&argc, argv);
		input_duplicate(&stack_a);
	}
	else
		input_without_quotes(argc, argv);
	return (0);
}
