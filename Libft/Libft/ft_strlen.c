/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 19:49:48 by asimone       #+#    #+#                 */
/*   Updated: 2022/10/14 18:07:20 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The function computes the length of the string using the while loop.*/

size_t	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

// int	main(void)
// {
// 	char	str[50];

// 	printf("mine: %zu\n", ft_strlen("Codam"));
// 	printf("not mine: %zu", strlen("Codam"));
// 	return (0);
// }
