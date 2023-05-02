/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 14:43:43 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/02 21:03:41 by asimone       ########   odam.nl         */
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

int		check_atoi(char *str, int *temp);
long	ft_atol(const char *str);
void	duplicate_check(t_node *stack);
int		ft_is_number(char c);
size_t	lstsize(t_node *lst);
t_node	*lstnew(int data);
void	lstadd_back(t_node **top_stack, t_node	*new_node);
void	push(t_node **stack_a, t_node **stack_b, char c);
void	swap(t_node **stack, char *str);
void	swap_time(t_node **stack_a, t_node **stack_b, char *str);
void	rotate(t_node **stack, char *str);
void	rotate_time(t_node **stack_a, t_node **stack_b, char *str);
void	reverse_rotate(t_node **stack, char *str);
void	reverse_rotate_time(t_node **stack_a, t_node **stack_b, char *str);
void	check_inputs(char **input, int argc);
t_node	*input_without_quotes(int argc, char **argv);
t_node	*input_quotes(char **input);
int is_number(char *number);
int		input_duplicate(t_node **stack);
size_t	list_size(t_node *stack);
void	sort_elements(t_node** stack_a, t_node **stack_b, int len);
void	print_stacks(t_node *stack_a, t_node *stack); //t_node** stack_b
int		get_lowest(t_node **head);
void 	ft_printlst(t_node **stack);
int		get_pos(t_node **head);

t_node	*lstlast(t_node *lst);
void	get_pos_radix(t_node **head);
void	lstadd_front(t_node **lst, t_node *new);
void	radix_sort(t_node **stack_a, t_node **stack_b, int argc);
int		get_biggest(t_node **head);
int	ordered_stack(t_node *stack);
#endif