/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 10:04:30 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/26 18:18:17 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int32_t	find_element(t_cmd *cmds, t_stack *stack_a)
{
	t_lst * seek;

	seek = stack_a->head;
	stack_a->position = 1;
	while (seek != NULL && seek->next != NULL)
	{
		if (seek->element > seek->next->element)
		{
			if (rotate_a_to_position(cmds, stack_a) == ERROR)
				return (ERROR);
			return (FOUND);
		}
		seek = seek->next;
		++(stack_a->position);
	}
	return (SORTED);
}

static int32_t	insert_element(t_cmd *cmds, t_stack *stack_a, t_stack *stack_b)
{
	t_lst *seek;

	if (stack_a->tail == NULL)
		return (ERROR);
	seek = stack_a->tail;
	while (seek != NULL)
	{
		if (stack_b->head != NULL
				&& (seek->element < stack_b->head->element
				|| stack_a->position == 1))
			if (add_instructions(PA, cmds, stack_a, stack_b) == ERROR)
				return (ERROR);
		if (stack_a->position > 1)
		{
			--(stack_a->position);
			if (add_instructions(RRA, cmds, stack_a, NULL) == ERROR)
				return (ERROR);
		}
		else
			return (SUCCESS);
		seek = stack_a->tail;
	}
	return (SUCCESS);
}

static int32_t	sort_element(t_cmd *cmds, t_stack *stack_a, t_stack *stack_b)
{
	t_lst	*scan;

	scan = stack_a->head;
	if (scan->next->element - scan->element == 1)
		add_instructions(SA, cmds, stack_a, stack_b);
	else
	{
		add_instructions(PB, cmds, stack_a, stack_b);
		if (insert_element(cmds, stack_a, stack_b) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

t_cmd *insertion_sort(t_stack stack_a, t_stack stack_b)
{
	t_cmd	*instr;
	int32_t	status;

	if (stack_a.head->next == NULL || (instr = init_instructions()) == NULL)
		return (NULL);
	status = FOUND;
	while (status != SORTED)
	{
		sleep(1);
		ft_print("-----\n");
		ft_print("original\n");
		print_stack(stack_a);
		if ((status = find_element(instr, &stack_a)) == ERROR)
			return (NULL);
		else if (status == FOUND)
		{
			ft_print("-----\n");
			ft_print("found\n");
			print_stack(stack_a);
			if (sort_element(instr, &stack_a, &stack_b) == ERROR)
				return (NULL);
			ft_print("-----\n");
			print_stack(stack_a);
		}
	}
	return (instr);
}
