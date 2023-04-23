/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 12:33:40 by asimone       #+#    #+#                 */
/*   Updated: 2023/04/18 16:24:12 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//// 4 elementi
//// 1 2 3  gia ordinati
//   1 3 2
//// 2 3 1  reverse_rotate + reverse_rotate + push
//   2 1 3
//// 3 1 2  swa
//   3 2 1
//// usa il sort_three_element
//// push back the smallest number

int	ordered_stack(t_node **stack)
{
	t_node	*current;
	int		previous;

	if (!*stack)
		return (1);
	current = *stack;
	previous = current->data;
	while (current)
	{
		if (current->data < previous)
			return (0);
		previous = current->data;
		current = current->next;
	}
	return (1);
}

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

//void	sort_four_elements(t_node **stack)
//{
//	get_the_smallest(stack);
//}

//void	sort_five_elements(t_node **stack)
//{

//}

void	sort_elements(t_node** stack_a, t_node**stack_b, int argc)
{
	if (ordered_stack(stack_a))
		return ;
	if (argc <= 5)
	{
		if (argc == 2)
			swap(stack_a, "sa\n");
		else if (argc == 3)
			sort_three_elements(stack_a);
		else if (argc == 4)
			sort_four_elements(stack_a, stack_b, argc);
		else if (argc == 5)
			sort_five_elements(stack_a, stack_b, argc);
	}
	else
		radix_sort(stack_a, stack_b, argc);
}