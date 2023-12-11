/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimone <asimone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:34:32 by asimone           #+#    #+#             */
/*   Updated: 2023/11/21 17:26:07 by asimone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	philosophers(int argc, char **argv, t_data *data)
{
	if (init_data(data, argc, argv) != 0)
		return (EXIT);
	if (data->num_of_philos == 1)
	{
		ft_handle_one_philo(data);
		return (SUCCESS);
	}
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
	data->philo_fully_ate = 0;
	data->nb_meals = 0;
	if (argc == 6)
		data->nb_meals = ft_atoi(argv[5]);
	return (malloc_philos(data));
}

int	init_mutexes(t_data *data)
{
	int		i;

	i = -1;
	if (pthread_mutex_init(&data->mut_die_t, NULL) != 0)
		return (EXIT);
	if (pthread_mutex_init(&data->mut_write, NULL) != 0)
		return (EXIT);
	while (++i < data->num_of_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (EXIT);
		if (pthread_mutex_init(&data->philos[i].mut_eat_t, NULL) != 0)
			return (EXIT);
		if (pthread_mutex_init(&data->philos[i].mut_fully_eat, NULL) != 0)
			return (EXIT);
	}
	return (SUCCESS);
}

int	init_philos(t_data *data)
{
	t_philo	*philos;
	int		i;

	i = -1;
	philos = data->philos;
	while (++i < data->num_of_philos)
	{
		philos[i].id = i + 1;
		philos[i].is_eating = 0;
		philos[i].death = 0;
		philos[i].nb_meals_had = 0;
		philos[i].last_eat_time = get_current_time();
		philos[i].data = data;
		philos[i].mut_die_t = &data->mut_die_t;
		philos[i].left_fork = &data->forks[i];
		philos[i].right_fork = &data->forks[(i + 1) % data->num_of_philos];
	}
	return (SUCCESS);
}

int	malloc_philos(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data->num_of_philos);
	if (!data->philos)
		return (write(2, MALLOC_ERROR, 13));
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_of_philos);
	if (!data->philos)
		return (free(data->philos), write(2, MALLOC_ERROR, 13));
	return (SUCCESS);
}
