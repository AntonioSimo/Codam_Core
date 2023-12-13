/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimone <asimone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:34:40 by asimone           #+#    #+#             */
/*   Updated: 2023/12/13 16:44:37 by asimone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_input(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (EXIT);
	if (ft_is_digit(argc, argv) != 0)
		return (EXIT);
	if (valid_input(argv) != 0)
		return (EXIT);
	return (SUCCESS);
}

int	ft_is_digit(int argc, char **argv)
{
	int	i;
	int	x;

	i = 1;
	while (i < argc)
	{
		x = 0;
		while (argv[i][x] != '\0')
		{
			if (argv[i][x] < '0' || argv[i][x] > '9')
				return (EXIT);
			x++;
		}
		i++;
	}
	return (SUCCESS);
}

int	valid_input(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) <= 0)
			return (EXIT);
		i++;
	}
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 200)
		return (EXIT);
	return (SUCCESS);
}
