/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_closest_rev_swap.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:34:06 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/05 12:37:40 by cbaillat         ###   ########.fr       */
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
	int32_t	smallest;

	position = 1;
	*swap = NOSWAP;
	if (choice == STACK_A)
		scan = stack.head_a;
	else
		scan = stack.head_b;
	smallest = return_smallest_element(scan);
	while ((scan != NULL && scan->next != NULL)
			&& (scan->next->element < scan->element))
	{
		scan = scan->next;
		++position;
	}
	if (scan->next->element == smallest)
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
	int32_t	biggest;

	*swap = NOSWAP;
	position = init_swap_up_values(&scan, &head, stack, choice);
	biggest = return_biggest_element(head);
	if (scan->element < head->element)
		return (position);
	while ((scan != NULL && scan->prev != NULL)
			&& (scan->prev->element > scan->element))
	{
		scan = scan->prev;
		--position;
	}
	if (scan->prev->element && scan->prev->element == biggest)
	{
		--position;
		scan = scan->prev;
	}
	while (scan != NULL && scan->prev != NULL)
	{
		if (scan->prev->element < scan->element)
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
	//debug
	int32_t	elements;

	closest_down = find_closest_rev_swap_down(stack, &swap_down, choice);
	//debug
	ft_print("closest down: %d\n", closest_down);
	closest_up = find_closest_rev_swap_up(stack, &swap_up, choice);
	//debug
	ft_print("closest up: %d\n", closest_up);
	//todo: we should compare to elemtents - closest_up + 1
	elements = (choice == STACK_A) ? stack.elements_a : stack.elements_b;
	if (swap_down == NOSWAP || closest_down > (elements - closest_up + 1))
		return (closest_up);
	else if (swap_up == NOSWAP || closest_down <= (elements - closest_up + 1))
		return (closest_down);
	return (0);
}
