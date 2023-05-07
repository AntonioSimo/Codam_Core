/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/13 15:37:34 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/03 12:53:51 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_biggest(t_node **head)
{
	t_node	*stack;
	int		max_number;

	stack = (*head);
	max_number = stack->data;
	while (stack)
	{
		if (stack->data > max_number)
			max_number = stack->data;
		stack = stack->next;
	}
	return (max_number);
}

int	second_biggest_number(t_node *stack, long biggest_number)
{
	int	new_big;
	//int	i;

	//i = 0;
	while (stack && stack->pos != -1)
		stack = stack->next;
	new_big = stack->data;
	while (stack)
	{
		if (stack->data > new_big && stack->data < biggest_number)
		{
			new_big = stack->data;
		}
		//i++;
		stack = stack->next;
	}
	return (new_big);
}		

void	counting_sort(t_node *head, int size)
{
	int		i;
	long	biggest_number;
	t_node	*copy;

	i = size;
	biggest_number = 2147483648;
	while (i)
	{
		copy = head;
		biggest_number = second_biggest_number(copy, biggest_number);
		while (copy)
		{
			if (copy->data == biggest_number)
			{
				copy->pos = i - 1;
			}
			copy = copy->next;
		}
		i--;
	}
}

void	radix_sort(t_node **stack_a, t_node **stack_b, int size)
{
	int	i;
	int	bit;

	bit = 1;
	counting_sort(*stack_a, size);
	while (!ordered_stack(*stack_a))
	{
		i = 0;
		while (i < size)
		{
			if ((*stack_a)->pos & bit)
				rotate(stack_a, "ra\n");
			else
				push(stack_a, stack_b, "pb\n");
			i++;
		}	
		bit <<= 1;
		while (*stack_b)
			push(stack_b, stack_a, "pa\n");
	}
}
