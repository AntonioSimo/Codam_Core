/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 12:33:48 by asimone       #+#    #+#                 */
/*   Updated: 2023/04/24 19:25:24 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*input_quotes(int *argc, char **input)
{
	int i;
	char **numbers;
	long temp;
	t_node *stack_a;

	(void) argc; // Putting void infront of an unused variable is going to let the compiler thinks it's being used.
				 // It's used to cheat the -Wall Flags etc.
	stack_a = NULL;
	i = 0;
	numbers = ft_split(input[1], ' ');
	//printf("%s", *numbers); // Putting * in front of a double array is going to get the first element from the double array...
	while(numbers[i])
	{
		if(!is_number(numbers[i]))
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		temp = ft_atol(numbers[i]);
		if (temp > INT_MAX || temp < INT_MIN)
			exit(write(2, "Error\n", 6));
		lstadd_back(&stack_a, lstnew(temp)); //Protect it. For you in the future- gr chino.
		i++;
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
		exit(1);
	}
	if (number[i] == '-' || number[i] == '+')
		i++;
	if (number[i] == '\0')
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i++;
	}
	return (0);
}

int input_duplicate(t_node **stack)
{
	//Initialize variables
	// First element with the second third fourt and go on.
	t_node	*head;
	t_node	*temp;

	head = *stack;
	temp = *stack;
	while (head != NULL)
	{
		// Compare digits
		temp = head->next;
		while (temp != NULL)
		{
			if (head->data == temp->data) // First element with the second. but not third? and not fourth? Why?
			{
				ft_putstr_fd("Error\n", 2);
				exit(1);
			}
			temp = temp->next;
		}
		head = head->next;
	}
	return (0); //Return 0 if no duplicates are found.
}

void	input_without_quotes(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc > 2)
	{
		argc--;
		argv++;
		while (argv[i])
		{
			{
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			i++;
		}
	}
}