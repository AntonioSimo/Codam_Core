/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/18 10:49:15 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/31 17:21:35 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

uint32_t	ft_pixel(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	color_mandelbrot(t_image *image, int iter)
{
	t_color	color;

	color.shape = log2(1.75 + iter - log2(log2(sqrt(image->zx * image->zx
						+ image->zy * image->zy))));
	if (!image->color_s.new_r || !image->color_s.new_g || !image->color_s.new_b)
	{
		color.r = (int)(color.shape * 100 / iter * 20);
		color.g = (int)(color.shape);
		color.b = (int)(color.shape * 10 / iter * 25);
	}
	else
	{
		color.r = (int)(color.shape * image->color_s.new_r / iter * 50);
		color.g = (int)(color.shape * image->color_s.new_g / iter * 50);
		color.b = (int)(color.shape * image->color_s.new_b / iter * 50);
	}
	color.a = 255;
	image->color = ft_pixel(color.r, color.g, color.b, color.a);
}

void	color_julia(t_image *image, int iter)
{
	image->color = 0xFFFFFF * sin(iter);
	mlx_put_pixel(image->image, image->x, image->y, image->color);
}
