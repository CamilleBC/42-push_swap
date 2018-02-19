/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 14:37:53 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/19 08:24:15 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utilities.h"

int32_t			is_rev_sorted(t_stack stack, int8_t stack_choice)
{
	t_lst	*scan;
	int32_t	last;

	if ((scan = return_stack_head(stack, stack_choice)) == NULL)
		return (ERROR);
	last = stack.biggest;
	while (scan != NULL && scan->next != NULL && scan->next->element != last)
	{
		if (scan->next->element != scan->element - 1)
			return (ERROR);
		scan = scan->next;
	}
	if (!scan->next)
		return (SUCCESS);
	if (scan != NULL && scan->next != NULL && scan->next->element == last)
		scan = scan->next;
	while (scan != NULL && scan->next != NULL)
	{
		if (scan->next->element != scan->element - 1)
			return (ERROR);
		scan = scan->next;
	}
	if ((scan = return_stack_head(stack, stack_choice)) == NULL)
		return (ERROR);
	return (find_element(scan, last));
}

int32_t			is_sorted(t_stack stack, int8_t stack_choice)
{
	t_lst	*scan;

	if ((scan = return_stack_head(stack, stack_choice)) == NULL)
		return (ERROR);
	while (scan && scan->next && scan->next->element != stack.smallest)
	{
		if (scan->next->element != scan->element + 1)
			return (ERROR);
		scan = scan->next;
	}
	if (!scan->next)
		return (1);
	if (scan && scan->next && scan->next->element == stack.smallest)
		scan = scan->next;
	while (scan && scan->next)
	{
		if (scan->next->element != scan->element + 1)
			return (ERROR);
		scan = scan->next;
	}
	if ((scan = return_stack_head(stack, stack_choice)) == NULL)
		return (ERROR);
	return (find_element(scan, stack.smallest));
}
