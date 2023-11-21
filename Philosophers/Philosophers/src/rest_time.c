/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rest_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimone <asimone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:34:43 by asimone           #+#    #+#             */
/*   Updated: 2023/11/15 17:39:49 by asimone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	rest_time(t_philo *philo, t_data *data)
{
	//philo->state = SLEEPING;
	print_message(data, PURPLE, philo->id, SLEEP);
	ft_usleep(data->time_to_sleep);
}
