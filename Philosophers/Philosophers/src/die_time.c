/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimone <asimone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:34:28 by asimone           #+#    #+#             */
/*   Updated: 2023/12/13 16:44:05 by asimone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	die_time(t_philo *philo, t_data *data)
{
	int			i;

	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_mutex_lock(data->philos[i].mut_die_t);
		data->philos[i].death = 1;
		pthread_mutex_unlock(data->philos[i].mut_die_t);
		i++;
	}
	printf("%s%lld %d %s\n", RED, get_current_time() - philo->data->start_time, \
				philo->id, DIED);
}
