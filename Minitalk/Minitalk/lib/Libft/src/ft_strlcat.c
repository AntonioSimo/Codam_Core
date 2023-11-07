/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 17:05:24 by asimone       #+#    #+#                 */
/*   Updated: 2023/02/06 13:54:47 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/**
* @brief	Used to concatenate two strings, src and dst, with a specified size 
*			limit dstsize. It ensures that the resulting concatenated string does 
*			not exceed the size limit of the destination string.
* @param	dst Represents a pointer to the destination string where the 
*			concatenation will occur. 
* @param	src Represents a pointer to the source string that will be 
*			appended to the destination string.
* @param	dstsize Represents the size limit of the destination string, 
*			including the null-terminating character.
* @return	The function returns the length of src plus the original length of 
*			dst (len_or), representing the total length of the concatenated string. 
*			Note that the returned value does not exceed the value of dstsize, 
*			even if the actual length of the concatenated string is longer.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len_or;

	j = 0;
	i = 0;
	if (dst)
		i = ft_strlen(dst);
	if (dstsize == 0 || dstsize <= i)
		return (ft_strlen(src) + dstsize);
	len_or = i;
	while (src[j] != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ft_strlen(src) + len_or);
}

//int main(void)
//{
//	char dst[50] = "This is Codam.";
//	char src[50] = "This is a coding school.";
//	ft_strlcat(dst, src, 25);
//	printf("%s", dst);
//	return (0);
//}