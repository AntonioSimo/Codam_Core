/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 19:49:48 by asimone       #+#    #+#                 */
/*   Updated: 2023/03/01 17:47:28 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/**
* @brief	Computes the length of a given string by counting the number of 
*			characters until it reaches the null-terminating character '\0'.
* @param	str Represent a pointer to the input string whose length we want 
*			to calculate. 
* @return	Represents the length of the string (excluding the null-terminating 
*			character).
*/
size_t	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (0);
	while (str && str[count] != '\0')
		count++;
	return (count);
}

 int	main(void)
 {
 	char	str[50];

 	printf("mine: %zu\n", ft_strlen("Codam"));
 	printf("not mine: %zu", strlen("Codam"));
 	return (0);
 }
