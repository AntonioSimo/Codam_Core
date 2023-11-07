/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 14:51:42 by asimone       #+#    #+#                 */
/*   Updated: 2023/02/06 13:55:39 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

//void	ft_test(unsigned int i, char *c)
//{
//	*c = *c + 4;
//	i++;
//}
/**
* @brief	Apply a specified function f to each character of a string s
* @param	s Represents the string to iterate over.
* @param	f This is a function pointer that points to a function taking two 
*			arguments: an unsigned integer representing the index and a character 
*			pointer representing the current character. 
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

//int main(void)
//{
//	char a[50] = "hello world.";
//	printf("%s", a);
//	ft_striteri(a, ft_test);
//	printf("%s", a);
//	return (0);
//}