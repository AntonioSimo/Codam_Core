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

int		check_atoi(char *str, int *temp)
{
	int i;

	i = 0;

	if (str[i] <= 48 && str[i] >= 57)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
	else 
		return (*temp);
}

int	ft_atoi_push_swap(char *str)
{
	int	i;
	int	neg;
	int	result;

	i = 0;
	result = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (neg < 0)
		return (result * neg);
	return (result);
}

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

void		**check_inputs(int counter, char **arguments)
{

	int i;

	i = 1;
	if (counter < 2)
	{
		exit (EXIT_FAILURE);
	}
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
//bigger than an integer and/or there are duplicates. print error when there are duplicates, input is not intiger, > or < INT_MAX INT_MIN, no numeric input, "      "

// - If no parameters are specified, the program must not display anything and give the
//prompt back.

// - hard code when sort 2, 3, 4, 5 and then big numbers.

//scrivere i comandi sa, ra, pa, rra, rrb, rb, sb, pb
