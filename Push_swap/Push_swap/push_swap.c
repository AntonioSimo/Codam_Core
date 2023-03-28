/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 13:41:50 by asimone       #+#    #+#                 */
/*   Updated: 2023/03/28 12:40:10 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node *stack = NULL;

	if ((void **)argv == check_inputs(argc, argv))
	{
		exit (EXIT_SUCCESS);
	}
	else 
	{
		push (&stack, argc, argv);
	}
	return (0);
}



// - In case of error, it must display "Error" followed by a ’\n’ on the standard error.
//Errors include for example: some arguments aren’t integers, some arguments are
//bigger than an integer and/or there are duplicates. Da check in atoi.

// - If no parameters are specified, the program must not display anything and give the
//prompt back.

//Creare una funzione check number con cifre + o - 

// - hard code when sort 2, 3, 4, 5 and then big numbers.

