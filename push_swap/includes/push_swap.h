/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:37:55 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/25 15:56:13 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "shared.h"
# include "instructions.h"
# include "print.h"
# include "stack.h"

# define FOUND		(int32_t)1
# define SORTED		(int32_t)0
# define NB_ALGOS	(int8_t)8
# define BEST		(int8_t)0
# define SORT_3		(int8_t)2
# define INSERTION	(int8_t)3

//STACK_MANIPULATION
void	convert_stack(t_stack *stack);
t_cmd	*insertion_sort(t_stack stack_a, t_stack stack_b);
int32_t	rotate_a_to_position(t_cmd *cmds, t_stack *stack);

//ALGORITHMS
t_cmd	*run_algorithm(int8_t choice, t_stack stack_a, t_stack stack_b);
t_cmd	*select_algorithm(t_cmd **cmds_array, int32_t size_cmds_array);

//LISTS
t_lst	*bisect_list(t_lst *head);
t_lst	*copy_list(t_lst *original);
void	free_list(t_lst *list);
t_lst	*merge_lists(t_lst *half1, t_lst *half2);
t_lst	*mergesort_list(t_lst *list);

#endif
