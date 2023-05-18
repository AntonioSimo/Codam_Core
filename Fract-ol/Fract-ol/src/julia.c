/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/18 10:44:55 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/18 13:29:10 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_julia(mlx_t *mlx, mlx_image_t *image)
{
	mlx_image_to_window(mlx, image, 0, 100);
	ft_printf("This is Julia\n");
}