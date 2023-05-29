/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/18 13:30:10 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/29 19:13:51 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_hook(struct mlx_key_data key_data, void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_RELEASE)
		mlx_close_window(mlx);
}

void	ft_scroll_hook(double move_x, double move_y, void *param)
{
	t_image	*image;

	image = (t_image *)param;
	(void) move_x;
	if (move_y < 0)
	{
		mlx_get_mouse_pos(image->mlx, &image->mouse_x, &image->mouse_y);
		printf("%d\t%d\n", image->mouse_x, image->mouse_y);
		image->z_max_x = image->z_max_x * image->mouse_x / (image->mlx->width / 2);
		image->z_max_y = image->z_max_y * image->mouse_y / (image->mlx->height / 2);
		image->zoom *= 1.1;
	}
	else
	{
		mlx_get_mouse_pos(image->mlx, &image->mouse_x, &image->mouse_y);
		image->z_max_x = image->z_max_x * image->mouse_x / (image->mlx->width / 2);
		image->z_max_y = image->z_max_y * image->mouse_y / (image->mlx->height / 2);
		image->zoom *= 0.9;
	}
	if (image->julia_or_mandelbrot == 0) 
		draw_mandelbrot(image);
	//else
	//	draw_julia(image);
	mlx_image_to_window(image->mlx, image->image, 0, 0);
}

void	ft_mouse_hook(mouse_key_t button, action_t action, modifier_key_t mods, void *param)
{
	(void) button;
	(void) action;
	(void) mods;
	t_image	*image;
	
	image = param;
	if (MLX_PRESS == 1)
	{
		mlx_get_mouse_pos(image->mlx, &image->mouse_x, &image->mouse_y);
		image->z_max_x *= 1.1;
		image->z_max_y *= 1.1;
	}
	if (image->julia_or_mandelbrot == 0)
		draw_mandelbrot(image);
	//else
	//	julia(image);
	//mlx_image_to_window(img->mlx, img->image, 0, 0);
}
