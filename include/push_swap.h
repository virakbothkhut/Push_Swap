/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhut <vkhut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:22:44 by vkhut             #+#    #+#             */
/*   Updated: 2024/11/27 20:15:37 by vkhut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include "../getNextLine/get_next_line.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	t_node			*bottom;
	int				size;
}					t_stack;


void 				ra(t_node **stack);
void 				rb(t_node **stack);
void 				pb(t_node **stack_a, t_node **stack_b);
void 				pa(t_node **stack_a, t_node **stack_b);
void 				sa(t_node **stack);
void 				sb(t_node **stack);
void 				ss(t_node **stack_a, t_node **stack_b);
void 				rr(t_node **stack_a, t_node **stack_b);
void 				rrr(t_node **stack_a, t_node **stack_b);
void 				rrb(t_node **stack);
void 				rra(t_node **stack);
t_node				*new_node(int value);
void				push_to_stack(t_stack *stack, t_node *node);
int					valid_integer(char *str);
int					with_range(char *str);
int					*allocate_memory(int size);
void				convert_t_integer(int ac, char **av, int *arr);
void				append_stack(t_stack *stack, int *arr, int size);
int					duplicates(t_stack *stack);
void				radix_sort(t_stack *stack_a, t_stack *stack_b);
int					get_max(t_stack *stack);
int					get_num_bits(int max);
void				free_stack(t_stack *stack);
void				print_stack(t_node *top);
void 				init_stack(t_stack *stack);

#endif
