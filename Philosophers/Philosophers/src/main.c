/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimone <asimone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:34:35 by asimone           #+#    #+#             */
/*   Updated: 2023/11/14 13:37:32 by asimone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_input(argc, argv) != 0)
		return (write(2, ERROR, 13));
	if (philosophers(argc, argv, &data) != 0)
		return (write(2, ERROR, 13));
	// destroy_mutex(&data);
	return (SUCCESS);
}
