/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 18:36:18 by asimone       #+#    #+#                 */
/*   Updated: 2022/11/10 17:46:46 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/**
* @brief	Write a single character to a specified file descriptor using the 
*			write system call to a specified file descriptor fd
* @param	c Represents the character to be written.
* @param	fd Represents the file descriptor specifies the output stream where 
*			the character should be written
* @return	Writes the character c to the file descriptor specified and returns 
*			the result of the write function.
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

//int main(void)
//{
//	ft_putchar_fd('C', 1);
//	return (0);
//}