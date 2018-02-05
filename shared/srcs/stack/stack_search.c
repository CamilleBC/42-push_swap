/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:35:57 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/05 10:13:50 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_manipulations.h"

int32_t	find_closest_swap_down(t_stack stack, int8_t *swap)
{
	t_lst	*scan;
	int32_t	position;

	position = 1;
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

	position = stack.elements_a;
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
	// ft_print("closest down: %d\n closest up: %d\n", closest_down, closest_up);
	if (swap_down == NOSWAP || closest_down > closest_up)
		return (closest_up);
	else if (swap_up == NOSWAP || closest_down <= closest_up)
		return (closest_down);
	return (0);
}

int32_t	find_smallest(t_lst *stack_lst, int32_t element)
{
	// if the element we want to place is smaller than the smallest we return
	// the position, else NOT FOUND
	t_lst	*scan;
	int32_t	elements;
	int32_t	position;
	int32_t	smallest;

	scan = stack_lst;
	smallest = scan->element;
	elements = 0;
	while (scan)
	{
		smallest = ft_min((intmax_t)smallest, (intmax_t)scan->element);
		scan = scan->next;
		++elements;
	}
	if (element > smallest)
		return (NOT_FOUND);
	scan = stack_lst;
	position = 1;
	while (scan && scan->element != smallest)
	{
		scan = scan->next;
		++position;
	}
	if (position >= elements)
		return (NOT_FOUND);
	return (position);
}

int32_t	find_biggest(t_lst *stack_lst, int32_t element)
{
	// if the element we want to place is bigger than the biggest we return
	// the position, else NOT FOUND
	t_lst	*scan;
	int32_t	biggest;
	int32_t	elements;
	int32_t	position;

	scan = stack_lst;
	biggest = scan->element;
	elements = 0;
	while (scan)
	{
		biggest = ft_max((intmax_t)biggest, (intmax_t)scan->element);
		scan = scan->next;
		++elements;
	}
	if (element < biggest)
		return (NOT_FOUND);
	scan = stack_lst;
	position = 1;
	while (scan && scan->element != biggest)
	{
		scan = scan->next;
		++position;
	}
	if (position >= elements)
		return (NOT_FOUND);
	return (position + 1);
}

int32_t	find_bigger_element(t_lst *stack_lst, int32_t element)
{
	t_lst	*scan;
	int32_t	position;
	int32_t	closest;

	scan = stack_lst;
	closest = INT32_MAX;
	while (scan)
	{
		if (scan->element > element)
			closest = ft_min((intmax_t)closest, (intmax_t)scan->element);
		scan = scan->next;
	}
	scan = stack_lst;
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

int32_t	find_element(t_lst *stack_lst, int32_t element)
{
	t_lst	*scan;
	int32_t	position;

	scan = stack_lst;
	position = 1;
	while (scan)
	{
		if (scan->element == element)
			return (position);
		scan = scan->next;
		++position;
	}
	return (NOT_FOUND);
}
