/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:27:39 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/22 20:49:39 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sort_elements(int32_t *instr, t_stack *stack_a, t_stack *stack_b)
{
	while (*instr)
		apply_instructions(*instr++, stack_a, stack_b);
}
