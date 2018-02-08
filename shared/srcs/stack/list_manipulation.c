/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:35:14 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/08 18:22:21 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/*
** Using the turtle and hare method, we return a pointer to a node near the
** middle of the list, after having cut the original list before that point.
**/

t_lst *bisect_list(t_lst *head)
{
	t_lst *fast;
	t_lst *slow;
	t_lst *prev;

	fast = head;
	slow = head;
	prev = NULL;
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

t_lst *copy_list(t_lst *original)
{
	t_lst	*copy_head;
	t_lst	*copy;
	t_lst	*tmp;

	copy_head = NULL;
	copy = NULL;
	while (original != NULL)
	{
		if (!(tmp = (t_lst *)malloc(sizeof(t_lst))))
		{
			free_list(copy_head);
			return (NULL);
		}
		tmp->element = original->element;
		tmp->next = NULL;
		tmp->prev = copy;
		if (copy_head == NULL)
			copy_head = tmp;
		else
			copy->next = tmp;
		copy = tmp;
		original = original->next;
	}
	return (copy_head);
}

void	free_list(t_lst *list)
{
	t_lst	*tmp;

	tmp = list;
	while (list != NULL)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
}

/*
** We just need a dummy head to attack the pointer that will return to half the
** elements in the list.
** Then we merge the lists together, the smallest head element going last.
** Combined with the recursive call, this will sort everything in the list.
*/

t_lst *merge_lists(t_lst *half1, t_lst *half2)
{
	t_lst   dummy_head;
	t_lst * tail;
	t_lst **min;
	t_lst * next;

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

/*
** By calling mergesort recursively, we sort the smallest list possible (2 link)
** and then merge them back, and back, and back, etc.
*/

t_lst *mergesort_list(t_lst *list)
{
	t_lst *half1;
	t_lst *half2;

	half1 = list;
	if ((half1 == NULL) || (half1->next == NULL))
		return half1;
	half2 = bisect_list(half1);
	return (merge_lists(mergesort_list(half1), mergesort_list(half2)));
}
