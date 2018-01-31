/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:37:21 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/31 16:00:59 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_copy(t_stack *cpy, t_stack to_cpy)
{
	if (cpy)
		free_stack(cpy);
	return (copy_stack(to_cpy));
}

t_cmd	*run_algorithm(int8_t choice, t_stack stack)
{
	t_cmd	*instructions;
	t_cmd	*ret;
	t_stack	*stack_cpy;

	stack_cpy = create_copy(NULL, stack);
	ret = NULL;
	if (stack.elements_a == 3)
		return (sort_three(*stack_cpy));
	stack_cpy = create_copy(stack_cpy, stack);
	instructions = sort_small(*stack_cpy);
	if (instructions && (!ret || ret->count > instructions->count))
		ret = instructions;
	stack_cpy = create_copy(stack_cpy, stack);
	instructions = sort_swap(*stack_cpy);
	if (instructions && (!ret || ret->count > instructions->count))
		ret = instructions;
	return (ret);
}
