/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 14:43:04 by asimone       #+#    #+#                 */
/*   Updated: 2022/10/25 14:51:12 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/**
* @brief	Searches for the last occurrence of the character c in the string s. 
*			It returns a pointer to the located character or NULL if the 
*			character is not found.
* @param	s Represent a pointer to the string in which we want to search for 
*			the character.
* @param	c Represent the character we are searching for, represented as 
*			an integer.
* @return	Return a pointer to the located character, or NULL if the character 
*			does not appear in the string.
*/
char	*ft_strrchr(const char *s, int c)
{
	int	length;

	length = ft_strlen(s);
	while (length > -1)
	{
		if (s[length] == (char)c)
			return ((char *)&s[length]);
		length--;
	}
	return (0);
}

// int	main(void)
// {
// 	char	s[50]= "Co\0dam. I\0t is c\0oding \0school.";
// 	int		c;
// 	char	*ptr;

// 	c = '\0';
// 	ptr = ft_strrchr(s, c);
// 	//ptr = strrchr(s, c);
// 	printf("mine: %s", ptr);
// 	//printf("not mine: %s", ptr);
// 	return (0);
// }