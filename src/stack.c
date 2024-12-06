#include "push_swap.h"

void push_b(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;

    if (*stack_a == NULL)
        return;

    tmp = *stack_a;
    *stack_a = (*stack_a)->next;
    tmp->next = *stack_b;
    *stack_b = tmp;

    write(1, "pb\n", 3);
}

void push_a(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;

    if (*stack_b == NULL)
        return;

    tmp = *stack_b;
    *stack_b = (*stack_b)->next;
    tmp->next = *stack_a;
    *stack_a = tmp;
    write(1, "pa\n", 3);

    printf("Operation: push_a\n");
    print_stack(*stack_a);
    print_stack(*stack_b);
}

void rotate_a(t_stack **stack_a)
{
    t_stack *first;
    t_stack *last;

    if (*stack_a == NULL || (*stack_a)->next == NULL)
        return;

    first = *stack_a;
    last = *stack_a;
    while (last->next)
        last = last->next;

    *stack_a = first->next;
    first->next = NULL;
    last->next = first;

    write(1, "ra\n", 3);
}

void reverse_rotate_a(t_stack **stack_a)
{
    t_stack *tmp;
    t_stack *prev;

    if (*stack_a == NULL || (*stack_a)->next == NULL)
        return;

    prev = NULL;
    tmp = *stack_a;
    while (tmp->next != NULL)
    {
        prev = tmp;
        tmp = tmp->next;
    }

    prev->next = NULL;
    tmp->next = *stack_a;
    *stack_a = tmp;

    write(1, "rra\n", 4);
}

void swap_a(t_stack **stack_a)
{
    t_stack *first;
    t_stack *second;

    if (*stack_a == NULL || (*stack_a)->next == NULL)
        return;

    first = *stack_a;
    second = (*stack_a)->next;
    first->next = second->next;
    second->next = first;
    *stack_a = second;

    write(1, "sa\n", 3);
}
