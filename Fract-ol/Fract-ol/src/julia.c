/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/18 10:44:55 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/24 19:58:38 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void julia(image_t *fractol) 
{
    double zx;
    double zy;
    complex_t z;
    int iter;
    complex_t c;
    //Complex_t c = {-0.7, 0.27015};
    //Complex_t c = {-0.8, 0.156};
    c = (complex_t){0.355, 0.355};
    //c.x = -0.7;
    //c.y = 0.27015;

    fractol->x = 0;
    while (fractol->x < HEIGHT) 
    {
        fractol->y = 0;
        while (fractol->y < WIDTH) 
        {
            double x = change_imaginary_image_x(fractol, fractol->x);
            double y = change_imaginary_image_y(fractol, fractol->y);
            iter = 0;
            z.x = x;
            z.y = y;
            while (iter < MAX_ITER)
            {
                zx = z.x * z.x - z.y * z.y + c.x;
                zy = 2 * z.x * z.y + c.y;
                z.x = zx;
                z.y = zy;
                if (z.x * z.x + z.y * z.y > 4.0)
                    break;
                iter++;
            }
            uint32_t    color = 0xFFFFFF / 101 * (iter + 1);
            mlx_put_pixel(fractol->image, fractol->y, fractol->x, color);
            fractol->y++;
        }
        fractol->x++;
    }
}
