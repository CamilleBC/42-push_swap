/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimise_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 12:22:10 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/13 15:59:29 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	insert_cmd(int32_t cmd, int32_t i, t_cmd *cmds)
{
	size_t	size;

	size = (size_t)((cmds->count - i) * sizeof(*(cmds->cmd_array)));
	ft_memmove(&(cmds->cmd_array[i + 2]), &(cmds->cmd_array[i + 1]), size);
	cmds->cmd_array[i + 1] = cmd;
	cmds->count += 1;
}

static void	replace_instruction(int32_t *i_ret, int32_t ret_array_value,
								int32_t cpy_array_value, t_cmd *ret_array)
{
	if ((ret_array_value == SA && cpy_array_value == SB)
		|| (ret_array_value == SB && cpy_array_value == SA))
		ret_array->cmd_array[*i_ret] = SS;
	else if ((ret_array_value == RA && cpy_array_value == RB)
		|| (ret_array_value == RB && cpy_array_value == RA))
		ret_array->cmd_array[*i_ret] = RR;
	else if ((ret_array_value == RRA && cpy_array_value == RRB)
		|| (ret_array_value == RRB && cpy_array_value == RRA))
		ret_array->cmd_array[*i_ret] = RRR;
	else
	{
		insert_cmd(cpy_array_value, *i_ret, ret_array);
		*i_ret += 1;
	}
}

t_cmd		*optimise_instructions(t_cmd *cmds_a, t_cmd *cmds_b)
{
	int32_t	i_cpy;
	int32_t	i_ret;
	t_cmd	*ret;
	t_cmd	*cpy;

	if (!cmds_a)
		return (cmds_b);
	else if (!cmds_b)
		return (cmds_a);
	ret = (cmds_a->count > cmds_b->count) ? cmds_a : cmds_b;
	cpy = (cmds_a->count > cmds_b->count) ? cmds_b : cmds_a;
	i_cpy = 0;
	i_ret = 0;
	while (i_cpy < cpy->count)
	{
		replace_instruction(&i_ret, ret->cmd_array[i_ret],
			cpy->cmd_array[i_cpy], ret);
		++i_cpy;
		++i_ret;
	}
	free_instructions(&cpy);
	return (ret);
}
