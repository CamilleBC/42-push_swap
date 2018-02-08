/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 09:30:25 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/08 18:28:09 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"
#include "stack.h"

void	free_instructions(t_cmd *cmds)
{
	// if (cmds && cmds->cmd_array)
		// free(cmds->cmd_array);
	if (cmds)
		free(cmds);
}

void	free_stack(t_stack *stack)
{
	t_lst	*tmp;
	if (stack)
	{
		while (stack->head_a)
		{
			tmp = stack->head_a->next;
			free(stack->head_a);
			stack->head_a = tmp;
		}
		while (stack->tail_a && stack->tail_a->prev)
		{
			tmp = stack->tail_a->prev;
			free(stack->tail_a);
			stack->tail_a = tmp;
		}
		while (stack->head_b)
		{
			tmp = stack->head_b->next;
			free(stack->head_b);
			stack->head_b = tmp;
		}
		while (stack->tail_b && stack->tail_b->prev)
		{
			tmp = stack->tail_b->prev;
			free(stack->tail_b);
			stack->tail_b = tmp;
		}
		free(stack);
	}
}
