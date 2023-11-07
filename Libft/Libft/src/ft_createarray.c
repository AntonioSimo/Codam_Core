/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_create_array                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 18:35:15 by asimone       #+#    #+#                 */
/*   Updated: 2023/02/06 13:58:00 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_createarray(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		perror("Error memory allocatio.\n");
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

//int main(void)
//{
//    int *int_array;
//	char *str;
//	int i;

//	i = 0;
//	str = "Ciao sono Antonio";
//	int_array = (int *)ft_createarray(10 * sizeof(int));
//	str = (char *)ft_createarray(ft_strlen(str) + 1);
//    while(i < 10)
//    {
//        int_array[i] = i * 2;
//	//	//printf("%i\n", *int_array);
//		i++;
//    }
//	while (str[i] != '\0')
//	{
//		printf("%c\n", str[i]);
//		i++;
//	}
//	strcpy(str, "Ciao sono Antonio");
//    free(int_array);
//	printf("%s\n", str);
//	free(str);
//	printf("%i\n", *int_array);
//    return (0);
//}