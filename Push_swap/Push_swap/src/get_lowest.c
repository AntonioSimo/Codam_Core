/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_lowest.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/25 15:02:47 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/01 18:14:47 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_lowest(t_node **head)
{
	t_node	*stack;
	t_node	*min;
	int lowest_number;

	stack = (*head);
	lowest_number = stack->data;
	min = stack;
	while (stack)
	{
		if (stack->data < lowest_number)
		{
			min = stack;
			lowest_number = stack->data;
		}
		stack = stack->next;
	}
	printf("This is the lowest %d\n", lowest_number);
	printf("-----------------------------\n");
	ft_printlst(&min);
	return (min);
}

int	get_pos(t_node **head)
{
	int		i;
	t_node	*min;
	t_node	*stack;

	i = 0;
	stack = (*head);
	while (stack)
	{
		min = get_lowest(head);
		if (stack->data == min->data)
			break;
		stack = stack->next;
		i++;
	}
	return (i);
}