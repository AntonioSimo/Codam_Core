/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 12:33:48 by asimone       #+#    #+#                 */
/*   Updated: 2023/03/28 12:54:47 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void	init(t_Node* stack)
//{
//	stack->top = NULL;
//}

//int		pop(t_Stack** stack)
//{
//	int value;

//	value = stack->top->data;
//	t_Node* node = stack->top;
//	stack->top = stack->top->next;

//	return (value);
//}

//int		check_atoi(char *str, int *temp)
//{
//	int i;

//	i = 0;

//	if (str[i] <= 48 && str[i] >= 57)
//	{
//		ft_putstr_fd("Error\n", STDERR_FILENO);
//		exit (EXIT_FAILURE);
//	}
//	else 
//		return (*temp);
//}

int	ft_isnumber(int c)
{
	return ((c >= '0' && c <= '9') || c == '+' || c == '-' || c != '\0');
}

//void	push(t_node** stack, int value, char **new_data)
//{
//	t_node* node;
//	int		i;

//	i = 1;
//	node = (t_node *) malloc(sizeof(t_node));
//	while (i < value)
//	{
//		node->data = ft_atoi_push_swap(new_data[i]);
//		node->next = (*stack);
//		(*stack) = node;
//		ft_printf("%d\n", node->data);
//		i++;
//	}
//}

//void		**check_inputs(int counter, char **arguments)
//{

//	int	i;

//	i = 1;
//	if (counter < 1)
//		exit (EXIT_FAILURE);
//	while (i < counter)
//	{
//		int	n_arguments = ft_atol(arguments[i]);
//		if (n_arguments < INT_MIN || n_arguments > INT_MAX)
//		{
//			ft_putstr_fd("Error\n", STDERR_FILENO);
//			exit (EXIT_FAILURE);
//		}
//			return (NULL);
//	}
//	return (NULL);
//}

int main(void)
{
	int number;

	number = 0;
	printf("%d", ft_isnumber(number));
}