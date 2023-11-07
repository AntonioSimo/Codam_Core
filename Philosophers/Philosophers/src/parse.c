#include "../include/philo.h"

int	check_input(int argc, char **argv)
{
	if (argc < 5)
		return (1);
	if (argc > 6)
		return (1);
	if (ft_is_digit(argc, argv) != 0)
		return (1);
	if (valid_input(argc, argv) != 0)
		return (1);
	return (0);
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
				return (1);
			x++;
		}
		i++;
	}
	return (0);
}

int	valid_input(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 6 && ft_atoi(argv[i]) <= 0)
		return (1);
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 200)
		return (1);
	return (0);
}
