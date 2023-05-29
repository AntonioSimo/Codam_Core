/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/18 10:49:15 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/29 19:04:52 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	ft_pixel(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	color_mandelbrot(t_image *image, int iter)
{
	t_color	color;

	color.brightness = log2(1.75 + iter - log(log2(sqrt(image->zx * image->zx + image->zy * image->zy)))) / log2(100);
	color.r = (int)(color.brightness * 100 / iter * 20);
	color.g = (int)(color.brightness);
	color.b = (int)(color.brightness * 10 / iter * 25);
	color.a = 255;
	image->color = ft_pixel(color.r, color.g, color.b, color.a);
}