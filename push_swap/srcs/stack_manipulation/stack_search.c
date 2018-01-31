/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:35:57 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/31 20:24:24 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int32_t	find_closest_swap_down(t_stack stack, int8_t *swap)
{
	t_lst	*scan;
	int32_t	position;

	position = 0;
	*swap = NOSWAP;
	scan = stack.head_a;
	while ((scan != NULL && scan->next != NULL)
			&& (scan->next->element > scan->element))
	{
		scan = scan->next;
		++position;
	}
	if (scan->next->element == 1)
	{
		++position;
		scan = scan->next;
	}
	while (scan != NULL && scan->next != NULL)
	{
		if (scan->element > scan->next->element)
		{
			*swap = SWAP;
			return (position);
		}
		scan = scan->next;
		++position;
	}
	return (0);
}

int32_t	find_closest_swap_up(t_stack stack, int8_t *swap)
{
	t_lst	*scan;
	int32_t	position;

	position = -1;
	*swap = NOSWAP;
	scan = stack.tail_a;
	if (scan->element > stack.head_a->element)
		return (position);
	while ((scan != NULL && scan->prev != NULL)
			&& (scan->prev->element < scan->element))
	{
		scan = scan->prev;
		--position;
	}
	if (scan->prev->element && scan->prev->element == stack.elements_a)
	{
		--position;
		scan = scan->prev;
	}
	while (scan != NULL && scan->prev != NULL)
	{
		if (scan->prev->element < scan->element)
		{
			*swap = SWAP;
			return (position);
		}
		scan = scan->prev;
		--position;
	}
	return (0);
}

int32_t	find_closest_swap_a(t_stack stack)
{
	int32_t	closest_down;
	int32_t	closest_up;
	int8_t	swap_down;
	int8_t	swap_up;

	closest_down = find_closest_swap_down(stack, &swap_down);
	closest_up = find_closest_swap_up(stack, &swap_up);
	if (swap_down == NOSWAP || (uint32_t)closest_down > ft_abs32(closest_up))
		return (closest_up);
	else if (swap_up == NOSWAP || (uint32_t)closest_down < ft_abs32(closest_up))
		return (closest_down);
	return (0);
}

int32_t	find_smallest_a(t_stack stack, int32_t element)
{
	// if the element we want to place is smaller than the smallest we return
	// the position, else NOT FOUND
	t_lst	*scan;
	int32_t	position;
	int32_t	smallest;

	scan = stack.head_a;
	smallest = scan->element;
	while (scan)
	{
		smallest = ft_min((intmax_t)smallest, (intmax_t)scan->element);
		scan = scan->next;
	}
	if (element > smallest)
		return (NOT_FOUND);
	scan = stack.head_a;
	position = 1;
	while (scan && scan->element != smallest)
	{
		scan = scan->next;
		++position;
	}
	return (position);
}

int32_t	find_biggest_a(t_stack stack, int32_t element)
{
	// if the element we want to place is smaller than the smallest we return
	// the position, else NOT FOUND
}

int32_t	find_element_a(t_stack stack, int32_t element)
{
	t_lst	*scan;
	int32_t	position;
	int32_t	closest;

	scan = stack.head_a;
	closest = 0;
	while (scan)
	{
		if (scan->element < element)
			closest = ft_max((intmax_t)closest, (intmax_t)scan->element);
		scan = scan->next;
	}
	scan = stack.head_a;
	position = 1;
	while (scan && scan->element != closest)
	{
		scan = scan->next;
		++position;
	}
	if (!scan)
		return (NOT_FOUND);
	return (position);
}

// we keep track of the smallest and biggest elements in the stack
// if the element we want to place is smaller than the smallest or bigger than
// the biggest, we return that position.
