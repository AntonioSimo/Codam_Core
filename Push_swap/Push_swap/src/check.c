/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/29 22:17:56 by asimone       #+#    #+#                 */
/*   Updated: 2023/04/24 19:09:07 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

//void	print_stacks(t_node *stack_a, t_node *stack_b)
//{
//	size_t size_a;
//	size_t size_b;
//	size_t i;
//	size_t i_2;

//	size_a = list_size(stack_a);
//	size_b = list_size(stack_b);
//	i = (size_a > size_b ? size_a - size_b : size_b - size_a);
//	i_2 = (size_a > size_b ? size_a - i : size_b - i);
//	if (size_a == size_b)
//	{
//		i_2 = size_a;
//		i = 0;
//	}
//	printf("\tA\tB\n");
//	while (i_2)
//	{
//		printf("\t%d\t%d\n" , stack_a->data, stack_b->data);
//		i_2--;
//		stack_a = stack_a->next;
//		stack_b = stack_b->next;
//	}
//	while (i && size_a > size_b)
//	{
//		printf("\t%d\n" , stack_a->data);
//		i--;
//		stack_a = stack_a->next;
//	}
//	while (i && size_a < size_b)
//	{
//			printf("\t\t%d\n" , stack_b->data);
//			i--;
//			stack_b = stack_b->next;

//	}
//	printf("\n\tEND PRINT FUNC\n");
//}