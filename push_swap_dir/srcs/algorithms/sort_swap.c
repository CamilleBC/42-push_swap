/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:35:28 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/05 09:26:31 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cmd	*sort_swap(t_stack stack)
{
	t_cmd	*cmds;
	int32_t	position;

	if (!(cmds = init_instructions()))
		return (NULL);
	while ((position = is_sorted(stack)) == ERROR)
	{
		position = find_closest_swap_a(stack);
		rotate_a_to_position(cmds, &stack, position, EXEC);
		add_and_exec_cmd(SA, cmds, &stack);
	}
	rotate_a_to_first(cmds, &stack, EXEC);
	return (cmds);
}
