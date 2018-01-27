/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearly_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:29:49 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/26 18:20:58 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int32_t	find_closest_from_bottom(t_stack stack)
{
	int32_t	position;
	t_lst	*scan;

	position = 1;
	scan = stack.tail;
	while (scan != NULL && scan->prev != NULL)
	{
		if (scan->prev->element > scan->element
				&& (scan->prev->element - scan->element == 1))
			return (position + 1);
		scan = scan->next;
		++position;
	}
	return (FAILURE);
}

static int32_t	find_closest_from_top(t_stack stack)
{
	int32_t	position;
	t_lst	*scan;

	position = 1;
	scan = stack.head;
	while (scan != NULL && scan->next != NULL)
	{
		if (scan->element > scan->next->element
				&&(scan->element - scan->next->element == 1))
			return (position);
		scan = scan->next;
		++position;
	}
	return (FAILURE);
}

static int32_t	get_max_interval(t_stack stack_a)
{
	t_lst	*scan;
	int32_t	interval;

	interval = 0;
	scan = stack_a.head;
	while (scan != NULL && scan->next != NULL)
	{
		if ((scan->element - scan->next->element) > 1)
			return (scan->element - scan->next->element);
		if ((scan->element - scan->next->element) == 1)

		interval = ft_max(interval, (scan->element - scan->next->element));
		scan = scan->next;
	}
	return (interval);
}

int32_t			swap_closest(t_stack *stack, t_cmd *cmds)
{
	int32_t	closest_top;
	int32_t	closest_bottom;

	closest_top = find_closest_from_top(*stack);
	closest_bottom = find_closest_from_bottom(*stack);
	if (closest_top == FAILURE)
		return (FAILURE);
	if (closest_top > closest_bottom)
	{
		while (--closest_bottom)
			add_instructions(RRA, cmds, stack, NULL);
		add_instructions(SA, cmds, stack, NULL);
	}
	else
	{
		while (--closest_top)
			add_instructions(RA, cmds, stack, NULL);
		add_instructions(SA, cmds, stack, NULL);
	}
	return (SUCCESS);
}

/*
** We pass over the array and check if the max interval between two numbers
** is at maximum 1 (1 3 5-4 is OK, 1 5-4-3 is OK, 1 5--3 4 is KO)
** If no interval is over 1, we need to get the position of the one furthest
** from the top, while still being less than the middle element.
** If we only have switches to do in the top and bottom 25% of the stack, we
** first rotate and switch for the 25% top, and then rev_rotate for the
** 25% bottom.
*/

t_cmd	*nearly_sorted(t_stack stack_a, t_stack stack_b)
{
	t_cmd	*instr;
	t_lst	*copy;
	int32_t	value;

	copy = copy_list(stack_a.head);
	if (stack_a.head->next == NULL || (instr = init_instructions()) == NULL)
		return (NULL);
	if (get_max_interval(stack_a) > 1)
		return (NULL);
	while (swap_closest(&stack_a, instr) != FAILURE)
		;
	if (stack_a.head->element > (stack_a.elements / 2))
		while (stack_a.head->element != 1)
			add_instructions(RRA, instr, &stack_a, &stack_b);
	else
		while (stack_a.head->element != 1)
			add_instructions(RA, instr, &stack_a, &stack_b);
	return (NULL);
}
