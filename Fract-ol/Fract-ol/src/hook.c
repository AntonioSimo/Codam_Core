/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/18 13:30:10 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/24 19:55:36 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_hooks(struct mlx_key_data key_data, void* param)
{
	mlx_t	*mlx;

	mlx = param;
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_RELEASE)
		mlx_close_window(mlx);
}

void my_scrollhook(double xdelta, double ydelta, void *param)
{
    image_t *fractol = param;

    (void)xdelta;
    if (ydelta < 0)
        fractol->zoom *= 1.1;
    else
        fractol->zoom *= 0.9;
    if (fractol->julia_or_mandelbrot == 0)
        mandelbrot(fractol);
    else
        julia(fractol);
    mlx_image_to_window(fractol->mlx, fractol->image, 0, 0);
}