/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 15:19:15 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/19 17:34:09 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int32_t	check_double(int32_t value, struct s_stack stack)
{
	while (stack.top != NULL)
	{
		if (stack.top->element == value)
			return (ERROR);
		stack.top = stack.top->next;
	}
	return (SUCCESS);
}
