/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/13 15:37:34 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/01 18:12:19 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_pos_radix(t_node **head)
{
	int		i;
	int		lowest_number;
	t_node	*min;
	t_node	*stack;

	i = 0;
	lowest_number = INT_MIN;
	stack = (*head);
		min = get_lowest(head);
	
	//while(stack)
	//{
		
	//}
	//printf("i=%d\n", i);
	//ft_printf("pos 1 = %d\n", (*head)->pos);
	//ft_printf("pos 2 =%d\n", (*head)->next->pos);
	//ft_printf("pos 3 =%d\n", (*head)->next->next->pos);
}

void	radix_sort(t_node **stack_a, t_node **stack_b, int argc)
{
	(void) stack_b;
	get_pos_radix(stack_a);
	//ft_printf("pos 1 = %d\n", (*stack_a)->pos);
	//ft_printf("pos 2 =%d\n", (*stack_a)->next->pos);
	//ft_printf("pos 3 =%d\n", (*stack_a)->next->next->pos);
	argc++;
}