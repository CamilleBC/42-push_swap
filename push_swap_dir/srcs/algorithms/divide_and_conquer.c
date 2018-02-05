/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_and_conquer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 07:03:04 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/05 12:43:18 by cbaillat         ###   ########.fr       */
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
				//debug
				// ft_print("position of %d is %d\n", scan_down->element, position);
			}
			else
			{
				position = find_element(stack->head_a, scan_up->element);
				//debug
				// ft_print("position of %d is %d\n", scan_up->element, position);
			}
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
	t_cmd	*cmds_a;
	t_cmd	*cmds_b;
	t_stack	*stack_cpy;

	if (!(cmds_a = init_instructions()) || !(cmds_b = init_instructions()))
		return (NULL);
	push_biggests_to_b(cmds_b, &stack);
	//debug
	ft_print("Biggests to B:\n");
	print_stack(stack);
	stack_cpy = create_copy(NULL, stack);
	cmds_a = sort_swap(*stack_cpy);
	stack_cpy = create_copy(NULL, stack);
	cmds_b = reverse_sort_swap(*stack_cpy, STACK_B);

	exec_instructions(*cmds_a, &stack);
	exec_instructions(*cmds_b, &stack);
	//debug
	ft_print("Sorted A B:\n");
	print_stack(stack);
	free_stack(stack_cpy);
	while (stack.head_b)
		add_and_exec_cmd(PA, cmds_a, &stack);
	rotate_a_to_first(cmds_a, &stack, EXEC);
	//debug
	ft_print("Sorted:\n");
	print_stack(stack);
	return (cmds_a);
	// Put all the elements superior to the half to side B
	// Sort A in ascending order and sort B in descending order simultaneously:
	//	- we simulate A moves and B moves
	//	- we optimize the moves
	//	- we execute the commands
	// Put back all elements of B in stack A
	// Rotate stack A
}
