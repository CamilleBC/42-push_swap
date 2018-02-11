/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_closest_swap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 10:58:18 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/10 23:12:06 by cbaillat         ###   ########.fr       */
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
	// ft_print("\n************************\n");
	// ft_print("closest down: %d\n closest up: %d\n", closest_down, closest_up);
	// print_stack(stack);
	// ft_print("\n************************\n");
	if (swap_down == NOSWAP || closest_down > closest_up)
		return (closest_up);
	else if (swap_up == NOSWAP || closest_down <= closest_up)
		return (closest_down);
	return (0);
}
