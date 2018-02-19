/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:37:21 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/19 08:12:05 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_cmd	*return_best_instructions(t_cmd *old, t_cmd *new)
{
	t_cmd	*ret;

	ret = NULL;
	if (!old || (new && (new->count < old->count)))
	{
		ret = new;
		if (old)
			free_instructions(&old);
	}
	else if (old)
	{
		ret = old;
		if (new)
			free_instructions(&new);
	}
	return (ret);
}

static t_cmd	*run_algo_under_a_hundred(t_stack stack)
{
	t_cmd	*instructions;
	t_cmd	*ret;
	t_stack	*stack_cpy;

	instructions = NULL;
	ret = NULL;
	stack_cpy = copy_stack(stack);
	instructions = sort_small(stack_cpy);
	ret = return_best_instructions(ret, instructions);
	stack_cpy = create_copy(&stack_cpy, stack);
	instructions = bubble_sort(stack_cpy, STACK_A);
	ret = return_best_instructions(ret, instructions);
	stack_cpy = create_copy(&stack_cpy, stack);
	instructions = sort_swap(stack_cpy, STACK_A);
	ret = return_best_instructions(ret, instructions);
	free_stack(&stack_cpy);
	return (ret);
}

t_cmd			*run_algorithm(t_stack stack)
{
	t_cmd	*instructions;
	t_cmd	*ret;
	t_stack	*stack_cpy;

	if (stack.elements_a == 3)
		return (sort_three(&stack));
	ret = NULL;
	if (stack.elements_a <= 100)
		ret = run_algo_under_a_hundred(stack);
	stack_cpy = copy_stack(stack);
	instructions = selection_sort(stack_cpy);
	ret = return_best_instructions(ret, instructions);
	stack_cpy = create_copy(&stack_cpy, stack);
	instructions = merge_sort(stack_cpy);
	ret = return_best_instructions(ret, instructions);
	free_stack(&stack_cpy);
	return (ret);
}
