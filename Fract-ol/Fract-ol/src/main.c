/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/09 11:29:19 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/29 19:14:43 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	mlx_t	*mlx;
	t_image	image;

	(void) argc;
	(void) argv;
	mlx = mlx_init(WIDTH, HEIGHT, "Fract-ol", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	image.image = mlx_new_image(mlx, WIDTH, HEIGHT);
	check_parmeters(mlx, &image, argc, argv);
	ft_memset(image.image->pixels, 255, image.image->width * image.image->height * sizeof(int32_t));
	if (image.julia_or_mandelbrot == 0)
		draw_mandelbrot(&image);
	mlx_scroll_hook(mlx, &ft_scroll_hook, &image);
	mlx_mouse_hook(mlx, &ft_mouse_hook, &image);
	mlx_image_to_window(mlx, image.image, 0, 0);
	mlx_key_hook(mlx, &ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
