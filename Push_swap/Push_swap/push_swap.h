/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 14:43:43 by asimone       #+#    #+#                 */
/*   Updated: 2023/03/23 18:51:58 by asimone       ########   odam.nl         */
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
    struct node *stack_a;
    struct node *stack_b;
} t_two_stack;

void	**check_inputs(int counter, char **arguments);
int		check_atoi(char *str, int *temp);
int	    ft_atoi_push_swap(char *str);
int	    lstsize(t_node *lst);
t_node	*lstnew(int data);
int		sa(t_two_stack *stack);

#endif