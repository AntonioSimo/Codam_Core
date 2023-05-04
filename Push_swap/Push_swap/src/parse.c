/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 12:33:48 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/04 11:48:58 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(char **input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		free(input[i]);
		i++;
	}
	free(input);
}

t_node	*input_quotes(char **input)
{
	int		i;
	char	**numbers;
	long	temp;
	t_node	*stack_a;
	t_node	*new_ele;

	stack_a = NULL;
	i = 0;
	numbers = ft_split(input[1], ' ');
	while (numbers[i])
	{
		if (!is_number(numbers[i]))
			exit(EXIT_FAILURE);
		temp = ft_atol(numbers[i]);
		new_ele = lstnew(temp);
		if (!new_ele)
			return (free(new_ele), NULL);
		lstadd_back(&stack_a, new_ele);
		i++;
	}
	free_array(numbers);
	return (stack_a);
}

t_node	*input_without_quotes(int argc, char **argv)
{
	int		i;
	long	temp;
	t_node	*stack_a;
	t_node	*new_element;

	stack_a = NULL;
	i = 0;
	if (argc > 2)
	{
		argc--;
		argv++;
		while (argv[i++])
		{
			if (!is_number(argv[i - 1]))
				exit(EXIT_FAILURE);
			temp = ft_atol(argv[i - 1]);
			new_element = lstnew(temp);
			if (!new_element)
				return (free(new_element), NULL);
			lstadd_back(&stack_a, new_element);
		}
	}
	return (stack_a);
}

int	is_number(char *number)
{
	int	i;

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
	if (ft_atol(&number[i]) > INT_MAX || ft_atol(&number[i]) < INT_MIN)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

int	input_duplicate(t_node **stack)
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
