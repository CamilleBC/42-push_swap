/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 14:16:12 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/13 10:45:00 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"

void	rev_rotate_a(t_stack *stack)
{
	t_lst	*tmp;

	if (!(stack->tail_a && stack->tail_a->prev))
		return ;
	tmp = stack->tail_a->prev;
	stack->tail_a->next = stack->head_a;
	stack->head_a->prev = stack->tail_a;
	stack->tail_a->prev = NULL;
	tmp->next = NULL;
	stack->head_a = stack->tail_a;
	stack->tail_a = tmp;
}

void	rev_rotate_b(t_stack *stack)
{
	t_lst	*tmp;

	if (!(stack->tail_b && stack->tail_b->prev))
		return ;
	tmp = stack->tail_b->prev;
	stack->tail_b->next = stack->head_b;
	stack->head_b->prev = stack->tail_b;
	stack->tail_b->prev = NULL;
	tmp->next = NULL;
	stack->head_b = stack->tail_b;
	stack->tail_b = tmp;
}

void	rev_rotate_ab(t_stack *stack)
{
	rev_rotate_a(stack);
	rev_rotate_b(stack);
}
