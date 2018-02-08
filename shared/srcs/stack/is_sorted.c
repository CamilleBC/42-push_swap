/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 14:37:53 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/08 17:54:14 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_manipulations.h"

int32_t	is_rev_sorted(t_stack stack, int8_t stack_choice)
{
	t_lst	*scan;
	int32_t	last;

	if (stack_choice == STACK_A && stack.head_a)
		scan = stack.head_a;
	else if (stack_choice == STACK_B && stack.head_b)
		scan = stack.head_b;
	else
		return (ERROR);
	last = return_biggest_element(scan);
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
	if (stack_choice == STACK_A && stack.head_a)
		scan = stack.head_a;
	else if (stack_choice == STACK_B && stack.head_b)
		scan = stack.head_b;
	return (find_element(scan, last));
}

int32_t	is_sorted(t_stack stack, int8_t stack_choice)
{
	t_lst	*scan;

	if (stack_choice == STACK_A && stack.head_a)
		scan = stack.head_a;
	else if (stack_choice == STACK_B && stack.head_b)
		scan = stack.head_b;
	else
		return (ERROR);
	while (scan && scan->next && scan->next->element != stack.smallest)
	{
		if (scan->next->element != scan->element + 1)
			return (ERROR);
		scan = scan->next;
	}
	if (!scan->next)
		return (SUCCESS);
	if (scan && scan->next && scan->next->element == stack.smallest)
		scan = scan->next;
	while (scan && scan->next)
	{
		if (scan->next->element != scan->element + 1)
			return (ERROR);
		scan = scan->next;
	}
	return (find_element(stack.head_a, stack.smallest));
}

int32_t	is_sorted_checker(t_stack stack)
{
	t_lst	*scan;

	if (stack.head_b || !stack.head_a)
		return (ERROR);
	scan = stack.head_a;
	while (scan != NULL && scan->next != NULL)
	{
		if (scan->element > scan->next->element)
			return (ERROR);
		scan = scan->next;
	}
	return (SUCCESS);
}
