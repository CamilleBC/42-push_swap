/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:29:51 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/26 15:43:44 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int32_t	return_position(int32_t element, t_stack stack)
{
	int32_t	position;
	t_lst	*scan;

	position = 1;
	scan = stack.head;
	while (scan != NULL)
	{
		if (scan->element == element)
			return (position);
		++position;
		scan = scan->next;
	}
}
