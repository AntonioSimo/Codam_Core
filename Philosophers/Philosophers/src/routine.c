/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimone <asimone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:34:46 by asimone           #+#    #+#             */
/*   Updated: 2023/11/15 19:21:11 by asimone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *args)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)args;
	data = philo->data;
	if (philo->id % 2 == 0)
		usleep(450);
	while (check_check(philo) != 1)
	{
		meal_time(philo, data);
		if (philo->nb_meals_had == data->nb_meals)
			break;
		rest_time(philo, data);
		think_time(philo, data);
	}
	return (NULL);
}

int	check_check(t_philo *philo)
{
	int	check = 0;

	pthread_mutex_lock(philo->mut_die_t);
	if (philo->death == 1)
	{
		//printf("first_check%i\n", philo->death);
		check = 1;
	}
	//printf("second_check%i\n", philo->death);
	pthread_mutex_unlock(philo->mut_die_t);
	return (check);
}

int	philo_thread(t_data *data)
{
	int		i;
	t_philo	*philos;

	philos = (t_philo *)data->philos;
	data->start_time = get_current_time();
	//	i = 0;
	//while (i < data->num_of_philos)
	//	philos[i++].last_eat_time = data->start_time;
	i = 0;
	while (i < data->num_of_philos)
	{
		if (pthread_create(&philos[i].philos_thread, NULL, routine, &philos[i]) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	if (pthread_create(&data->death_monitor, NULL, death_monitor, data) != 0)
		return (EXIT_FAILURE);
	if (pthread_join(data->death_monitor, NULL) != 0)
		return (EXIT);
	if (join_thread(data, philos) != 0)
		return (EXIT);
	return (EXIT_SUCCESS);
}

int	join_thread(t_data *data, t_philo *philo)
{
	int i;

	i = 0;
	while (i < data->num_of_philos)
	{
		if (pthread_join(data->philos[i].philos_thread, NULL) != 0)
			return (EXIT);
		i++;
	}
	destroy_mutex(data, philo);
	return (SUCCESS);
}

void	destroy_mutex(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&philo->mut_eat_t);
		i++;
	}
	// pthread_mutex_destroy(&data->philos->mut_write);
	pthread_mutex_destroy(philo->mut_die_t);
}

