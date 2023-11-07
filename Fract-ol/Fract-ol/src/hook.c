/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/18 13:30:10 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/31 16:50:09 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_hook(struct mlx_key_data key_data, void *param)
{
	t_image	*image;

	image = param;
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_RELEASE)
		mlx_close_window(image->mlx);
}

void	ft_scroll_hook(double move_x, double move_y, void *param)
{
	t_image	*image;

	image = (t_image *)param;
	(void) move_x;
	if (move_y < 0)
		image->zoom *= 1.1;
	else if (move_y > 0)
		image->zoom *= 1 / 1.1;
	if (image->julia_or_mandelbrot == 0)
		draw_mandelbrot(image);
	else
		draw_julia(image);
	mlx_image_to_window(image->mlx, image->image, 0, 0);
}
