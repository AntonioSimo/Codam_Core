#include "../include/philo.h"

void	*routine(void *args)
{
	int		i;
	t_data	*data;
	t_philo	*philo;

	i = 0;
	philo = (t_philo *)args;
	data = philo->data;
	if (philo->id % 2)
		usleep(500);
	while (1)
	{
		meal_time(philo, data);
		rest_time(philo, data);
		think_time(philo, data);
		die_time(philo, data);
		if (philo->nb_meals_had == data->nb_meals)
			break ;
		i++;
	}
}

int	philo_thread(t_data *data)
{
	int		i;
	t_philo	*philos;

	i = 0;
	data->start_time = get_current_time(0);
	philos = (t_philo *)data->philos;
	while (i < data->num_of_philos)
	{
		pthread_create(&data->philos_thread, NULL, routine, &philos[i]);
		//ft_usleep(500);
		i++;
	}
	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_join(data->philos_thread, NULL);
		i++;
	}
	return (0);
}
