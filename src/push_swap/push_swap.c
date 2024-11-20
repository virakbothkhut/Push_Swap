#include "push_stack.h"
#include "push_swap.h"
#include "utils.h"
#include "validation.h"

void free_stack(t_stack *stack)
{
    t_node *current;
    t_node *next;

    current = stack->top;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}
void print_stack(t_node *top)
{
    t_node *current = top;
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main(int ac, char **av)
{
    t_stack stack_a;
    t_stack stack_b;
    

    init_stack(&stack_a);
    init_stack(&stack_b);

    if (handle_errors(ac, av, &stack_a))
        return (1);
    char *line;
    while ((line = get_next_line(0)) != NULL)
    {
        if (handle_input_line(line, &stack_a, &stack_b))
        {
            free(line);
            break;
        }
        free(line);
    }
    free_stack(&stack_a);
    free_stack(&stack_b);
    return 0;

    // if (ac < 2)
    // {
    //     printf("Error: Not enough arguments\n");
    //     return 1;
    // }
    // for (int i = 1; i < ac; i++)
    // {
    //     printf("argument %d: %s\n", i, av[i]);
    // }
    // t_stack stack_a;
    // t_stack stack_b;
    // init_stack(&stack_a);
    // init_stack(&stack_b);
    // for (int i = 1; i < ac; i++)
    // {
    //     if (handle_input_line(av[i], &stack_a, &stack_b) != 0)
    //     {
    //         printf("Error: invalid input'%s'\n", av[i]);
    //         return 1;
    //     }
    // }
    // printf("Stack contents: ");
    // print_stack(stack_a.top);
    // return 0;
}
