#include "push_swap.h"

void r_rotate_a(t_stack **stack_a)
{
    t_stack *last;
    t_stack *second_last;

    if (*stack_a == NULL || (*stack_a)->next == NULL)
        return;

    last = *stack_a;
    while (last->next)
    {
        second_last = last;
        last = last->next;
    }

    second_last->next = NULL;
    last->next = *stack_a;
    *stack_a = last;

    write(1, "rra\n", 4);
}