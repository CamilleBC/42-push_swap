/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 19:55:55 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/30 16:43:38 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cmd	*sort_three(t_stack stack)
{
	t_cmd	*instructions;

	if (is_sorted(stack) == SUCCESS)
		return (NULL);
	if ((instructions = init_instructions()) == NULL)
		return (NULL);
	if (stack.head_a->element == 1)
	{
		add_cmd_to_instructions(SA, instructions);
		add_cmd_to_instructions(RA, instructions);
	}
	else if (stack.head_a->element == 2 && stack.head_a->next->element == 3)
		add_cmd_to_instructions(RRA, instructions);
	else if (stack.head_a->element == 2)
		add_cmd_to_instructions(SA, instructions);
	else if (stack.head_a->element == 3 && stack.head_a->next->element == 2)
	{
		add_cmd_to_instructions(SA, instructions);
		add_cmd_to_instructions(RRA, instructions);
	}
	else if (stack.head_a->element == 3)
		add_cmd_to_instructions(RA, instructions);
	return (instructions);
}
