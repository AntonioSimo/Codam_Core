/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 17:00:40 by asimone       #+#    #+#                 */
/*   Updated: 2023/02/06 13:56:48 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/**
* @brief	This function calculates the number of digits in an integer, taking 
			into account positive and negative numbers.
* @param	nbr Represents the integer to count the digits.
* @return 	The number of digits present in the integer nbr.
*/
int	ft_countnbr(int nbr)
{
	int	count_digit;

	count_digit = 0;
	if (nbr >= 1)
	{
		while (nbr >= 1)
		{
			nbr /= 10;
			count_digit++;
		}
	}
	else
	{
		count_digit++;
		while (nbr <= -1)
		{
			nbr /= 10;
			count_digit++;
		}
	}
	return (count_digit);
}

/**
* @brief	Converts the integer n into a string representation.
* @param	str This parameter represents the integer value to be converted.
* @return 	It returns the resulting string as the output of the function.
*/
char	*ft_itoa(int n)
{
	char	*ptr;
	int		i;
	int		neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	ptr = (char *)malloc(ft_countnbr(n) + 1 * sizeof(char));
	if (ptr == 0)
		return (NULL);
	i = ft_countnbr(n);
	neg = 0;
	ptr[i] = '\0';
	if (n < 0)
	{	
		neg = 1;
		n *= -1;
		ptr[0] = '-';
	}
	while (i > neg)
	{
		i--;
		ptr[i] = n % 10 + '0';
		n /= 10;
	}	
	return (ptr);
}

// int main(void)
// {
// 	int a;
//	char *b;

// 	a = -143;
// 	b = ft_itoa(a);
//	printf("%s", b);
// 	//free(a);	
// 	//while(1)
// 	//	system("leaks a.out");
// }