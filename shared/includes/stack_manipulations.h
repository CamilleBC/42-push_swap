/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulations.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 08:30:13 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/12 16:20:56 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_MANIPULATIONS_H
# define STACK_MANIPULATIONS_H

# include "instructions.h"
# include "stack.h"

# define NOT_FOUND		(int8_t)-1
# define NOSWAP			(int8_t)0
# define SWAP			(int8_t)1

/*
** STACK CHECKS
*/

int32_t	is_rev_sorted(t_stack stack, int8_t stack_choice);
int32_t	is_sorted(t_stack stack, int8_t stack_choice);
int32_t	is_sorted_checker(t_stack stack);

/*
** STACK SEARCH
*/

int32_t	find_biggest(t_lst *stack_lst, int32_t element);
int32_t	find_closest_rev_swap(t_stack stack, int8_t stack_choice);
int32_t	find_closest_swap(t_stack stack, int8_t stack_choice);
int32_t	find_element(t_lst *stack_lst, int32_t element);
int32_t	find_bigger_element(t_lst *stack_lst, int32_t element);
int32_t	find_smallest(t_lst *stack_lst, int32_t element);
int32_t	return_biggest_element(t_lst *stack_lst);
int32_t	return_smallest_element(t_lst *stack_lst);

/*
** STACK MOVE
*/

int32_t	rotate_to_last(t_cmd *cmds, t_stack *stack, int32_t execute,
						int8_t choice);
int32_t	rotate_to_position(t_cmd *cmds, t_stack *stack, int32_t position,
								int8_t choice);
int32_t	rotate_a_to_first(t_cmd *cmds, t_stack *stack, int32_t execute);
int32_t	rotate_a_to_position(t_cmd *cmds, t_stack *stack, int32_t position,
								int32_t execute);
int32_t	rotate_b_to_position(t_cmd *cmds, t_stack *stack, int32_t position,
								int32_t execute);

#endif
