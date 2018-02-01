/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_from_A_to_B.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 09:27:49 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/30 12:55:30 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cmd	*shortest_from_A_to_B(t_stack *stack)
{
	t_cmd	*atob_cmds;
	t_cmd	*shortest_cmds;
	t_stack	*stack_cpy;
	t_lst	*scan;


	scan = stack->head_a;
	while(scan != NULL)
	{
		stack_cpy = copy_stack(stack);
		atob_cmds = calculate_instructions(stack_cpy, );


	}
}
