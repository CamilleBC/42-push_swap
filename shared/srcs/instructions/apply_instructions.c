/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:44:30 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/22 19:47:24 by cbaillat         ###   ########.fr       */
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

#include "print.h"
int32_t	*add_instructions(int32_t cmd, int32_t *cmd_array,
			t_stack *stack_a, t_stack *stack_b)
{
	static int64_t	i = 0;

	if (cmd_array == NULL || !(i % (MAX_INSTR - 1)))
		if ((cmd_array = ft_realloc(cmd_array, i, i + MAX_INSTR)) == NULL)
			return (NULL);
	cmd_array[i++] = cmd;
	apply_instructions(cmd, stack_a, stack_b);
	return (cmd_array);
}
