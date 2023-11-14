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
	int	i;

	i = 0;
	pthread_mutex_lock(philo->mut_die_t);
	while (i < data->num_of_philos && philo->state != DEAD)
	{
		if ((data->time_to_print - philo->last_eat_time) >= data->time_to_die)
		{
			printf("time_to_print: %llu\t", data->time_to_print);
			printf("last_eat_time: %llu\t", philo->last_eat_time);
			printf("time_to_die: %llu\n", data->time_to_die);
			die_time(philo, data);
			printf("id: %i\t", philo->id);
			printf("state: %i\n", philo->state);
			pthread_mutex_unlock(philo->mut_die_t);
			return (EXIT);
		}
		usleep(150);
		i++;
	}
	pthread_mutex_unlock(philo->mut_die_t);
	return (SUCCESS);
}