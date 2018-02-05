/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:35:28 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/05 12:39:15 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cmd	*sort_swap(t_stack stack)
{
	t_cmd	*cmds;
	int32_t	position;

	if (!(cmds = init_instructions()))
		return (NULL);
	while ((position = is_sorted(stack, STACK_A)) == ERROR)
	{
		position = find_closest_swap_a(stack);
		rotate_a_to_position(cmds, &stack, position, EXEC);
		add_and_exec_cmd(SA, cmds, &stack);
	}
	rotate_a_to_first(cmds, &stack, EXEC);
	//debug
	// ft_print("SWAP SORT:\n");
	// print_stack(stack);
	// print_instructions(BOTH, *cmds);
	return (cmds);
}

t_cmd	*reverse_sort_swap(t_stack stack, int8_t stack_choice)
{
	t_cmd	*cmds;
	int32_t	position;

	if (!(cmds = init_instructions()))
		return (NULL);
	//debug
	ft_print("REVERSE SWAP SORT 1:\n");
	print_stack(stack);
	while ((position = is_rev_sorted(stack, stack_choice)) == ERROR)
	{
		//debug
		ft_print("is_rev_sorted position: %d\n", (int64_t)position);
		position = find_closest_rev_swap(stack, stack_choice);
		ft_print("find_closest_rev_swap position: %d\n", position);
		//debug
		ft_print("Before rotation:\n");
		print_stack(stack);
		rotate_to_position(cmds, &stack, position, stack_choice);
		//debug
		ft_print("Before rotation:\n");
		print_stack(stack);
		add_and_exec_cmd(SB, cmds, &stack);
		//debug
		ft_print("After swap:\n");
		print_stack(stack);
		// sleep(2);
	}
	rotate_to_last(cmds, &stack, EXEC, stack_choice);
	//debug
	ft_print("REVERSE SWAP SORT:\n");
	print_stack(stack);
	print_instructions(BOTH, *cmds);
	return (cmds);
}
