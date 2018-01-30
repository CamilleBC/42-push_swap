/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 23:58:38 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/30 14:15:52 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "instructions.h"

void	swap_a(t_stack *stack)
{
	t_lst	*tmp;
	t_lst	*end;

	if (!(stack->head_a && stack->head_a->next))
		return ;
	tmp = stack->head_a->next;
	end = tmp->next;
	stack->head_a->next = tmp->next;
	if (end)
		end->prev = stack->head_a;
	stack->head_a->prev = tmp;
	tmp->next = stack->head_a;
	tmp->prev = NULL;
	stack->head_a = tmp;
}

void	swap_b(t_stack *stack)
{
	t_lst	*tmp;
	t_lst	*end;

	if (!(stack->head_b && stack->head_b->next))
		return ;
	tmp = stack->head_b->next;
	end = tmp->next;
	stack->head_b->next = tmp->next;
	if (end)
		end->prev = stack->head_b;
	stack->head_b->prev = tmp;
	tmp->next = stack->head_b;
	tmp->prev = NULL;
	stack->head_b = tmp;
}

void	swap_ab(t_stack *stack)
{
	swap_a(stack);
	swap_b(stack);
}
