/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimone <asimone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:34:35 by asimone           #+#    #+#             */
/*   Updated: 2023/12/13 16:44:24 by asimone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_free_philo(t_data *data)
{
	if (data->philos)
		free(data->philos);
	if (data->forks)
		free(data->forks);
}

void	destroy_mutex(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&philo[i].mut_eat_t);
		pthread_mutex_destroy(&philo[i].mut_fully_eat);
		i++;
	}
	pthread_mutex_destroy(&data->mut_die_t);
	pthread_mutex_destroy(&data->mut_write);
}

int	ft_handle_one_philo(t_data *data)
{
	printf(CYAN "0 1 has taken a fork\n" RESET);
	ft_usleep(data->time_to_die);
	printf(RED "%lld 1 died\n" RESET, data->time_to_die);
	ft_free_philo(data);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_input(argc, argv) != 0)
		return (write(2, ERROR, 12));
	if (philosophers(argc, argv, &data) != 0)
		return (write(2, ERROR, 12));
	return (SUCCESS);
}
