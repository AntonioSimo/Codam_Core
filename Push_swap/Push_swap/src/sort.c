/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 12:33:40 by asimone       #+#    #+#                 */
/*   Updated: 2023/04/05 16:47:38 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 4 elementi
// 1 2 3 4 gia ordinati
// 2 4 1 3 reverse_rotate + reverse_rotate + push
// 3 1 4 2 swap
// 1 2 4 3 push
// 3 4 2 1 reverse_rotate + push
// usa il sort_three_element
// push back the smallest number


void	sort_three_elements(t_node **stack)
{
	int	first;
	int	second;
	int third;

	first = (*stack)->data;
	second = (*stack)->next->data;
	third = (*stack)->next->next->data;
	if (first > second && first < third && second < third)
		swap (stack, "sa\n");
	else if (first < second && first > third && second > third)
		reverse_rotate (stack, "rra\n");
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

void	sort_elements(t_node** stack)
{
	if (!(*stack)->next)
		return ;
	else if (!(*stack)->next->next)
	{
		if ((*stack)->data > (*stack)->next->data)
			swap(stack, "sa\n");
	}
	else if (!(*stack)->next->next->next)
		sort_three_elements(stack);
}