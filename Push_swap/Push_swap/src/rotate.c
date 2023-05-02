/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 19:34:11 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/02 20:56:43 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_time(t_node **stack_a, t_node **stack_b, char *str)
{
	rotate(stack_a, NULL);
	rotate(stack_b, NULL);
	if (str)
		write(1, "rr\n", 3);
}

void	reverse_rotate_time(t_node **stack_a, t_node **stack_b, char *str)
{
	reverse_rotate(stack_a, NULL);
	reverse_rotate(stack_b, NULL);
	if (str)
		write(1, "rrr\n", 4);
}

void	rotate(t_node **stack, char *str)
{
	t_node	*head;
	t_node	*tail;

	if (lstsize(*stack) <= 1)
		return ;
	head = *stack;
	tail = *stack;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = head;
	tail->prev = tail;
	*stack = head->next;
	head->prev = NULL;
	head->next->prev = NULL;
	head->next = NULL;
	if (str)
		write(1, str, strlen(str));
}

void	reverse_rotate(t_node **stack, char *str)
{
	t_node	*new_node;
	
	new_node = lstnew((lstlast(*stack))->data);
	lstadd_front(stack, new_node);
	while ((*stack) != NULL)
	{
		if ((*stack)->next->next == NULL)
		{
			free((*stack)->next);
			(*stack)->next = NULL;
		}
		(*stack) = (*stack)->next;
	}
	(*stack) = new_node;
	if (str)
		write(1, str, strlen(str));
}
