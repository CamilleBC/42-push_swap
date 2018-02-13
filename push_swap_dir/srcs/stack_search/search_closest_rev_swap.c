/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_closest_rev_swap.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:34:06 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/13 14:52:30 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utilities.h"

static int32_t	init_rev_swap_up_values(t_lst **tail, t_lst **head,
										t_stack stack, int8_t choice)
{
	if (choice == STACK_A)
	{
		*tail = (t_lst*)stack.tail_a;
		*head = (t_lst*)stack.head_a;
		return (stack.elements_a);
	}
	else
	{
		*tail = (t_lst*)stack.tail_b;
		*head = (t_lst*)stack.head_b;
		return (stack.elements_b);
	}
}

static int32_t	find_closest_rev_swap_down(t_stack stack, int8_t choice)
{
	t_lst	*scan;
	int32_t	position;

	position = 1;
	if ((scan = return_stack_head(stack, choice)) == NULL)
		return (0);
	while ((scan != NULL && scan->next != NULL)
			&& (scan->element > scan->next->element))
	{
		scan = scan->next;
		++position;
	}
	if (scan->next->element == stack.biggest)
	{
		++position;
		scan = scan->next;
	}
	while (scan != NULL && scan->next != NULL)
	{
		if (scan->element < scan->next->element)
			return (position);
		scan = scan->next;
		++position;
	}
	return (0);
}

static int32_t	find_closest_rev_swap_up(t_stack stack, int8_t choice)
{
	t_lst	*scan;
	t_lst	*head;
	int32_t	position;

	position = init_rev_swap_up_values(&scan, &head, stack, choice);
	if (scan->element < head->element && scan->element != stack.smallest)
		return (position);
	while ((scan && scan->prev) && (scan->element < scan->prev->element))
	{
		scan = scan->prev;
		--position;
	}
	if (scan->prev && scan->prev->element == stack.biggest)
	{
		--position;
		scan = scan->prev;
	}
	while (scan != NULL && scan->prev != NULL)
	{
		if (scan->element > scan->prev->element)
			return (position - 1);
		scan = scan->prev;
		--position;
	}
	return (0);
}

int32_t			find_closest_rev_swap(t_stack stack, int8_t choice)
{
	int32_t	closest_down;
	int32_t	closest_up;
	int32_t	elements;

	closest_down = find_closest_rev_swap_down(stack, choice);
	closest_up = find_closest_rev_swap_up(stack, choice);
	elements = (choice == STACK_A) ? stack.elements_a : stack.elements_b;
	if (!closest_down || closest_down > (elements - closest_up + 1))
		return (closest_up);
	else if (!closest_up || closest_down <= (elements - closest_up + 1))
		return (closest_down);
	return (0);
}
