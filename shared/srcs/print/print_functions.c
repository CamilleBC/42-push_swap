/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:06:16 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/22 20:51:03 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	print_instructions(int32_t *instr)
{
	int32_t	i = 0;

	while (instr[i])
	{
		ft_print("Instruction #%d: %s\n", i, (char *)&instr[i]);
		++i;
	}
}

void	print_nb_moves(int32_t *instr)
{
	int32_t	i = 0;

	while (instr[i])
	{
		++i;
	}
	ft_print("Moves: #%d\n", i);
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
