/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 16:59:45 by asimone       #+#    #+#                 */
/*   Updated: 2023/02/06 13:55:19 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/**
* @brief	The function concatenates two strings into a new dynamically 
*			allocated string.
* @param	s1 Represents the first string to concatenates.
* @param	s2 Represents the second string to concatenates.
* @return	Returns a pointer to the new string.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;

	if (s1 == 0)
		return (ft_strdup(s2));
	if (s2 == 0)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(len * sizeof(char));
	if (str == NULL)
		return (free(str), NULL);
	ft_strlcpy(str, s1, len);
	ft_strlcat(str, s2, len);
	return (str);
}

// int	main(void)
// {
//  	char *s1 = "where is my ";
//  	char *s2 = "malloc???";
//  	char *s3 = "where is my malloc ???";

// 	char *res = ft_strjoin(s1, s2);
// 	printf("%s", res);
// 	return (0);
// }