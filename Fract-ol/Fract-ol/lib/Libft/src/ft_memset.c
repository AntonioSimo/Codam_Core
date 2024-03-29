/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 20:07:34 by asimone       #+#    #+#                 */
/*   Updated: 2022/11/14 10:02:27 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/**
* @brief	Writes len bytes of value c (converted to an unsigned char) to the 
*			string str.
* @param	str Represents a pointer to the memory block to be filled.
* @param	c Represents the value to be set in each byte of the memory block.
* @param	len Represents is the number of bytes to be set.
* @return	The function returns the str pointer, which now points to the 
*			filled memory block.
*/
void	*ft_memset(void *str, int c, size_t len)
{
	while (len > 0)
	{
		len--;
		((char *)str)[len] = (unsigned char)c;
	}
	return (str);
}

// int	main(void)
// {
// 	char	str[50] = "Ciao sono Antonio";
// 	int		c;
// 	size_t	len;

// 	c = 'A';
// 	len = 4;
// 	printf("mine: %s\n", ft_memset(str, c, len));
// 	printf("not mine: %s", memset(str, c, len));
// 	return (0);
// }
