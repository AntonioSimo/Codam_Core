/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 14:43:52 by asimone       #+#    #+#                 */
/*   Updated: 2022/11/02 18:21:15 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/**
* @brief	Used to convert an uppercase letter to its corresponding lowercase 
*			letter.
* @param	c Represent the character to be converted.
* @return	If the initial character c is an uppercase letter, the function will
*			return the corresponding lowercase letter. If the initial character 
*			is not an uppercase letter, the function will simply return the
*			unchanged character.
*/
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

// int	main(void)
// {
// 	printf("mine: %c\n", ft_tolower('Z'));
// 	printf("not mine: %c", tolower('Z'));
// 	return (0);
// }
