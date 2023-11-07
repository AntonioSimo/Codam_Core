/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 16:40:58 by asimone       #+#    #+#                 */
/*   Updated: 2022/11/16 15:56:11 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
/**
* @brief	Computes the length of a given string by counting the number of 
*			characters until it reaches the null-terminating character '\0'.
* @param	str Represent a pointer to the input string whose length we want 
*			to calculate. 
* @return	Represents the length of the string (excluding the null-terminating 
*			character).
*/
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
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

// int	main(void)
// {
// 	char	s[50] = "Ciao sono Antonio";

// 	ft_putstr(s);
// }
