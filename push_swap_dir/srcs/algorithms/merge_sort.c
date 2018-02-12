/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 17:37:27 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/12 18:17:33 by cbaillat         ###   ########.fr       */
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
		if (CURR_ELMT(scan) > NEXT_ELMT(scan))
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
		if (CURR_ELMT(scan) < NEXT_ELMT(scan))
			i++;
		scan = scan->next;
	}
	return (i);
}

static void		push_back_to_a(t_stack *stack, t_cmd *cmds)
{
	t_lst	*node_a;
	t_lst	*node_a_last;
	t_lst	*node_b;

	node_a = stack->head_a;
	node_a_last = stack->tail_a;
	node_b = stack->head_b;
	while (node_b)
	{
		if (CURR_ELMT(node_b) < CURR_ELMT(node_a) &&
			CURR_ELMT(node_b) > CURR_ELMT(node_a_last))
			add_and_exec_cmd(PA, cmds, stack);
		else if ((CURR_ELMT(node_b) < CURR_ELMT(node_a) &&
			CURR_ELMT(node_a) < CURR_ELMT(node_a_last)) || !node_a->next)
			add_and_exec_cmd(PA, cmds, stack);
		else if (CURR_ELMT(node_b) > CURR_ELMT(node_a) &&
			CURR_ELMT(node_a) < CURR_ELMT(node_a_last)
			&& CURR_ELMT(node_b) > CURR_ELMT(node_a_last))
			add_and_exec_cmd(PA, cmds, stack);
		else
			add_and_exec_cmd(RRA, cmds, stack);
		node_a = stack->head_a;
		node_a_last = stack->tail_a;
		node_b = stack->head_b;
	}
}

t_cmd			*merge_sort(t_stack stack)
{
	t_cmd	*cmds;
	int32_t	position;
	int32_t	waves_a;
	int32_t	waves_b;

	if (!(cmds = init_instructions()))
		return (NULL);
	waves_b = 0;
	while (stack.head_b || (position = is_sorted(stack, STACK_A)) == ERROR)
	{
		waves_a = count_unsorted(stack.head_a);
		while (waves_a + 1 > waves_b)
		{
			add_and_exec_cmd(PB, cmds, &stack);
			waves_a = count_unsorted(stack.head_a);
			waves_b = count_unsorted_reverse(stack.head_b);
		}
		push_back_to_a(&stack, cmds);
		while (CURR_ELMT(stack.head_a) > CURR_ELMT(stack.tail_a))
			add_and_exec_cmd(RRA, cmds, &stack);
		waves_a = count_unsorted(stack.head_a);
		waves_b = count_unsorted_reverse(stack.head_b);
	}
	rotate_a_to_first(cmds, &stack, EXEC);
	return (cmds);
}
