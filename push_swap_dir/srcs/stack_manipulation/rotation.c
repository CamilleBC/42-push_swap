/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:34:59 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/13 14:52:28 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utilities.h"

int32_t	rotate_to_first(t_cmd *cmds, t_stack *stack, int8_t choice)
{
	int32_t	position;

	if (choice == STACK_A)
		stack->smallest = return_smallest_element(stack->head_a);
	else
		stack->smallest = return_smallest_element(stack->head_b);
	if ((position = is_sorted(*stack, STACK_A)) != ERROR)
		rotate_to_position(cmds, stack, position, choice);
	return (SUCCESS);
}

int32_t	rotate_to_last(t_cmd *cmds, t_stack *stack, int8_t choice)
{
	int32_t	position;

	if (choice == STACK_A)
		stack->biggest = return_biggest_element(stack->head_a);
	else
		stack->biggest = return_biggest_element(stack->head_b);
	if ((position = is_rev_sorted(*stack, choice)) != ERROR)
		rotate_to_position(cmds, stack, position, choice);
	return (SUCCESS);
}

int32_t	rotate_to_position(t_cmd *cmds, t_stack *stack, int32_t position,
								int8_t choice)
{
	int32_t	elements;

	elements = (choice == STACK_A) ? stack->elements_a : stack->elements_b;
	if (position > (elements / 2))
	{
		while (position++ <= elements)
		{
			if (choice == STACK_A)
				add_and_exec_cmd(RRA, cmds, stack);
			else
				add_and_exec_cmd(RRB, cmds, stack);
		}
	}
	else
	{
		while (position-- > 1)
		{
			if (choice == STACK_A)
				add_and_exec_cmd(RA, cmds, stack);
			else
				add_and_exec_cmd(RB, cmds, stack);
		}
	}
	return (SUCCESS);
}
