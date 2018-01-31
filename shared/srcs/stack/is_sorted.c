/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 14:37:53 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/31 16:21:55 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int32_t	is_sorted(t_stack stack)
{
	int32_t	i;
	t_lst	*scan;

	if (stack.head_b || !stack.head_a)
		return (ERROR);
	scan = stack.head_a;
	i = 1;
	while (scan != NULL && scan->next != NULL && scan->next->element != 1)
	{
		if (scan->next->element != scan->element + 1)
			return (ERROR);
		i++;
		scan = scan->next;
	}
	if (scan != NULL && scan->next != NULL && scan->next->element == 1)
		scan = scan->next;
	while (scan != NULL && scan->next != NULL)
	{
		if (scan->next->element != scan->element + 1)
			return (ERROR);
		scan = scan->next;
	}
	if (i == stack.elements_a)
		return (SUCCESS);
	return (i);
}
