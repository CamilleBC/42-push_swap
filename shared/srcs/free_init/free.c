/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 09:30:25 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/31 16:22:29 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"
#include "stack.h"

void	free_instructions(t_cmd *cmds)
{
	free(cmds->cmd_array);
	free(cmds);
}

void	free_stack(t_stack *stack)
{
	t_lst	*tmp;
	while (stack->head_a)
	{
		tmp = stack->head_a->next;
		free(stack->head_a);
		stack->head_a = tmp;
	}
	while (stack->head_b)
	{
		tmp = stack->head_b->next;
		free(stack->head_b);
		stack->head_b = tmp;
	}
	free(stack);
}
