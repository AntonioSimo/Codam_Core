/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 17:00:48 by asimone       #+#    #+#                 */
/*   Updated: 2023/02/06 13:37:32 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

//char	ft_test(unsigned int i, char c)
//{
//	char str = c + 1;
//	return (str);
//}
/**
* @brief	Applies a function f to each character of the input string s.
* @param	s Represent a pointer to the input string on which the mapping 
*			function will be applied.
* @param	f Represent a pointer to a function that takes an unsigned integer 
*			(representing the index) and a character as arguments and returns 
*			a character. The purpose of this function is to transform each 
*			character of the string.
* @return	It returns a new string with the modified characters.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (s == NULL)
		return (NULL);
	str = ft_strdup(s);
	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		str[i] = f(i, str[i]);
		i++;
	}
	return (str);
}

//int main(void)
//{
//	char a[50] = "hello world.";
//	char *b;
//	printf("%s\n", a);
//	b = ft_strmapi(a, *ft_test);
//	printf("%s", b);
//	return (0);
//}