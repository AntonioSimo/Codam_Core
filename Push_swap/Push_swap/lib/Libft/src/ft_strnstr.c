/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 18:44:49 by asimone       #+#    #+#                 */
/*   Updated: 2022/10/18 15:09:01 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/**
* @brief	Locates the first occurrence of the null-terminated string needle in 
*			the string haystack, where not more than len characters are searched.
*			Characters that appear after a ‘\0’ character are not searched. 
* @param	haystack Represent a pointer to the string in which we want to search 
*			for the substring.
* @param	needle Represent a pointer to the substring we are searching for.
* @param	len The maximum number of characters in haystack to search within.
* @return	If needle is an empty string, haystack is returned; if needle occurs 
*			nowhere in haystack, NULL is returned; otherwise a pointer to the 
*			first character of the first occurrence of needle is returned.
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			i;
	size_t			j;
	char			*nhaystack;

	nhaystack = (char *) haystack;
	i = 0;
	j = 0;
	if (haystack == NULL && len == 0)
		return (NULL);
	if (needle[j] == '\0')
		return (&nhaystack[i]);
	while (nhaystack[i] != '\0')
	{
		while (nhaystack[i + j] == needle[j] && i + j < len)
		{
			j++;
			if (needle[j] == '\0')
				return (&nhaystack[i]);
		}
		i++;
		j = 0;
	}
	return (NULL);
}

// int	main(void)
// {
// // 	const char 	needle[50] = "sx";
// // 	const char 	haystack[50] = "Ciao sono Antonio";
// // 	size_t		len;
// // 	char 		*ptr;

// // 	len = 20;
// // 	ptr = ft_strnstr(haystack, needle, len);
// // 	//ptr = strnstr(haystack, needle, len);
// // 	printf("mine: %s", ptr);
// // 	//printf("not mine: %s", ptr);
// // 	return (0);

// 	char haystack[30] = "aaabcabcd";
// 	char needle[10] = "aabc";
// 	printf("%s",ft_strnstr(haystack, needle, 0));

// }