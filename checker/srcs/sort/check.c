/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:27:32 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/20 21:08:58 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int32_t	check_elements(t_stack stack_a, t_stack stack_b)
{
	t_lst	*tmp;

	if (stack_b.top)
		return (FAILURE);
	tmp = stack_a.top;
	stack_a.top = stack_a.top->next;
	while (stack_a.top)
	{
		if (tmp->element > stack_a.top->element)
			return (FAILURE);
		tmp = stack_a.top;
		stack_a.top = stack_a.top->next;
	}
	return (SUCCESS);
}
