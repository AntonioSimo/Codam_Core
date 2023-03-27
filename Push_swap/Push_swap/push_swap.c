/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 13:41:50 by asimone       #+#    #+#                 */
/*   Updated: 2023/03/21 12:31:57 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void	init(t_Node* stack)
//{
//	stack->top = NULL;
//}

//int		pop(t_Stack** stack)
//{
//	int value;

//	value = stack->top->data;
//	t_Node* node = stack->top;
//	stack->top = stack->top->next;

//	return (value);
//}

//int		check_atoi(char *str, int *temp)
//{
//	int i;

//	i = 0;

//	if (str[i] <= 48 && str[i] >= 57)
//	{
//		ft_putstr_fd("Error\n", STDERR_FILENO);
//		exit (EXIT_FAILURE);
//	}
//	else 
//		return (*temp);
//}

void	push(t_node** stack, int value, char **new_data)
{
	t_node* node;
	int		i;

	i = 1;
	node = (t_node *) malloc(sizeof(t_node));
	while (i < value)
	{
		node->data = ft_atoi_push_swap(new_data[i]);
		node->next = (*stack);
		(*stack) = node;
		ft_printf("%d\n", node->data);
		i++;
	}
}

void		

void		**check_inputs(int counter, char **arguments)
{

	int	i;

	i = 1;
	if (counter < 1)
		exit (EXIT_FAILURE);
	while (i < counter)
	{
		int	n_arguments = ft_atoi_push_swap(arguments[i]);
		if (n_arguments < INT_MIN || n_arguments > INT_MAX)
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			exit (EXIT_FAILURE);
		}
			return (NULL);
	}
	return (NULL);
}


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

