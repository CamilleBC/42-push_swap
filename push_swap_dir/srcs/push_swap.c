/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:16:15 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/13 15:43:29 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_output(int32_t cmd[MAX_CMD])
{
	while (*cmd++)
		if (*(cmd - 1) == SA)
			ft_putstr("sa\n");
		else if (*(cmd - 1) == SB)
			ft_putstr("sb\n");
		else if (*(cmd - 1) == SS)
			ft_putstr("ss\n");
		else if (*(cmd - 1) == PA)
			ft_putstr("pa\n");
		else if (*(cmd - 1) == PB)
			ft_putstr("pb\n");
		else if (*(cmd - 1) == RA)
			ft_putstr("ra\n");
		else if (*(cmd - 1) == RB)
			ft_putstr("rb\n");
		else if (*(cmd - 1) == RR)
			ft_putstr("rr\n");
		else if (*(cmd - 1) == RRA)
			ft_putstr("rra\n");
		else if (*(cmd - 1) == RRB)
			ft_putstr("rrb\n");
		else if (*(cmd - 1) == RRR)
			ft_putstr("rrr\n");
}

int			main(int ac, char **av)
{
	t_cmd	*instructions;
	t_stack	*stack;

	if (ac < 2)
		return (SUCCESS);
	else if (ac == 2)
		stack = get_element_string(&av[1]);
	else
		stack = return_stack(ac - 1, &av[1]);
	if (!stack)
	{
		ft_putstr("Error\n");
		return (SUCCESS);
	}
	convert_stack(stack);
	instructions = NULL;
	instructions = run_algorithm(*stack);
	if (instructions)
		print_output(instructions->cmd_array);
	free_instructions(&instructions);
	free_stack(&stack);
	return (SUCCESS);
}
