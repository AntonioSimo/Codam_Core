/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 12:30:54 by asimone       #+#    #+#                 */
/*   Updated: 2022/11/10 17:49:18 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/**
* @brief	Write an integer to a specified file descriptor fd.
* @param	n Represents the integer to be written.
* @param	fd Represents the file descriptor specifies the output stream where 
*			the integer should be written.
* @return	Writes the integer n to the file descriptor specified and returns the
*			result of the write function.
*/
void	ft_putnbr_fd(int n, int fd)
{
	int	i;

	if (n == -2147483648)
	{
		ft_putstr_fd ("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	i = n % 10 + 48;
	write(fd, &i, 1);
}

//int main(void)
//{
//	int n = 14;
//	ft_putnbr_fd(n, 1);
//	return (0);
//}