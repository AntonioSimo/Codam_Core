#include "../include/philo.h"

void	die_time(t_philo *philo, t_data *data)
{
	philo->state = DEAD;
	print_message(data, RED, philo->id, DIED);
	ft_usleep(data->time_to_die);
}
