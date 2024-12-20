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

void		input_checker(int ac, char **av);
int			check_duplicate(char **av);
int			is_sorted(t_stack *stack);
t_stack		*create_stack(int ac, char **av);
void		index_stack(t_stack *head, int l_size);
void		free_stack(t_stack **head);
void		free_split_string(char **split_string);
void		radix_sort(t_stack **stack_a, t_stack **stack_b);
int			get_max_bits(t_stack *stack);
void		bucket_sort(t_stack **stack_a, t_stack **stack_b, int bit_position);
int			get_node_count(t_stack *head);
void		r_rotate_a(t_stack **head);
void		push_b(t_stack **stack_a, t_stack **stack_b);
void		push_a(t_stack **stack_a, t_stack **stack_b);
void		rotate_a(t_stack **stack_a);
void		swap_a(t_stack **stack_a);
void		sort_five(t_stack **stack_a, t_stack **stack_b);
void		sort_three(t_stack **head);
int			is_valid_num(const char *str);
int			find_biggest(t_stack *head);
int			find_smallest(t_stack *head);
void		split_ac(char *ac, char **pointer);
int			validate_ac(char *ac, char **pointer);
void		add_to_stack(t_stack **stack, t_stack *new_node);
int			cal_rotates(t_stack *stack, int small);
t_stack		*new_node(int value);
void		r_or_rr(t_stack **stack_a, int volume);
#endif
