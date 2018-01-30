/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:37:21 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/30 16:49:46 by cbaillat         ###   ########.fr       */
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
	if (stack.elements_a == 3)
		return (sort_three(*stack_cpy));
	stack_cpy = create_copy(stack_cpy, stack);
	instructions = insertion_sort(*stack_cpy);
	if (instructions && (!ret || ret->count > instructions->count))
		ret = instructions;
	stack_cpy = create_copy(stack_cpy, stack);
	instructions = insertion_sort(*stack_cpy);
	if (instructions && (!ret || ret->count > instructions->count))
		ret = instructions;
	free_stack(stack_cpy);
	return (ret);
}
