/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 23:58:38 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/20 23:37:36 by cbaillat         ###   ########.fr       */
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
** INIT	|	x--	top	-->	top->next --> end| tmp == NULL
**
** A = tmp = top->next
**
** A	|		x-- top <--> tmp <--> end
**
** 1	|		x-- top <--x tmp <--> end
**					    |___________î
**
** 2	|		x-- top <--x tmp x--> end
**					    î___________î
**
** 3	|		<-- top <--x tmp x--> end
**				|	    î__î________î
**				|__________|
**
** State| <-- tmp <--x top <--> end
**		  |			 î
**		  |__________|
**
** 4	| <-- tmp <--> top <--> end
**		  |			 î
**		  |__________|
**
** 5	| x-- tmp <--> top <--> end
*/

void	swap(t_stack *stack)
{
	t_lst	*tmp;
	t_lst	*end;

	if (!(stack->top && stack->top->next))
		return ;
	tmp = stack->top->next;
	end = tmp->next;
	stack->top->next = tmp->next;
	end->prev = stack->top;
	stack->top->prev = tmp;
	tmp->next = stack->top;
	tmp->prev = NULL;
	stack->top = tmp;
}

void	push(t_stack *stack_from, t_stack *stack_to)
{
	t_lst	*tmp;

	if (!stack_from->top)
		return ;
	tmp = stack_from->top->next;
	stack_from->top->next = stack_to->top;
	if (stack_to->top)
		stack_to->top->prev = stack_from->top;
	stack_to->top = stack_from->top;
	if (!stack_to->bottom)
		stack_to->bottom = stack_to->top;
	stack_from->top = tmp;
	if (!tmp)
		stack_from->bottom = tmp;
	else
		stack_from->top->prev = NULL;
}

void	rotate(t_stack *stack)
{
	t_lst	*tmp;

	if (!(stack->top && stack->top->next))
		return ;
	tmp = stack->top->next;
	stack->bottom->next = stack->top;
	stack->top->prev = stack->bottom;
	stack->top->next = NULL;
	tmp->prev = NULL;
	stack->bottom =  stack->top;
	stack->top = tmp;
}

void	rev_rotate(t_stack *stack)
{
	t_lst	*tmp;

	if (!(stack->bottom && stack->bottom->prev))
		return ;
	tmp = stack->bottom->prev;
	stack->bottom->next = stack->top;
	stack->top->prev = stack->bottom;
	stack->bottom->prev = NULL;
	tmp->next = NULL;
	stack->top = stack->bottom;
	stack->bottom = tmp;
}
