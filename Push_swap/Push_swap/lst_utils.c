/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/20 15:14:31 by asimone       #+#    #+#                 */
/*   Updated: 2023/03/28 20:06:29 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void push(t_node **head_ref, int new_data)
//{
//    t_node *new_node = lstnew(new_data);
//    new_node->next = *head_ref;
//    *head_ref = new_node;
//}

t_node	*lstlast(t_node *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

//void	lstclear(t_node **lst, void (*del)(void *))
//{
//	t_node	*node;

//	if (*lst == NULL)
//		return ;
//	while (*lst != NULL)
//	{
//		node = (*lst)->next;
//		ft_lstdelone(*lst, del);
//		*lst = node;
//	}
//	*lst = NULL;
//}

void	del_first(t_two_stack *stack, int control)
{
	t_node	*head;

	if (control)
	{
		head = stack->stack_a->next;
		free(stack->stack_a);
		stack->stack_a = head;
	}
	else
	{
		head = stack->stack_b->next;
		free(stack->stack_b);
		stack->stack_b = head;
	}
}

void	lstadd_front(t_node **lst, t_node *new)
{
	new->next = *lst;
	*lst = new;
	(*lst)->prev = NULL;
}

void	lstadd_back(t_node **top_stack, int number)
{
	t_node *new_node = lstnew(number);
    t_node *last_node;

	if (*top_stack == NULL) //if empty, new node becomes the stack
	{
		*top_stack = new_node;
		new_node->prev = new_node; //inizializzare il campo prev del primo elemento
		return;
	}
	last_node = *top_stack; //last node is now head
	while (last_node->next != NULL) // anything under the head?
        last_node = last_node->next;
	last_node->next = new_node;
	new_node->prev = last_node;

    return;
}

int	lstsize(t_node *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_node	*lstnew(int data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}
