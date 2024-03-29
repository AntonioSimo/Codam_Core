/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 18:40:17 by asimone       #+#    #+#                 */
/*   Updated: 2022/11/04 15:24:01 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/**
* @brief	Allocates sufficient memory for a copy of the string s1, does the 
*			copy, and returns a pointer to it.
* @param	s1 Represents the source string.
* @return	Returns a pointer to the newly allocated memory block containing 
*			the duplicated string.
*/
char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*ptr;

	len = ft_strlen(s1) + 1;
	i = 0;
	ptr = (char *)malloc(len * sizeof(char));
	if (ptr == NULL)
		return (free(ptr), NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = s1[i];
	return (ptr);
}

// int main(void)
// {
//     char s1[50] = "Ciao sono Antonio";
//     char *ptr;

//     printf("The string in s1 is %s\n", s1);
//     ptr = ft_strdup(s1);
//     printf("The duplicated string is %s", ptr);
//     free(ptr);
//     return (0);
// }