/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimone <asimone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:17:00 by asimone           #+#    #+#             */
/*   Updated: 2023/11/29 19:26:44 by asimone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	*helper_check(t_philo *philo, t_data *data, int i)
{
	int	delta_time;
	
	pthread_mutex_lock(&philo[i].mut_eat_t);
	delta_time = get_current_time() - philo[i].last_eat_time;
	pthread_mutex_unlock(&philo[i].mut_eat_t);
	if (delta_time >= data->time_to_die)
	{
		die_time(&philo[i], data);
		return (NULL);
	}
	return (NULL);
}

void	*check_monitor(void *args)
{
	t_data	*data;
	t_philo	*philo;
	int		philo_fully_ate;
	int		max_meals;
	int		i;
	int		n_meals;

	data = (t_data *)args;
	philo_fully_ate = 0;
	max_meals = data->nb_meals;
	philo = data->philos;
	while (1)
	{
		i = 0;
		philo_fully_ate = 0;
		while (i < data->num_of_philos)
		{
			pthread_mutex_lock(&philo[i].mut_fully_eat);
			n_meals = philo[i].nb_meals_had;
			pthread_mutex_unlock(&philo[i].mut_fully_eat);
			if (data->nb_meals && n_meals == max_meals)
				philo_fully_ate++;
			else
				helper_check(philo, data, i);
			i++;
		}
		if (philo_fully_ate == data->num_of_philos)
			return (NULL);
	}
	return (NULL);
}
