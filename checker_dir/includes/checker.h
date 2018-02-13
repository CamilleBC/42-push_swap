/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:23:01 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/13 14:59:50 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "shared.h"
# include "instructions.h"
# include "print.h"
# include "stack.h"

int32_t	check_elements(t_stack stack);
int32_t	return_instructions(t_cmd *cmds);

#endif
