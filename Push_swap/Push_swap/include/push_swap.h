/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 14:43:43 by asimone       #+#    #+#                 */
/*   Updated: 2023/04/23 17:09:08 by asimone       ########   odam.nl         */
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
	int				pos;
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
size_t	lstsize(t_node *lst);
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
void	input_without_quotes(int argc, char **argv);
void	input_quotes(int argc, char **input);

size_t	list_size(t_node *stack);
void	print_stacks(t_node *stack_a, t_node *stack_b);
void	sort_elements(t_node** stack_a, t_node** stack_b, int argc);

#endif