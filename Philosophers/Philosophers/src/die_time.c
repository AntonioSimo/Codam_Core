/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimone <asimone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:34:28 by asimone           #+#    #+#             */
/*   Updated: 2023/11/21 12:29:22 by asimone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	die_time(t_philo *philo, t_data *data)
{
	print_message(data, RED, philo->id, DIED);
	int i = 0;
	while (i < data->num_of_philos)
	{
		pthread_mutex_lock(data->philos[i].mut_die_t);
		data->philos[i].death = 1;
		pthread_mutex_unlock(data->philos[i].mut_die_t);
		i++;
	}
	// ft_usleep(data->time_to_die);
}