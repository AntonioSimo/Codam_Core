/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 16:38:55 by asimone       #+#    #+#                 */
/*   Updated: 2023/04/20 15:34:27 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
/**
* @brief	Write an integer to the standard output. 
* @param	n Represents the integer to be written.
* @return	The function returns the total counter, which represents the 
*			number of characters written.
*/
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

 int	main(void)
 {
 	int	i;

 	i = 345;
 	ft_putnbr(i);
 }
