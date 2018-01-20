/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:27:55 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/20 21:09:08 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "common.h"
# include "instructions.h"

//DEBUG
#include "checker.h"

int32_t	check_elements(t_stack stack_a, t_stack stack_b);
void	sort_elements(int32_t instr[MAX_INSTR],
						t_stack *stack_a, t_stack *stack_b);

#endif
