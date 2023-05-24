/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/09 14:43:25 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/24 19:58:26 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/Libft/include/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"
#include <math.h>

#define HEIGHT 2000
#define WIDTH 2000
#define MAX_ITER 100
#define BPP sizeof(int32_t)
#define RED "\x1b[31;01m"
#define BOLD "\033[1m"
#define RESET "\x1b[0m"

typedef struct complex_s
{
    double x;
    double y;
} complex_t;

typedef struct color_s
{    
    int32_t r;
    int32_t g;
    int32_t b;
    int32_t a;
} color_t;

typedef struct s_image
{
    mlx_image_t *image;
    mlx_t       *mlx;
    int         julia_or_mandelbrot;
    int         iter;
    double      moveX;
    double      moveY;
    double      zx;
    double      zy;
    double      cx;
    double      cy;
    double      x;
    double      y;
	double      z_max_x;
    double      z_max_y;
    double      zoom;
} image_t;

double change_imaginary_image_x(image_t *immagine, uint32_t x_coordinate);

double change_imaginary_image_y(image_t *immagine, uint32_t y_coordinate);

uint32_t 	ft_pixel(uint32_t r, uint32_t g, uint32_t b, uint32_t a);

void		ft_hooks(struct mlx_key_data key_data, void* param);

void 		my_scrollhook(double xdelta, double ydelta, void *param);

int    julia_or_mandelbrot(char *which_fractal);

void        mandelbrot(image_t *fractol);

void        julia(image_t *fractol);

#endif