/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimone <asimone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:34:49 by asimone           #+#    #+#             */
/*   Updated: 2023/11/21 17:45:33 by asimone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	think_time(t_philo *philo)
{
	print_message(philo, YELLOW, THINK);
	usleep(500);
}
