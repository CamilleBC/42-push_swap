/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:44:36 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/22 11:46:55 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int32_t	pop_tail(struct s_stack *stack)
{
	t_lst	*tmp;
	int32_t	ret;

	tmp = stack->tail->prev;
	ret = stack->tail->element;
	free(stack->tail);
	stack->tail = tmp;
	stack->tail->next = NULL;
	return (ret);
}

int32_t	pop_head(struct s_stack *stack)
{
	t_lst	*tmp;
	int32_t	ret;

	tmp = stack->head->next;
	ret = stack->head->element;
	free(stack->head);
	stack->head = tmp;
	stack->head->prev = NULL;
	return (ret);
}

int32_t	push_tail(int32_t value, struct s_stack *stack)
{
	t_lst	*tmp;

	if ((tmp = (t_lst*)malloc(sizeof(t_lst))) == NULL)
		return (MALLOC_FAIL);
	tmp->element = value;
	tmp->prev = NULL;
	tmp->next = NULL;
	if (stack->head == NULL)
	{
		stack->head = tmp;
		stack->tail = tmp;
		return (SUCCESS);
	}
	stack->tail->next = tmp;
	tmp->prev = stack->tail;
	stack->tail = tmp;
	return (SUCCESS);
}

int32_t	push_head(int32_t value, struct s_stack *stack)
{
	t_lst	*last;

	last = stack->head;
	if ((stack->head = (t_lst*)malloc(sizeof(t_lst))) == NULL)
		return (MALLOC_FAIL);
	stack->head->element = value;
	stack->head->next = last;
	if (last != NULL)
		last->prev = stack->head;
	if (stack->tail == NULL)
		stack->tail = stack->head;
	return (SUCCESS);
}
