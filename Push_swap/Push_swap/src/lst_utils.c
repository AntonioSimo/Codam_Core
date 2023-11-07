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
/**
* @brief	Returns the last node of the list.
* @param	lst Represents a pointer to the head of the linked list.
* @return	The last node of the list.
*/
t_node	*lstlast(t_node *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/**
* @brief	Adds a new element to the end of a linked list. 
* @param	top_stack Represents a pointer to a pointer of the head of the 
*			linked list
* @param	new_node Represents a pointer to the new element to be added.
*/
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

/**
* @brief	The function is used to determine the number of elements in a 
*			linked list.
* @param	lst Represents a pointer to the head of the linked list.
* @return	The number of elements in the linked list.
*/
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

/**
* @brief	Create a new node for a linked list with the provided content.
* @param	data Represents the value to be stored in the node.
* @return	Returns the new_node pointer, which points to the newly created node.
*/
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

/**
* @brief	Adds a new element to the front of a linked list. 
* @param	lst Represents a pointer to a pointer of the head of the linked list
* @param	new Represents a pointer to the new element to be added.
*/
void	lstadd_front(t_node **lst, t_node *new)
{
	new->next = *lst;
	*lst = new;
}
