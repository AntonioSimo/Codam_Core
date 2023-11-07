/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 13:47:50 by asimone       #+#    #+#                 */
/*   Updated: 2022/11/02 12:12:09 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/**
* @brief	Tests for a decimal digit character. 
* @param	c Represents the character to be checked.
* @return 	If c is either a digit character, the function returns a non-zero 
			value (typically 1), otherwise the function returns 0.
*/
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

// int	main(void)
// {
// 	printf("mine: %i\n", ft_isdigit('0'));
// 	printf("not mine: %i", isdigit(''));
// 	return (0);
// }
