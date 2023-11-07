/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/09 14:42:11 by asimone       #+#    #+#                 */
/*   Updated: 2022/11/09 19:14:08 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
/**
* @brief	Write a single character to the standard output.
* @param	c Represents the character to be written to the standard output.
* @return	Writes the character c to the standard output and returns the result
*			of the write function.
*/
int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}
