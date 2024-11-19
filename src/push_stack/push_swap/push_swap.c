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
    char *line;

stack_a.top = NULL;  // Ensure top is NULL initially
stack_b.top = NULL;
stack_a.size = 0;  // Set size to 0 initially
stack_b.size = 0;

    if (handle_errors(ac, av, &stack_a))
        return (1);

    while (get_next_line(0, &line))
    {
        if (line && *line)
        {
            if (handle_input_line(line, &stack_a))
            {
                free(line);
                return (1);
            }
        }
        free(line);
    }


    printf("Stack A before sorting:\n");
    print_stack(stack_a.top);


    radix_sort(&stack_a, &stack_b);

    printf("Stack A after sorting:\n");
    print_stack(stack_a.top);

    free_stack(&stack_a);
    free_stack(&stack_b);

    return (0);
}
