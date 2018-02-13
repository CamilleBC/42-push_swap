/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:07:10 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/13 15:07:11 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cmd	*selection_sort(t_stack stack)
{
	t_cmd	*cmds;
	int		position;

	if (!(cmds = init_instructions()))
		return (NULL);
	while (stack.head_a->next)
	{
		stack.smallest = return_smallest_element(stack.head_a);
		position = find_element(stack.head_a, stack.smallest);
		rotate_to_position(cmds, &stack, position, STACK_A);
		add_and_exec_cmd(PB, cmds, &stack);
	}
	while (stack.head_b)
		add_and_exec_cmd(PA, cmds, &stack);
	return (cmds);
}
