/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/20 15:14:31 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/03 18:46:39 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*lstlast(t_node *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	lstadd_back(t_node **top_stack, t_node *new_node)
{
	t_node	*last_node;

	if (*top_stack == NULL)
	{
		*top_stack = new_node;
		return ;
	}
	last_node = *top_stack;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = new_node;
	new_node->prev = last_node;
	return ;
}

size_t	lstsize(t_node *lst)
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

	new_node = ft_calloc(1, sizeof(t_node));
	if (!new_node)
		return (free(new_node), NULL);
	new_node->data = data;
	new_node->pos = -1;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	lstadd_front(t_node **lst, t_node *new)
{
	new->next = *lst;
	*lst = new;
}
