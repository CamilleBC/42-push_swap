/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 11:35:56 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/11 17:11:22 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	*free_and_return(t_stack **stack, t_lst **list)
{
	free_list(list);
	free_stack(stack);
	return (NULL);
}

t_stack	*return_stack(int ac, char **av)
{
	int64_t	tmp;
	int64_t	i;
	t_stack	*stack;
	t_lst	*tmp_lst = NULL;

	if (!(stack = init_stack(ac)))
		return (NULL);
	i = 0;
	while (i < ac)
	{
		if ((!ft_strisnumber(av[i]))
				|| ((tmp = ft_atoi64(av[i])) > INT32_MAX || tmp < INT32_MIN)
				|| (check_double(tmp, *stack) == ERROR)
				|| (!(stack->tail_a = malloc(sizeof(t_list)))))
			return (free_and_return(&stack, NULL));
		stack->tail_a->element = tmp;
		stack->tail_a->next = NULL;
		stack->tail_a->prev = tmp_lst;
		if (!stack->head_a)
			stack->head_a = stack->tail_a;
		else
			tmp_lst->next = stack->tail_a;
		tmp_lst = stack->tail_a;
		i++;
	}
	return (stack);
}
