/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimise_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 12:22:10 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/26 12:52:52 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	replace_instruction(int32_t cmd, int32_t i, t_cmd *cmds)
{
	size_t	size;

	size = (size_t)((cmds->count - (i + 2)) * sizeof(*(cmds->cmd_array)));
	if (cmd == NO_CMD)
	{
		ft_memmove(&(cmds->cmd_array[i]), &(cmds->cmd_array[i + 2]), size);
		ft_bzero(&(cmds->cmd_array[i + size]), 2);
		cmds->count -= 2;
	}
	else
	{
		cmds->cmd_array[i++] = cmd;
		ft_memmove(&(cmds->cmd_array[i]), &(cmds->cmd_array[i + 1]), size);
		ft_bzero(&(cmds->cmd_array[i + size]), 1);
		cmds->count -= 1;
	}
}

void		optimise_instructions(t_cmd *cmds)
{
	int32_t	i;

	if (cmds == NULL || cmds->cmd_array == NULL)
		return ;
	i = 0;
	while (i + 1 < cmds->count)
	{
		if ((cmds->cmd_array[i] == SA && cmds->cmd_array[i + 1] == SB)
				|| (cmds->cmd_array[i] == SB && cmds->cmd_array[i + 1] == SA))
			replace_instruction(SS, i, cmds);
		else if ((cmds->cmd_array[i] == RA && cmds->cmd_array[i + 1] == RB)
				|| (cmds->cmd_array[i] == RB && cmds->cmd_array[i + 1] == RA))
			replace_instruction(RR, i, cmds);
		else if ((cmds->cmd_array[i] == RRA && cmds->cmd_array[i + 1] == RRB)
				|| (cmds->cmd_array[i] == RRB && cmds->cmd_array[i + 1] == RRA))
			replace_instruction(RRR, i, cmds);
		else if ((cmds->cmd_array[i] == RA && cmds->cmd_array[i + 1] == RRA)
				|| (cmds->cmd_array[i] == RRA && cmds->cmd_array[i + 1] == RA)
				|| (cmds->cmd_array[i] == RB && cmds->cmd_array[i + 1] == RRB)
				|| (cmds->cmd_array[i] == RRB && cmds->cmd_array[i + 1] == RB)
				|| (cmds->cmd_array[i] == PA && cmds->cmd_array[i + 1] == PB)
				|| (cmds->cmd_array[i] == PB && cmds->cmd_array[i + 1] == PA))
			replace_instruction(NO_CMD, i, cmds);
		i++;
	}
}
