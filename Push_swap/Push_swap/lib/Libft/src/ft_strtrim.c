/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 17:00:51 by asimone       #+#    #+#                 */
/*   Updated: 2022/11/15 16:08:07 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

//static	int	ft_check(char s, char const *set)
//{
//	while (*set)
//		if (*set++ == s)
//			return (1);
//	return (0);
//}
/**
* @brief	Trims the leading and trailing characters from a string s1 based on 
*			a set of characters specified in the set string. 
* @param	s1 Represent the input string from which we want to remove the 
*			leading and trailing characters.
* @param	set Represent the set of characters that we want to remove from the 
*			beginning and end of s1.
* @return	It returns a new dynamically allocated string with the trimmed content.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	end;
	size_t	start;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL || *set == 0)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (ft_check(s1[start], set))
		start++;
	while (ft_check(s1[end - 1], set))
		end--;
	if (start >= end)
		return (ft_strdup(""));
	str = ft_substr(s1, start, end - start);
	return (str);
}

// int main(void)
// {
//	char a[50] = "Hello World.";
//	printf("%s", ft_strtrim(a, "H"));
//	return (0);
// }