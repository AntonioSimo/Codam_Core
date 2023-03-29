/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 13:41:50 by asimone       #+#    #+#                 */
/*   Updated: 2023/03/29 22:15:32 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node *stack;

	stack = NULL;
	if (argc == 1)
	{
		exit (EXIT_SUCCESS);
	}
	else if (argc == 2)
	{
		input_quotes(argc, argv);
	}
	else
		input_whitout_quotes(argc, argv);
	return (0);
}
