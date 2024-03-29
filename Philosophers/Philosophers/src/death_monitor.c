/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimone <asimone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:17:00 by asimone           #+#    #+#             */
/*   Updated: 2023/12/13 16:41:38 by asimone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	helper_check(t_philo *philo, t_data *data, int max_meals, int i)
{
	int		n_meals;

	pthread_mutex_lock(&philo[i].mut_fully_eat);
	n_meals = philo[i].nb_meals_had;
	pthread_mutex_unlock(&philo[i].mut_fully_eat);
	if (data->nb_meals && n_meals == max_meals)
		data->philo_fully_ate++;
	pthread_mutex_lock(&philo[i].mut_eat_t);
	if (get_current_time() - philo[i].last_eat_time >= data->time_to_die)
	{
		pthread_mutex_unlock(&philo[i].mut_eat_t);
		die_time(&philo[i], data);
		return (EXIT);
	}
	pthread_mutex_unlock(&philo[i].mut_eat_t);
	return (SUCCESS);
}

void	*check_monitor(void *args)
{
	t_data	*data;
	t_philo	*philo;
	int		max_meals;
	int		i;

	data = (t_data *)args;
	data->philo_fully_ate = 0;
	max_meals = data->nb_meals;
	philo = data->philos;
	while (1)
	{
		i = 0;
		data->philo_fully_ate = 0;
		while (i < data->num_of_philos)
		{
			if (helper_check(philo, data, max_meals, i) != 0)
				return (NULL);
			i++;
		}
		if (data->philo_fully_ate == data->num_of_philos)
			return (NULL);
	}
	return (NULL);
}
