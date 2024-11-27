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

int main(int ac, char **av)
{
    t_stack stack_a;
    t_stack stack_b;

    init_stack(&stack_a);
    init_stack(&stack_b);

    if (handle_errors(ac, av, &stack_a))
        return (1);

    // Debug: Initial stack state
    printf("Initial stack_a: ");
    print_stack(stack_a.top); // Assuming you have a print_stack function

    printf("Initial stack_b: ");
    print_stack(stack_b.top); // Assuming you have a print_stack function

    char *line;
    while ((line = get_next_line(0)) != NULL)
    {
        printf("Read line: '%s'\n", line); // Debug print to show what is read
        if (*line == '\0')
        {
            printf("Empty line received. Skipping...\n"); // Debug for empty lines
            free(line);
            continue; // Skip empty lines
        }
        if (handle_input_line(line, &stack_a, &stack_b)) // Processes each line
        {
            break; // Exit on error (return value 1 indicates an error)
        }
        free(line);
    }

    // Debug: Final stack state after processing
    printf("Final stack_a: ");
    print_stack(stack_a.top); // Assuming you have a print_stack function

    printf("Final stack_b: ");
    print_stack(stack_b.top); // Assuming you have a print_stack function

    free_stack(&stack_a);
    free_stack(&stack_b);
    return 0;
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
