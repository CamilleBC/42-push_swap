/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:23:01 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/20 23:33:29 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "shared.h"
# include "instructions.h"
# include "stack.h"

//DEBUG
#define TOP		(int8_t)1
#define BOTTOM	(int8_t)0
void	print_instructions(int32_t instr[MAX_INSTR]);
void	print_stack(int8_t way, t_stack stack);

int32_t	check_elements(t_stack stack_a, t_stack stack_b);
int32_t	return_instructions(int32_t (*instr)[MAX_INSTR]);
void	sort_elements(int32_t instr[MAX_INSTR],
						t_stack *stack_a, t_stack *stack_b);

#endif
