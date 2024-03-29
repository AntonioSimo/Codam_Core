/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 18:35:18 by asimone       #+#    #+#                 */
/*   Updated: 2023/02/06 13:57:11 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/**
* @brief	Converts the initial portion of the string pointed to by str to int
*			representation.
* @param	str This parameter is a pointer to a null-terminated string of 
			characters that represents the input to be converted to an integer. 
			It's of type const char *, indicating that the function does not 
			modify the string.
* @return 	It will return the str converted to int.
*/
int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	result;

	i = 0;
	result = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (neg < 0)
		return (result * neg);
	return (result);
}

// int	main(void)
// {
// 	char str[50] = " -1234";
// 	int	val = ft_atoi(str);
// 	printf("%d", val);
// 	return (0);
// }