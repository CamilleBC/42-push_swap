/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 19:55:55 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/26 16:10:29 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cmd	*sort_three(t_stack stack_a, t_stack stack_b)
{
	t_cmd	*instructions;

	if ((instructions = init_instructions()) == NULL)
		return (NULL);
	if (stack_a.head->element == 1)
	{
		add_instructions(SA, instructions, &stack_a, NULL);
		add_instructions(RA, instructions, &stack_a, NULL);
	}
	else if (stack_a.head->element == 2 && stack_a.head->next->element == 3)
		add_instructions(RRA, instructions, &stack_a, NULL);
	else if (stack_a.head->element == 2)
		add_instructions(SA, instructions, &stack_a, NULL);
	else if (stack_a.head->element == 3 && stack_a.head->next->element == 2)
	{
		add_instructions(SA, instructions, &stack_a, NULL);
		add_instructions(RRA, instructions, &stack_a, NULL);
	}
	else if (stack_a.head->element == 3)
		add_instructions(RA, instructions, &stack_a, NULL);
	return (instructions);
}
