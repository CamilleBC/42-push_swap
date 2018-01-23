/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:44:30 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/23 17:51:32 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"

void	free_instructions(t_cmd *cmds)
{
	free(cmds->cmd_array);
	free(cmds);
}

t_cmd	*init_instructions(void)
{
	t_cmd	*cmds;

	if ((cmds = (t_cmd*)malloc(sizeof(t_cmd))) == NULL)
		return (NULL);
	cmds->cmd_array = NULL;
	cmds->count = 0;
	return (cmds);
}

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

int32_t	add_instructions(int32_t cmd, t_cmd *cmds,
			t_stack *stack_a, t_stack *stack_b)
{
	static int64_t	i = 0;

	if (cmds->cmd_array == NULL)
	{
		i = 0;
		if ((cmds->cmd_array = (int32_t*)malloc(sizeof(int32_t) * MAX_CMD)) == NULL)
			return (ERROR);
	}
	else if (!(i % (MAX_CMD / sizeof(int32_t) - 1)))
		if ((cmds->cmd_array = ft_realloc(cmds->cmd_array, i * sizeof(int32_t),
					i * sizeof(int32_t) + MAX_CMD)) == NULL)
			return (ERROR);
	cmds->cmd_array[i++] = cmd;
	++(cmds->count);
	apply_instructions(cmd, stack_a, stack_b);
	return (SUCCESS);
}
