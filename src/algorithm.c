#include "push_swap.h"

void radix_sort(t_stack **stack_a, t_stack **stack_b)
{
    int max_bits = get_max_bits(*stack_a);
    int i = 0;

    while (i < max_bits)
    {
        bucket_sort(stack_a, stack_b, i);
        printf("After bucket_sort (bit_position %d):\n", i);
        print_stack(*stack_a);
        print_stack(*stack_b);
        i++;
    }
}

int get_max_bits(t_stack *stack)
{
    int max_value = 0;
    t_stack *current = stack;

    while (current)
    {
        if (current->value > max_value)
            max_value = current->value;
        current = current->next;
    }

    int bits = 0;
    while ((max_value >> bits) != 0)
    {
        bits++;
    }
    return bits;
}

void bucket_sort(t_stack **stack_a, t_stack **stack_b, int bit_position)
{
    int volume = get_node_count(*stack_a);
    int i = 0;

    while (i < volume)
    {
        if (((*stack_a)->value >> bit_position) & 1)
        {
            push_b(stack_a, stack_b);
        }
        else
        {
            rotate_a(stack_a);
        }
        i++;
    }

    while (*stack_b)
    {
        push_a(stack_a, stack_b);
    }
}

void sort_three(t_stack **head)
{
    int biggest = find_biggest(*head);

    if ((*head)->value == biggest)
    {
        rotate_a(head);
        printf("After rotate_a:\n");
        print_stack(*head);
    }
    else if ((*head)->next->value == biggest)
    {
        r_rotate_a(head);
    }

    if ((*head)->value > (*head)->next->value)
    {
        swap_a(head);
        printf("After swap_a:\n");
        print_stack(*head);
    }
}

void sort_five(t_stack **stack_a, t_stack **stack_b)
{
    int volume = get_node_count(*stack_a);
    int smallest;

    while (volume > 3)
    {
        smallest = find_smallest(*stack_a);
        t_stack *tmp = *stack_a;
        int rotations = 0;

        while (tmp)
        {
            if (tmp->value == smallest)
                break;
            tmp = tmp->next;
            rotations++;
        }

        if (rotations <= volume / 2)
        {
            while ((*stack_a)->value != smallest)
                rotate_a(stack_a);
        }
        else
        {
            while ((*stack_a)->value != smallest)
                r_rotate_a(stack_a);
        }

        push_b(stack_a, stack_b);
        volume--;
    }

    sort_three(stack_a);

    push_a(stack_a, stack_b);
    push_a(stack_a, stack_b);

    if ((*stack_a)->value > (*stack_a)->next->value)
    {
        swap_a(stack_a);
    }
}
