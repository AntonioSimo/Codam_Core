/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimone <asimone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:34:52 by asimone           #+#    #+#             */
/*   Updated: 2023/12/13 16:07:00 by asimone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	neg;
	int	result;

	i = 0;
	result = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (neg < 0)
		return (result * neg);
	return (result);
}

void	ft_usleep(long long sleep_time)
{
	long long	start_time;

	start_time = get_current_time();
	while ((get_current_time() - start_time) < sleep_time)
		usleep(300);
}

long long	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (write(2, GET_TIME_ERROR, 26));
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	print_message(t_philo *philo, char *state)
{
	pthread_mutex_lock(&philo->data->mut_write);
	pthread_mutex_lock(philo->mut_die_t);
	if (philo->death)
	{
		pthread_mutex_unlock(philo->mut_die_t);
		pthread_mutex_unlock(&philo->data->mut_write);
		return ;
	}
	printf("%lld %d %s\n", get_current_time() - philo->data->start_time, \
			philo->id, state);
	pthread_mutex_unlock(philo->mut_die_t);
	pthread_mutex_unlock(&philo->data->mut_write);
}
