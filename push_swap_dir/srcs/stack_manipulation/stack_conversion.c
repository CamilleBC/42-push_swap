/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 18:02:11 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/10 23:30:44 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_lst *find_and_convert(t_lst *to_convert, t_lst *seek)
{
	int32_t	i;

	i = 1;
	if (!to_convert || !seek)
		return (to_convert);
	while (seek->element != to_convert->element && seek != NULL)
	{
		seek = seek->next;
		++i;
	}
	to_convert->element = i;
	return (to_convert);
}

void convert_stack(t_stack *stack)
{
	t_lst	*traverse;
	t_lst	*copy;

	traverse = stack->head_a;
	copy = copy_list(stack->head_a);
	copy = mergesort_list(copy);
	while (traverse != NULL)
	{
		traverse = find_and_convert(traverse, copy);
		traverse = traverse->next;
	}
	free_list(&copy);
}
