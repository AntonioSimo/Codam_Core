/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/18 13:16:50 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/18 13:25:19 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_init(int argc, char *choose_fractal)
{
	if (argc == 2)
	{
		if (ft_strncmp("Julia", choose_fractal, 5) == 0)
			return (1);
		else if (ft_strncmp("Mandelbrot", choose_fractal, 10) == 0)
			return (0);
		else
		{
			ft_printf(RED BOLD \
			"Write: './fractol Julia' or './fractol Mandelbrot'\n" RESET);
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
