/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/18 13:30:58 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/29 19:06:40 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	change_imaginary_image_x(t_image *image, uint32_t x_coordinate)
{
	double	interval;
	double	coordinate;

	image->move_x = image->zoom;
	interval = image->zoom * image->z_max_x / image->image->width;
	coordinate = interval * (double)x_coordinate - image->move_x;
	return (coordinate);
}

double	change_imaginary_image_y(t_image *image, uint32_t y_coordinate)
{
	double	interval;
	double	coordinate;

	image->move_y = image->move_x * 3 / 4;
	interval = image->zoom * image->z_max_y / image->image->height;
	coordinate = interval * (double)y_coordinate - image->move_y;
	return (coordinate);
}