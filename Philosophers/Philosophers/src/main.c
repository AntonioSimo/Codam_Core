/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimone <asimone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:34:35 by asimone           #+#    #+#             */
/*   Updated: 2023/11/21 17:59:45 by asimone          ###   ########.fr       */
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

int	ft_handle_one_philo(t_data *data)
{
	printf(CYAN "0 1 has taken a fork\n" RESET);
	ft_usleep(data->time_to_die);
	printf(RED "0 1 died\n" RESET);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_input(argc, argv) != 0)
		return (write(2, ERROR, 12));
	if (philosophers(argc, argv, &data) != 0)
		return (write(2, ERROR, 12));
	ft_free_philo(&data);
	return (SUCCESS);
}
