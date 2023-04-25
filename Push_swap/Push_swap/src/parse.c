/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 12:33:48 by asimone       #+#    #+#                 */
/*   Updated: 2023/04/25 16:57:24 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*input_quotes(char **input)
{
	int i;
	char **numbers;
	long temp;
	t_node *stack_a;

	stack_a = NULL;
	i = 0;
	numbers = ft_split(input[1], ' ');
	while(numbers[i])
	{
		if(!is_number(numbers[i]))
		{
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
		}
		temp = ft_atol(numbers[i]);
		if (temp > INT_MAX || temp < INT_MIN)
		{
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
		}
		lstadd_back(&stack_a, lstnew(temp)); //Protect it. For you in the future- gr chino.
		i++;
	}
	return (stack_a);
}

t_node	*input_without_quotes(int argc, char **argv)
{
	int	i;
	long temp;
	t_node *stack_a;

	stack_a = NULL;
	i = 0;
	if (argc > 2)
	{
		argc--;
		argv++;
		while (argv[i++])
		{
			if(!is_number(argv[i-1]))
			{
				ft_putstr_fd("Error\n", 2);
				exit(EXIT_FAILURE);
			}
			temp = ft_atol(argv[i-1]);
			if (temp > INT_MAX || temp < INT_MIN)
			{
				ft_putstr_fd("Error\n", 2);
				exit(EXIT_FAILURE);
			}
			lstadd_back(&stack_a, lstnew(temp)); 
		}
	}
	return (stack_a);
}

int is_number(char *number)
{
	int i;

	i = 0;
	if (!number)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (number[i] == '-' || number[i] == '+')
		i++;
	if (number[i] == '\0')
		return (0);
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
			return (0);
		i++;
	}
	return (1);
}

int input_duplicate(t_node **stack)
{
	t_node	*head;
	t_node	*temp;

	head = *stack;
	temp = *stack;
	while (head != NULL)
	{
		temp = head->next;
		while (temp != NULL)
		{
			if (head->data == temp->data)
			{
				ft_putstr_fd("Error\n", 2);
				exit(EXIT_FAILURE);
			}
			temp = temp->next;
		}
		head = head->next;
	}
	return (0);
}
