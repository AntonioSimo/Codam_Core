/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/18 13:16:50 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/24 19:54:26 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int    julia_or_mandelbrot(char *which_fractal)

{
	if (ft_strncmp("Julia", which_fractal, 5) == 0)
		return (1);
	else if (ft_strncmp("Mandelbrot", which_fractal, 10) == 0)
		return (0);
	else
	{
		ft_printf(RED BOLD \
		"Write: './fractol Julia' or './fractol Mandelbrot'\n" RESET);
		exit(EXIT_FAILURE);
	}
	return (0);
}
