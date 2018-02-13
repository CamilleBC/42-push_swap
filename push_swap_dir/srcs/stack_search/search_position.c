/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:45:00 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/13 16:08:34 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utilities.h"

static void	init_find_values(t_lst **scan, t_lst *stack_lst, int32_t *save,
								int32_t *elements)
{
	*scan = stack_lst;
	*save = (*scan)->element;
	*elements = 0;
}

int32_t		find_smallest(t_lst *stack_lst, int32_t element)
{
	t_lst	*scan;
	int32_t	elements;
	int32_t	position;
	int32_t	smallest;

	init_find_values(&scan, stack_lst, &smallest, &elements);
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

int32_t		find_biggest(t_lst *stack_lst, int32_t element)
{
	t_lst	*scan;
	int32_t	biggest;
	int32_t	elements;
	int32_t	position;

	init_find_values(&scan, stack_lst, &biggest, &elements);
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

int32_t		find_bigger_element(t_lst *stack_lst, int32_t element)
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

int32_t		find_element(t_lst *stack_lst, int32_t element)
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
