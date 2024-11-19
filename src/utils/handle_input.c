#include "push_swap.h"
#include "utils.h"
#include "push_stack.h"

void push_to_stack(t_stack *stack, t_node *node)
{
    if (stack->top == NULL)
    {
        stack->top = node;
        stack->bottom = node;
    }
    else
    {
        node->next = stack->top;
        stack->top = node;
    }
    stack->size++;
}

int handle_input_line(char *line, t_stack *stack_a)
{
    int value = atoi(line);  
    t_node *node = new_node(value);  

    if (!node)
        return 1;  

    push_to_stack(stack_a, node); 

    return 0;
}
