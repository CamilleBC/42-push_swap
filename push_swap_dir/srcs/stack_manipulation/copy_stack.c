/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 11:36:23 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/13 20:00:10 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utilities.h"
#include "list_utilities.h"

static void		*free_and_return(t_stack **stack, t_lst **list)
{
	free_list(list);
	free_stack(stack);
	return (NULL);
}

static t_stack	*copy_stack_a(t_stack src, t_stack *dst)
{
	t_lst	*list_copy;

	if (!dst)
		if (!(dst = init_stack(src.elements_a)))
			return (NULL);
	if ((list_copy = copy_list(src.head_a)) == NULL)
	{
		free_stack(&dst);
		return (NULL);
	}
	dst->head_a = list_copy;
	while (list_copy->next != NULL)
		list_copy = list_copy->next;
	dst->tail_a = list_copy;
	dst->elements_a = src.elements_a;
	return (dst);
}

static t_stack	*copy_stack_b(t_stack src, t_stack *dst)
{
	t_lst	*list_copy;

	if (!dst)
		if (!(dst = init_stack(src.elements_b)))
			return (NULL);
	if ((list_copy = copy_list(src.head_b)) == NULL)
	{
		free_stack(&dst);
		return (NULL);
	}
	dst->head_b = list_copy;
	while (list_copy->next != NULL)
		list_copy = list_copy->next;
	dst->tail_b = list_copy;
	dst->elements_b = src.elements_b;
	return (dst);
}

t_stack			*copy_stack(t_stack stack)
{
	t_stack	*stack_copy;

	if ((stack_copy = init_stack(stack.elements_a)) == NULL)
		return (NULL);
	if ((stack_copy = copy_stack_a(stack, stack_copy)) == NULL)
		return (free_and_return(&stack_copy, NULL));
	if (stack.head_b)
		if ((stack_copy = copy_stack_b(stack, stack_copy)) == NULL)
			return (free_and_return(&stack_copy, NULL));
	return (stack_copy);
}

t_stack			*create_copy(t_stack **cpy, t_stack to_cpy)
{
	free_stack(cpy);
	return (copy_stack(to_cpy));
}
