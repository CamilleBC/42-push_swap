/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 14:13:53 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/30 14:15:34 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"

void	rotate_a(t_stack *stack)
{
	t_lst	*tmp;

	if (!(stack->head_a && stack->head_a->next))
		return ;
	tmp = stack->head_a->next;
	stack->tail_a->next = stack->head_a;
	stack->head_a->prev = stack->tail_a;
	stack->head_a->next = NULL;
	tmp->prev = NULL;
	stack->tail_a =  stack->head_a;
	stack->head_a = tmp;
}

void	rotate_b(t_stack *stack)
{
	t_lst	*tmp;

	if (!(stack->head_b && stack->head_b->next))
		return ;
	tmp = stack->head_b->next;
	stack->tail_b->next = stack->head_b;
	stack->head_b->prev = stack->tail_b;
	stack->head_b->next = NULL;
	tmp->prev = NULL;
	stack->tail_b =  stack->head_b;
	stack->head_b = tmp;
}

void	rotate_ab(t_stack *stack)
{
	rotate_a(stack);
	rotate_b(stack);
}
