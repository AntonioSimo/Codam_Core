/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 14:43:43 by asimone       #+#    #+#                 */
/*   Updated: 2023/03/29 22:15:18 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/include/libft.h"

# define RED "\033[31;1m"
# define BOLD "\033[1m"
# define RESET "\033[0m"

typedef struct node {
	int				data;
	struct node		*next;
	struct node		*prev;
}	t_node;

typedef struct stack {
	t_node	*stack_a;
	t_node	*stack_b;
}	t_two_stack;

int		check_atoi(char *str, int *temp);
long	ft_atol(const char *str);
int		ft_is_number(char c);
int		lstsize(t_node *lst);
t_node	*lstnew(int data);
void	lstadd_back(t_node **top_stack, int number);
void	push(t_node **stack_a, t_node **stack_b, char *str);
void	swap(t_node **stack, char *str);
void	swap_time(t_node **stack_a, t_node **stack_b, char *str);
void	rotate(t_node **stack, char *str);
void	rotate_time(t_node **stack_a, t_node **stack_b, char *str);
void	reverse_rotate(t_node **stack, char *str);
void	reverse_rotate_time(t_node **stack_a, t_node **stack_b, char *str);
void	check_inputs(char **input, int argc);
void	input_whitout_quotes(int argc, char **argv);
void	input_quotes(int argc, char **input);

#endif