/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/09 14:43:25 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/29 19:14:08 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/Libft/include/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <math.h>

# define HEIGHT 2000
# define WIDTH 2000
# define MAX_ITER 100
# define BPP
# define RED "\x1b[31;01m"
# define BOLD "\033[1m"
# define RESET "\x1b[0m"

// Rappresentazione della parte "reale" e "immaginaria" di un numero complesso

typedef struct complex_s
{
	double	x;
	double	y;
}	t_complex;

// Rappresentazione di un colore. I valori possono variare da 0 a 255
// r = rosso, g = verde, b = blu e a = opacita'del colore
// brightness = luminosita' del colore e puo'variare da 0.0 a 1.0

typedef struct color_s
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;
	uint32_t	a;
	double	brightness;
}	t_color;

// Rappresentazione di un'immagine all'interno di un programma grafico.
// image = immagine stessa, mlx = puntatore all'istanza MLX associata a questa immagine
// julia_or_mandelbrot = indica l'immagine rappresenta il set Julia o Mandelbrot
// iter = rappresenta il numero di iterazioni per il calcolo dei set
// move_x e move_y = coordinate di spostamento, zx e zy = coordinate complesse dell'immagine
// cx e cy = coordinate complessa del punto di riferimento nell'insieme di Julia o Mandelbrot.
// x e y = coorinate dell'immagine, z_max_x e z_max_y = valori massimi delle coordinate complesse x e y nell'immagine
// zoom = zoom dellímmagine, color = colore utilizzato per l'immagine
// mouse_x e mouse_y = coordinate x e y del mouse

typedef struct s_image
{
	mlx_image_t	*image;
	mlx_t		*mlx;
	int			julia_or_mandelbrot;
	int			iter;
	double		move_x;
	double		move_y;
	double		zx;
	double		zy;
	double		cx;
	double		cy;
	double		x;
	double		y;
	double		z_max_x;
	double		z_max_y;
	double		zoom;
	uint32_t	color;
	int32_t		mouse_x;
	int32_t		mouse_y;
}	t_image;

double	change_imaginary_image_x(t_image *image, uint32_t x_coordinate);

double	change_imaginary_image_y(t_image *image, uint32_t y_coordinate);

void	color_mandelbrot(t_image *image, int iter);

void	mandelbrot(t_image *image, int iter);

void    draw_mandelbrot(t_image *image);

void	ft_hook(struct mlx_key_data key_data, void *param);

void	ft_mouse_hook(mouse_key_t button, action_t action, modifier_key_t mods, void *param);

void	ft_scroll_hook(double move_x, double move_y, void *param);

uint32_t	ft_pixel(uint32_t r, uint32_t g, uint32_t b, uint32_t a);

int		julia_or_mandelbrot(char *fractal, t_image *image);

void	check_parmeters(mlx_t *mlx, t_image *image, int argc, char **argv);

#endif