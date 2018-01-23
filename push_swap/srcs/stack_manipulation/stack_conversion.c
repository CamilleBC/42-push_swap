/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 18:02:11 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/23 19:24:53 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Using the turtle and hare method, we return a pointer to a node near the
** middle of the list, after having cut the original list before that point.
**/

static t_lst *bisect_stack(t_list *head)
{
	t_lst *fast;
	t_lst *slow;
	t_lst *prev;

	fast = head;
	slow = head;
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		prev = slow;
		slow = slow->next;
	}
	if (prev != NULL)
	{
		prev->next = NULL;
		slow->prev = NULL;
	}
	return (slow);
}

static t_lst *merge_lists(t_lst *half1, t_lst *half2)
{
	t_lst  dummy_head;
	t_lst *tail;
	t_lst **min;
	t_lst *next;

	dummy_head.element = 0;
	dummy_head.next = NULL;
	dummy_head.prev = NULL;
	tail = &dummy_head;
	while ((half1 != NULL) && (half2 != NULL))
	{
		min = (half1->element < half2->element) ? &half1 : &half2;
		next = (*min)->next;
		tail->next = *min;
		tail = tail->next;
		*min = next;
	}
	tail->next = half1 ? half1 : half2;
	return (dummy_head.next);
}

t_lst	*sort_list(t_lst *list)
{
	t_lst	*half1;
	t_lst	*half2;

	half1 = list;
	if ((half1 == NULL) || (half1->next == NULL))
		return half1;
	half2 = bisectList(half1);

	return (merge_lists(sort_list(half1), sort_list(half2)));
}

void sort_stack() {}

void convert_stack(t_stack *stack, t_stack copy)
{
	t_lst *traverse;

	traverse = stack->head;
	while (copy.head != NULL)
	{

		copy.head = copy.head->next;
	}
}
