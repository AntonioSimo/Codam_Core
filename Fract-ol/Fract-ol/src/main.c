/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/09 11:29:19 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/18 13:58:25 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	
	if (ft_init(argc, argv[1]) == 1)
	{
		mlx = mlx_init(WIDTH_WINDOW, HEIGHT_WINDOW, "Julia", true);
		if (!mlx)
			exit(EXIT_FAILURE);
		image = mlx_new_image(mlx, WIDTH_WINDOW, HEIGHT_WINDOW);
		ft_memset(image->pixels, 255, image->width * image->height * BPP);
		mlx_key_hook(mlx, &ft_hooks, mlx);
		ft_julia(mlx, image);
	}
	else
	{
		mlx = mlx_init(WIDTH_WINDOW, HEIGHT_WINDOW, "Mandelbrot", true);
		if (!mlx)
			exit(EXIT_FAILURE);
		image = mlx_new_image(mlx, WIDTH_WINDOW, HEIGHT_WINDOW);
		ft_memset(image->pixels, 255, image->width * image->height * BPP);
		mlx_key_hook(mlx, &ft_hooks, mlx);
		ft_mandelbrot(mlx, image);
	}
	mlx_loop(mlx);
	mlx_terminate(mlx);
}