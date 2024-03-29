/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 19:21:20 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/03 12:29:01 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/**
* @brief	Performs a push operation, moving the top element from one stack to 
*			another, and optionally prints a string.
* @param	stack_a Pointer to the top of the source stack.
* @param	stack_b Pointer to the top of the destination stack.
* @param	str String to be printed.
*/
void	push(t_node **stack_a, t_node **stack_b, char *str)
{
	t_node	*head_a;
	t_node	*head_b;
	t_node	*second_element_a;

	head_a = *stack_a;
	head_b = *stack_b;
	second_element_a = head_a->next;
	head_a->next = head_b;
	if (!stack_a)
		return ;
	if (head_b)
		head_b->prev = head_a;
	else
		head_b = head_a;
	if (second_element_a)
		second_element_a->prev = NULL;
	*stack_a = second_element_a;
	*stack_b = head_a;
	if (str)
		write(1, str, strlen(str));
}
