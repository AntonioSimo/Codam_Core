#include "../include/philo.h"

int	check_input(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (EXIT);
	if (ft_is_digit(argc, argv) != 0)
		return (EXIT);
	if (valid_input(argc, argv) != 0)
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

int	valid_input(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 6 && ft_atoi(argv[i]) <= 0)
		return (EXIT);
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 200)
		return (EXIT);
	return (SUCCESS);
}
