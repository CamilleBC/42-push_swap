/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:09:14 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/19 08:11:04 by cbaillat         ###   ########.fr       */
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
