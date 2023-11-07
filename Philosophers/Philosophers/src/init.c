#include "../include/philo.h"

int	philosophers(int argc, char **argv, t_data	*data)
{
	if (init_data(data, argc, argv) != 0)
		return (1);
	init_philos(data);
	init_mutexes(data);
	return (0);
}

int	init_data(t_data *data, int argc, char **argv)
{
	data->num_of_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->nb_meals = 0;
	if (argc == 6)
	{
		data->nb_meals = ft_atoi(argv[5]);
		if (data->nb_meals <= 0)
			return (ERR);
	}
	//data->start_time = get_current_time(); in the thread
	return (malloc_philos(data));
}

void	init_mutexes(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->num_of_philos)
	{
		data->death_check = 0;
		pthread_mutex_init(&data->forks[i], NULL);
		pthread_mutex_init(&data->mut_die_t, NULL);
		pthread_mutex_init(&data->mut_eat_t, NULL);
		i++;
	}
}

void	init_philos(t_data *data)
{
	t_philo	*philos;
	int		i;

	i = 0;
	philos = data->philos;
	while (i < data->num_of_philos)
	{
		philos[i].id = i + 1;
		philos[i].nb_meals_had = 0;
		philos[i].last_eat_time = 0;
		philos[i].state = ALIVE;
		philos[i].mut_die_t = &data->mut_die_t;
		philos[i].mut_eat_t = &data->mut_eat_t;
		philos[i].left_fork = &data->forks[i];
		if (i == 0)
			philos[i].right_fork = &data->forks[data->num_of_philos - 1];
		else
			philos[i].right_fork = &data->forks[i - 1];
		i++;
	}
}

int	malloc_philos(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data->num_of_philos);
	if (!data->philos)
		return (write(2, ERROR, 13));
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_of_philos);
	if (!data->philos)
		return (free(data->philos), write(2, ERROR, 13));
	return (0);
}
