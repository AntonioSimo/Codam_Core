/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimone <asimone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:34:52 by asimone           #+#    #+#             */
/*   Updated: 2023/11/14 15:52:03 by asimone          ###   ########.fr       */
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
	while (str[i] >= 9 && str[i] <= 13 || str[i] == ' ')
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

	start_time = get_current_time(0);
	while ((get_current_time(0) - start_time) < sleep_time)
		usleep(200);
}

long long	get_current_time(long long start_time)
{
	struct timeval	time;
	long long		current_time;

	if (gettimeofday(&time, NULL) == -1)
		return (write(2, GET_TIME_ERROR, 26));
	current_time = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (current_time - start_time);
}

void	print_message(t_data *data, char *color, int id, char *state)
{
	pthread_mutex_lock(&data->mut_write);
	data->time_to_print = get_current_time(data->start_time);
	printf("%s%lld %d %s\n", color, data->time_to_print, id, state);
	pthread_mutex_unlock(&data->mut_write);
}
