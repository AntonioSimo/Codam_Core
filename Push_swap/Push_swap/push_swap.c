/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 13:41:50 by asimone       #+#    #+#                 */
/*   Updated: 2023/03/09 16:36:42 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(struct stuck **head, int size, char **new_data)
{
	struct stuck *a;
	int i;

	i = 1;
	a = (struct stuck *) malloc(sizeof(struct stuck));
	while (i < size)
	{
		a -> data = ft_atoi(new_data[i]);
		a -> next = (*head);
		(*head) = a;
		ft_printf("%d\n", a->data);
		i++;
	}
}

int	main(int argc, char **argv)
{
	struct stuck *a = NULL;

	if (argc < 2)
	{
		ft_printf("You are doing something wrong, Mate.");
		exit(EXIT_FAILURE);
	}
	else
	{
		push(&a, argc, argv);
	}
}