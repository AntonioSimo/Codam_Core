/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnnbr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 17:34:57 by asimone       #+#    #+#                 */
/*   Updated: 2022/11/16 15:56:57 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnnbr(unsigned int n)
{
	unsigned int	i;
	int				counter;

	counter = 0;
	if (n >= 10)
		counter += ft_putnnbr(n / 10);
	i = n % 10 + 48;
	counter += write(1, &i, 1);
	return (counter);
}

// int	main(void)
// {
// 	unsigned int	n;

// 	n = -1;
// 	ft_putnnbr(n);
// }
