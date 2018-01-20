/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:44:36 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/20 21:16:16 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	free_stack(t_stack **stack)
{
	t_lst	*tmp;
	while ((*stack)->top)
	{
		tmp = (*stack)->top->next;
		free((*stack)->top);
		(*stack)->top = tmp;
	}
	free(*stack);
}

int32_t	pop_bottom(struct s_stack *stack)
{
	t_lst	*tmp;
	int32_t	ret;

	tmp = stack->bottom->prev;
	ret = stack->bottom->element;
	free(stack->bottom);
	stack->bottom = tmp;
	stack->bottom->next = NULL;
	return (ret);
}

int32_t	pop_top(struct s_stack *stack)
{
	t_lst	*tmp;
	int32_t	ret;

	tmp = stack->top->next;
	ret = stack->top->element;
	free(stack->top);
	stack->top = tmp;
	stack->top->prev = NULL;
	return (ret);
}

int32_t	push_bottom(int32_t value, struct s_stack *stack)
{
	t_lst	*tmp;

	if ((tmp = (t_lst*)malloc(sizeof(t_lst))) == NULL)
		return (MALLOC_FAIL);
	tmp->element = value;
	tmp->prev = NULL;
	tmp->next = NULL;
	if (stack->top == NULL)
	{
		stack->top = tmp;
		stack->bottom = tmp;
		return (SUCCESS);
	}
	stack->bottom->next = tmp;
	tmp->prev = stack->bottom;
	stack->bottom = tmp;
	return (SUCCESS);
}

int32_t	push_top(int32_t value, struct s_stack *stack)
{
	t_lst	*last;

	last = stack->top;
	if ((stack->top = (t_lst*)malloc(sizeof(t_lst))) == NULL)
		return (MALLOC_FAIL);
	stack->top->element = value;
	stack->top->next = last;
	if (last != NULL)
		last->prev = stack->top;
	if (stack->bottom == NULL)
		stack->bottom = stack->top;
	return (SUCCESS);
}
