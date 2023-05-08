/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 14:43:43 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/08 11:00:55 by asimone       ########   odam.nl         */
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

int		get_pos(t_node **head);
int		get_lowest(t_node **head);

t_node	*lstlast(t_node *lst);
void	lstadd_back(t_node **top_stack, t_node *new_node);
size_t	lstsize(t_node *lst);
t_node	*lstnew(int data);
void	lstadd_front(t_node **lst, t_node *new);
void	free_stack(t_node *stack);

t_node	*input_quotes(char **input);
t_node	*input_without_quotes(int argc, char **argv);
int		is_number(char *number);
int		input_duplicate(t_node **stack);

int		number_of_elements(t_node *stack_a);

void	push(t_node **stack_a, t_node **stack_b, char *str);

int		get_biggest(t_node **head);
int		second_biggest_number(t_node *stack, long biggest_number);
void	counting_sort(t_node *head, int size);
void	radix_sort(t_node **stack_a, t_node **stack_b, int size);

void	rotate_time(t_node **stack_a, t_node **stack_b, char *str);
void	reverse_rotate_time(t_node **stack_a, t_node **stack_b, char *str);
void	rotate(t_node **stack, char *str);
void	reverse_rotate(t_node **stack, char *str);

int		ordered_stack(t_node *stack);
void	sort_three_elements(t_node **stack);
void	sort_four_elements(t_node **stack_a, t_node **stack_b);
void	sort_five_elements(t_node **stack_a, t_node **stack_b);
void	sort_elements(t_node **stack_a, t_node **stack_b, int size);

void	swap_time(t_node **stack_a, t_node **stack_b, char *str);
void	swap(t_node **stack, char *str);

long	ft_atol(const char *str);

void	ft_printlst(t_node *stack);
#endif