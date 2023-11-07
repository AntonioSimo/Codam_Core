/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 19:27:08 by asimone       #+#    #+#                 */
/*   Updated: 2022/11/02 12:11:20 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/**
* @brief	Tests for an ASCII character, which is any character between 0 and 
			octal 0177 inclusive.
* @param	c Represents the character to be checked.
* @return 	If c is either an ASCII character, the function returns a non-zero 
			value (typically 1), otherwise the function returns 0.
*/
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 0177);
}

//int	main(void)
//{
//	printf("mine: %i\n", ft_isascii(43));
//	printf("not mine: %i", isascii(43));
//	return (0);
//}
