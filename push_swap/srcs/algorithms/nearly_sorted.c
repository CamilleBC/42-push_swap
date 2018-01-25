/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearly_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:29:49 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/25 17:26:43 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int32_t	get_max_interval(t_stack stack_a)
{
	t_lst	*scan;
	int32_t	interval;

	interval = 0;
	scan = stack_a.head;
	while (scan != NULL && scan->next != NULL)
	{
		if ((scan->element - scan->next->element) > 1)
			return (scan->element - scan->next->element);
		interval = ft_max(interval, (scan->element - scan->next->element));
		scan = scan->next;
	}
	return (interval);
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
	int32_t	interval;

	if (stack_a.head->next == NULL || (instr = init_instructions()) == NULL)
		return (NULL);
	interval = get_max_interval(stack_a);
	ft_print("Max Interval is: %d", interval);
	return (NULL);
}
