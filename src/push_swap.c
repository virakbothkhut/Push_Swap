#include "push_swap.h"

int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;

    if (ac < 2)
        return (0);

    input_checker(ac, av);
    stack_a = create_stack(ac, av);
    if (!stack_a)
    {
        ft_putstr_fd("Error\n", 6);
        return (1);
    }
    stack_b = NULL;
    printf("Initial stack_a:\n");
    print_stack(stack_a);

    if (is_sorted(stack_a))
    {

        free_stack(&stack_a);
        return (0);
    }
    int volume = get_node_count(stack_a);
    if (volume <= 3)
        sort_three(&stack_a);
    else if (volume <= 5)
        sort_five(&stack_a, &stack_b);
    else
        radix_sort(&stack_a, &stack_b);

    printf("Final stack_a (sorted):\n");
    print_stack(stack_a);

    free_stack(&stack_a);
    free_stack(&stack_b);

    return 0;
}
