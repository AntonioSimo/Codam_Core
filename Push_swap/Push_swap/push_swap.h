/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 14:43:43 by asimone       #+#    #+#                 */
/*   Updated: 2023/03/20 16:38:01 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "Libft/include/libft.h"

typedef struct node {
    int data;
    int index;
    struct node* next;
} t_node;

typedef struct stack {
    struct t_node *stack_a;
    struct t_node *stack_b;
} t_two_stack;

void	**check_inputs(int counter, char **arguments);

#endif