/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_and_conquer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 07:03:04 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/12 16:32:03 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_biggests_to_b(t_cmd *cmds, t_stack *stack)
{
	t_lst *scan_down;
	t_lst *scan_up;
	int32_t	half;
	int32_t	position;

	scan_down = stack->head_a;
	scan_up = stack->tail_a;
	half = (stack->elements_a / 2) + 1;
	while (scan_up && scan_down)
	{
		if (scan_down->element > half || scan_up->element > half)
		{
			if (scan_down->element > half)
				position = find_element(stack->head_a, scan_down->element);
			else
				position = find_element(stack->head_a, scan_up->element);
			rotate_a_to_position(cmds, stack, position, EXEC);
			add_and_exec_cmd(PB, cmds, stack);
			scan_down = stack->head_a;
			scan_up = stack->tail_a;
		}
		else
		{
			scan_down = scan_down->next;
			scan_up = scan_up->prev;
		}
	}
}

t_cmd	*divide_and_conquer(t_stack stack)
{
	t_cmd	*cmds_ret;
	t_cmd	*cmds_a;
	t_cmd	*cmds_b;
	t_stack	*stack_copy;

	if (!(cmds_ret = init_instructions()))
		return (NULL);
	stack_copy = copy_stack(stack);
	push_biggests_to_b(cmds_ret, stack_copy);
	if (stack_copy->elements_a == 3)
		cmds_a = sort_three(*stack_copy);
	else
		cmds_a = sort_swap(*stack_copy, STACK_A);

	//debug
	//exec_instructions(*cmds_a, stack_copy);
	//print_stack(*stack_copy);
	//todo
	// When sorting B we could send A instructions and optimize directly, as well
	// as pushing back to A when the (A bottom) == (B head - 1)
	// or (A head) == (B head + 1)
	cmds_b = reverse_sort_swap(*stack_copy, STACK_B);

	free_stack(&stack_copy);

	cmds_a = optimise_instructions(cmds_a, cmds_b);
	if (cmds_a)
	{
		append_instructions(cmds_ret, cmds_a);
		free_instructions(&cmds_a);
		// free_instructions(&cmds_b);
	}

	exec_instructions(*cmds_ret, &stack);
	while (stack.head_b)
		add_and_exec_cmd(PA, cmds_ret, &stack);
	rotate_a_to_first(cmds_ret, &stack, EXEC);
	return (cmds_ret);
}
