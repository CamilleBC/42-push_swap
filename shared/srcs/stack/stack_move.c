/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:34:59 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/11 17:28:44 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_manipulations.h"

/* int32_t	go_to_closest(t_stack *stack, struct s_cmd *cmds)
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
			add_cmd(RRA, cmds);
			//debug
			print_stack(*stack);
			// sleep(1);
		}
		if (stack->head_a->element == stack->tail_a->element - 1)
			add_cmd(RRA, cmds);
	}
	else
	{
		while (distance-- > 0)
		{
			//debug
			ft_print("RA\n");
			add_cmd(RA, cmds);
			//debug
			print_stack(*stack);
		}
		if (stack->head_a->element != stack->head_a->next->element + 1)
			add_cmd(RA, cmds);
	}
	//debug
	ft_print("GO TO CLOSEST return\n");
	print_stack(*stack);
	// sleep(1);
	return (SUCCESS);
} */

int32_t	rotate_a_to_first(t_cmd *cmds, t_stack *stack, int32_t execute)
{
	int32_t	position;

	//debug
	// ft_print("Stack before rotation:\n");
	// print_stack(*stack);
	if ((position = is_sorted(*stack, STACK_A)) != ERROR)
	// {
		//debug
		// ft_print("Position first is: %d\n", position);
		rotate_a_to_position(cmds, stack, position, execute);
	// }
	return (SUCCESS);
}

int32_t	rotate_to_last(t_cmd *cmds, t_stack *stack, int32_t execute,
						int8_t choice)
{
	int32_t	position;

	//debug
	// ft_print("Stack before rotation:\n");
	// print_stack(*stack);
	if ((position = is_rev_sorted(*stack, choice)) != ERROR)
		rotate_to_position(cmds, stack, position, execute);
	return (SUCCESS);
}

int32_t	rotate_to_position(t_cmd *cmds, t_stack *stack, int32_t position,
								int8_t choice)
{
	int32_t	elements;

	elements = (choice == STACK_A) ? stack->elements_a : stack->elements_b;
	if (position > (elements / 2))
	{
		while (position++ <= elements)
		{
			if (choice == STACK_A)
				add_and_exec_cmd(RRA, cmds, stack);
			else
				add_and_exec_cmd(RRB, cmds, stack);
		}
	}
	else
	{
		while (position-- > 1)
		{
			if (choice == STACK_A)
				add_and_exec_cmd(RA, cmds, stack);
			else
				add_and_exec_cmd(RB, cmds, stack);
		}
	}
	return (SUCCESS);
}



int32_t	rotate_a_to_position(t_cmd *cmds, t_stack *stack, int32_t position,
								int32_t execute)
{
	if (position > (stack->elements_a / 2))
	{
		while (position++ <= stack->elements_a)
		{
			if (execute == EXEC)
				add_and_exec_cmd(RRA, cmds, stack);
			else
				add_cmd(RRA, cmds);
		}
	}
	else
	{
		while (position-- > 1)
		{
			if (execute == EXEC)
				add_and_exec_cmd(RA, cmds, stack);
			else
				add_cmd(RA, cmds);
		}
	}
	return (SUCCESS);
}

int32_t	rotate_b_to_position(t_cmd *cmds, t_stack *stack, int32_t position,
								int32_t execute)
{
	if (position > (stack->elements_b / 2))
	{
		while (position++ < stack->elements_b)
		{
			if (execute == EXEC)
				add_and_exec_cmd(RRB, cmds, stack);
			else
				add_cmd(RRB, cmds);
		}
	}
	else
	{
		while (position-- > 0)
		{
			if (execute == EXEC)
				add_and_exec_cmd(RB, cmds, stack);
			else
				add_cmd(RB, cmds);
		}
	}
	return (SUCCESS);
}
