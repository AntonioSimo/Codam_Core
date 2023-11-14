/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimone <asimone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:17:00 by asimone           #+#    #+#             */
/*   Updated: 2023/11/14 19:46:10 by asimone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// void	*death_monitor(void *args)
// {
// 	t_data	*data;

// 	data = (t_data *)args;
// 	while (data->philos->state != DEAD)
// }

int	death_check(t_philo *philo, t_data *data)
{
	int i = 0;
	pthread_mutex_lock(&data->mut_die_t);
	while (philo->state != DEAD)
	{
		//pthread_mutex_unlock(&data->mut_die_t);
		if (philo->last_eat_time >= (data->time_to_die - data->time_to_print))
		{
			pthread_mutex_unlock(&data->mut_die_t);
			die_time(philo, data);
			return (1);
		}
		i++;
	}
	pthread_mutex_unlock(&data->mut_die_t);
	return (0);
}