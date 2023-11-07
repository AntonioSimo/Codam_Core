/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 18:35:15 by asimone       #+#    #+#                 */
/*   Updated: 2023/02/06 13:58:00 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/**
* @brief	Allocates enough space for count objects that are size bytes of 
			memory each. The allocated memory is filled with bytes of value zero.
			If count or size is 0, then calloc() returns either NULL, or a 
			unique pointer value that can later be successfully passed to free().
* @param	count This parameter represents the number of elements to allocate 
			in memory. It indicates how many objects of the same type need to 
			be allocated and initialized to zero. 
* @param	size This parameter represents the size of each element to allocate 
			in memory. It indicates how many bytes will be allocated 
			for each element. 
* @return 	It will return a pointer to the allocated memory.
*/
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, size * count);
	return (ptr);
}

//int main(void)
//{
//	int count;
//	int size;
//	void *ptr;

//	ptr = ft_calloc(SIZE_MAX, 2);
//	free(ptr);
//	return (0);
//}