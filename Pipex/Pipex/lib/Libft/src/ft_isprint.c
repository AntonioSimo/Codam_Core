/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 19:39:26 by asimone       #+#    #+#                 */
/*   Updated: 2022/11/02 12:23:20 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/**
* @brief	Tests for any printing character, including space (‘ ’).  The value 
			of the argument must be representable as an unsigned char or the 
			value of EOF.
* @param	c Represents the character to be checked.
* @return 	If c is either a printing character, the function returns a 
			non-zero value (typically 1), otherwise the function returns 0.
*/
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

// int	main(void)
// {
// 	printf("mine: %i\n", ft_isprint(''));
// 	// printf("not mine: %i", isprint(''));
// 	return (0);
// }
