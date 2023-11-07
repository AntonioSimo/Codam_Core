/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 13:08:44 by asimone       #+#    #+#                 */
/*   Updated: 2022/11/02 12:22:26 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/**
* @brief	Test for any character for which isupper() or islower()is true. The 
			value of the argument must be representable as an unsigned char or 
			the value of EOF.
* @param	c Represents the character to be checked.
* @return 	If c is either an alphabetical character, the function returns a 
			non-zero value (typically 1), otherwise the function returns 0.
*/
int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

// int	main(void)
// {
// 	printf("mine: %i\n", ft_isalpha('4'));
// 	//printf("not mine: %i", isalpha(''));
// 	return (0);
// }
