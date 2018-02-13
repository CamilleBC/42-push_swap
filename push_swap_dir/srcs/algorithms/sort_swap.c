/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:35:28 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/13 20:27:38 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cmd	*sort_swap(t_stack *stack, int8_t stack_choice)
{
	t_cmd	*cmds;
	int32_t	position;
	int32_t	command;

	if (!(cmds = init_instructions()))
		return (NULL);
	if (stack_choice == STACK_A)
	{
		stack->smallest = return_smallest_element(stack->head_a);
		stack->biggest = return_biggest_element(stack->head_a);
		command = SA;
	}
	else
	{
		stack->smallest = return_smallest_element(stack->head_b);
		stack->biggest = return_biggest_element(stack->head_b);
		command = SB;
	}
	while ((position = is_sorted(*stack, stack_choice)) == ERROR)
	{
		position = find_closest_swap(*stack, stack_choice);
		rotate_to_position(cmds, stack, position, stack_choice);
		add_and_exec_cmd(command, cmds, stack);
	}
	rotate_to_first(cmds, stack, stack_choice);
	return (cmds);
}

t_cmd	*reverse_sort_swap(t_stack *stack, int8_t stack_choice)
{
	t_cmd	*cmds;
	int32_t	position;
	int32_t	command;

	if (!(cmds = init_instructions()))
		return (NULL);
	if (stack_choice == STACK_A)
	{
		stack->smallest = return_smallest_element(stack->head_a);
		stack->biggest = return_biggest_element(stack->head_a);
		command = SA;
	}
	else
	{
		stack->smallest = return_smallest_element(stack->head_b);
		stack->biggest = return_biggest_element(stack->head_b);
		command = SB;
	}
	while ((position = is_rev_sorted(*stack, stack_choice)) == ERROR)
	{
		position = find_closest_rev_swap(*stack, stack_choice);
		rotate_to_position(cmds, stack, position, stack_choice);
		add_and_exec_cmd(command, cmds, stack);
	}
	rotate_to_last(cmds, stack, stack_choice);
	return (cmds);
}
