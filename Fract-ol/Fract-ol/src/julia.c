/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/18 10:44:55 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/31 16:13:09 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	julia(t_image *img, t_complex c, int i)
{
	while (img->y < img->image->height)
	{
		img->x = 0;
		while (img->x < img->image->width)
		{
			img->cx = change_imaginary_image_x(img, img->x);
			img->cy = change_imaginary_image_y(img, img->y);
			i = 0;
			img->z.x = img->cx;
			img->z.y = img->cy;
			while (img->z.x * img->z.x + img->z.y * img->z.y <= 4.0 && i < 300)
			{
				img->x_temp = img->z.x * img->z.x - img->z.y * img->z.y + c.x;
				img->y_temp = 2 * img->z.x * img->z.y + c.y;
				img->z.x = img->x_temp;
				img->z.y = img->y_temp;
				i++;
			}
			color_julia(img, i);
			img->x++;
		}
		img->y++;
	}
}

void	draw_julia(t_image *image)
{
	int			iter;

	iter = 0;
	image->y = 0;
	image->z_max_x = 2;
	image->z_max_y = 2.5;
	julia(image, image->input_julia, iter);
}
