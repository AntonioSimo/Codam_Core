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
	while (1)
	{
		meal_time(philo, data);
		if (philo->nb_meals_had == data->nb_meals)
			break;
		rest_time(philo, data);
		think_time(philo, data);
	}
	return (NULL);
}

int	philo_thread(t_data *data)
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = (t_philo *)data->philos;
	data->start_time = get_current_time();
	while (i < data->num_of_philos)
		philos[i++].last_eat_time = data->start_time;
	i = 0;
	while (i < data->num_of_philos)
	{
		if (pthread_create(&data->philos_thread, NULL, routine, &philos[i]) != 0)
			return (EXIT);
		i++;
	}
	if (pthread_create(&data->death_monitor, NULL, death_monitor, &data) != 0)
		return (EXIT);
	pthread_join(data->death_monitor, NULL);
	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_join(data->philos_thread, NULL);
		i++;
	}
	//destroy_mutex(data, philos);
	return (SUCCESS);
}

void	destroy_mutex(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&philo->mut_die_t);
	// pthread_mutex_destroy(&data->philos->mut_write);
	pthread_mutex_destroy(&philo->mut_die_t);
}

