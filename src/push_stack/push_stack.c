#include "push_stack.h"
#include "push_swap.h"
#include "utils.h"

void ra(t_node **stack)
{
	t_node *first;
	t_node *last;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	first = *stack;
	*stack = first->next;
	first->next = NULL;

	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
}

void rb(t_node **stack)
{
	t_node *first;
	t_node *last;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	first = *stack;
	*stack = first->next;
	first->next = NULL;

	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
}

void pb(t_node **stack_a, t_node **stack_b)
{
	t_node *temp;

	if (*stack_a == NULL)
		return;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
}

void pa(t_node **stack_a, t_node **stack_b)
{
	t_node *temp;

	if (*stack_b == NULL)
		return;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
}

void sa(t_node **stack)
{
    t_node *first;
    t_node *second;

    // If the stack is empty or has only one element, nothing to swap
    if (*stack == NULL || (*stack)->next == NULL)
        return;

    first = *stack;            // The first node (top of the stack)
    second = first->next;      // The second node

    first->next = second->next;  // The first node now points to the third node
    second->next = first;        // The second node now points to the first node
    *stack = second;             // The second node becomes the new top of the stack
}


void sb(t_node **stack)
{
	t_node *first;
	t_node *second;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	first = *stack;
	second = first->next;

	first->next = second->next;
	second->next = first;
	*stack = second;
}

void rr(t_node **stack_a, t_node **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void rra(t_node **stack)
{
	t_node *last;
	t_node *second_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	last = *stack;
	second_last = NULL;

	while (last->next)
	{
		second_last = last;
		last = last->next;
	}

	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void rrb(t_node **stack)
{
	t_node *last;
	t_node *second_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	last = *stack;
	second_last = NULL;

	while (last->next)
	{
		second_last = last;
		last = last->next;
	}

	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void rrr(t_node **stack_a, t_node **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}

t_node *new_node(int value)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void ss(t_node **stack_a, t_node **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
