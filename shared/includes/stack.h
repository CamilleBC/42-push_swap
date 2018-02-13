/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:02:33 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/13 14:58:57 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "shared.h"

# define NOT_FOUND		(int8_t)-1
# define STACK_A		(int8_t)0
# define STACK_B		(int8_t)1
# define STACK_AB		(int8_t)2

typedef struct	s_lst
{
	struct s_lst	*next;
	struct s_lst	*prev;
	int32_t			element;
}				t_lst;

typedef struct	s_stack
{
	t_lst	*head_a;
	t_lst	*tail_a;
	int64_t	elements_a;
	t_lst	*head_b;
	t_lst	*tail_b;
	int64_t	elements_b;
	int32_t	smallest;
	int32_t	biggest;
}				t_stack;

struct s_cmd;

t_stack			*return_stack(int ac, char **av);

/*
** PARSING functions
*/

int32_t			check_double(int32_t value, t_stack stack);
t_stack			*get_element_string(char **av);

/*
** INIT and FREE functions
*/

void			free_list(t_lst **list);
void			free_stack(t_stack **stack);
t_stack			*init_stack(int elements);

#endif
