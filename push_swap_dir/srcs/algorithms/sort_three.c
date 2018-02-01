/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 19:55:55 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/31 14:25:51 by cbaillat         ###   ########.fr       */
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
	//debug
	ft_print("SORT THREE:\n");
	print_stack(stack);
	print_instructions(BOTH, *instructions);
	return (instructions);
}
