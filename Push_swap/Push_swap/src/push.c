/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 19:21:20 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/02 21:21:48 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void	push(t_node **stack_a, t_node **stack_b, char *str)
//{
//	t_node	*head_a;
//	t_node	*head_b;
//	t_node	*second_element_a;

//	head_a = *stack_a;
//	head_b = *stack_b;
//	second_element_a = head_a->next;
//	//head_a->next = head_b;
//	if (!stack_a)
//		return ;
//	if (head_b)
//		head_b->prev = head_a;
//	else
//		head_b = head_a;
//	if (second_element_a)
//		second_element_a->prev = NULL;
//	*stack_a = second_element_a;
//	*stack_b = head_a;
//	if (str)
//		write(1, str, strlen(str));
//}



void	push(t_node **stack_a, t_node **stack_b, char c)
{
	t_node	*head_a;
	t_node	*head_b;
	//t_node	*second_element_a;
	
	if (c == 'b')
	{
		ft_printf("pb\n");
		if(*stack_a)
		{
			head_a = *stack_a;
			*stack_a = head_a->next;
			head_a->next = *stack_b;
			*stack_b = head_a;
		}
	}
	if (c == 'a')
	{
		ft_printf("pa\n");
		if (*stack_b)
		{
			head_b = *stack_b;
			*stack_b = head_b->next;
			head_b->next = *stack_a;
			*stack_a = head_b;
		}
	}
}

//void    ft_give_index(t_stack **stack, int size)
//{
//    int     i;
//    long    min_found;
//    t_stack *min;
//    t_stack *copy;
//    min_found = -2147483649;
//    i = 0;
//    while (i < size)
//    {
//        min = ft_get_min(stack, min_found);
//        min->index = i;
//        min_found = min->content;
//        i++;
//    }
//    copy = *stack;
//    while (*stack)
//    {
//        if ((*stack)->content == min->content)
//            (*stack)->index = min->index;
//        *stack = (*stack)->next;
//    }
//    *stack = copy;
//}