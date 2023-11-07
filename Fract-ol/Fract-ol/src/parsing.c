/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/18 13:16:50 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/31 19:29:50 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	julia_or_mandelbrot(char *fractal, t_image *image)
{
	if (ft_strncmp("Julia", fractal, 6) == 0)
	{
		image->zoom = 1;
		return (1);
	}
	else if (ft_strncmp("Mandelbrot", fractal, 11) == 0)
	{
		image->zoom = 4;
		return (0);
	}
	else
	{
		ft_printf(RED BOLD "Error. Please type:\n");
		ft_printf("'./fractol Mandelbrot' or './fractol Julia'\n" RESET);
		exit(EXIT_FAILURE);
	}
}

void	config_pre_draw(t_image *image, int argc, char **argv)
{
	image->julia_or_mandelbrot = julia_or_mandelbrot(argv[1], image);
	if (argc == 3)
	{
		if (image->julia_or_mandelbrot == 1)
			julia_set(image, argv[2]);
		else
			color_mandelbrot_choice(image, argv[2]);
	}
	else if (image->julia_or_mandelbrot == 1)
	{

	}
}

bool	check_parmeters(int argc, char **argv)
{
	if ((argc != 2) && (argc != 3))
		return (false);
	else if ((ft_strncmp("Julia", argv[1], 6) != 0) && \
		(ft_strncmp("Mandelbrot", argv[1], 11) != 0))
		return (false);
	if ((ft_strncmp("Julia", argv[1], 6) == 0) && (argc == 3))
	{
		if (((argv[2][0] != '1') && (argv[2][0] != '2') && \
		(argv[2][0] != '3')) || (argv[2][1] != '\0'))
			return (false);
	}
	else if ((ft_strncmp("Mandelbrot", argv[1], 11) == 0) && (argc == 3))
	{
		if ((ft_strncmp("GREEN", argv[2], 6) != 0) && \
		(ft_strncmp("BLUE", argv[2], 5) != 0) && \
		(ft_strncmp("ORANGE", argv[2], 7) != 0))
			return (false);
	}
	return (true);
}

void	julia_set(t_image *image, char *sec_arg)
{
	if (*sec_arg == '1')
	{
		image->input_julia.x = -0.7;
		image->input_julia.y = 0.27015;
	}
	else if (*sec_arg == '2')
	{
		image->input_julia.x = 0.355;
		image->input_julia.y = 0.355;
	}
	else if (*sec_arg == '3')
	{
		image->input_julia.x = 0.285;
		image->input_julia.y = 0.01;
	}
}

void	color_mandelbrot_choice(t_image *image, char *sec_arg)
{
	if (ft_strncmp("GREEN", sec_arg, 6) == 0)
	{
		image->color_s.new_r = 20;
		image->color_s.new_g = 100;
		image->color_s.new_b = 20;
	}
	else if (ft_strncmp("BLUE", sec_arg, 5) == 0)
	{
		image->color_s.new_r = 1;
		image->color_s.new_g = 1;
		image->color_s.new_b = 100;
	}
	else if (ft_strncmp("ORANGE", sec_arg, 7) == 0)
	{
		image->color_s.new_r = 100;
		image->color_s.new_g = 50;
		image->color_s.new_b = 1;
	}
}
