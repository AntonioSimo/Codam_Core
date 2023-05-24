/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 15:32:27 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/24 19:56:05 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void mandelbrot(image_t *fractol)
{
    int iteration;
    double xtemp;

    fractol->x = 0;
    while (((uint32_t) fractol->x) < fractol->image->width)
    {
        fractol->y = 0;
        while (((uint32_t) fractol->y) < fractol->image->height)
        {
            double zx = 0.0;
            double zy = 0.0;
            double cx = change_imaginary_image_x(fractol, fractol->x);
            double cy = change_imaginary_image_y(fractol, fractol->y);
            iteration = 0;
            while (zx * zx + zy * zy < 4 && iteration < MAX_ITER)
            {
                xtemp = zx * zx - zy * zy + cx;
                zy = 2 * zx * zy + cy;
                zx = xtemp;
                iteration++;
            }
            double brightness = log2(1.75 + iteration - log2(sqrt(zx * zx + zy * zy))) / log2(100);
            int r = (int)(brightness * 100/ iteration * 20);
            int g = (int)(brightness );
            int b = (int)(brightness * 10 / iteration * 25);
            int a = 255;
            uint32_t color = ft_pixel(r, g, b, a);
            mlx_put_pixel(fractol->image, fractol->x, fractol->y, color);
            fractol->y++;
        }
        fractol->x++;
    }
}