/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_closest_rev_swap.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:34:06 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/08 16:46:32 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_manipulations.h"

int32_t	init_swap_up_values(t_lst **tail, t_lst **head, t_stack stack,
								int8_t choice)
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

int32_t	find_closest_rev_swap_down(t_stack stack, int8_t *swap, int8_t choice)
{
	t_lst	*scan;
	int32_t	position;

	position = 1;
	*swap = NOSWAP;
	if (choice == STACK_A)
		scan = stack.head_a;
	else
		scan = stack.head_b;
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
		{
			*swap = SWAP;
			return (position);
		}
		scan = scan->next;
		++position;
	}
	return (0);
}

int32_t	find_closest_rev_swap_up(t_stack stack, int8_t *swap, int8_t choice)
{
	t_lst	*scan;
	t_lst	*head;
	int32_t	position;

	*swap = NOSWAP;
	position = init_swap_up_values(&scan, &head, stack, choice);
	if (scan->element < head->element && scan->element != stack.smallest)
		return (position);
	while ((scan != NULL && scan->prev != NULL)
			&& (scan->element < scan->prev->element))
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
		{
			*swap = SWAP;
			return (position - 1);
		}
		scan = scan->prev;
		--position;
	}
	return (0);
}

int32_t	find_closest_rev_swap(t_stack stack, int8_t choice)
{
	int32_t	closest_down;
	int32_t	closest_up;
	int8_t	swap_down;
	int8_t	swap_up;
	int32_t	elements;

	closest_down = find_closest_rev_swap_down(stack, &swap_down, choice);
	closest_up = find_closest_rev_swap_up(stack, &swap_up, choice);
	elements = (choice == STACK_A) ? stack.elements_a : stack.elements_b;
	if (swap_down == NOSWAP || closest_down > (elements - closest_up + 1))
		return (closest_up);
	else if (swap_up == NOSWAP || closest_down <= (elements - closest_up + 1))
		return (closest_down);
	return (0);
}
