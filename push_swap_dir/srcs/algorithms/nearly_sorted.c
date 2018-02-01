/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearly_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:29:49 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/31 11:41:31 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int32_t	get_max_interval(t_stack stack)
{
	t_lst	*scan;
	int32_t	interval;

	interval = 0;
	scan = stack.head_a;
	while (scan != NULL && scan->next != NULL)
	{
		if ((scan->element - scan->next->element) > 1)
			return (scan->element - scan->next->element);
		interval = ft_max(interval, (scan->element - scan->next->element));
		scan = scan->next;
	}
	return (interval);
}

int32_t			swap_closest(t_stack stack, t_cmd *cmds)
{
	int32_t	closest;

	closest = find_closest(stack, -42);
	if (closest_top == FAILURE)
		return (FAILURE);
	if (closest_top > closest_bottom)
	{
		while (--closest_bottom)
			add_cmd(RRA, cmds);
		add_cmd(SA, cmds);
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

t_cmd	*nearly_sorted(t_stack stack)
{
	t_cmd	*instr;
	int32_t	value;
	int32_t	position;

	if (stack.head_a->next == NULL || (instr = init_instructions()) == NULL)
		return (NULL);
	if ((position = is_sorted(stack)) != ERROR)
	{
		rotate_a_to_position(instr, &stack);
		return (instr);
	}
	if (get_max_interval(stack) > 1)
		return (NULL);
	while (swap_closest(stack, instr) != FAILURE)
		;
	if ((position = is_sorted(stack)) != ERROR)
	{
		rotate_a_to_position(instr, &stack);
		return (instr);
	}
	return (NULL);
}
