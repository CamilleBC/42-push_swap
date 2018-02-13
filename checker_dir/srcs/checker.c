/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:15:49 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/13 15:08:24 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void		free_all(t_cmd *cmds, t_stack *stack)
{
	if (cmds)
		free_instructions(&cmds);
	if (stack)
		free_stack(&stack);
}

static int32_t	is_sorted_checker(t_stack stack)
{
	t_lst	*scan;

	if (stack.head_b || !stack.head_a)
		return (ERROR);
	scan = stack.head_a;
	while (scan != NULL && scan->next != NULL)
	{
		if (scan->element > scan->next->element)
			return (ERROR);
		scan = scan->next;
	}
	return (SUCCESS);
}

static void		run_checker(t_stack *stack, t_cmd *cmds)
{
	if ((cmds = init_instructions()))
		if (return_instructions(cmds) != ERROR)
		{
			exec_instructions(*cmds, stack);
			if (is_sorted_checker(*stack) == SUCCESS)
				ft_putstr("OK\n");
			else
				ft_putstr("KO\n");
		}
}

int				main(int ac, char **av)
{
	t_cmd	*cmds;
	t_stack	*stack;

	stack = NULL;
	cmds = NULL;
	if (ac < 2)
		return (SUCCESS);
	else if (ac == 2)
		stack = get_element_string(&av[1]);
	else
		stack = return_stack(ac - 1, &av[1]);
	if (stack)
		run_checker(stack, cmds);
	else
		ft_putstr("Error\n");
	free_all(cmds, stack);
	return (SUCCESS);
}
