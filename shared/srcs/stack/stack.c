/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 15:19:15 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/22 16:09:19 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int32_t	check_double(int32_t value, t_stack stack)
{
	while (stack.head != NULL)
	{
		if (stack.head->element == value)
			return (ERROR);
		stack.head = stack.head->next;
	}
	return (SUCCESS);
}

void	free_stack(t_stack **stack)
{
	t_lst	*tmp;
	while ((*stack)->head)
	{
		tmp = (*stack)->head->next;
		free((*stack)->head);
		(*stack)->head = tmp;
	}
	free(*stack);
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

t_stack	*init_stack(int ac)
{
	t_stack	*stack;

	if ((stack = (t_stack*)malloc(sizeof(t_stack))) == NULL)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->elements = ac;
	stack->position = 0;
	return (stack);
}

/*
** We need to check:
** - if the parameter is really a number
** - if we don't over/underflow
** - if we don't have doubles
*/

t_stack	*return_stack(int ac, char **av)
{
	int64_t	tmp;
	t_stack	*stack;

	if ((stack = init_stack(ac)) == NULL)
		return (NULL);
	while (--ac >= 0)
	{
		if (!ft_strisnumber(av[ac]))
			return (NULL);
		if ((tmp = ft_atoi64(av[ac])) > INT32_MAX || tmp < INT32_MIN)
			return (NULL);
		if (check_double(tmp, *stack) == ERROR)
			return (NULL);
		push_head(tmp, stack);
	}
	return (stack);
}
