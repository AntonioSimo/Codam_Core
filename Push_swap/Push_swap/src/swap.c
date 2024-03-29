/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fra <fra@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:24:13 by asimone           #+#    #+#             */
/*   Updated: 2023/05/03 01:12:59 by fra              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/**
* @brief	Swaps the top elements of two stacks (stack_a and stack_b) at the 
*			same time and prints a given string.
* @param	stack_a Pointer to the top of the first stack.
* @param	stack_b Pointer to the top of the second stack.
* @param	str String to be printed.
*/
void	swap_time(t_node **stack_a, t_node **stack_b, char *str)
{
	swap(stack_a, NULL);
	swap(stack_b, NULL);
	if (str)
		write(1, str, strlen(str));
}

/**
* @brief	Swaps the top two elements of a stack and prints a given string.
* @param	stack Pointer to the top of the stack.
* @param	str String to be printed.
*/
void	swap(t_node **stack, char *str)
{
	t_node	*head;
	t_node	*second_element;
	t_node	*third_element;

	if (lstsize(*stack) <= 1)
		return ;
	head = *stack;
	second_element = (*stack)->next;
	third_element = (*stack)->next->next;
	if (third_element)
		third_element->prev = head;
	second_element->prev = NULL;
	second_element->next = head;
	head->prev = second_element;
	head->next = third_element;
	*stack = second_element;
	if (str)
		write(1, str, strlen(str));
}
