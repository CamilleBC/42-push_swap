/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 09:24:06 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/05 10:24:44 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int32_t	find_element_and_push_back(t_cmd *cmds, t_stack *stack)
{
	int32_t	position;

	position = find_bigger_element(stack->head_a, stack->head_b->element);
	//debug
	// ft_print("*******************\n");
	// ft_print("STACK BEFORE INSERT\n");
	// print_stack(*stack);
	// ft_print("position: %d\n", (int64_t)position);
	if (position == NOT_FOUND)
	{
		if ((position = find_biggest(stack->head_a, stack->head_b->element))
				== NOT_FOUND)
			position = find_smallest(stack->head_a, stack->head_b->element);
	}
	// ft_print("position small/big: %d\n", (int64_t)position);
	if (position != NOT_FOUND)
		rotate_a_to_position(cmds, stack, position, EXEC);
	if (add_and_exec_cmd(PA, cmds, stack) == ERROR)
		return (ERROR);
	//debug
	// ft_print("STACK AFTER INSERT\n");
	// print_stack(*stack);
	// ft_print("*******************\n");
	return (SUCCESS);
}

static int32_t	push_until_three_in_a(t_cmd *cmds, t_stack *stack)
{
	while (stack->elements_a > 3)
		if (add_and_exec_cmd(PB, cmds, stack) == ERROR)
			return (ERROR);
	return (SUCCESS);
}

static int32_t	sort_3(t_cmd *cmds, t_stack *stack)
{
	if (is_sorted(*stack) == SUCCESS)
		return (SUCCESS);
	if ((stack->head_a->element > stack->head_a->next->element)
		&& (stack->head_a->next->next->element > stack->head_a->element))
		if (add_and_exec_cmd(RA, cmds, stack) == ERROR)
			return (ERROR);
	if (stack->head_a->element > stack->head_a->next->element)
		if (add_and_exec_cmd(SA, cmds, stack) == ERROR)
			return (ERROR);
	if (stack->head_a->next->element > stack->head_a->next->next->element)
		if (add_and_exec_cmd(RRA, cmds, stack) == ERROR)
			return (ERROR);
	if (stack->head_a->element > stack->head_a->next->element)
		if (add_and_exec_cmd(SA, cmds, stack) == ERROR)
			return (ERROR);
	return (SUCCESS);
}

t_cmd	*sort_small(t_stack stack)
{
	t_cmd	*cmds;

	if (!(cmds = init_instructions()))
		return (NULL);
	if (push_until_three_in_a(cmds, &stack) == ERROR)
		return (NULL);
	if (sort_3(cmds, &stack) == ERROR)
		return (NULL);
	//debug
	// ft_print("sort 3:\n");
	// print_stack(stack);
	while (stack.elements_b > 0)
		if (find_element_and_push_back(cmds, &stack) == ERROR)
			return (NULL);
	rotate_a_to_first(cmds, &stack, EXEC);
	//debug
	// ft_print("SMALL SORT:\n");
	// print_stack(stack);
	// print_instructions(BOTH, *cmds);
	return (cmds);
}
