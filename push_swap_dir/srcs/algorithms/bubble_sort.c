/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 19:08:38 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/13 20:03:07 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cmd	*bubble_sort(t_stack *stack, int8_t stack_choice)
{
	t_cmd	*cmds;
	t_lst	*scan;
	int32_t	position;

	if (!(cmds = init_instructions()))
		return (NULL);
	if (stack_choice == STACK_A)
		stack->smallest = return_smallest_element(stack->head_a);
	else
		stack->smallest = return_smallest_element(stack->head_b);
	while ((position = is_sorted(*stack, stack_choice)) == ERROR)
	{
		if (stack_choice == STACK_A)
			scan = stack->head_a;
		else
			scan = stack->head_b;
		if (scan->next->element == stack->smallest
				|| scan->element < scan->next->element)
			add_and_exec_cmd(RA, cmds, stack);
		else
			add_and_exec_cmd(SA, cmds, stack);
	}
	rotate_to_first(cmds, stack, stack_choice);
	return (cmds);
}
