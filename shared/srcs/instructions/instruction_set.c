/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 23:58:38 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/22 11:46:55 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "instructions.h"

void	double_instruction(void (*ptr_func)(t_stack*),
			t_stack *stack_a, t_stack *stack_b)
{
	ptr_func(stack_a);
	ptr_func(stack_b);
}
/*
** INIT	|	x--	head	-->	head->next --> end| tmp == NULL
**
** A = tmp = head->next
**
** A	|		x-- head <--> tmp <--> end
**
** 1	|		x-- head <--x tmp <--> end
**					    |___________î
**
** 2	|		x-- head <--x tmp x--> end
**					    î___________î
**
** 3	|		<-- head <--x tmp x--> end
**				|	    î__î________î
**				|__________|
**
** State| <-- tmp <--x head <--> end
**		  |			 î
**		  |__________|
**
** 4	| <-- tmp <--> head <--> end
**		  |			 î
**		  |__________|
**
** 5	| x-- tmp <--> head <--> end
*/

void	swap(t_stack *stack)
{
	t_lst	*tmp;
	t_lst	*end;

	if (!(stack->head && stack->head->next))
		return ;
	tmp = stack->head->next;
	end = tmp->next;
	stack->head->next = tmp->next;
	end->prev = stack->head;
	stack->head->prev = tmp;
	tmp->next = stack->head;
	tmp->prev = NULL;
	stack->head = tmp;
}

void	push(t_stack *stack_from, t_stack *stack_to)
{
	t_lst	*tmp;

	if (!stack_from->head)
		return ;
	tmp = stack_from->head->next;
	stack_from->head->next = stack_to->head;
	if (stack_to->head)
		stack_to->head->prev = stack_from->head;
	stack_to->head = stack_from->head;
	if (!stack_to->tail)
		stack_to->tail = stack_to->head;
	stack_from->head = tmp;
	if (!tmp)
		stack_from->tail = tmp;
	else
		stack_from->head->prev = NULL;
}

void	rotate(t_stack *stack)
{
	t_lst	*tmp;

	if (!(stack->head && stack->head->next))
		return ;
	tmp = stack->head->next;
	stack->tail->next = stack->head;
	stack->head->prev = stack->tail;
	stack->head->next = NULL;
	tmp->prev = NULL;
	stack->tail =  stack->head;
	stack->head = tmp;
}

void	rev_rotate(t_stack *stack)
{
	t_lst	*tmp;

	if (!(stack->tail && stack->tail->prev))
		return ;
	tmp = stack->tail->prev;
	stack->tail->next = stack->head;
	stack->head->prev = stack->tail;
	stack->tail->prev = NULL;
	tmp->next = NULL;
	stack->head = stack->tail;
	stack->tail = tmp;
}
