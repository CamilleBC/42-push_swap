/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 11:36:23 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/11 17:11:44 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	*free_and_return(t_stack **stack, t_lst **list)
{
	free_list(list);
	free_stack(stack);
	return (NULL);
}

t_stack	*copy_stack_a(t_stack src, t_stack *dst)
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
	return(dst);
}

t_stack	*copy_stack_b(t_stack src, t_stack *dst)
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
	return(dst);
}

t_stack	*copy_stack(t_stack stack)
{
	t_stack	*stack_copy;

	if ((stack_copy = init_stack(stack.elements_a)) == NULL)
		return (NULL);
	if ((stack_copy = copy_stack_a(stack, stack_copy)) == NULL)
		return (NULL);
	if (stack.head_b)
		if ((stack_copy = copy_stack_b(stack, stack_copy)) == NULL)
			return (free_and_return(&stack_copy, NULL));
	return (stack_copy);
}

t_stack	*create_copy(t_stack *cpy, t_stack to_cpy, int8_t stack_choice)
{
	t_stack	*tmp;

	if (stack_choice == STACK_A)
	{
		if (!cpy)
			return (copy_stack(to_cpy));
		tmp = cpy;
		cpy = copy_stack(to_cpy);
	}
	else if (stack_choice == STACK_B)
	{
		if (!cpy)
			return (copy_stack(to_cpy));
		tmp = cpy;
		cpy = copy_stack(to_cpy);
	}
	else if (stack_choice == STACK_AB)
	{
		if (!cpy)
			return (copy_stack(to_cpy));
		tmp = cpy;
		cpy = copy_stack(to_cpy);
	}
	if (tmp)
		free_stack(&tmp);
	return (cpy);
}
