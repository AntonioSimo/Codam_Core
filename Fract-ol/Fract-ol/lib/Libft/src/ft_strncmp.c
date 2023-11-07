/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 18:43:00 by asimone       #+#    #+#                 */
/*   Updated: 2022/10/17 15:30:13 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/**
* @brief	Lexicographically compare the null-terminated strings s1 and s2. The 
*			strncmp() function compares not more than n characters. Because 
*			strncmp() is designed for comparing strings rather than binary data, 
*			characters that appear after a ‘\0’ character are not compared.
* @param	s1 Represent a pointer to the first string to be compared.
* @param	s2 Represent a pointer to the second string to be compared.
* @param	n Represent the maximum number of characters to compare between 
*			the two strings.
* @return	If a mismatch is found or a null-terminating character is reached, 
*			the function returns the difference between the two characters 
*			otherwise the function returns 0 to indicate their equality.
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ns1;
	unsigned char	*ns2;

	ns1 = (unsigned char *) s1;
	ns2 = (unsigned char *) s2;
	i = 0;
	while (n != 0)
	{
		if (ns1[i] != ns2[i] || (ns1[i] == 0 || ns2[i] == 0))
			return (ns1[i] - ns2[i]);
		i++;
		n--;
	}
	return (0);
}

// int	main(void)
// {
// 	char	s1[50] = "";
// 	char	s2[50] = "AAAAAAA";
// 	size_t	n;
// 	int		a;
// 	int		b;

// 	n = 6;
// 	a = ft_strncmp(s1, s2, n);
// 	b = strncmp(s1, s2, n);
// 	printf("mine: %i\n", a);
// 	printf("not mine: %i", b);
// 	return (0);
// }
