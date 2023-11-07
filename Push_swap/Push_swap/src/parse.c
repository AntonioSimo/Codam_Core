/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 12:33:48 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/08 14:08:30 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/**
* @brief	Deallocate memory occupied by an array of strings 
* @param	input The array of strings to be freed. 
* @return	It frees the memory allocated for the array itself using the free function.
*/
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

/**
* @brief	Processes the input array of strings and creates a linked list 
*			containing the parsed numbers.
* @param	input The array of strings containing the input numbers.
* @return	The head of the linked list
*/
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

/**
* @brief	Processes the command-line arguments and creates a linked list
*			containing the parsed numbers.
* @param	argc The number of command-line arguments.
* @param	argv An array of strings representing the command-line arguments.
* @return	The head of the linked list
*/
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

/**
* @brief	Checks whether a given string represents a valid integer number.
* @param	number The string to be checked.
* @return	If the string passes all the checks and is determined to be a 
*			valid number, the function returns 1 to indicate that it is a 
*			valid number, otherwise it returns 0.
*/
int	is_number(char *number)
{
	int	i;

	i = 0;
	if (number[i] == '\0')
		return (0);
	while (number[i])
	{
		if (number[i] == '-' || number[i] == '+')
			i++;
		if (!ft_isdigit(number[i]))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		i++;
	}
	i = 0;
	if (ft_atol(&number[i]) > INT_MAX || ft_atol(&number[i]) < INT_MIN)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}

/**
* @brief	Checks for duplicate values in a linked list.
* @param	stack  A pointer to the head of the linked list.
* @return	It returns 0 to indicate that no duplicate values were found.
*/
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
