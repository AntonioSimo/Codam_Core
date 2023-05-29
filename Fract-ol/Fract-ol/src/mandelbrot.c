/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 15:32:27 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/29 19:04:48 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_image *image, int iter)
{
	double	xtemp;

	while (image->y < image->image->height)
	{
		image->x = 0;
		while (image->x < image->image->width)
		{
			image->zx = 0.0;
			image->zy = 0.0;
			image->cx = change_imaginary_image_x(image, image->x);
			image->cy = change_imaginary_image_y(image, image->y);
			iter = 0;
			while (image->zx * image->zx + image->zy * image->zy < 4 && iter < MAX_ITER)
			{
				xtemp = image->zx * image->zx - image->zy * image->zy + image->cx;
				image->zy = 2 * image->zx * image->zy + image->cy;
				image->zx = xtemp;
				iter++;
			}
			color_mandelbrot(image, iter);
			mlx_put_pixel(image->image, image->x, image->y, image->color);
			image->x++;
		}
		image->y++;
	}
}

void	draw_mandelbrot(t_image *image)
{
	int	iter;

	iter = 0;
	image->y = 0;
	mandelbrot(image, iter);
}
