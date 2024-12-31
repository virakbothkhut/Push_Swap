/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhut <vkhut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:22:44 by vkhut             #+#    #+#             */
/*   Updated: 2024/12/06 16:01:00 by vkhut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				number;
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

//Input checker
void		input_checker(int ac, char **av);
int			check_duplicate(char **av);
int			is_valid_num(const char *str);
void		check_ac(char **pointer);
int			validate_ac(char *ac, char **pointer);
int			count_words(const char *str, char delimiter);

//input handler
void		handle_single_ac(char *ac);
void		free_pointer(char **pointer);
void		handle_multi_ac(int ac, char **av);

// reverse roatate 
void		r_rotate_a(t_stack **stack_a);
int			cal_rotates(t_stack *stack, int smallest);
void		r_or_rr(t_stack **stack_a, int volume);

//set up
void		add_to_stack(t_stack **stack, t_stack *new_node);
t_stack		*create_stack(int ac, char **av);
t_stack		*create_stack_single(char *ac);
t_stack		*create_stack_multi(int ac, char **av);
int			get_node_count(t_stack *stack);
int			is_sorted(t_stack *stack);

//sort handlers
void		assign_index(t_stack **stack);
void		sort_values(int *arr, int size);
void		assign_index_to_stack(t_stack **stack, int *arr, int size);
void		process_bit(t_stack **stack_a, t_stack **stack_b, int bit);
void		push_back_a(t_stack **stack_a, t_stack **stack_b);

//Algorithm
void		radix_sort(t_stack **stack_a, t_stack **stack_b);
int			get_max_bits(t_stack **stack);
void		sort_five(t_stack **stack_a, t_stack **stack_b);
void		sort_three(t_stack **head);

//stack
int			push_a(t_stack **stack_a, t_stack **stack_b);
int			push_b(t_stack **stack_a, t_stack **stack_b);
int			rotate_a(t_stack **stack_a);
void		swap_a(t_stack **stack_a);

//utils
int			find_biggest(t_stack *head);
int			find_smallest(t_stack *head);
t_stack		*new_node(int value);
void		free_stack(t_stack **stack);

#endif
