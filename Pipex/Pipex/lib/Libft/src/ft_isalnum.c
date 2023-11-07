/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 19:08:32 by asimone       #+#    #+#                 */
/*   Updated: 2022/11/02 12:09:40 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/**
* @brief	Test for any character for which isalpha() or isdigit()is true. The 
			value of the argument must be representable as an unsigned char or 
			the value of EOF.
* @param	c Represents the character to be checked.
* @return 	If c is either an alphabetical character or a digit, the function 
			returns a non-zero value (typically 1), otherwise the function 
			returns 0.
*/
int	ft_isalnum(char c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

// int	main(void)
// {
// 	printf("mine: %i\n", ft_isalnum('2'));
// 	printf("not mine: %i", isalnum(''));
// 	return (0);
// }
