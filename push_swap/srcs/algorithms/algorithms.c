/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:37:21 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/30 13:06:34 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cmd	*run_algorithm(int8_t choice, t_stack stack)
{
	t_cmd	**cmds_array;
	t_cmd	*ret;
	t_stack	*stack_cpy;
	int32_t	i;

	i = 0;
	if (is_sorted(stack) == SUCCESS)
	{
		ft_print("----sorted----\n");
		return (NULL);
	}
	if ((cmds_array = (t_cmd**)malloc(sizeof(t_cmd*) * NB_ALGOS)) == NULL)
		return (NULL);
	stack_cpy = copy_stack(stack);
	if (choice == SORT_THREE || stack_a.elements == 3)
		return (sort_three(*stack_cpy));
	free_stack(stack_cpy);
	stack_cpy = copy_stack(stack_a);
	// if (choice == NEARLY_SORTED || choice == BEST)
		// cmds_array[i++] = nearly_sorted(*stack_cpy, stack_b);
	free_stack(stack_cpy);
	stack_cpy = copy_stack(stack_a);
	if (choice == INSERTION || choice == BEST)
		cmds_array[i++] = insertion_sort(*stack_cpy, stack_b);
	free_stack(stack_cpy);
	ret = select_algorithm(cmds_array, i);
	return (ret);

}

t_cmd	*select_algorithm(t_cmd **cmds_array, int32_t size_cmds_array)
{
	t_cmd	*ret;
	int32_t	i;

	i = 0;
	if ((ret = init_instructions()) == NULL)
		return (NULL);
	ret->count = INT64_MAX;
	while (i < size_cmds_array)
	{
		if (cmds_array[i] == NULL)
		{
			++i;
			continue ;
		}
		if (cmds_array[i]->count < ret->count)
			ret = cmds_array[i];
		++i;
	}
	return (ret);
}
