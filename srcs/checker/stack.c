/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:44:36 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/18 18:33:58 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

inline void		push_value(int32_t value, t_stack *stack)
{
	stack->items[++(stack->top)] = value;
}

inline int32_t	pop_value(int32_t value, t_stack *stack)
{
	return (stack->items[--(stack->top)]);
}

static int32_t	check_double(int32_t value, t_stack stack)
{
	int32_t	i;

	i = 0;
	while (i++ < stack.top)
		if (stack.items[i] == value)
			return (ERROR);
	return (SUCCESS);
}

int32_t			return_stack(int count, char **params, t_stack *stack)
{
	int32_t	*stack_items;
	int64_t	count_original;
	int32_t	i;
	int64_t	tmp;

	count_original = count;
	if ((stack_items = (int32_t *)malloc(sizeof(*stack_items) * count))== NULL)
		return (ERROR);
	while (--count >= 0)
	{
		// Checking if the parameter is really a number
		if (!ft_strisnum(params[count]))
			return (ERROR);
		// Checking if we don't over/underflow
		if ((tmp = ft_atoi64(params[count])) > MAX_32 || tmp < MIN_32)
			return (ERROR);
		if (check_double(tmp, *stack) == FAILURE)
			return (ERROR);
		push_value(tmp, stack);
	}
	return (stack);
}
