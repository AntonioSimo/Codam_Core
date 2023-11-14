/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimone <asimone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:34:46 by asimone           #+#    #+#             */
/*   Updated: 2023/11/14 19:46:55 by asimone          ###   ########.fr       */
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
		usleep(450);
	while (death_check(philo, data) == 0)
	{
		meal_time(philo, data);
		if (philo->nb_meals_had == data->nb_meals)
			break;
		rest_time(philo, data);
		think_time(philo, data);
	}
}

int	philo_thread(t_data *data)
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = (t_philo *)data->philos;
	data->start_time = get_current_time(0);
	while (i < data->num_of_philos)
	{
		if (pthread_create(&data->philos_thread, NULL, routine, &philos[i]) != 0)
			return (EXIT);
		i++;
	}
	i = 0;
	//usleep(600);
	// if (pthread_create(&data->death_monitor, NULL, death_monitor, &data) != 0)
	//   	return (EXIT);
	while (i < data->num_of_philos)
	{
		pthread_join(data->philos_thread, NULL);
		i++;
	}
	//destroy_mutex(data);
	return (SUCCESS);
}

//void	destroy_mutex(t_data *data)
//{
// 	int	i;

// 	i = 0;
// 	while (i < data->num_of_philos)
// 	{
// 		pthread_mutex_destroy(&data->forks[i]);
// 		i++;
// 	}
// 	pthread_mutex_destroy(&data->mut_eat_t);
// 	pthread_mutex_destroy(&data->mut_write);
//	pthread_mutex_destroy(&data->mut_die_t);
//}

