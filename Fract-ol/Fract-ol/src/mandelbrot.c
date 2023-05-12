/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/09 11:29:19 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/12 15:53:11 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int32_t main(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(1920, 1080, "Hello World!", 1);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}