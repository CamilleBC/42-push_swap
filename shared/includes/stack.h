/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:02:33 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/11 17:44:45 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "shared.h"

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

struct	s_cmd;

int32_t			check_double(int32_t value, t_stack stack);
t_stack			*create_copy(t_stack *cpy, t_stack to_cpy);
t_stack			*copy_stack(t_stack stack);
t_stack			*get_element_string(char **av);
t_stack			*return_stack(int ac, char **av);

/*
** INIT and FREE functions
*/

void	free_stack(t_stack **stack);
t_stack	*init_stack(int elements);

/*
** STACK BASICS
*/

int32_t			pop_tail_a(struct s_stack *stack);
int32_t			pop_head_a(struct s_stack *stack);
int32_t			push_tail_a(int32_t value, struct s_stack *stack);
int32_t			push_head_a(int32_t value, struct s_stack *stack);

/*
** LISTS
*/

t_lst			*bisect_list(t_lst *head);
t_lst			*copy_list(t_lst *original);
void			free_list(t_lst **list);
t_lst			*merge_lists(t_lst *half1, t_lst *half2);
t_lst			*mergesort_list(t_lst *list);

#endif
