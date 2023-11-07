#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_input(argc, argv) != 0)
		return (write(2, ERROR, 13));
	if (philosophers(argc, argv, &data) != 0)
		return (write(2, ERROR, 13));
	return (0);
}
