/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 16:48:25 by asimone       #+#    #+#                 */
/*   Updated: 2022/11/14 13:20:58 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/**
* @brief	Copy a string from the source to the destination, ensuring that the
*			destination string does not overflow. 
* @param	dst Represents a pointer to the destination string where the copy 
*			operation will occur. It should be large enough to accommodate 
*			the copied string,
* @param	src Represents a pointer to the source string that will be copied 
*			to the destination string.
* @param	dstsize Represents the size limit of the destination string, 
*			including the null-terminating character.
* @return	The total length of the source string, regardless of the 
*			destination size limit.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srcsize;

	srcsize = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (srcsize);
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srcsize);
}

//int main(void)
//{
//	char	dst[50];
//	char	src[50] = "Ciao sono Antonio";
//	//ft_strlcpy(dst, src, sizeof(dst));
//	strlcpy(dst, src, sizeof(dst));
//	printf("%s\n", dst);
//}