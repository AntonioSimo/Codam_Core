/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 14:49:26 by asimone       #+#    #+#                 */
/*   Updated: 2023/03/01 17:50:33 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/**
* @brief	Locates the first occurrence of c (converted to a char) in the string 
*			pointed to by s. The terminating null character is considered to be 
*			part of the string; therefore if c is ‘\0’, the functions locate the 
*			terminating ‘\0’.
* @param	str Represents the string in which the search will be performed.
* @param	c  Represents the character to be found in the string.
* @return	Returns a pointer to that location in the string. If the character 
*			is not found, it returns NULL.
*/
char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*nstr;

	if (!str)
		return (0);
	nstr = (char *) str;
	i = 0;
	while (str && str[i] != '\0')
	{
		if (str[i] == (char)c)
			return (&nstr[i]);
		i++;
	}
	if ((char)c == 0)
		return (&nstr[i]);
	return (NULL);
}

// int	main(void)
// {
// 	char	str[50] = "Codam. It is coding. school.";
// 	int		c;
// 	char	*ptr;

// 	c = 'i';
// 	printf("mine %s\n", ft_strchr(str, c));
// 	printf("not mine %s\n", strchr(str, c));
// 	//char *ptr = strchr(str, c);
// 	// printf("mine: %s", ptr);
// 	//printf("not mine: %s", ptr);
// 	return (0);
// }
