/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utilities.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:22:01 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/13 15:06:59 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_UTILITIES_H
# define STACK_UTILITIES_H

# include "stack.h"
# include "instructions.h"

t_stack	*copy_stack(t_stack stack);
void	convert_stack(t_stack *stack);
t_stack	*create_copy(t_stack *cpy, t_stack to_cpy);
int32_t	is_rev_sorted(t_stack stack, int8_t stack_choice);
int32_t	is_sorted(t_stack stack, int8_t stack_choice);

/*
** SEARCH POSITION
*/

int32_t	find_biggest(t_lst *stack_lst, int32_t element);
int32_t	find_closest_rev_swap(t_stack stack, int8_t stack_choice);
int32_t	find_closest_swap(t_stack stack, int8_t stack_choice);
int32_t	find_element(t_lst *stack_lst, int32_t element);
int32_t	find_bigger_element(t_lst *stack_lst, int32_t element);
int32_t	find_smallest(t_lst *stack_lst, int32_t element);

/*
** SEARCH VALUES
*/

int32_t	return_biggest_element(t_lst *stack_lst);
int32_t	return_smallest_element(t_lst *stack_lst);
t_lst	*return_stack_head(t_stack stack, int8_t stack_choice);

/*
** ROTATION
*/

int32_t	rotate_to_first(t_cmd *cmds, t_stack *stack, int8_t choice);
int32_t	rotate_to_last(t_cmd *cmds, t_stack *stack, int8_t choice);
int32_t	rotate_to_position(t_cmd *cmds, t_stack *stack, int32_t position,
								int8_t choice);

#endif
