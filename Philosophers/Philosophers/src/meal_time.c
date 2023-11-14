/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimone <asimone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:34:38 by asimone           #+#    #+#             */
/*   Updated: 2023/11/14 19:16:35 by asimone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	take_left_fork(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(philo->left_fork);
	print_message(data, CYAN, philo->id, TAKE_FORKS);
}

void	take_right_fork(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(philo->right_fork);
	print_message(data, CYAN, philo->id, TAKE_FORKS);
}

void	leave_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	meal_time(t_philo *philo, t_data *data)
{
	take_left_fork(philo, data);
	take_right_fork(philo, data);
	pthread_mutex_lock(philo->mut_eat_t);
	philo->last_eat_time = data->time_to_print;
	philo->state = EATING;
	print_message(data, GREEN, philo->id, EAT);
	philo->nb_meals_had++;
	pthread_mutex_unlock(philo->mut_eat_t);
	ft_usleep(data->time_to_eat);
	leave_forks(philo);
}
