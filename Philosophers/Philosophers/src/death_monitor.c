/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimone <asimone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:17:00 by asimone           #+#    #+#             */
/*   Updated: 2023/11/21 17:25:54 by asimone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void		*check_monitor(void *args)
{
	t_data *data;

	data = (t_data *)args;
	t_philo	*philo;
	int	i;
	int delta_time;
	int n_meals;
	int philo_fully_ate = 0;
	int max_meals = data->nb_meals;
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
			if (n_meals == max_meals)
				philo_fully_ate++;
			else
			{
				pthread_mutex_lock(&philo[i].mut_eat_t);
				delta_time = get_current_time() - philo[i].last_eat_time;
				pthread_mutex_unlock(&philo[i].mut_eat_t);
				if (delta_time >= data->time_to_die)
				{
					die_time(&philo[i], data);
					return (NULL);
				}
			}
			i++;
		}
		if (philo_fully_ate == data->num_of_philos)
			return (NULL);
	}
	return (NULL);
}
