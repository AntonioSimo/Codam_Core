/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoh.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 18:43:59 by asimone       #+#    #+#                 */
/*   Updated: 2023/03/08 17:30:20 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
/**
* @brief	Convert an unsigned long integer to its hexadecimal 
*			representation and write it to the standard output.
* @param	n Represents the unsigned long integer to be converted.
* @param	check Rapresents a flag used for special character encoding.
* @return	The function returns the total counter, which represents 
*			the number of characters written.
*/
int	ft_itoh(unsigned long n, int check)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if (n < 10)
		counter += ft_putchar(n + '0');
	else if (n >= 16)
	{
		counter += ft_itoh (n / 16, check);
		if (counter < 0)
			return (-1);
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
