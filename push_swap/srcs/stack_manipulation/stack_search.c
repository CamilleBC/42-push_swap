/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:35:57 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/30 16:56:03 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int32_t	find_closest_swap_up(t_lst *tail)
{
	int32_t	position;
	t_lst	*scan_up;

	position = -1;
	scan_up = tail;
	while (scan_up != NULL && scan_up->prev != NULL)
			// && scan->prev->element != 1)
	{
		//debug
		// ft_print("bottom element: %d\n", scan->element);
		// ft_print("stack_b element: %d\n", (int64_t)b_element);
		if (scan_up->prev->element > scan_up->element)
			return (position - 1);
		scan_up = scan_up->prev;
		--position;
	}
	//debug
	// if (b_element != -42)
		// sleep(5);
	return (0);
}

int32_t	find_closest_swap_down(t_lst *head)
{
	int32_t	position;
	t_lst	*scan_down;

	position = 0;
	scan_down = head;
	while (scan_down != NULL && scan_down->next != NULL)
	{
		//debug
		// ft_print("top element: %d\n", scan->element);
		// ft_print("stack_b element: %d\n", (int64_t)b_element);
		if (scan_down->element > scan_down->next->element)
			return (position);
		scan_down = scan_down->next;
		++position;
	}
	//debug
	// if (b_element != -42)
		// sleep(5);
	return (0);
}

int32_t	find_closest_swap_a(t_stack stack)
{
	int32_t	closest_down;
	int32_t	closest_up;

	closest_down = find_closest_swap_down(stack.head_a);
	closest_up = find_closest_swap_up(stack.tail_a);
	//debug
	ft_print("************\n");
	ft_print("Closest DOWN: %d\n", (int64_t)closest_down);
	ft_print("Closest UP: %d\n", (int64_t)closest_up);
	if ((uint32_t)closest_down > ft_abs32(closest_up) || closest_down == 0)
		return (closest_up);
	else
		return (closest_down);
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
