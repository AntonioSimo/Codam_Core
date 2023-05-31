/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/09 11:29:19 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/31 17:23:00 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_error()
{
	ft_printf(RED BOLD "Sorry, wrong info to run the program.\n");
	ft_printf("Please type or './fractol Julia <1> or <2> or <3> or \n");
	ft_printf("Please type './fractol Mandelbrot <color>'\n" RESET);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	mlx_t		*mlx;
	t_image		image;

	if (check_parmeters(argc, argv) == false)
		print_error();
	mlx = mlx_init(WIDTH, HEIGHT, "FRACT-OL", true);
	if (!mlx)
		return (EXIT_FAILURE);
	image.image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!image.image)
	{
		mlx_terminate(mlx);
		return (EXIT_FAILURE);
	}
	image.mlx = mlx;
	config_pre_draw(&image, argc, argv);
	ft_scroll_hook(0, 0, &image);
	mlx_scroll_hook(mlx, &ft_scroll_hook, &image);
	if (mlx_image_to_window(mlx, image.image, 0, 0) < 0)
		exit (EXIT_FAILURE);
	mlx_key_hook(mlx, &ft_hook, &image);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
