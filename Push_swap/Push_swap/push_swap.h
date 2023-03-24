/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 14:43:43 by asimone       #+#    #+#                 */
/*   Updated: 2023/03/24 16:45:46 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "Libft/include/libft.h"

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} t_node;

typedef struct stack {
    t_node *stack_a;
    t_node *stack_b;
} t_two_stack;

void	**check_inputs(int counter, char **arguments);
int		check_atoi(char *str, int *temp);
int	    ft_atoi_push_swap(char *str);
int	    lstsize(t_node *lst);
t_node	*lstnew(int data);
int		sa(t_two_stack *stack);

#endif