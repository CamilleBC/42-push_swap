/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:02:33 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/20 23:17:33 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "shared.h"

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

int32_t			check_double(int32_t value, t_stack stack);
void			free_stack(t_stack **stack);
t_stack			*get_element_string(char **av);
t_stack			*init_stack(void);
int32_t			pop_bottom(struct s_stack *stack);
int32_t			pop_top(struct s_stack *stack);
int32_t			push_bottom(int32_t value, struct s_stack *stack);
int32_t			push_top(int32_t value, struct s_stack *stack);
t_stack			*return_stack(int ac, char **av);

#endif
