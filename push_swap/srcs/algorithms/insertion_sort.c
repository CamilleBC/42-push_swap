/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 10:04:30 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/29 21:21:30 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* static int32_t	find_element(t_cmd *cmds, t_stack *stack_a)
{
	t_lst * seek;

	seek = stack_a->head;
	stack_a->position = 1;
	while (seek != NULL && seek->next != NULL)
	{
		if (seek->element > seek->next->element)
		{
			if (rotate_a_to_position(cmds, stack_a) == ERROR)
				return (ERROR);
			return (FOUND);
		}
		seek = seek->next;
		++(stack_a->position);
	}
	return (SORTED);
}

static int32_t	insert_element(t_cmd *cmds, t_stack *stack_a, t_stack *stack_b)
{
	t_lst *seek;

	if (stack_a->tail == NULL)
		return (ERROR);
	seek = stack_a->tail;
	//debug
	ft_print("Stack A\n");
	print_stack(*stack_a);
	ft_print("Stack B\n");
	print_stack(*stack_b);
	ft_print("Tail element: %d\n", seek->element);
	ft_print("StackB element: %d\n", stack_b->head->element);
	ft_print("Posistion: %d\n", stack_a->position);
	while (seek != NULL)
	{
		if (stack_b->head != NULL
				&& (seek->element == stack_b->head->element - 1))
		{
			if (add_instructions(PA, cmds, stack_a, stack_b) == ERROR)
				return (ERROR);
			//debug
			ft_print("PA\n");
			print_stack(*stack_a);
		}
		if (stack_a->position > 1)
		{
			--(stack_a->position);
			if (add_instructions(RRA, cmds, stack_a, NULL) == ERROR)
				return (ERROR);
			//debug
			ft_print("RRA\n");
			print_stack(*stack_a);
		}
		else
			return (SUCCESS);
		seek = stack_a->tail;
	}
	return (SUCCESS);
}

static int32_t	sort_element(t_cmd *cmds, t_stack *stack_a, t_stack *stack_b)
{
	t_lst	*scan;

	scan = stack_a->head;
	if (scan->element - scan->next->element == 1)
	{
		ft_print("SA\n");
		add_instructions(SA, cmds, stack_a, stack_b);
		add_instructions(RRA, cmds, stack_a, stack_b);
	}
	else
	{
		ft_print("PB\n");
		add_instructions(PB, cmds, stack_a, stack_b);
		if (insert_element(cmds, stack_a, stack_b) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}
*/

int32_t	check_sorted(t_stack *stack_a, t_stack *stack_b, t_cmd *cmds)
{
	int32_t	position;

	if ((stack_a->position = is_sorted(*stack_a)) != ERROR
				&& stack_b->head == NULL)
	{
		rotate_a_to_position(cmds, stack_a);
	//debug
	ft_print("************\n");
	ft_print("Is Sorted NEXT\n");
		return (SORTED);
	}
	else if ((stack_a->position = is_partially_sorted(*stack_a) != ERROR)
				&& stack_b->head == NULL)
	{
		// store everything in stack B
		if (stack_a->position > stack_a->elements / 2)
			while ((stack_a->position)++ < stack_a->elements)
			{
				add_instructions(RRA, cmds, stack_a, stack_b);
				add_instructions(PB, cmds, stack_a, stack_b);
			}
		else
			while ((stack_a->position)-- > 0)
				add_instructions(PB, cmds, stack_a, stack_b);
		// put everything back in stack A where it should be
		while (stack_b->head != NULL)
		{
			position = search_next_element(*stack_a, stack_b->head->element);
			while (position++ < 0)
				add_instructions(RRA, cmds, stack_a, NULL);
			while (position-- > 0)
				add_instructions(RA, cmds, stack_a, NULL);
			add_instructions(PA, cmds, stack_a, stack_b);
		}
	//debug
	ft_print("************\n");
	ft_print("Is Partially Sorted NEXT\n");
		return (SORTED);
	}
	return (ERROR);
}

int32_t	sort_next(t_stack *stack_a, t_stack *stack_b, t_cmd *cmds)
{
	//debug
	ft_print("************\n");
	ft_print("SORT NEXT\n");
	print_stack(*stack_a);

	if (check_sorted(stack_a, stack_b, cmds) == SORTED)
	{
	//debug
	ft_print("************\n");
	ft_print("CHECK SORTED OK\n");
		return (SORTED);
	}
	else if (stack_a->head->next->element == stack_a->head->element - 1)
		add_instructions(SA, cmds, stack_a, stack_b);
	else if (stack_a->tail->element == stack_a->head->element - 1)
		add_instructions(RRA, cmds, stack_a, stack_b);
	else if (stack_a->head->next->element < stack_a->head->element - 1)
		add_instructions(PB, cmds, stack_a, stack_b);
	else if (stack_b->head != NULL
				&& (stack_a->tail->element == stack_b->head->element - 1))
		add_instructions(PA, cmds, stack_a, stack_b);
	// sleep(2);
	return (FOUND);
}

t_cmd *insertion_sort(t_stack stack_a, t_stack stack_b)
{
	t_cmd	*instr;
	int32_t	status;
		int i = 1;

	if (stack_a.head->next == NULL || (instr = init_instructions()) == NULL)
		return (NULL);
	status = FOUND;
	while (status != SORTED)
	{
		ft_print("-----\n");
		ft_print("original\n");
		print_stack(stack_a);
		if (go_to_closest(&stack_a, &stack_b, instr) == SORTED)
			break;
		else if (sort_next(&stack_a, &stack_b, instr) == SORTED)
			break;
		//debug
		ft_print("-----\n");
		ft_print("after sort\n");
		print_stack(stack_a);
		ft_print("sort_next #%d OK\n", i++);
		// sleep(2);
	}
	return (instr);
}

/* t_cmd *insertion_sort(t_stack stack_a, t_stack stack_b)
{
	t_cmd	*instr;
	int32_t	status;

	if (stack_a.head->next == NULL || (instr = init_instructions()) == NULL)
		return (NULL);
	status = FOUND;
	while (status != SORTED)
	{
		ft_print("-----\n");
		ft_print("original\n");
		print_stack(stack_a);
		if ((status = find_element(instr, &stack_a)) == ERROR)
			return (NULL);
		else if (status == FOUND)
		{
			ft_print("-----\n");
			ft_print("found\n");
			print_stack(stack_a);
			if (sort_element(instr, &stack_a, &stack_b) == ERROR)
				return (NULL);
			ft_print("-----\n");
		}
		ft_print("status is: %d (sorted = 0, found = 1)\n", status);
		sleep(5);
	}
	return (instr);
}
 */
