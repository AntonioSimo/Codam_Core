/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 15:32:27 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/31 16:13:17 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_image *img, int iter)
{
	double	xtemp;

	while (img->y < img->image->height)
	{
		img->x = 0;
		while (img->x < img->image->width)
		{
			img->zx = 0.0;
			img->zy = 0.0;
			img->cx = change_imaginary_image_x(img, img->x);
			img->cy = change_imaginary_image_y(img, img->y);
			iter = 0;
			while (img->zx * img->zx + img->zy * img->zy < 4 && iter < MAX_ITER)
			{
				xtemp = img->zx * img->zx - img->zy * img->zy + img->cx;
				img->zy = 2 * img->zx * img->zy + img->cy;
				img->zx = xtemp;
				iter++;
			}
			color_mandelbrot(img, iter);
			mlx_put_pixel(img->image, img->x, img->y, img->color);
			img->x++;
		}
		img->y++;
	}
}

void	draw_mandelbrot(t_image *image)
{
	int	iter;

	iter = 0;
	image->y = 0;
	image->z_max_x = 2;
	image->z_max_y = 2.5;
	mandelbrot(image, iter);
}
