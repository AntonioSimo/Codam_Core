/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 16:38:55 by asimone       #+#    #+#                 */
/*   Updated: 2023/03/08 17:11:15 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	i;
	int	counter;

	counter = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		counter += write(1, "-", 1);
		if (counter < 0)
			return (-1);
		n = -n;
	}
	if (n >= 10)
		counter += ft_putnbr(n / 10);
	if (counter < 0)
		return (-1);
	i = n % 10 + 48;
	counter += write(1, &i, 1);
	return (counter);
}

// int	main(void)
// {
// 	int	i;

// 	i = 345;
// 	ft_putnbr(i);
// }
