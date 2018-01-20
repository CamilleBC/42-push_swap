/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:44:30 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/20 17:11:52 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"

void	apply_instructions(int32_t cmd, t_stack *stack_a, t_stack *stack_b)
{
	if (cmd == SA)
		swap(stack_a);
	else if (cmd == SB)
		swap(stack_b);
	else if (cmd == SS)
		double_instruction(swap, stack_a, stack_b);
	else if (cmd == PA)
		push(stack_b, stack_a);
	else if (cmd == PB)
		push(stack_a, stack_b);
	else if (cmd == RA)
		rotate(stack_a);
	else if (cmd == RB)
		rotate(stack_b);
	else if (cmd == RR)
		double_instruction(swap, stack_a, stack_b);
	else if (cmd == RRA)
		rev_rotate(stack_a);
	else if (cmd == RRB)
		rev_rotate(stack_b);
	else if (cmd == RRR)
		double_instruction(swap, stack_a, stack_b);
}
