/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/18 13:30:58 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/31 15:23:38 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

double	change_imaginary_image_x(t_image *image, uint32_t x_coordinate)
{
	double	interval;
	double	coordinate;

	interval = image->z_max_x / image->image->width;
	image->move_x = image->zoom;
	coordinate = image->zoom * interval * (double)x_coordinate - image->move_x;
	return (coordinate);
}

double	change_imaginary_image_y(t_image *image, uint32_t y_coordinate)
{
	double	interval;
	double	coordinate;

	interval = image->z_max_x / image->image->height;
	image->move_y = image->zoom;
	coordinate = image->zoom * interval * (double)y_coordinate - image->move_y;
	return (coordinate);
}
