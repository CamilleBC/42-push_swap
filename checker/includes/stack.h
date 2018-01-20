/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:02:33 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/20 21:16:38 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "common.h"
# include "parsing.h"
# include "../libft/includes/libft.h"

/*
** Forward declaration of stack to avoid circular dependencies
*/

struct s_stack;

void	free_stack(t_stack **stack);
int32_t	pop_bottom(struct s_stack *stack);
int32_t	pop_top(struct s_stack *stack);
int32_t	push_bottom(int32_t value, struct s_stack *stack);
int32_t	push_top(int32_t value, struct s_stack *stack);

#endif
