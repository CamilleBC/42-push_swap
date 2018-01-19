/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:02:33 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/19 17:26:26 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "common.h"
# include "parsing.h"
# include "../libft/includes/libft.h"

typedef struct	s_lst
{
	struct s_lst	*next;
	struct s_lst	*prev;
	int32_t			element;
}				t_lst;

typedef struct	s_stack
{
	t_lst	*top;
	t_lst	*bottom;
}				t_stack;


int32_t			init_stack(t_stack **stack);
int32_t			pop_bottom(t_stack *stack);
int32_t			push_bottom(int32_t value, t_stack *stack);
int32_t			pop_top(t_stack *stack);
int32_t			push_top(int32_t value, t_stack *stack);
int32_t			return_stack(int ac, char **av, t_stack **stack_a);

#endif
