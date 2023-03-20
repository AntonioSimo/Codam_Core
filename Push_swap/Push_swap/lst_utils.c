/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/20 15:14:31 by asimone       #+#    #+#                 */
/*   Updated: 2023/03/20 15:14:32 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//void	ft_lstadd_back(t_list **lst, t_list *new)
//{
//	t_list	*lst_node;

//	if (*lst == NULL)
//	{
//		*lst = new;
//		return ;
//	}
//	lst_node = ft_lstlast(*lst);
//	lst_node->next = new;
//}

//t_list	*ft_lstlast(t_list *lst)
//{
//	if (lst == NULL)
//		return (NULL);
//	while (lst->next != NULL)
//		lst = lst->next;
//	return (lst);
//}

//t_list	*ft_lstnew(void *content)
//{
//	t_list	*new_node;

//	new_node = malloc(sizeof(t_list));
//	if (!new_node)
//		return (NULL);
//	new_node->content = content;
//	new_node->next = NULL;
//	return (new_node);
//}

//int	ft_lstsize(t_list *lst)
//{
//	int	i;

//	i = 0;
//	while (lst)
//	{
//		i++;
//		lst = lst->next;
//	}
//	return (i);
//}