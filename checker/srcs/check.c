/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:27:32 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/22 11:46:55 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int32_t	check_elements(t_stack stack_a, t_stack stack_b)
{
	t_lst	*tmp;

	if (stack_b.head)
		return (FAILURE);
	tmp = stack_a.head;
	stack_a.head = stack_a.head->next;
	while (stack_a.head)
	{
		if (tmp->element > stack_a.head->element)
			return (FAILURE);
		tmp = stack_a.head;
		stack_a.head = stack_a.head->next;
	}
	return (SUCCESS);
}
