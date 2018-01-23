/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:06:16 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/23 12:21:19 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	print_instructions(int8_t display, t_cmd cmds)
{
	int32_t	i = 0;

	if (display == COUNT || display == BOTH)
		ft_print("Moves: #%d\n", cmds.count);
	if (display == CMDS || display == BOTH)
	{
		while (cmds.cmd_array[i])
		{
			ft_print("Instruction #%d: %s\n", i, (char *)&(cmds.cmd_array[i]));
			++i;
		}
	}
}

void	print_stack(t_stack stack)
{
	ft_putstr("Stack Head ");
	while (stack.head != NULL)
	{
		ft_print("| %d | ", (int64_t)stack.head->element);
		stack.head = stack.head->next;
	}
	ft_putstr("Tail\n");
}
