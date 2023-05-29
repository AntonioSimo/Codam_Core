/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/18 13:16:50 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/29 17:46:30 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_or_mandelbrot(char *fractal, t_image *image)
{
	if (ft_strncmp("Julia", fractal, 5) == 0)
	{
		image->z_max_x = 2;
		image->z_max_y = 2;
		image->zoom = 0.7;
		return (1);
	}
	else if (ft_strncmp("Mandelbrot", fractal, 11) == 0)
	{
		image->z_max_x = 2;
		image->z_max_y = 2;
		image->zoom = 10;
		return (0);
	}
	else
	{
		ft_printf(RED BOLD "Error. Please type:\n");
		ft_printf("'./fractol Mandelbrot' or './fractol Julia'\n" RESET);
		exit(EXIT_FAILURE);
		return (0);
	}
}

void	check_parmeters(mlx_t *mlx, t_image *image, int argc, char **argv)
{
	if (argc == 2)
	{
		image->julia_or_mandelbrot = julia_or_mandelbrot(argv[1], image);
		image->image->width = mlx->width;
		image->image->height = mlx->height;
		image->mlx = mlx;
	}
	else
	{
		ft_printf(RED BOLD "Error. Please type: './fractol + fractol name'\n" RESET);
		exit(EXIT_FAILURE);
	}
}
