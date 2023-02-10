/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoh.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 18:43:59 by asimone       #+#    #+#                 */
/*   Updated: 2022/11/09 19:15:19 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_itoh(unsigned long n, int check)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if (n < 10)
	{
		i = n + '0';
		counter += write(1, &i, 1);
	}
	else if (n >= 16)
	{
		counter += ft_itoh (n / 16, check);
		counter += ft_itoh (n % 16, check);
	}
	else
	{
		if (check)
			i = n + 'W';
		else
			i = n + 55;
		counter += write(1, &i, 1);
	}
	return (counter);
}

// int	main(void)
// { 
// 	int	i;

// 	i = 1544896215;
// 	int b = ft_itoh(i, 0);
// 	printf("\n%i", b);
// }
