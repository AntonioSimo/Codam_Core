/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimone <asimone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:34:38 by asimone           #+#    #+#             */
/*   Updated: 2023/11/21 17:41:25 by asimone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	take_left_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_message(philo, TAKE_FORKS);
}

void	take_right_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_message(philo, TAKE_FORKS);
}

void	leave_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	meal_time(t_philo *philo, t_data *data)
{
	take_left_fork(philo);
	take_right_fork(philo);
	pthread_mutex_lock(&philo->mut_eat_t);
	philo->last_eat_time = get_current_time();
	pthread_mutex_unlock(&philo->mut_eat_t);
	print_message(philo, EAT);
	ft_usleep(data->time_to_eat);
	leave_forks(philo);
	pthread_mutex_lock(&philo->mut_fully_eat);
	philo->nb_meals_had++;
	pthread_mutex_unlock(&philo->mut_fully_eat);
}
