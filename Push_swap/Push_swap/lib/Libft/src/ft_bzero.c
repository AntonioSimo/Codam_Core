/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 14:11:24 by asimone       #+#    #+#                 */
/*   Updated: 2022/11/14 10:13:14 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/**
* @brief	Writes n zeroed bytes to the string str. If n is zero, bzero() 
*			does nothing.
* @param	str This parameter is a pointer to the start of the memory block 
			to set to zero. It can point to any data type because it's 
			a void pointer.
* @param	n This parameter represents the number of bytes to set to zero 
			starting from the memory address pointed to by str. 
* @return 	The function doesn't return a value because it modifies the 
*			memory block in-place.
*/
void	ft_bzero(void *str, size_t n)
{
	ft_memset(str, 0, n);
}

// int	main(void)
// {
// 	//int		i;
// 	int		x;
// 	char	str[50] = "1234";
// 	size_t	n;
// 	//char	nstr[50] = "1234";
// 	//size_t	a;

// 	//i = 0;
// 	x = 0;
// 	n = 2;
// 	//a = 2;
// 	ft_bzero(str, n);
// 	//bzero(nstr, a);
// 	//while (i != 50)
// 	//	printf("%c", nstr[i]);
// 	//	i++;
// 	//printf("\n"); /*printing the new lines*/
// 	while (x != 50)
// 		printf("%c", str[x]);
// 		x++;
// 	return (0);
// }
