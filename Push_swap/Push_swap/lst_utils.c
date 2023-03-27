/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/20 15:14:31 by asimone       #+#    #+#                 */
/*   Updated: 2023/03/23 20:37:04 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void	lstadd_back(t_node **lst, t_node *new)
//{
//	t_node	*lst_node;

//	if (*lst == NULL)
//	{
//		*lst = new;
//		return ;
//	}
//	lst_node = ft_lstlast(*lst);
//	lst_node->next = new;
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
		return;
	}
	last_node = *top_stack; //last node is now head
	while (last_node->next != NULL) // anything under the head?
        last_node = last_node->next;
	new_node->prev = last_node;
	last_node->next = new_node;

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