/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_to.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 11:15:11 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/26 16:56:23 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int32_t	rotate_a_to_position(t_cmd *cmds, t_stack *stack_a)
{
	int64_t	position;

	position = stack_a->position;
	ft_print("position = %d\n", position);
	if (position > (stack_a->elements / 2))
	{
		while (position++ <= stack_a->elements)
			if (add_instructions(RRA, cmds, stack_a, NULL) == ERROR)
				return (ERROR);
	}
	else
	{
		ft_print("RA\n");
		while (position-- > 1)
			if (add_instructions(RA, cmds, stack_a, NULL) == ERROR)
				return (ERROR);
	}
	return (SUCCESS);
}
