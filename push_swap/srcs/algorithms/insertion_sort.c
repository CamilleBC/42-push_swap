/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 10:04:30 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/22 21:20:00 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int32_t *find_element(int32_t *status, int32_t *cmds, t_stack *stack_a,
							 t_stack *stack_b)
{
	t_lst * seek;

	if (stack_a->head->next == NULL)
	{
		*status = SORTED;
		return (NULL);
	}
	seek = stack_a->head->next;
	stack_a->position = 1;
	while (seek != NULL)
	{
		++(stack_a->position);
		if (seek->element < seek->prev->element)
		{
			*status = FOUND;
			cmds = rotate_a_to_position(stack_a, cmds);
			cmds = add_instructions(PB, cmds, stack_a, stack_b);
			return (cmds);
		}
		seek = seek->next;
	}
	*status = SORTED;
	return (cmds);
}

static int32_t *insert_element(int32_t *cmds, t_stack *stack_a,
								t_stack *stack_b)
{
	t_lst *seek;

	if (stack_a->tail == NULL)
		return (NULL);
	seek = stack_a->tail;
	while (seek != NULL)
	{
		if (stack_b->head != NULL
		&& (seek->element < stack_b->head->element || stack_a->position == 1))
			cmds = add_instructions(PA, cmds, stack_a, stack_b);
		if (stack_a->position > 1)
		{
			--(stack_a->position);
			cmds = add_instructions(RRA, cmds, stack_a, NULL);
		}
		else
			return (cmds);
		seek = stack_a->tail;
	}
	return (cmds);
}

int32_t *insertion_sort(t_stack stack_a, t_stack stack_b)
{
	int32_t *instr;
	int32_t  status;

	instr = NULL;
	if (stack_a.head->next == NULL)
		return (NULL);
	status = FOUND;
	while (status != SORTED)
	{
		instr = find_element(&status, instr, &stack_a, &stack_b);
		if (status == FOUND)
		{
			instr = insert_element(instr, &stack_a, &stack_b);
		}
	}
	return (instr);
}
