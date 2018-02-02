/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_and_conquer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 07:03:04 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/02 09:02:15 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_biggests_to_b(t_cmd *cmds, t_stack *stack)
{
	t_lst *scan;
	int32_t	biggest;
	int32_t	position;

	scan = stack->head_a;
	biggest = stack->elements_a;
	while (scan)
	{
		if (scan->element > biggest / 2)
		{
			position = find_element(stack->head_a, scan->element);
			print_stack(*stack);
			ft_print("position of %d is %d\n", scan->element, position);
			rotate_a_to_position(cmds, stack, position, EXEC);
			add_and_exec_cmd(PB, cmds, stack);
			scan = stack->head_a;
		}
		else
			scan = scan->next;
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
