/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/25 11:31:07 by asimone       #+#    #+#                 */
/*   Updated: 2023/03/01 15:54:18 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(int fd, char *buffer)
{
	char	*text;
	int		x;

	x = 1;
	text = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!text)
		return (free(buffer), NULL);
	while (x > 0 && !ft_strchr(buffer, '\n'))
	{
		x = read(fd, text, BUFFER_SIZE);
		if (x == -1)
		{
			free(buffer);
			free(text);
			return (NULL);
		}
		if (x == 0)
			break ;
		text[x] = '\0';
		buffer = ft_free_strjoin(buffer, text);
		if (buffer == NULL)
			return (NULL);
	}
	free(text);
	return (buffer);
}

char	*ft_find_leftover(char *str)
{
	char	*leftover;
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	while (str && str[i] != '\n' && str[i] != '\0')
		i++;
	leftover = malloc(sizeof(char) * (ft_strlen(str) - i) + 1);
	if (!leftover)
		return (free(str), NULL);
	if (str[i] == '\n')
		i++;
	while (str && str[i] != '\0')
	{
		leftover[x] = str[i];
		i++;
		x++;
	}
	leftover[x] = '\0';
	return (free(str), leftover);
}

char	*ft_read_line(char	*str)
{
	char	*to_read;
	size_t	i;

	i = 0;
	while (str && str[i] != '\n' && str[i] != '\0')
		i++;
	if (str && str[i] == '\n')
		i++;
	to_read = malloc((i + 1) * sizeof (char));
	if (!to_read)
		return (NULL);
	i = 0;
	while (str && str[i] != '\n' && str[i] != '\0')
	{
		to_read[i] = str[i];
		i++;
	}
	if (str && str[i] == '\n')
	{
		to_read[i] = '\n';
		i++;
	}
	to_read[i] = '\0';
	return (to_read);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (BUFFER_SIZE < 1 && read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_read_line(buffer);
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = ft_find_leftover(buffer);
	if (!ft_strlen(buffer))
	{
		free(buffer);
		buffer = NULL;
	}
	return (line);
}

//int main(void)
//{
//	int fd = open("text1.txt", O_RDONLY);
//	char	*str;

//	str = get_next_line(fd);
//	printf("%s", str);
//	while(str)
//	{
//		str = get_next_line(fd);
//		if (str)
//			printf("%s",str);
//		free(str);
//	}
//	close (fd);
//}
