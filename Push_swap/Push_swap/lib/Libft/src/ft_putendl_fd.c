/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 14:02:23 by asimone       #+#    #+#                 */
/*   Updated: 2022/11/10 17:48:03 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/**
* @brief	Write a string s, followed by a newline character, to a specified 
*			file descriptor fd.
* @param	s Represents the string to be written.
* @param	fd Represents the file descriptor specifies the output stream where 
*			the string should be written.
* @return	Writes the string s to the file descriptor specified and returns the
*			result of the write function.
*/
void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == 0)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

//int main(void)
//{
//	char s[50] = "Ciao sono Antonio.";
//	ft_putendl_fd(s, 1);
//	return(0);
//}