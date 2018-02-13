/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:43:47 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/13 14:50:47 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utilities.h"

int32_t	return_biggest_element(t_lst *stack_lst)
{
	t_lst	*scan;
	int32_t	biggest;

	biggest = 0;
	scan = stack_lst;
	while (scan)
	{
		if (scan->element > biggest)
			biggest = ft_max(biggest, scan->element);
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
