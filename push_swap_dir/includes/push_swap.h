/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:37:55 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/13 15:06:42 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "shared.h"
# include "instructions.h"
# include "print.h"
# include "stack.h"
# include "stack_utilities.h"
# include "list_utilities.h"

void	convert_stack(t_stack *stack);

/*
** ALGORITHMS
*/

t_cmd	*divide_and_conquer(t_stack stack);
t_cmd	*merge_sort(t_stack stack);
t_cmd	*reverse_sort_swap(t_stack stack, int8_t stack_choice);
t_cmd	*run_algorithm(t_stack stack);
t_cmd	*selection_sort(t_stack stack);
t_cmd	*sort_small(t_stack stack);
t_cmd	*sort_three(t_stack stack);
t_cmd	*sort_swap(t_stack stacki, int8_t stack_choice);

/*
** INSTRUCTIONS
*/

t_cmd	*optimise_instructions(t_cmd *cmds_a, t_cmd *cmds_b);

#endif
