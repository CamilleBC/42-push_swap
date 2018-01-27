/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 15:19:15 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/27 08:10:04 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int32_t	check_double(int32_t value, t_stack stack)
{
	while (stack.head != NULL)
	{
		if (stack.head->element == value)
			return (ERROR);
		stack.head = stack.head->next;
	}
	return (SUCCESS);
}

void	free_stack(t_stack *stack)
{
	t_lst	*tmp;
	while (stack->head)
	{
		tmp = stack->head->next;
		free(stack->head);
		stack->head = tmp;
	}
	free(stack);
}

t_stack	*init_stack(int ac)
{
	t_stack	*stack;

	if ((stack = (t_stack*)malloc(sizeof(t_stack))) == NULL)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->elements = ac;
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
		push_head(tmp, stack);
	}
	return (stack);
}
