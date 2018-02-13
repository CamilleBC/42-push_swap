/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:06:16 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/13 10:45:36 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	print_instructions(int8_t display, t_cmd cmds)
{
	int32_t	i;

	i = 0;
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

void	print_list(t_lst *list)
{
	ft_putstr("List Head ");
	while (list != NULL)
	{
		ft_print("| %d | ", (int64_t)list->element);
		list = list->next;
	}
	ft_putstr("Tail\n");
}

void	print_stack(t_stack stack)
{
	if (stack.head_a)
	{
		ft_putstr("Stack A Head ");
		while (stack.head_a != NULL)
		{
			ft_print("| %d | ", (int64_t)stack.head_a->element);
			stack.head_a = stack.head_a->next;
		}
		ft_putstr("Tail\n");
	}
	if (stack.head_b)
	{
		ft_putstr("Stack B Head ");
		while (stack.head_b != NULL)
		{
			ft_print("| %d | ", (int64_t)stack.head_b->element);
			stack.head_b = stack.head_b->next;
		}
		ft_putstr("Tail\n");
	}
}
