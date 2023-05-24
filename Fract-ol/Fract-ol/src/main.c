/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/09 11:29:19 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/24 19:59:29 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int32_t main(int argc, char **argv)
{
    mlx_t	*mlx;
    image_t	fractol;

    if (argc == 2)
    {
        mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
        fractol.image = mlx_new_image(mlx, WIDTH, HEIGHT);
        fractol.julia_or_mandelbrot = julia_or_mandelbrot(argv[1]);
        fractol.image->width = WIDTH;
        fractol.image->height = HEIGHT;
        fractol.zoom = 10;
        fractol.z_max_y = -2;
        fractol.z_max_x = 2;
        fractol.mlx = mlx;
        if (!mlx)
            exit(EXIT_FAILURE);
        ft_memset(fractol.image->pixels, 255, fractol.image->width * fractol.image->height * BPP);
        if (fractol.julia_or_mandelbrot == 0)
            mandelbrot(&fractol);
        else
            julia(&fractol);
        mlx_scroll_hook(mlx, &my_scrollhook, &fractol);
        mlx_image_to_window(mlx, fractol.image, 0, 0);
        mlx_key_hook(mlx, &ft_hooks, mlx);
        mlx_loop(mlx);
        mlx_terminate(mlx);
    }
    else
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

//int	main(int argc, char **argv)
//{
//	mlx_t		*mlx;
//	mlx_image_t	*image;
	
//	if (ft_init(argc, argv[1]) == 1)
//	{
//		mlx = mlx_init(WIDTH_WINDOW, HEIGHT_WINDOW, "Julia", true);
//		if (!mlx)
//			exit(EXIT_FAILURE);
//		image = mlx_new_image(mlx, WIDTH_WINDOW, HEIGHT_WINDOW);
//		ft_memset(image->pixels, 255, image->width * image->height * BPP);
//		mlx_key_hook(mlx, &ft_hooks, mlx);
//		ft_julia(mlx, image);
//	}
//	else
//	{
//		mlx = mlx_init(WIDTH_WINDOW, HEIGHT_WINDOW, "Mandelbrot", true);
//		if (!mlx)
//			exit(EXIT_FAILURE);
//		image = mlx_new_image(mlx, WIDTH_WINDOW, HEIGHT_WINDOW);
//		ft_memset(image->pixels, 255, image->width * image->height * BPP);
//		mlx_key_hook(mlx, &ft_hooks, mlx);
//		ft_mandelbrot(mlx, image);
//	}
//	mlx_loop(mlx);
//	mlx_terminate(mlx);
//}