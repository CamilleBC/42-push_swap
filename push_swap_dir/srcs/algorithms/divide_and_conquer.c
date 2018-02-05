/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_and_conquer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 07:03:04 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/02 09:14:56 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_biggests_to_b(t_cmd *cmds, t_stack *stack)
{
	t_lst *scan_down;
	t_lst *scan_up;
	int32_t	half;
	int32_t	position;

	scan_down = stack->head_a;
	scan_up = stack->tail_a;
	half = stack->elements_a / 2;
	while (scan_up && scan_down)
	{
		if (scan_down->element > half || scan_up->element > half)
		{
			if (scan_down->element > half)
			{
				position = find_element(stack->head_a, scan_down->element);
				ft_print("position of %d is %d\n", scan_down->element, position);
			}
			else
			{
				position = find_element(stack->head_a, scan_up->element);
				ft_print("position of %d is %d\n", scan_up->element, position);
			}
			print_stack(*stack);
			rotate_a_to_position(cmds, stack, position, EXEC);
			add_and_exec_cmd(PB, cmds, stack);
			scan_down = stack->head_a;
			scan_up = stack->tail_a;
		}
		else
		{
			scan_down = scan_down->next;
			scan_up = scan_up->prev;
		}
	}
}

t_cmd	*divide_and_conquer(t_stack stack)
{
	t_cmd	*cmds;

	if (!(cmds = init_instructions()))
		return (NULL);
	push_biggests_to_b(cmds, &stack);
	//debug
	ft_print("Biggests to B:\n");
	print_stack(stack);
	return (cmds);
	// Put all the elements superior to the half to side B
	// Sort A in ascending order and sort B in descending order simultaneously:
	//	- we simulate A moves and B moves
	//	- we optimize the moves
	//	- we execute the commands
	// Put back all elements of B in stack A
	// Rotate stack A
}
