/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:44:36 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/19 22:10:54 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int32_t			init_stack(t_stack **stack)
{
	if ((*stack = (t_stack*)malloc(sizeof(t_stack))) == NULL)
		return (MALLOC_FAIL);
	(*stack)->top = NULL;
	(*stack)->bottom = NULL;
	return (SUCCESS);
}

int32_t			pop_bottom(t_stack *stack)
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

int32_t			push_bottom(int32_t value, t_stack *stack)
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

int32_t			pop_top(t_stack *stack)
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

int32_t			push_top(int32_t value, t_stack *stack)
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
		stack->bottom = last;
	return (SUCCESS);
}

/*
** We need to check:
** - if the parameter is really a number
** - if we don't over/underflow
** - if we don't double numbers
*/
int32_t			return_stack(int ac, char **av, t_stack **stack_a)
{
	int64_t	tmp;

	if (init_stack(stack_a) != SUCCESS)
		return (ERROR);
	while (--ac >= 0)
	{
		if (!ft_strisnumber(av[ac]))
			return (ERROR);
		if ((tmp = ft_atoi(av[ac])) > MAX_32 || tmp < MIN_32)
			return (ERROR);
		if (check_double(tmp, **stack_a) == ERROR)
			return (ERROR);
		push_top(tmp, *stack_a);
	}
	return (SUCCESS);
}
