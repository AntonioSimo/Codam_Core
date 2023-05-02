/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/13 15:37:34 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/02 22:24:06 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//t_node *ft_get_min(t_node **stack, long limit)
//{
//    t_node *current;
//    t_node *min;
//    int     min_found;
//    if (!*stack)
//        return (NULL);
//    current = *stack;
//    min_found = INT_MAX;
//    min = NULL;
//    while (current)
//    {
//        if (current->data > limit && current->data < min_found)
//        {
//            min_found = current->data;
//            min = current;
//        }
//        current = current->next;
//    }
//    return (min);
//}
//void    counting_sort(t_node **stack, int size)
//{
//    int     i;
//    long    min_found;
//    t_node *min;
//    t_node *copy;
//    min_found = -2147483649;
//    i = 0;
//    while (i < size)
//    {
//        min = ft_get_min(stack, min_found);
//        min->pos = i;
//        min_found = min->data;
//        i++;
//    }
//    copy = *stack;
//    while (*stack)
//    {
//        if ((*stack)->data == min->data)
//            (*stack)->pos = min->pos;
//        *stack = (*stack)->next;
//    }
//    *stack = copy;
//}
int	get_biggest(t_node **head)
{
	t_node *stack;
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

static int	second_biggest_number(t_node *stack, long biggest_number)
{
	int new_big;
	int i;

	i = 0;
	new_big = stack->data;
	while(stack)
	{
		if (stack->data > new_big && stack->data < biggest_number)
		{
			new_big = stack->data;
		}
		i++;
		stack = stack->next;
	}
	return (new_big);
}		

void	counting_sort(t_node **head, int size)
{
	int		i;
	long		biggest_number;
	t_node	*copy;

	i = size;
	copy = *head;
	biggest_number = 2147483648;
	while(i)
	{
		biggest_number = second_biggest_number(copy, biggest_number);
		while (*head)
		{
			if ((*head)->data == biggest_number)
			{
				(*head)->pos = i - 1;
				*head = copy;
				break;
			}
			*head = (*head)->next;
		}
		ft_printf("%d\n", (*head)->pos);
		i--;
	}
	*head = copy;
}

//void	radix_sort(t_node **stack_a, t_node **stack_b, int size)
//{
//	int 	i;
//	int 	bit;
//	t_node	*temporary_value;
	
//	bit = 0;
//	while (bit < 32)
//	{
//		i = 0;
//		temporary_value = *stack_a;
//		while (i < size)
//		{
//			if ((1 & (temporary_value->data >> bit)) == 0)
//				push(stack_a, stack_b, 'b');
//			else
//				rotate(stack_a, "ra\n");
//			temporary_value = *stack_a;
//			i++;
//		}
//		temporary_value = *stack_b;
//		while (*stack_b)
//			push(stack_a, stack_b, 'a');
//		bit++;
//		if (ordered_stack(stack_a))
//			return;
//	}
//}


void	radix_sort(t_node **stack_a, t_node **stack_b, int size)
{
	int i;
	int bit;
	
	bit = 1;
	counting_sort(stack_a, size);
	i = 0;
	while (i < 5)
	{
		i = 0;
		while (i < size)
		{
			if ((*stack_a)->pos & bit)
				rotate(stack_a, "ra\n");
			else
				push(stack_a, stack_b, 'b');
			i++;
		}	
		bit <<= 1;
		while (*stack_b)
			push(stack_a, stack_b, 'a');
	}
}