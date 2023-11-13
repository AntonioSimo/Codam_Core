#include "../include/philo.h"

int	philosophers(int argc, char **argv, t_data	*data)
{
	if (init_data(data, argc, argv) != 0)
		return (EXIT);
	if (init_mutexes(data) != 0)
		return (EXIT);
	if (init_philos(data) != 0)
		return (EXIT);
	if (philo_thread(data) != 0)
		return (EXIT);
	return (SUCCESS);
}

int	init_data(t_data *data, int argc, char **argv)
{
	data->num_of_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->nb_meals = 0;
	data->start_time = 0;
	if (argc == 6)
	{
		data->nb_meals = ft_atoi(argv[5]);
		if (data->nb_meals <= 0)
			return (EXIT);
	}
	return (malloc_philos(data));
}

int	init_mutexes(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_mutex_init(&data->mut_eat_t, NULL);
		pthread_mutex_init(&data->forks[i], NULL);
		pthread_mutex_init(&data->mut_write, NULL);
		i++;
	}
	return (SUCCESS);
}

int	init_philos(t_data *data)
{
	t_philo	*philos;
	int		i;

	i = 0;
	philos = data->philos;
	while (i < data->num_of_philos)
	{
		philos[i].id = i + 1;
		philos[i].is_eating = 0;
		philos[i].nb_meals_had = 0;
		philos[i].last_eat_time = 0;
		philos[i].state = THINKING;
		philos[i].data = data;
		philos[i].mut_eat_t = &data->mut_eat_t;
		philos[i].left_fork = &data->forks[i];
		if (i == 0)
		{
			philos[i].right_fork = &data->forks[data->num_of_philos - 1];
		}
		else
			philos[i].right_fork = &data->forks[i - 1];
		i++;
	}
	return (SUCCESS);
}

int	malloc_philos(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data->num_of_philos);
	if (!data->philos)
		return (write(2, ERROR, 13));
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_of_philos);
	if (!data->philos)
		return (free(data->philos), write(2, ERROR, 13));
	return (SUCCESS);
}
