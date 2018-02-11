/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:37:21 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/11 15:21:52 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cmd	*return_best_instructions(t_cmd *old, t_cmd *new)
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

t_cmd	*run_algorithm(int8_t choice, t_stack stack)
{
	t_cmd	*instructions;
	t_cmd	*ret;
	t_stack	*stack_cpy;

	stack_cpy = create_copy(NULL, stack, STACK_AB);
	ret = NULL;
	if (stack.elements_a == 3)
		return (sort_three(*stack_cpy));
	if (stack.elements_a < 30)
	{
		// stack_cpy = create_copy(NULL, stack, STACK_AB);
		// instructions = sort_small(*stack_cpy);
		// ret = return_best_instructions(ret, instructions);
	}
	if (stack.elements_a < 100)
	{
		stack_cpy = create_copy(NULL, stack, STACK_AB);
		instructions = sort_swap(*stack_cpy);
		ret = return_best_instructions(ret, instructions);
	}
	stack_cpy = create_copy(NULL, stack, STACK_AB);
	instructions = divide_and_conquer(*stack_cpy);
	ret = return_best_instructions(ret, instructions);
	free_stack(&stack_cpy);
	return (ret);
}
