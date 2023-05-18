/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/09 14:43:25 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/18 14:01:23 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/Libft/include/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"
#include <math.h>

#define HEIGHT_WINDOW 1920
#define WIDTH_WINDOW 1080
#define MAX_ITER 100
#define BPP sizeof(int32_t)
#define RED "\x1b[31;01m"
#define BOLD "\033[1m"
#define RESET "\x1b[0m"


uint32_t 	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);

void		ft_hooks(struct mlx_key_data key_data, void* param);

int			ft_init(int argc, char *choose_fractal);

void		ft_mandelbrot(mlx_t *mlx, mlx_image_t *image);

void		ft_julia(mlx_t *mlx, mlx_image_t *image);

#endif