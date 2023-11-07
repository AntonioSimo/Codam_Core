/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/01 11:42:46 by asimone       #+#    #+#                 */
/*   Updated: 2023/03/01 15:55:26 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_find_leftover(char *str);
char	*ft_read_file(int fd, char *buffer);
char	*ft_strchr(char *str, int c);
char	*ft_free_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);

#endif