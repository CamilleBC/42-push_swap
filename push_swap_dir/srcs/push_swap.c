/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:16:15 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/11 17:12:46 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Un second nommé push_swap qui calcule et affiche sur la sortie standard le
** plus petit programme dans le langage des instructions de Push_swap qui trie
** les entiers passés en paramètre.
*/

#include "push_swap.h"

static void	free_all(t_cmd *cmds, t_stack *stack)
{
	if (cmds)
		free_instructions(&cmds);
	if (stack)
		free_stack(&stack);
}

static void	print_output(int32_t cmd[MAX_CMD])
{
	while (*cmd)
	{
		if (*cmd == SA)
			ft_putstr("sa\n");
		else if (*cmd == SB)
			ft_putstr("sb\n");
		else if (*cmd == SS)
			ft_putstr("ss\n");
		else if (*cmd == PA)
			ft_putstr("pa\n");
		else if (*cmd == PB)
			ft_putstr("pb\n");
		else if (*cmd == RA)
			ft_putstr("ra\n");
		else if (*cmd == RB)
			ft_putstr("rb\n");
		else if (*cmd == RR)
			ft_putstr("rr\n");
		else if (*cmd == RRA)
			ft_putstr("rra\n");
		else if (*cmd == RRB)
			ft_putstr("rrb\n");
		else if (*cmd == RRR)
			ft_putstr("rrr\n");
		++cmd;
	}
}

int	main (int ac, char **av)
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
	instructions = run_algorithm(BEST, *stack);
	if (instructions && instructions->cmd_array)
		print_output(instructions->cmd_array);
	// free_all(instructions, stack);
	free_instructions(&instructions);
	free_stack(&stack);
	return (SUCCESS);
}
