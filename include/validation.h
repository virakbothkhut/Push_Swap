#ifndef VALIDATION_H
# define VALIDATION_H

# include "push_swap.h"

void	append_stack(t_stack *stack, int *arr, int size);
int		duplicates(t_stack *stack);
void	show_error(void);
int		handle_errors(int ac, char **av, t_stack *stack);

#endif
