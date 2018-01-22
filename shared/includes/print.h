/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:07:26 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/22 20:47:19 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "shared.h"
# include "stack.h"

void	print_instructions(int32_t instr[MAX_INSTR]);
void	print_nb_moves(int32_t *instr);
void	print_stack(t_stack stack);

#endif
