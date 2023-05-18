/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 15:32:27 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/18 11:48:58 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandelbrot(mlx_t *mlx, mlx_image_t *image)
{
	mlx_image_to_window(mlx, image, 0, 100);
	ft_printf("This is Mandelbrot");
}