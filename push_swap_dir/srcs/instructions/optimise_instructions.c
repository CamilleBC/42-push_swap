/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimise_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 12:22:10 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/11 12:06:28 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* static void	replace_instruction(int32_t cmd, int32_t i, t_cmd *cmds)
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
 */

static void	insert_cmd(int32_t cmd, int32_t i, t_cmd *cmds)
{
	size_t	size;

	size = (size_t)((cmds->count - i) * sizeof(*(cmds->cmd_array)));
	ft_memmove(&(cmds->cmd_array[i + 2]), &(cmds->cmd_array[i + 1]), size);
	cmds->cmd_array[i + 1] = cmd;
	cmds->count += 1;
}


t_cmd	*optimise_instructions(t_cmd *cmds_a, t_cmd *cmds_b)
{
	int32_t	i_cpy;
	int32_t	i_ret;
	t_cmd	*ret;
	t_cmd	*cpy;

	if (!cmds_a || !cmds_a->cmd_array)
		return (cmds_b);
	else if (!cmds_b || !cmds_b->cmd_array)
		return (cmds_a);
	ret = (cmds_a->count > cmds_b->count) ? cmds_a : cmds_b;
	cpy = (cmds_a->count > cmds_b->count) ? cmds_b : cmds_a;
	i_cpy = 0;
	i_ret = 0;
	while (i_cpy < cpy->count)
	{
		if ((ret->cmd_array[i_ret] == SA && cpy->cmd_array[i_cpy] == SB)
			|| (ret->cmd_array[i_ret] == SB && cpy->cmd_array[i_cpy] == SA))
			ret->cmd_array[i_ret] = SS;
		else if ((ret->cmd_array[i_ret] == RA && cpy->cmd_array[i_cpy] == RB)
			|| (ret->cmd_array[i_ret] == RB && cpy->cmd_array[i_cpy] == RA))
			ret->cmd_array[i_ret] = RR;
		else if ((ret->cmd_array[i_ret] == RRA && cpy->cmd_array[i_cpy] == RRB)
			|| (ret->cmd_array[i_ret] == RRB && cpy->cmd_array[i_cpy] == RRA))
			ret->cmd_array[i_ret] = RRR;
		else
		{
			insert_cmd(cpy->cmd_array[i_cpy], i_ret, ret);
			++i_ret;
		}
		++i_cpy;
		++i_ret;
	}
	free_instructions(&cpy);
	return (ret);
}
