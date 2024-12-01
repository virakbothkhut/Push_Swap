/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhut <vkhut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:22:50 by vkhut             #+#    #+#             */
/*   Updated: 2024/11/20 21:53:35 by vkhut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H

# include "push_swap.h"

void	append_stack(t_stack *stack, int *arr, int size);
int		duplicates(t_stack *stack);
int	    handle_errors(int ac, char **av, t_stack *stack);
void	show_error(void);

#endif
