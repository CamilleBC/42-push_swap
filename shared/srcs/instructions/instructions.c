/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:44:30 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/08 12:06:36 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"

void	append_instructions(t_cmd *original, t_cmd *to_append)
{
	int32_t	i;

	if (original == NULL)
		return ;
	i = 0;
	while (i < to_append->count)
	{
		original->cmd_array[i + original->count] = to_append->cmd_array[i];
		++i;
	}
	original->count += to_append->count;
}

void	exec_command(int32_t cmd, t_stack *stack)
{
	if (cmd == SA)
		swap_a(stack);
	else if (cmd == SB)
		swap_b(stack);
	else if (cmd == SS)
		swap_ab(stack);
	else if (cmd == PA)
		push_a(stack);
	else if (cmd == PB)
		push_b(stack);
	else if (cmd == RA)
		rotate_a(stack);
	else if (cmd == RB)
		rotate_b(stack);
	else if (cmd == RR)
		rotate_ab(stack);
	else if (cmd == RRA)
		rev_rotate_a(stack);
	else if (cmd == RRB)
		rev_rotate_b(stack);
	else if (cmd == RRR)
		rev_rotate_ab(stack);
}

void	exec_instructions(t_cmd cmds, t_stack *stack)
{
	int32_t i;

	i = 0;
	while (i < cmds.count)
	{
		exec_command(cmds.cmd_array[i], stack);
		++i;
	}
}

int32_t	add_cmd(int32_t cmd, t_cmd *cmds)
{
	if (cmds->count > MAX_CMD)
		return (ERROR);
	cmds->cmd_array[cmds->count] = cmd;
	cmds->count += 1;
	return (SUCCESS);
}

int32_t	add_and_exec_cmd(int32_t cmd, t_cmd *cmds, t_stack *stack)
{
	if (add_cmd(cmd, cmds) == ERROR)
		return (ERROR);
	exec_command(cmd, stack);
	return (SUCCESS);
}
