/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimone <asimone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:34:46 by asimone           #+#    #+#             */
/*   Updated: 2023/12/13 16:50:48 by asimone          ###   ########.fr       */
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
		usleep(1000);
	while (check_check(philo) != 1)
	{
		meal_time(philo, data);
		if (philo->nb_meals_had == data->nb_meals)
			break ;
		rest_time(philo, data);
		think_time(philo);
	}
	return (NULL);
}

int	check_check(t_philo *philo)
{
	int	check;

	check = 0;
	pthread_mutex_lock(philo->mut_die_t);
	if (philo->death == 1)
		check = 1;
	pthread_mutex_unlock(philo->mut_die_t);
	return (check);
}

int	philo_thread(t_data *data)
{
	int		i;
	t_philo	*philos;

	philos = (t_philo *)data->philos;
	i = 0;
	data->start_time = get_current_time();
	while (i < data->num_of_philos)
	{
		if (pthread_create(&philos[i].philos_thread, NULL, routine, \
				&philos[i]) != 0)
			return (EXIT);
		i++;
	}
	if (pthread_create(&data->death_monitor, NULL, check_monitor, data) != 0)
		return (EXIT);
	if (join_thread(data, philos) != 0)
		return (EXIT);
	return (SUCCESS);
}

int	join_thread(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		if (pthread_join(data->philos[i].philos_thread, NULL) != 0)
			return (EXIT);
		i++;
	}
	if (pthread_join(data->death_monitor, NULL) != 0)// || philo->death == 1)
		return (EXIT);
	destroy_mutex(data, philo);
	ft_free_philo(data);
	return (SUCCESS);
}
