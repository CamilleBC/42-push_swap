/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:02:33 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/29 15:37:37 by cbaillat         ###   ########.fr       */
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
	t_lst	*head;
	t_lst	*tail;
	int64_t	elements;
	int64_t	position;
}				t_stack;

struct	s_cmd;

int32_t			check_double(int32_t value, t_stack stack);
t_stack			*copy_stack(t_stack stack);
void			free_stack(t_stack *stack);
t_stack			*get_element_string(char **av);
t_stack			*init_stack(int ac);
int32_t			pop_tail(struct s_stack *stack);
int32_t			pop_head(struct s_stack *stack);
int32_t			push_tail(int32_t value, struct s_stack *stack);
int32_t			push_head(int32_t value, struct s_stack *stack);
t_stack			*return_stack(int ac, char **av);

/*
** LISTS
*/

t_lst			*bisect_list(t_lst *head);
t_lst			*copy_list(t_lst *original);
void			free_list(t_lst *list);
t_lst			*merge_lists(t_lst *half1, t_lst *half2);
t_lst			*mergesort_list(t_lst *list);

#endif
