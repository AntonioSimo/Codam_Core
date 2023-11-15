/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimone <asimone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:17:00 by asimone           #+#    #+#             */
/*   Updated: 2023/11/15 19:19:00 by asimone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*death_monitor(void *args)
{
	t_data	*data;
	t_philo *philo;
	int	i;

	i = 0;
	data = (t_data *)args;
	pthread_mutex_lock(&philo->mut_die_t);
	while (i < data->num_of_philos && philo->state != DEAD)
	{
		if ((get_current_time() - philo->last_eat_time) >= data->time_to_die)
		{
			pthread_mutex_unlock(&philo->mut_die_t);
			die_time(philo, data);
			break;
		}
		usleep(150);
		i++;
	}
	pthread_mutex_unlock(&philo->mut_die_t);
}

// int	death_check(t_philo *philo, t_data *data)
// {


// 	return (SUCCESS);
// }