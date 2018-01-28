/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:37:55 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/28 19:47:41 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "shared.h"
# include "instructions.h"
# include "print.h"
# include "stack.h"

# define FOUND			(int32_t)1
# define SORTED			(int32_t)0
# define NB_ALGOS		(int8_t)8
# define BEST			(int8_t)0
# define SORT_THREE		(int8_t)2
# define NEARLY_SORTED	(int8_t)2
# define INSERTION		(int8_t)3

//STACK_MANIPULATION
void	convert_stack(t_stack *stack);
t_cmd	*insertion_sort(t_stack stack_a, t_stack stack_b);
int32_t	rotate_a_to_position(t_cmd *cmds, t_stack *stack);

//ALGORITHMS
t_cmd	*nearly_sorted(t_stack stack_a, t_stack stack_b);
t_cmd	*run_algorithm(int8_t choice, t_stack stack_a, t_stack stack_b);
t_cmd	*select_algorithm(t_cmd **cmds_array, int32_t size_cmds_array);
t_cmd	*sort_three(t_stack stack_a, t_stack stack_b);

//INSTRUCTIONS
void		optimise_instructions(t_cmd *cmds);

#endif
