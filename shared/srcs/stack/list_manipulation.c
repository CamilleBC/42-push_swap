/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:35:14 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/11 11:25:03 by cbaillat         ###   ########.fr       */
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
	t_lst	*head;
	t_lst	*tmp;
	t_lst	*tail;

	head = NULL;
	tmp = NULL;
	while (original)
	{
		if (!(tail = (t_lst *)malloc(sizeof(t_lst))))
		{
			free_list(&head);
			return (NULL);
		}
		tail->element = original->element;
		tail->next = NULL;
		tail->prev = tmp;
		if (head == NULL)
			head = tail;
		else
			tmp->next = tail;
		tmp = tail;
		original = original->next;
	}
	return (head);
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
