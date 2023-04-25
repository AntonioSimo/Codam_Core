/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_lowest.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/25 15:02:47 by asimone       #+#    #+#                 */
/*   Updated: 2023/04/25 20:27:05 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_lowest(t_node **head, int lowest_number)
{
	t_node	*stack;
	t_node	*min;
	int 	biggest_number;

	stack = (*head);
	biggest_number = INT_MAX;
	min = (*head);
	while (stack)
	{
		if (stack->data <= biggest_number && stack->data > lowest_number)
		{
			biggest_number = stack->data;
			min = stack;
			//tmp->pos = i;
			//i++;
		}
		//printf("lowest = %d", biggest_number);
		//printf("pos = %d\n", tmp->pos);
		stack = stack->next;
	}
	return (min);
}

void	get_pos(t_node **head, int size)
{
	int		i;
	long	min_found;
	t_node	*min;

	min_found = INT_MIN;
	i = 0;
	while (i < size)
	{
		min = get_lowest(head, min_found);
		min->pos = i;
		min_found = min->data;
		i++;
	}
	printf("lowest number = %ld\n", min_found);
	printf("pos = %d\n", i);
}
