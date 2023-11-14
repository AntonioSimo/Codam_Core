/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimone <asimone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:34:49 by asimone           #+#    #+#             */
/*   Updated: 2023/11/14 16:01:45 by asimone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	think_time(t_philo *philo, t_data *data)
{
	philo->state = THINKING;
	print_message(data, YELLOW, philo->id, THINK);
}
