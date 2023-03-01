/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 10:50:26 by asimone       #+#    #+#                 */
/*   Updated: 2023/02/06 14:01:28 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

//void    ft_print_result(char const *s)
//{
//        int             len;

//        len = 0;
//        while (s[len])
//                len++;
//        write(1, s, len);
//}

//void    ft_print_result2(int n)
//{
//        char c;

//        if (n >= 10)
//                ft_print_result2(n / 10);
//        c = n % 10 + '0';
//        write (1, &c, 1);
//}

//int main(int argc, const char *argv[])
//{
//t_list	*elem;
//int		arg;

//alarm(TIMEOUT);
//if (argc == 1)
//return (0);
//else if ((arg = atoi(argv[1])) == 1)
//        {
//                char    str [] = "lorem ipsum dolor sit";

//                if (!(elem = ft_lstnew(str)))
//                                ft_print_result("NULL");
//                else
//                {
//                        if (!(elem->content))
//                                ft_print_result("NULL");
//                        else
//                        {
//                                ft_print_result(elem->content);
//                        }
//                        if (!(elem->next))
//                        {
//                                write(1, "\n", 1);
//                                ft_print_result("NULL");
//                        }
//                }
//        }
//        else if (arg == 2)
//        {
//                int             i;

//                i = 42;
//                if (!(elem = ft_lstnew(&i)))
//                                ft_print_result("NULL");
//                else
//                {
//                        if (!(elem->content))
//                                ft_print_result("NULL");
//                        else
//                        {
//                                ft_print_result2(*(int *)(elem->content));
//                        }
//                        if (!(elem->next))
//                        {
//                                write(1, "\n", 1);
//                                ft_print_result("NULL");
//                        }
//                }
//        }
//        else if (arg == 3)
//        {
//                if (!(elem = ft_lstnew(NULL)))
//                                ft_print_result("NULL");
//                else
//                {
//                        if (!(elem->content))
//                        {
//                                ft_print_result("NULL");
//                        }
//                        else
//                        {
//                                ft_print_result(elem->content);
//                        }
//                        if (!(elem->next))
//                        {
//                                write(1, "\n", 1);
//                                ft_print_result("NULL");
//                        }
//                }
//        }
//        return (0);
//}