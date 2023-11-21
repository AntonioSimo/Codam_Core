/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimone <asimone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:17:00 by asimone           #+#    #+#             */
/*   Updated: 2023/11/21 14:33:34 by asimone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// int		death_monitor(t_data *data)
// {
// 	t_philo	*philo;
// 	int	i;

// 	philo = data->philos;
// 	// while (1)
// 	// {
// 		i = 0;
// 		while (i < data->num_of_philos)
// 		{
// 			// pthread_mutex_lock(&data->mut_die_t);
// 			pthread_mutex_lock(&philo[i].mut_eat_t);
// 			if ((get_current_time() - philo[i].last_eat_time) >= data->time_to_die)
// 			{
// 				die_time(&philo[i], data);
// 				// pthread_mutex_unlock(&data->mut_die_t);
// 				pthread_mutex_unlock(&philo[i].mut_eat_t);
// 				return (1);
// 			}
// 			// pthread_mutex_unlock(&data[i]mut_die_t);
// 			pthread_mutex_unlock(&philo[i].mut_eat_t);
// 			i++;
// 		}
// 	// }
// 	return (0);
// }

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

// void	test(t_philo *philo, t_data *data)
// {
// 	long long test1 = 0;
// 	long long test2 = 0;
// 	long long test3 = 0;
// 	long long test4 = 0;
// 	long long time = get_current_time();

// 	test1 = time - data->start_time;
// 	test2 = time - philo->last_eat_time;
// 	test3 = time;
// 	test4 = data->time_to_die;
// 	printf("test1: %llu\n", test1);
// 	printf("test2: %llu\n", test2);
// 	printf("test3: %llu\n", test3);
// 	printf("test4: %llu\n", test4);
// }