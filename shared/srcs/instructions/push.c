/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 14:15:31 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/13 10:41:38 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"

void	push_a(t_stack *stack)
{
	t_lst	*tmp;

	if (!stack->head_b)
		return ;
	tmp = stack->head_b->next;
	stack->head_b->next = stack->head_a;
	if (stack->head_a)
		stack->head_a->prev = stack->head_b;
	stack->head_a = stack->head_b;
	if (!stack->tail_a)
		stack->tail_a = stack->head_a;
	stack->head_b = tmp;
	if (!tmp)
		stack->tail_b = tmp;
	else
		stack->head_b->prev = NULL;
	stack->elements_a += 1;
	stack->elements_b -= 1;
}

void	push_b(t_stack *stack)
{
	t_lst	*tmp;

	if (!stack->head_a)
		return ;
	tmp = stack->head_a->next;
	stack->head_a->next = stack->head_b;
	if (stack->head_b)
		stack->head_b->prev = stack->head_a;
	stack->head_b = stack->head_a;
	if (!stack->tail_b)
		stack->tail_b = stack->head_b;
	stack->head_a = tmp;
	if (!tmp)
		stack->tail_a = tmp;
	else
		stack->head_a->prev = NULL;
	stack->elements_a -= 1;
	stack->elements_b += 1;
}
