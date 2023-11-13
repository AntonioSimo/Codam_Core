#include "../include/philo.h"

void	think_time(t_philo *philo, t_data *data)
{
	philo->state = THINKING;
	print_message(data, YELLOW, philo->id, THINK);
}
