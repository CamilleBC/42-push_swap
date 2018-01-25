/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:07:26 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/25 15:23:20 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "shared.h"
# include "instructions.h"
# include "stack.h"

# define	COUNT (int8_t)0
# define	CMDS (int8_t)1
# define	BOTH (int8_t)2

void	print_instructions(int8_t display, t_cmd cmds);
void	print_list(t_lst *list);
void	print_stack(t_stack stack);

#endif
