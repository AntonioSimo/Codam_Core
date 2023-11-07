/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 15:19:02 by asimone       #+#    #+#                 */
/*   Updated: 2022/11/16 18:43:15 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/**
* @brief	Count the number of words in a string str based on a specified 
*			delimiter c.
* @param	str Represents a pointer to the input string.
* @param	c Represents the delimiter of the string.
* @return	It returns the final count of words.
*/
static	size_t	ft_count_words(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] != c && str[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

/**
* @brief	Helper function used to deallocate memory that has been previously 
*			allocated dynamically for a two-dimensional array of strings.
* @param	ptr Pointer to an array of pointers to characters. In the context 
*			of this function, ptr represents a dynamically allocated 
*			two-dimensional array of strings.
* @return	The function returns NULL to indicate that the memory has been 
*			successfully deallocated.
*/
static	char	**ft_free_malloc(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != 0)
		free(ptr[i++]);
	free(ptr);
	return (NULL);
}

/**
* @brief	Used to find the length of a substring within a given string s 
*			until a specified delimiter c is encountered
* @param	s Represents the input string that needs to be processed.
* @param	c Represents the delimiter of the string.
* @return	The index of the delimiter or the length of the substring 
*			before the delimiter.
*/
static	int	ft_find_string_limit(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

/**
* @brief	Used to split a strings using the character c as a delimiter.
* @param	s Represents the input string that needs to be split.
* @param	c Represents a character that serves as a delimiter or separator.
* @return	The function returns the ptr array, which contains the split substrings.
*/
char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		i;
	size_t	j;
	size_t	words;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	ptr = malloc((words + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	while (j < words)
	{
		while (s[i] == c)
			i++;
		ptr[j] = ft_substr(s, i, ft_find_string_limit(&s[i], c));
		if (ptr[j] == NULL)
			return (ft_free_malloc(ptr));
		i = i + ft_find_string_limit(&s[i], c);
		j++;
	}
	ptr[j] = NULL;
	return (ptr);
}

// int main(void)
// {
// 	char **str;
// 	char i;

// 	i = 0;
// 	str = ft_split("hello world", ' ');
// 	while (str[i])
// 	{
// 		free(str[i]);
// 		i++;
// 	}
// 	free(str);
// 	system ("leaks a.out");
// }