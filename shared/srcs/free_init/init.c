/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 09:29:57 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/31 16:22:35 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"
#include "stack.h"

t_cmd	*init_instructions(void)
{
	t_cmd	*cmds;

	if ((cmds = (t_cmd*)malloc(sizeof(t_cmd))) == NULL)
		return (NULL);
	cmds->cmd_array = NULL;
	cmds->count = 0;
	return (cmds);
}

t_stack	*init_stack(int elements)
{
	t_stack	*stack;

	if ((stack = (t_stack*)malloc(sizeof(t_stack))) == NULL)
		return (NULL);
	stack->head_a = NULL;
	stack->tail_a = NULL;
	stack->elements_a = elements;
	stack->head_b = NULL;
	stack->tail_b = NULL;
	stack->elements_b = 0;
	return (stack);
}
