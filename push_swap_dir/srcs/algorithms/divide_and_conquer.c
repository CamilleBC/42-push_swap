/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_and_conquer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 07:03:04 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/13 20:46:17 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_push_variables(t_stack stack, t_lst **head, t_lst **tail,
								int32_t *half)
{
	*head = stack.head_a;
	*tail = stack.tail_a;
	*half = (stack.elements_a / 2) + 1;
}

void		push_biggests_to_b(t_cmd *cmds, t_stack *stack)
{
	t_lst	*scan_down;
	t_lst	*scan_up;
	int32_t	half;
	int32_t	position;

	init_push_variables(*stack, &scan_down, &scan_up, &half);
	while (scan_up && scan_down)
	{
		if (scan_down->element < half || scan_up->element < half)
		{
			if (scan_down->element < half)
				position = find_element(stack->head_a, scan_down->element);
			else
				position = find_element(stack->head_a, scan_up->element);
			rotate_to_position(cmds, stack, position, STACK_A);
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

static void	push_all_stack_b(t_stack *stack, t_cmd *cmds)
{
	while (stack->head_b)
		add_and_exec_cmd(PA, cmds, stack);
}

t_cmd		*divide_and_conquer(t_stack *stack)
{
	t_cmd	*cmds_ret;
	t_cmd	*cmds_a;
	t_cmd	*cmds_b;
	t_stack	*stack_copy;

	if (!(cmds_ret = init_instructions()))
		return (NULL);
	stack_copy = copy_stack(*stack);
	push_biggests_to_b(cmds_ret, stack_copy);
	if (stack_copy->elements_a == 3)
	{
		// ft_print("sort_three\n");
		cmds_a = sort_three(stack_copy);
		// print_instructions(BOTH, *cmds_a);
	}
	else
		cmds_a = sort_swap(stack_copy, STACK_A);
	cmds_b = reverse_sort_swap(stack_copy, STACK_B);
	free_stack(&stack_copy);
	cmds_a = optimise_instructions(cmds_a, cmds_b);
	if (cmds_a)
	{
		append_instructions(cmds_ret, cmds_a);
		free_instructions(&cmds_a);
	}
	exec_instructions(*cmds_ret, stack);
	push_all_stack_b(stack, cmds_ret);
	rotate_to_first(cmds_ret, stack, STACK_A);
	return (cmds_ret);
}
