/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/25 11:31:10 by asimone       #+#    #+#                 */
/*   Updated: 2023/03/01 17:53:42 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"
/**
* @brief	Computes the length of a given string by counting the number of 
*			characters until it reaches the null-terminating character '\0'.
* @param	str Represent a pointer to the input string whose length we want 
*			to calculate. 
* @return	Represents the length of the string (excluding the null-terminating 
*			character).
*/
size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

/**
* @brief	Locates the first occurrence of c (converted to a char) in the string 
*			pointed to by s. The terminating null character is considered to be 
*			part of the string; therefore if c is ‘\0’, the functions locate the 
*			terminating ‘\0’.
* @param	str Represents the string in which the search will be performed.
* @param	c  Represents the character to be found in the string.
* @return	Returns a pointer to that location in the string. If the character 
*			is not found, it returns NULL.
*/
char	*ft_strchr(char *str, int c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	return (0);
}

/**
* @brief	The function concatenates two strings into a new dynamically 
*			allocated string. The resulting string str is created by allocating 
*			memory based on the combined lengths of s1 and s2, including space 
*			for the null terminator.
* @param	s1 Represents the first string to concatenates.
* @param	s2 Represents the second string to concatenates.
* @return	The function frees the memory allocated for s1 using free and returns
*			the newly concatenated string str.
*/
char	*ft_free_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (free(s1), free(s2), NULL);
	while (s1 && s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	free(s1);
	return (str);
}
