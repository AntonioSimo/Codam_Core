/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 14:43:43 by asimone       #+#    #+#                 */
/*   Updated: 2023/03/28 20:04:34 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "Libft/include/libft.h"

typedef struct node {
	int				data;
	struct node		*next;
	struct node		*prev;
}	t_node;

typedef struct stack {
	t_node	*stack_a;
	t_node	*stack_b;
}	t_two_stack;

void	**check_inputs(int counter, char **arguments);
int		check_atoi(char *str, int *temp);
long	ft_atol(const char *str);
int		lstsize(t_node *lst);
t_node	*lstnew(int data);
void	lstadd_back(t_node **top_stack, int number);
int		push(t_node **stack, t_node **stack_b, char *str);
int		swap(t_node **stack, char *str);
int		swap_time(t_node **stack_a, t_node **stack_b, char *str);
int		rotate(t_node **stack, char *str);
int		rotate_time(t_node **stack_a, t_node **stack_b, char *str);
int		reverse_rotate(t_node **stack, char *str);
int		reverse_rotate_time(t_node **stack_a, t_node **stack_b, char *str);

#endif