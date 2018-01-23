/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:23:01 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/23 12:47:06 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "shared.h"
# include "instructions.h"
# include "print.h"
# include "stack.h"

int32_t	check_elements(t_stack stack_a, t_stack stack_b);
int32_t	return_instructions(t_cmd *cmds);
void	sort_elements(t_cmd *instr, t_stack *stack_a, t_stack *stack_b);

#endif
