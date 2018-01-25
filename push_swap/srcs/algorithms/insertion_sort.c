/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 10:04:30 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/25 17:57:21 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int32_t	find_element(t_cmd *cmds, t_stack *stack_a, t_stack *stack_b)
{
	t_lst * seek;

	if (stack_a->head->next == NULL)
		return (SORTED);
	seek = stack_a->head->next;
	stack_a->position = 1;
	while (seek != NULL)
	{
		++(stack_a->position);
		if (seek->element < seek->prev->element)
		{
			if (rotate_a_to_position(cmds, stack_a) == ERROR)
				return (ERROR);
			if (add_instructions(PB, cmds, stack_a, stack_b) == ERROR)
				return (ERROR);
			return (FOUND);
		}
		seek = seek->next;
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

t_cmd *insertion_sort(t_stack stack_a, t_stack stack_b)
{
	t_cmd	*instr;
	int32_t	status;

	if (stack_a.head->next == NULL || (instr = init_instructions()) == NULL)
		return (NULL);
	status = FOUND;
	while (status != SORTED)
	{
		if ((status = find_element(instr, &stack_a, &stack_b)) == ERROR)
			return (NULL);
		else if (status == FOUND)
			if (insert_element(instr, &stack_a, &stack_b) == ERROR)
				return (NULL);
	}
	return (instr);
}
