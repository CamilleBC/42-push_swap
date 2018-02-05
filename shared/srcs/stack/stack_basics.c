/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:44:36 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/30 14:41:34 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int32_t	pop_tail_a(struct s_stack *stack)
{
	t_lst	*tmp;
	int32_t	ret;

	tmp = stack->tail_a->prev;
	ret = stack->tail_a->element;
	free(stack->tail_a);
	stack->tail_a = tmp;
	stack->tail_a->next = NULL;
	return (ret);
}

int32_t	pop_head_a(struct s_stack *stack)
{
	t_lst	*tmp;
	int32_t	ret;

	tmp = stack->head_a->next;
	ret = stack->head_a->element;
	free(stack->head_a);
	stack->head_a = tmp;
	stack->head_a->prev = NULL;
	return (ret);
}

int32_t	push_tail_a(int32_t value, struct s_stack *stack)
{
	t_lst	*tmp;

	if ((tmp = (t_lst*)malloc(sizeof(t_lst))) == NULL)
		return (MALLOC_FAIL);
	tmp->element = value;
	tmp->prev = NULL;
	tmp->next = NULL;
	if (stack->head_a == NULL)
	{
		stack->head_a = tmp;
		stack->tail_a = tmp;
		return (SUCCESS);
	}
	stack->tail_a->next = tmp;
	tmp->prev = stack->tail_a;
	stack->tail_a = tmp;
	return (SUCCESS);
}

int32_t	push_head_a(int32_t value, struct s_stack *stack)
{
	t_lst	*last;

	last = stack->head_a;
	if ((stack->head_a = (t_lst*)malloc(sizeof(t_lst))) == NULL)
		return (MALLOC_FAIL);
	stack->head_a->element = value;
	stack->head_a->next = last;
	if (last != NULL)
		last->prev = stack->head_a;
	if (stack->tail_a == NULL)
		stack->tail_a = stack->head_a;
	return (SUCCESS);
}
