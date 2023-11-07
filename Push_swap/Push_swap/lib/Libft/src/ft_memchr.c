/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 14:16:15 by asimone       #+#    #+#                 */
/*   Updated: 2023/02/06 13:56:24 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/**
* @brief	Locates the first occurrence of c (converted to an unsigned char) 
*			in string s.
* @param	s Represents a pointer to the memory block to search in.
* @param	c Represents the character to search for.
* @param	n Represents the maximum number of bytes to search within the 
*			memory block.
* @return	If no match is found after examining all n characters, the loop will 
*			exit, and the function will reach the return (NULL) statement, 
*			indicating that the character c was not found within the memory block.
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	char			*scopy;

	scopy = (char *)s;
	i = 0;
	while (i < n)
	{
		if (scopy[i] == (unsigned char)c)
			return (&scopy[i]);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	s[50] = "Ciao π, sono Antonio";
// 	char	c;
// 	size_t	n;

// 	c = 'C';
// 	n = 19;
// 	char *chr = ft_memchr(s, c, n);
// 	//char *nchr = memchr(s, c, n);
// 	printf("mine: %s", chr);
// 	//printf("not mine: %s", nchr);
// 	return (0);
// }