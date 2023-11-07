#include "../include/philo.h"

void	rest_time(t_data *data)
{
	t_philo philo;

	philo.state = SLEEPING;
	print_message(PURPLE, data->time_to_sleep, philo.id, SLEEP);
	ft_usleep(500);
}