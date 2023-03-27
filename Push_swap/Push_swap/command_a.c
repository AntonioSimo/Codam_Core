/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   command_a.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/20 15:14:56 by asimone       #+#    #+#                 */
/*   Updated: 2023/03/24 17:09:25 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sa Swap the first 2 elements at the top of stack a.
//Do nothing if there is only one or no elements.

//void push(t_node **head_ref, int new_data)
//{
//    t_node *new_node = lstnew(new_data);
//    new_node->next = *head_ref;
//    *head_ref = new_node;
//}

void print_list(t_node *head)
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

void	del_first(t_two_stack *stack, int control)
{
	t_node	*head;

	if (control)
	{
		head = stack->stack_a->next;
		free(stack->stack_a);
		stack->stack_a = head;
	}
	else
	{
		head = stack->stack_b->next;
		free(stack->stack_b);
		stack->stack_b = head;
	}
}

int		pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*head_a;
	t_node	*head_b;
	t_node	*second_element_a;
	t_node	*second_element_b;

	head_a = *stack_a;
	head_b = *stack_b;
	second_element_a = head_a->next;

	head_a->next = head_b;
	if (head_b)
		head_b->prev = head_a;
	else
		head_b = head_a;
	if (second_element_a)
		second_element_a->prev = NULL;
	*stack_a = second_element_a;
	*stack_b = head_a;

	return (0);
}

int		sa(t_node **stack_a_or_b)
{
	t_node	*head;
	t_node	*second_element;
	t_node	*third_element;

	if (lstsize(*stack_a_or_b) <= 1)
		return (1);
	head = *stack_a_or_b;
	second_element = (*stack_a_or_b)->next;
	third_element = (*stack_a_or_b)->next->next;
	if(third_element)
		third_element->prev = head;
	second_element->prev = NULL;
	second_element->next = head;
	head->prev = second_element;
	head->next = third_element;
	*stack_a_or_b = second_element;

	return (0);
}

int		ra(t_node **stack_a_or_b)
{
	t_node	*head;
	t_node	*tail;

	if (lstsize(*stack_a_or_b) <= 1)
		return (1);
	head = *stack_a_or_b;
	tail = *stack_a_or_b;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = head;
	tail->prev = tail;
	*stack_a_or_b = head->next;
	head->next->prev = NULL;
	head->next = NULL;

	return (0);
}

int		rra(t_node **stack_a_or_b)
{
	t_node	*head;
	t_node	*tail;

	if (lstsize(*stack_a_or_b) <= 1)
		return (1);
	head = *stack_a_or_b;
	tail = *stack_a_or_b;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = head;
	head->prev = tail;
	*stack_a_or_b = tail;
	tail->prev->next = NULL;
	tail->prev = NULL;

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
	
    rra(&stack->stack_a);

    printf("Lista stack_a dopo la chiamata a pa:\n");
    print_list(stack->stack_a); // Stampa la lista stack_a dopo la chiamata a sa
	print_list(stack->stack_b);

    return 0;
}