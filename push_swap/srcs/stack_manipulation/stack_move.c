/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:34:59 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/30 16:09:51 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int32_t	go_to_closest(t_stack *stack, struct s_cmd *cmds)
{
	int32_t	distance;
	int32_t	b_element;

	(stack->head_b == NULL) ?
		(b_element = (-42)) : (b_element = stack->head_b->element);
	distance = find_closest(*stack, b_element);
	//debug
	ft_print("************\n");
	ft_print("GO TO CLOSEST\n");
	ft_print("Distance = %d\n", (int64_t)distance);
	if (distance < 0)
	{
		while (distance++ < 0)
		{
			//debug
			ft_print("RRA\n");
			add_cmd_to_instructions(RRA, cmds);
			//debug
			print_stack(*stack);
			// sleep(1);
		}
		if (stack->head_a->element == stack->tail_a->element - 1)
			add_cmd_to_instructions(RRA, cmds);
	}
	else
	{
		while (distance-- > 0)
		{
			//debug
			ft_print("RA\n");
			add_cmd_to_instructions(RA, cmds);
			//debug
			print_stack(*stack);
		}
		if (stack->head_a->element != stack->head_a->next->element + 1)
			add_cmd_to_instructions(RA, cmds);
	}
	//debug
	ft_print("GO TO CLOSEST return\n");
	print_stack(*stack);
	// sleep(1);
	return (SUCCESS);
}

int32_t	rotate_a_to_position(t_cmd *cmds, t_stack *stack, int32_t position)
{
	int64_t	position;

	if (position > (stack->elements_a / 2))
		while (position++ <= stack->elements_a)
			add_cmd_to_instructions(RRA, cmds);
	else
		while (position-- > 1)
			add_cmd_to_instructions(RA, cmds);
	return (SUCCESS);
}

int32_t	rotate_b_to_position(t_cmd *cmds, t_stack *stack, int32_t position)
{
	int64_t	position;

	if (position > (stack->elements_b / 2))
		while (position++ <= stack->elements_b)
			add_cmd_to_instructions(RRB, cmds);
	else
		while (position-- > 1)
			add_cmd_to_instructions(RB, cmds);
	return (SUCCESS);
}
