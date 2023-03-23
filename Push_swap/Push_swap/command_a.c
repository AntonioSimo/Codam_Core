/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   command_a.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/20 15:14:56 by asimone       #+#    #+#                 */
/*   Updated: 2023/03/23 18:51:51 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sa Swap the first 2 elements at the top of stack a.
//Do nothing if there is only one or no elements.

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

void	lstadd_front(t_node **lst, t_node *new)
{
	new->next = *lst;
	*lst = new;
	(*lst)->prev = NULL;
}

void	lstadd_back(t_node **head, t_node *new)
{
    t_node* last_node;
	
	last_node = *head;
    new->next = NULL;
    if (*head == NULL) 
	{
        new->prev = NULL;
        *head = new;
        return;
    }
    while (last_node->next != NULL)
        last_node = last_node->next;
    last_node->next = new;
    new->prev = last_node;
 
    return;
}

int	lstsize(t_node *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_node	*lstnew(int data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

int		pa(t_two_stack *stack)
{
	t_node	*head;

	if(stack->stack_b)
	{
		lstadd_front(stack, lstnew(stack->stack_b->data));
		free(stack->stack_b); //delete the first element of the stack
	}
	write(1, "pa\n", 3);
	return (0);
}

int		sa(t_two_stack *stack)
{
	t_node *first_number;
	t_node *second_number;
	t_node *temp;

	printf("test sa\n");
	if(lstsize(stack->stack_a) <= 1)
	{
		return (1);
	}
	first_number = lstnew(stack->stack_a->data);
	second_number = lstnew(stack->stack_a->next->data);
	temp = first_number;
	first_number = second_number;
	second_number = temp;

	return (0);
}

int		ra(t_two_stack *stack)
{
	t_node	*head;

	if(lstsize(stack->stack_a) <= 1)
		return (1);
	head = stack->stack_a->next;
	lstadd_back(stack, lstnew(stack->stack_a->data));
	free(stack->stack_a);
	stack->stack_a = head;
	
	return (0);
}

//int		rra(t_two_stack *stack)
//{
//	t_node	*head;


//	if (lstsize(stack->stack_a) > 1)
//	{
//		head = lstnew(lstadd_back(stack, stack->stack_a)->data);
//		while (stack->stack_a != NULL)
//		{
//			if (stack->stack_a->next->next == NULL)
//			{
//				free(stack->stack_a->next);
//				stack->stack_a->next = NULL;
//			}
//			stack->stack_a = head;
//			stack->stack_a->prev = NULL;
//		}
//	}
//	return (0);
//}

int main() {
	//t_two_stack *stack_a = NULL;
    t_node *head = NULL;
    t_node *node1 = (t_node*)malloc(sizeof(t_node));
    t_node *node2 = (t_node*)malloc(sizeof(t_node));
	t_node *node3 = (t_node*)malloc(sizeof(t_node));

    int data1 = 10;
    int data2 = 20;
	int data3 = 30;

    // Inizializza il primo nodo
    node1->data = data1;
    node1->prev = NULL;
    node1->next = NULL;

    // Aggiunge il primo nodo alla lista
    lstadd_back(&head, node1);

    // Inizializza il secondo nodo
    node2->data = data2;
    node2->prev = NULL;
    node2->next = NULL;

    // Aggiunge il secondo nodo alla lista
    lstadd_back(&head, node2);

	//inizzializza il terzo nodo
	node3->data = data3;
	node3->prev = NULL;
	node3->next = NULL;

	//aggiungi il terzo nodo alla lista
	lstadd_back(&head, node3);

    // Stampa i dati della lista
    t_node *current = head;

    while (current != NULL) 
	{
        printf("%d ", (current->data));
        current = current->next;
    }
	sa(head);

    printf("\n");

    // Dealloca la memoria dei nodi
    free(node1);
    free(node2);
	free(node3);

    return 0;
}