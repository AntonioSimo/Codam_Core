/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 19:34:11 by asimone       #+#    #+#                 */
/*   Updated: 2023/03/28 20:01:25 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_node *head)
{
	if (head)
	{
		while (head->next != NULL)
		{
			printf("%d ", head->data);
			head = head->next;
		}
		printf("%d ", head->data);
	}
	printf("\n");
}

int	rotate_time(t_node **stack_a, t_node **stack_b, char *str)
{
	rotate(stack_a, NULL);
	rotate(stack_b, NULL);
	if (str)
		write(1, "rr\n", 3);
	return (0);
}

int	reverse_rotate_time(t_node **stack_a, t_node **stack_b, char *str)
{
	reverse_rotate(stack_a, NULL);
	reverse_rotate(stack_b, NULL);
	if (str)
		write(1, "rrr\n", 4);
	return (0);
}

int	rotate(t_node **stack, char *str)
{
	t_node	*head;
	t_node	*tail;

	if (lstsize(*stack) <= 1)
		return (1);
	head = *stack;
	tail = *stack;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = head;
	tail->prev = tail;
	*stack = head->next;
	head->prev = NULL;
	head->next->prev = NULL;
	head->next = NULL;
	if (str)
		write(1, str, strlen(str));
	return (0);
}

int	reverse_rotate(t_node **stack, char *str)
{
	t_node	*head;
	t_node	*tail;

	if (lstsize(*stack) <= 1)
		return (1);
	head = *stack;
	tail = *stack;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = head;
	head->prev = tail;
	*stack = tail;
	tail->prev->next = NULL;
	tail->prev = NULL;
	if (str)
		write(1, str, strlen(str));
	return (0);
}

int main(void)
{
	t_two_stack *stack = malloc(sizeof(t_two_stack));
    //t_node *stack_a = malloc(sizeof(t_node)); // Alloca la memoria per la struct t_two_stack

    stack->stack_a = NULL;
    stack->stack_b = NULL;

    // Aggiungi alcuni nodi alla lista stack_a
    lstadd_back(&stack->stack_a, 3);
    lstadd_back(&stack->stack_a, 2);
    lstadd_back(&stack->stack_a, 1);
	lstadd_back(&stack->stack_b, 7);
    lstadd_back(&stack->stack_b, 4);
    lstadd_back(&stack->stack_b, 2);

    printf("Lista stack_a prima della chiamata a pa:\n");
    print_list(stack->stack_a); // Stampa la lista stack_a prima della chiamata a sa
	print_list(stack->stack_b);

    // Chiamata alla funzione sa
	
    rotate_time(&stack->stack_a, &stack->stack_b, NULL);

    printf("Lista stack_a dopo la chiamata a pa:\n");
    print_list(stack->stack_a); // Stampa la lista stack_a dopo la chiamata a sa
	print_list(stack->stack_b);

    return 0;
}