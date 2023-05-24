/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/18 13:30:58 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/24 19:56:14 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double change_imaginary_image_x(image_t *immagine, uint32_t x_coordinate)
{
    double interval;
    double coordinate;

    immagine->moveX = immagine->zoom;
    interval = immagine->zoom * (immagine->z_max_x - immagine->zx) / immagine->image->width;
    coordinate = immagine->zx + interval * (double)x_coordinate - immagine->moveX;
    return (coordinate);
}

double change_imaginary_image_y(image_t *immagine, uint32_t y_coordinate)
{
    double interval;
    double coordinate;

    immagine->moveY = immagine->moveX * 3 / 4;
    interval = immagine->zoom * (immagine->zy - immagine->z_max_y) / immagine->image->height;
    coordinate = immagine->zy + interval * (double)y_coordinate - immagine->moveY;
    return (coordinate);
}
