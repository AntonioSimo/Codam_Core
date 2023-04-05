/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 12:33:48 by asimone       #+#    #+#                 */
/*   Updated: 2023/04/05 16:57:21 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_number(char c)
{
	if ((c >= '0' && c <= '9') || c == '+' || c == '-')
		return (1);
	return (0);
}

void	input_quotes(int argc, char **input)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		input = ft_split(input[1], ' ');
		argc = 0;
		while (input[argc])
		{
			argc++;
		}
	}
	while (input[i])
	{
		if (ft_is_number(*(input[i])) == 0)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		i++;
	}
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