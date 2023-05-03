/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 12:33:40 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/03 12:55:44 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ordered_stack(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_three_elements(t_node **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->data;
	second = (*stack)->next->data;
	third = (*stack)->next->next->data;
	if (first > second && first < third && second < third)
		swap (stack, "sa\n");
	else if (first < second && first > third && second > third)
	{
		reverse_rotate (stack, "rra\n");
	}
	else if (first > second && first > third && second < third)
		rotate (stack, "ra\n");
	else if (first > second && first > third && second > third)
	{
		rotate (stack, "ra\n");
		swap (stack, "sa\n");
	}
	else if (first < second && first < third && second > third)
	{
		reverse_rotate (stack, "rra\n");
		swap (stack, "sa\n");
	}
	else
		return ;
}

void	sort_four_elements(t_node **stack_a, t_node **stack_b)
{
	int	pos;

	pos = get_pos(stack_a);
	if (pos == 1)
		swap(stack_a, "sa\n");
	else if (pos == 2)
	{
		reverse_rotate(stack_a, "rra\n");
		reverse_rotate(stack_a, "rra\n");
	}
	else if (pos == 3)
		reverse_rotate(stack_a, "rra\n");
	push(stack_a, stack_b, "pb\n");
	sort_three_elements(stack_a);
	push(stack_b, stack_a, "pa\n");
}

void	sort_five_elements(t_node **stack_a, t_node **stack_b)
{
	int	pos;

	pos = get_pos(stack_a);
	if (pos == 1)
		swap (stack_a, "sa\n");
	else if (pos == 2)
	{
		rotate(stack_a, "ra\n");
		rotate(stack_a, "ra\n");
	}
	else if (pos == 3)
	{
		reverse_rotate(stack_a, "rra\n");
		reverse_rotate(stack_a, "rra\n");
	}
	else if (pos == 4)
		reverse_rotate(stack_a, "rra\n");
	push(stack_a, stack_b, "pb\n");
	sort_four_elements(stack_a, stack_b);
	push(stack_b, stack_a, "pa\n");
}

void	sort_elements(t_node **stack_a, t_node **stack_b, int size)
{
	if (ordered_stack(*stack_a))
		return ;
	if (size <= 5)
	{
		if (size == 2)
			swap(stack_a, "sa\n");
		else if (size == 3)
			sort_three_elements(stack_a);
		else if (size == 4)
			sort_four_elements(stack_a, stack_b);
		else if (size == 5)
			sort_five_elements(stack_a, stack_b);
	}
	else
		radix_sort(stack_a, stack_b, size);
}
