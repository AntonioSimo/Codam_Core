/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 13:49:50 by asimone       #+#    #+#                 */
/*   Updated: 2022/10/14 18:22:29 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/**
* @brief	Used to convert an lowercase letter to its corresponding uppercase. 
*			letter.
* @param	c Represent the character to be converted.
* @return	If the initial character c is a lowercase letter, the function will
*			return the corresponding uppercase letter. If the initial character 
*			is not an lowercase letter, the function will simply return the
*			unchanged character.
*/
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

// int	main(void)
// {
// 	printf("mine: %c\n", ft_toupper('c'));
// 	printf("not mine: %c", toupper('c'));
// 	return (0);
// }
