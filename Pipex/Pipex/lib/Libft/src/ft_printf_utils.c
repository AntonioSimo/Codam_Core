/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 18:08:51 by asimone       #+#    #+#                 */
/*   Updated: 2023/03/08 17:32:46 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/**
* @brief	Write a single character to the standard output.
* @param	c Represents the character to be written to the standard output.
* @return	Writes the character c to the standard output and returns the result
*			of the write function.
*/
int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

/**
* @brief	Write a string to the standard output. 
* @param	s Represents a pointer to the string to be written.
* @return	If the string pointer s is NULL, it means that the string is empty 
*			or uninitialized. In this case, the function writes the string 
*			"(null)". If the string pointer s is not NULL, it means that a valid
*			string is passed. The function calls the ft_strlen function to 
*			determine the length of the string s. The function then calls the 
*			write function to write the string s to the standard output.
*/
int	ft_putstr(char *s)
{
	if (s == NULL)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

/**
* @brief	Write an integer to the standard output. 
* @param	n Represents the integer to be written.
* @return	The function returns the total counter, which represents the 
*			number of characters written.
*/
int	ft_putnbr(int n)
{
	int	i;
	int	counter;

	counter = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		counter += write(1, "-", 1);
		if (counter < 0)
			return (-1);
		n = -n;
	}
	if (n >= 10)
		counter += ft_putnbr(n / 10);
	if (counter < 0)
		return (-1);
	i = n % 10 + 48;
	counter += write(1, &i, 1);
	return (counter);
}

/**
* @brief	Write an unsigned integer to the standard output
* @param	n Represents the unsigned integer to be written.
* @return	The function returns the total counter, which represents
*			the number of characters written.
*/
int	ft_putnnbr(unsigned int n)
{
	unsigned int	i;
	int				counter;

	counter = 0;
	if (n >= 10)
		counter += ft_putnnbr(n / 10);
	if (counter < 0)
		return (-1);
	i = n % 10 + 48;
	counter += write(1, &i, 1);
	return (counter);
}

/**
* @brief	Convert an unsigned long integer to its hexadecimal 
*			representation and write it to the standard output.
* @param	n Represents the unsigned long integer to be converted.
* @param	check Rapresents a flag used for special character encoding.
* @return	The function returns the total counter, which represents 
*			the number of characters written.
*/
int	ft_itoh(unsigned long n, int check)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if (n < 10)
		counter += ft_putchar(n + '0');
	else if (n >= 16)
	{
		counter += ft_itoh (n / 16, check);
		if (counter < 0)
			return (-1);
		counter += ft_itoh (n % 16, check);
	}
	else
	{
		if (check)
			i = n + 'W';
		else
			i = n + 55;
		counter += write(1, &i, 1);
	}
	return (counter);
}
