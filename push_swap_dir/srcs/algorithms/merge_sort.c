/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 17:37:27 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/13 20:05:37 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		count_unsorted(t_lst *head)
{
	t_lst	*scan;
	int32_t	i;

	scan = head;
	i = 0;
	while (scan->next)
	{
		if (scan->element > scan->next->element)
			i++;
		scan = scan->next;
	}
	return (i);
}

static int		count_unsorted_reverse(t_lst *head)
{
	t_lst	*scan;
	int32_t	i;

	i = 0;
	if (!(scan = head))
		return (i);
	i++;
	while (scan->next)
	{
		if (scan->element < scan->next->element)
			i++;
		scan = scan->next;
	}
	return (i);
}

static void		push_back_to_a(t_stack *stack, t_cmd *cmds)
{
	t_lst	*scan_a;
	t_lst	*scan_a_last;
	t_lst	*scan_b;

	scan_a = stack->head_a;
	scan_a_last = stack->tail_a;
	scan_b = stack->head_b;
	while (scan_b)
	{
		if (scan_b->element < scan_a->element &&
			scan_b->element > scan_a_last->element)
			add_and_exec_cmd(PA, cmds, stack);
		else if ((scan_b->element < scan_a->element &&
			scan_a->element < scan_a_last->element) || !scan_a->next)
			add_and_exec_cmd(PA, cmds, stack);
		else if (scan_b->element > scan_a->element &&
			scan_a->element < scan_a_last->element
			&& scan_b->element > scan_a_last->element)
			add_and_exec_cmd(PA, cmds, stack);
		else
			add_and_exec_cmd(RRA, cmds, stack);
		scan_a = stack->head_a;
		scan_a_last = stack->tail_a;
		scan_b = stack->head_b;
	}
}

t_cmd			*merge_sort(t_stack *stack)
{
	t_cmd	*cmds;
	int32_t	position;
	int32_t	unsorted_a;
	int32_t	unsorted_b;

	if (!(cmds = init_instructions()))
		return (NULL);
	unsorted_b = 0;
	while (stack->head_b || (position = is_sorted(*stack, STACK_A)) == ERROR)
	{
		unsorted_a = count_unsorted(stack->head_a);
		while (unsorted_a + 1 > unsorted_b)
		{
			add_and_exec_cmd(PB, cmds, stack);
			unsorted_a = count_unsorted(stack->head_a);
			unsorted_b = count_unsorted_reverse(stack->head_b);
		}
		push_back_to_a(stack, cmds);
		while (stack->head_a->element > stack->tail_a->element)
			add_and_exec_cmd(RRA, cmds, stack);
		unsorted_a = count_unsorted(stack->head_a);
		unsorted_b = count_unsorted_reverse(stack->head_b);
	}
	rotate_to_first(cmds, stack, STACK_A);
	return (cmds);
}
