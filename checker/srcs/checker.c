/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:15:49 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/30 14:52:55 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Un premier nommé checker qui prend des entiers en paramètres et qui lit des
** instructions sur l’entrée standard. Une fois ces instructions lues, checker
** les exécute puis affiche OK si les entiers sont triés, ou KO sinon.
*/

#include "checker.h"

static void	free_all(t_cmd *cmds, t_stack *stack)
{
	free_instructions(cmds);
	free_stack(stack);
}

int			main (int ac, char **av)
{
	t_cmd	*instructions;
	int32_t	status;
	t_stack	*stack;

	if (ac < 2)
		return (SUCCESS);
	else if (ac == 2)
		stack = get_element_string(&av[1]);
	else
		stack = return_stack(ac - 1, &av[1]);
	if (stack == NULL)
	{
		ft_putstr("Error\n");
		return (SUCCESS);
	}
	instructions = init_instructions();
	if (return_instructions(instructions) != ERROR)
	{
		exec_instructions(*instructions, stack);
		if (is_sorted(*stack) == SUCCESS)
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
	}
	else
		ft_putstr("Error\n");
	print_stack(*stack);
	print_instructions(COUNT, *instructions);
	free_all(instructions, stack);
	return (SUCCESS);
}
