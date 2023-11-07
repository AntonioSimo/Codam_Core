/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnnbr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 17:34:57 by asimone       #+#    #+#                 */
/*   Updated: 2023/03/08 17:12:01 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
/**
* @brief	Write an unsigned integer to the standard output
* @param	n Represents the unsigned integer to be written.
* @return	The function returns the total counter, which represents
*			the number of characters written.
*/
int	ft_putnnbr(unsigned int n)
{
	unsigned int	i;
	int				counter;

	counter = 0;
	if (n >= 10)
		counter += ft_putnnbr(n / 10);
	if (counter < 0)
		return (-1);
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
