/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 21:00:59 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/29 21:02:56 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int32_t	is_partially_sorted(t_stack stack)
{
	int32_t	i;
	int32_t	occurence;
	t_lst	*scan;

	scan = stack.head;
	i = 1;
	occurence = 0;
	while (scan != NULL && scan->next != NULL)
	{
		if (scan->element > scan->next->element)
		{
			++occurence;
			break;
		}
		i++;
		scan = scan->next;
	}
	if (scan != NULL && scan->next != NULL)
		scan = scan->next;
	while (scan != NULL && scan->next != NULL)
	{
		if (scan->element > scan->next->element)
			++occurence;
		scan = scan->next;
	}
	if (occurence > 1)
		return (ERROR);
	if (i == stack.elements)
		return (SUCCESS);
	return (i);
}

int32_t	is_sorted(t_stack stack)
{
	int32_t	i;
	t_lst	*scan;

	scan = stack.head;
	i = 1;
	while (scan != NULL && scan->next != NULL && scan->next->element != 1)
	{
		if (scan->element > scan->next->element)
			return (ERROR);
		i++;
		scan = scan->next;
	}
	if (scan != NULL && scan->next != NULL && scan->next->element == 1)
		scan = scan->next;
	while (scan != NULL && scan->next != NULL)
	{
		if (scan->element > scan->next->element)
			return (ERROR);
		scan = scan->next;
	}
	if (i == stack.elements)
		return (SUCCESS);
	return (i);
}
