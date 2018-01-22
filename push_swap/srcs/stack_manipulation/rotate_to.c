/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_to.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 11:15:11 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/22 17:02:45 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int32_t	*rotate_a_to_position(t_stack *stack_a, int32_t *cmds)
{
	int64_t	position;

	position = stack_a->position;
	if (position > (stack_a->elements / 2))
	{
		while (position++ <= stack_a->elements)
			cmds = add_instructions(RRA, cmds, stack_a, NULL);
	}
	else
	{
		while (position-- > 1)
			cmds = add_instructions(RA, cmds, stack_a, NULL);
	}
	return (cmds);
}
