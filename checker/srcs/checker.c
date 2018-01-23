/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:15:49 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/23 14:59:01 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Un premier nommé checker qui prend des entiers en paramètres et qui lit des
** instructions sur l’entrée standard. Une fois ces instructions lues, checker
** les exécute puis affiche OK si les entiers sont triés, ou KO sinon.
*/

#include "checker.h"

static void	free_all(t_cmd *cmds, t_stack *stack_a, t_stack *stack_b)
{
	free_instructions(cmds);
	free_stack(stack_a);
	free_stack(stack_b);
}

int			main (int ac, char **av)
{
	t_cmd	*instructions;
	int32_t	status;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (SUCCESS);
	else if (ac == 2)
		stack_a = get_element_string(&av[1]);
	else
		stack_a = return_stack(ac - 1, &av[1]);
	if (stack_a == NULL)
	{
		ft_putstr("Error\n");
		return (SUCCESS);
	}
	stack_b = init_stack(0);
	instructions = init_instructions();
	if (return_instructions(instructions) != ERROR)
	{
		sort_elements(instructions, stack_a, stack_b);
		if ((status = check_elements(*stack_a, *stack_b)) == FAILURE)
			ft_putstr("KO\n");
		else if (status == SUCCESS)
			ft_putstr("OK\n");
	}
	else
		ft_putstr("Error\n");
	print_stack(*stack_a);
	print_instructions(COUNT, *instructions);
	free_all(instructions, stack_a, stack_b);
	return (SUCCESS);
}
