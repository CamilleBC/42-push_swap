/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:16:15 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/20 23:39:48 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Un second nommé push_swap qui calcule et affiche sur la sortie standard le
** plus petit programme dans le langage des instructions de Push_swap qui trie
** les entiers passés en paramètre.
*/

#include "push_swap.h"

int	main (int ac, char **av)
{
	int32_t	instructions[MAX_INSTR];
	int32_t	status;
	int32_t	*stack_a;
	int32_t	*stack_b;

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
	stack_b = init_stack();
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (SUCCESS);
}
