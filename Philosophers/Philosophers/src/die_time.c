/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimone <asimone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:34:28 by asimone           #+#    #+#             */
/*   Updated: 2023/11/29 17:35:03 by asimone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	die_time(t_philo *philo, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_of_philos)
	{
		pthread_mutex_lock(data->philos[i].mut_die_t);
		data->philos[i].death = 1;
		pthread_mutex_unlock(data->philos[i].mut_die_t);
	}
	usleep(500);
	printf("%s%lld %d %s\n", RED, get_current_time() - philo->start_time, \
				philo->id, DIED);
}
