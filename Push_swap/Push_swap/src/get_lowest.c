/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_lowest.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/25 15:02:47 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/10 12:35:35 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/**
* @brief	Locates the lowest value in a linked list of nodes.
* @param	head Represent pointer to the pointer of the head node of the 
*			linked list.
* @return	Returns the lowest value found in the linked list.
*/
int	get_lowest(t_node **head)
{
	t_node	*stack;
	int		lowest_number;

	stack = (*head);
	lowest_number = stack->data;
	while (stack)
	{
		if (stack->data < lowest_number)
			lowest_number = stack->data;
		stack = stack->next;
	}
	return (lowest_number);
}

/**
* @brief	Locates the position (index) of the node with the lowest value in 
*			a linked list.
* @param	head Represent pointer to the pointer of the head node of the 
*			linked list.
* @return	Returns the position (index) of the node with the lowest value 
*			in the linked list.
*/
int	get_pos(t_node **head)
{
	int		i;
	int		min;
	t_node	*stack;

	i = 0;
	stack = (*head);
	while (stack)
	{
		min = get_lowest(head);
		if (stack->data == min)
			break ;
		stack = stack->next;
		i++;
	}
	return (i);
}
