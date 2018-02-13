/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:45:52 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/13 14:52:30 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utilities.h"

t_lst	*return_stack_head(t_stack stack, int8_t stack_choice)
{
	if (stack_choice == STACK_A && stack.head_a)
		return (stack.head_a);
	else if (stack_choice == STACK_B && stack.head_b)
		return (stack.head_b);
	else
		return (NULL);
}
