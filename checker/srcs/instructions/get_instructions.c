/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 17:37:30 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/19 22:58:53 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"

static inline void	init_instructions(int32_t (*instr)[MAX_INSTR])
{
	ft_bzero(instr, MAX_INSTR);
}

static int32_t		check_instructions(int32_t (*instr)[MAX_INSTR])
{
	int32_t	i;

	i = 0;
	while ((*instr)[i] != 0)
	{
		if (!((*instr)[i] == SA
			|| (*instr)[i] == SB
			|| (*instr)[i] == SS
			|| (*instr)[i] == PA
			|| (*instr)[i] == PB
			|| (*instr)[i] == RA
			|| (*instr)[i] == RB
			|| (*instr)[i] == RR
			|| (*instr)[i] == RRA
			|| (*instr)[i] == RRB
			|| (*instr)[i] == RRR))
				return (ERROR);
		++i;
	}
	return (SUCCESS);
}

/*
** We cast the char pointer into an in32_t pointer to get the raw value of the
** first four octets (no instruction is longer than 3 chars)
** WARNING: Intel PCs are little endians so bytes are in reverse order.
*/

int32_t				return_instructions(int32_t (*instr)[MAX_INSTR])
{
	char	*line;
	int32_t	status;
	int32_t	i;

	init_instructions(instr);
	i = 0;
	while ((status = get_next_line(0, &line)) > FILE_READ)
	{
		if (ft_strlen(line) > 3)
			return (ERROR);
		(*instr)[i++] = *(int32_t *)line;
	}
	if (status == ERROR)
		return (ERROR);
	if (check_instructions(instr) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
