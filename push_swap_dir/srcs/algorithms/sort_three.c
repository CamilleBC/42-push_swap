/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 19:55:55 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/08 17:45:34 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cmd	*sort_three(t_stack stack)
{
	t_cmd	*instructions;

	stack.smallest = return_smallest_element(stack.head_a);
	if (is_sorted(stack, STACK_A) == SUCCESS)
		return (NULL);
	if ((instructions = init_instructions()) == NULL)
		return (NULL);
	if (stack.head_a->element == 1)
	{
		add_cmd(SA, instructions);
		add_cmd(RA, instructions);
	}
	else if (stack.head_a->element == 2 && stack.head_a->next->element == 3)
		add_cmd(RRA, instructions);
	else if (stack.head_a->element == 2)
		add_cmd(SA, instructions);
	else if (stack.head_a->element == 3 && stack.head_a->next->element == 2)
	{
		add_cmd(SA, instructions);
		add_cmd(RRA, instructions);
	}
	else if (stack.head_a->element == 3)
		add_cmd(RA, instructions);
	return (instructions);
}
