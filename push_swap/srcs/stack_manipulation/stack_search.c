/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:35:57 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/29 21:16:43 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int32_t	find_closest_from_bottom(t_stack stack, int32_t b_element)
{
	int32_t	position;
	t_lst	*scan;

	position = -1;
	scan = stack.tail;
	while (scan != NULL && scan->prev != NULL)
			// && scan->prev->element != 1)
	{
		//debug
		// ft_print("bottom element: %d\n", scan->element);
		// ft_print("stack_b element: %d\n", (int64_t)b_element);
		if (scan->prev->element > scan->element)
			return (position - 1);
		else if (scan->element == b_element - 1)
			return (position - 1);
		scan = scan->prev;
		--position;
	}
	//debug
	// if (b_element != -42)
		// sleep(5);
	return (0);
}

int32_t	find_closest_from_top(t_stack stack, int32_t b_element)
{
	int32_t	position;
	t_lst	*scan;

	position = 0;
	scan = stack.head;
	while (scan != NULL && scan->next != NULL
				&& scan->next->element != stack.elements)
	{
		//debug
		// ft_print("top element: %d\n", scan->element);
		// ft_print("stack_b element: %d\n", (int64_t)b_element);
		if (scan->element > scan->next->element)
			return (position);
		else if (scan->next->element == b_element - 1)
			return (position + 1);
		scan = scan->next;
		++position;
	}
	//debug
	// if (b_element != -42)
		// sleep(5);
	return (0);
}

int32_t	find_closest(t_stack stack, int32_t b_element)
{
	int32_t	closest_top;
	int32_t	closest_bottom;

	closest_top = find_closest_from_top(stack, b_element);
	closest_bottom = find_closest_from_bottom(stack, b_element);
	//debug
	ft_print("************\n");
	ft_print("Closest TOP: %d\n", (int64_t)closest_top);
	ft_print("Closest BOTTOM: %d\n", (int64_t)closest_bottom);
	if ((uint32_t)closest_top > ft_abs32(closest_bottom))
		return (closest_bottom);
	else
		return (closest_top);
}

int32_t	search_next_element(t_stack stack, int32_t element)
{
	t_lst	*scan;
	int32_t	i;

	scan = stack.head;
	i = 0;
	while (scan != NULL && scan->element != element)
	{
		scan = scan->next;
		++i;
	}
	if (i > stack.elements / 2)
		i = stack.elements - i;
	return (i);
}
