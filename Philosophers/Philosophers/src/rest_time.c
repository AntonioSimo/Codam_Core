#include "../include/philo.h"

void	rest_time(t_philo *philo, t_data *data)
{
	philo->state = SLEEPING;
	print_message(data, PURPLE, philo->id, SLEEP);
	ft_usleep(data->time_to_sleep);
}
