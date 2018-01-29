/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:34:59 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/29 21:20:57 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int32_t	go_to_closest(t_stack *stack_a, t_stack *stack_b, struct s_cmd *cmds)
{
	int32_t	distance;
	int32_t	b_element;

	//debug
	(stack_b->head == NULL) ?
		(b_element = (-42)) : (b_element = stack_b->head->element);
	distance = find_closest(*stack_a, b_element);
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
			add_instructions(RRA, cmds, stack_a, NULL);
			//debug
			print_stack(*stack_a);
			// sleep(1);
		}
		if (stack_a->head->element == stack_a->tail->element - 1)
			add_instructions(RRA, cmds, stack_a, NULL);
	}
	else
	{
		while (distance-- > 0)
		{
			//debug
			ft_print("RA\n");
			add_instructions(RA, cmds, stack_a, NULL);
			//debug
			print_stack(*stack_a);
		}
		if (stack_a->head->element != stack_a->head->next->element + 1)
			add_instructions(RA, cmds, stack_a, NULL);
	}
	//debug
	ft_print("Go to closest return\n");
	print_stack(*stack_a);
	// sleep(1);
	return (SUCCESS);
}

int32_t	rotate_a_to_position(t_cmd *cmds, t_stack *stack_a)
{
	int64_t	position;

	position = stack_a->position;
	ft_print("position = %d\n", position);
	if (position > (stack_a->elements / 2))
	{
		while (position++ <= stack_a->elements)
			if (add_instructions(RRA, cmds, stack_a, NULL) == ERROR)
				return (ERROR);
	}
	else
	{
		ft_print("RA\n");
		while (position-- > 1)
			if (add_instructions(RA, cmds, stack_a, NULL) == ERROR)
				return (ERROR);
	}
	return (SUCCESS);
}
