/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:37:21 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/23 17:39:05 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cmd	*run_algorithm(int8_t choice, t_stack stack_a, t_stack stack_b)
{
	t_cmd	**cmds_array;
	t_cmd	*ret;
	int32_t	i;

	i = 0;
	if ((cmds_array = (t_cmd**)malloc(sizeof(t_cmd*) * NB_ALGOS)) == NULL)
		return (NULL);
	if (choice == INSERTION || choice == BEST)
		cmds_array[i++] = insertion_sort(stack_a, stack_b);
	ret = select_algorithm(cmds_array, i);
	return (ret);

}

t_cmd	*select_algorithm(t_cmd **cmds_array, int32_t size_cmds_array)
{
	t_cmd	*ret;
	int32_t	i;

	i = 0;
	ret = cmds_array[0];
	while (++i < size_cmds_array)
		if (cmds_array[i]->count < ret->count)
			ret = cmds_array[i];
	return (ret);
}
