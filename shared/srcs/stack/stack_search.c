/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:35:57 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/11 17:12:13 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_manipulations.h"

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

int32_t	return_biggest_element(t_lst *stack_lst)
{
	t_lst	*scan;
	int32_t	biggest;

	biggest= 0;
	scan = stack_lst;
	while (scan)
	{
		if (scan->element > biggest)
			biggest= ft_max(biggest, scan->element);
		scan = scan->next;
	}
	return (biggest);
}

int32_t	return_smallest_element(t_lst *stack_lst)
{
	t_lst	*scan;
	int32_t	smallest_element;

	smallest_element = INT32_MAX;
	scan = stack_lst;
	while (scan)
	{
		if (scan->element < smallest_element)
			smallest_element = ft_min(smallest_element, scan->element);
		scan = scan->next;
	}
	return (smallest_element);
}
