/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:15:49 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/18 18:39:33 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Un premier nommé checker qui prend des entiers en paramètres et qui lit des
** instructions sur l’entrée standard. Une fois ces instructions lues, checker
** les exécute puis affiche OK si les entiers sont triés, ou KO sinon.
*/

#include "checker.h"



int	main (int ac, char **av)
{
	char	*line;
	t_stack	*stack;
	int32_t	gnl_status;
	int32_t	checker_status;
	int32_t	i;

	if (ac < 2)
		return (SUCCESS);
	if ((stack = return_stack(ac - 1, &av[1])) == ERROR)
		ft_putstr("Error\n");
	i = 0;
	while (i < stack->top)
	{
		ft_putstr("Stack #");
		ft_putnbr(i);
		ft_putstr(": ");
		ft_putnbr(stack->items[i]);
		ft_putstr("\n");
	}
	// while ((gnl_status = get_next_line(0, &line)) > FILE_READ)
	// {
		// do instruction;
	// }
	if (gnl_status == ERROR || checker_status == ERROR)
		ft_putstr("Error\n");
	else if (checker_status == SUCCESS)
		ft_putstr("OK\n");
	else if (checker_status == FAILURE)
		ft_putstr("KO\n");
	return (SUCCESS);
}
