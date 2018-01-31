/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:35:28 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/31 18:37:04 by cbaillat         ###   ########.fr       */
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
		if (position < 0)
			position = stack.elements_a + position - 1;
		rotate_a_to_position(cmds, &stack, position, EXEC);
		add_and_exec_cmd(SA, cmds, &stack);
	}
	rotate_a_to_first(cmds, &stack, EXEC);
	//debug
	ft_print("SWAP SORT:\n");
	print_stack(stack);
	print_instructions(COUNT, *cmds);
	return (cmds);
}
