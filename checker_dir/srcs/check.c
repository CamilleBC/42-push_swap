/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:27:32 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/30 14:51:17 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int32_t	check_elements(t_stack stack)
{
	t_lst	*tmp;

	if (stack.head_b)
		return (FAILURE);
	tmp = stack.head_a;
	stack.head_a = stack.head_a->next;
	while (stack.head_a)
	{
		if (tmp->element > stack.head_a->element)
			return (FAILURE);
		tmp = stack.head_a;
		stack.head_a = stack.head_a->next;
	}
	return (SUCCESS);
}
