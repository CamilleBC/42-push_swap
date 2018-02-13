/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:09:14 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/13 15:09:15 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int32_t	check_double(int32_t value, t_stack stack)
{
	while (stack.head_a != NULL)
	{
		if (stack.head_a->element == value)
			return (ERROR);
		stack.head_a = stack.head_a->next;
	}
	return (SUCCESS);
}

t_stack	*get_element_string(char **av)
{
	int32_t	count;
	char	**parameters;
	t_stack	*stack;

	if (*av == NULL)
		return (NULL);
	if ((stack = (t_stack*)malloc(sizeof(t_stack))) == NULL)
		return (NULL);
	parameters = ft_strsplit(*av, ' ');
	count = 0;
	while (parameters[count] != 0)
		++count;
	return (stack = return_stack(count, parameters));
}
