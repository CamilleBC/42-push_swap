/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:27:39 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/23 14:59:57 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sort_elements(t_cmd *instr, t_stack *stack_a, t_stack *stack_b)
{
	int32_t	i;

	if (!instr->cmd_array)
		return ;
	i = 0;
	while (instr->cmd_array[i])
		apply_instructions(instr->cmd_array[i++], stack_a, stack_b);
}
