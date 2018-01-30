/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 15:19:15 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/30 15:09:03 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*copy_stack(t_stack stack)
{
	t_stack	*stack_copy;
	t_lst	*list_copy;

	if ((stack_copy = init_stack(stack.elements_a)) == NULL)
		return (NULL);
	if ((list_copy = copy_list(stack.head_a)) == NULL)
		return (NULL);
	stack_copy->head_a = list_copy;
	while (list_copy->next != NULL)
		list_copy = list_copy->next;
	stack_copy->tail_a = list_copy;
	if (stack.head_b != NULL)
	{
		if ((list_copy = copy_list(stack.head_b)) == NULL)
			return (NULL);
		stack_copy->head_b = list_copy;
		while (list_copy->next != NULL)
			list_copy = list_copy->next;
		stack_copy->tail_b = list_copy;
		stack_copy->elements_b = stack.elements_b;
	}
	stack_copy->position = 0;
	return (stack_copy);
}

void	free_stack(t_stack *stack)
{
	t_lst	*tmp;
	while (stack->head_a)
	{
		tmp = stack->head_a->next;
		free(stack->head_a);
		stack->head_a = tmp;
	}
	while (stack->head_b)
	{
		tmp = stack->head_b->next;
		free(stack->head_b);
		stack->head_b = tmp;
	}
	free(stack);
}

t_stack	*init_stack(int ac)
{
	t_stack	*stack;

	if ((stack = (t_stack*)malloc(sizeof(t_stack))) == NULL)
		return (NULL);
	stack->head_a = NULL;
	stack->tail_a = NULL;
	stack->elements_a = ac;
	stack->head_b = NULL;
	stack->tail_b = NULL;
	stack->elements_b = 0;
	stack->position = 0;
	return (stack);
}

/*
** We need to check:
** - if the parameter is really a number
** - if we don't over/underflow
** - if we don't have doubles
*/

t_stack	*return_stack(int ac, char **av)
{
	int64_t	tmp;
	t_stack	*stack;

	if ((stack = init_stack(ac)) == NULL)
		return (NULL);
	while (--ac >= 0)
	{
		if (!ft_strisnumber(av[ac]))
			return (NULL);
		if ((tmp = ft_atoi64(av[ac])) > INT32_MAX || tmp < INT32_MIN)
			return (NULL);
		if (check_double(tmp, *stack) == ERROR)
			return (NULL);
		push_head_a(tmp, stack);
	}
	return (stack);
}
