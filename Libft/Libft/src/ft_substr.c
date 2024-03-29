/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 14:44:43 by asimone       #+#    #+#                 */
/*   Updated: 2022/11/15 16:06:17 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/**
* @brief	Extract a portion of a string starting from a specified index with 
*			a given length.
* @param	s Represent the input string from which the substring will be extracted.
* @param	start Represent the starting index of the substring.
* @param	len Represent the maximum length of the substring.
* @return	It returns the dynamically allocated string ptr, which contains 
*			the extracted substring
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (s == 0)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (len >= ft_strlen(s) - start)
		len = ft_strlen(s) - start + 1;
	else
		len++;
	ptr = malloc((len) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, &s[start], len);
	return (ptr);
}

 int	main(void)
 {
	char a [50] = "Ciao son";//o Antonio.";
	char *b;
	int start = 10;
	size_t len = 50;
	b = ft_substr(a, start, len);
	printf("%s", b);
 	//system("leaks a.out");
 }
