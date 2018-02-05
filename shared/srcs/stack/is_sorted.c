/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 14:37:53 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/05 08:55:16 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_manipulations.h"

int32_t	is_sorted(t_stack stack)
{
	t_lst	*scan;

	if (stack.head_b || !stack.head_a)
		return (ERROR);
	scan = stack.head_a;
	while (scan != NULL && scan->next != NULL && scan->next->element != 1)
	{
		if (scan->next->element != scan->element + 1)
			return (ERROR);
		scan = scan->next;
	}
	if (!scan->next)
		return (SUCCESS);
	if (scan != NULL && scan->next != NULL && scan->next->element == 1)
		scan = scan->next;
	while (scan != NULL && scan->next != NULL)
	{
		if (scan->next->element != scan->element + 1)
			return (ERROR);
		scan = scan->next;
	}
	return (find_element(stack.head_a, 1));
}

int32_t	is_sorted_checker(t_stack stack)
{
	t_lst	*scan;

	if (stack.head_b || !stack.head_a)
		return (ERROR);
	scan = stack.head_a;
	while (scan != NULL && scan->next != NULL && scan->next->element != 1)
	{
		if (scan->element > scan->next->element)
			return (ERROR);
		scan = scan->next;
	}
	return (SUCCESS);
}
