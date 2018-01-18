/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:36:43 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/18 18:06:57 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# define MALLOC_FAIL (int32_t) -2

typedef struct	s_stack
{
	int32_t	top;
	int32_t	*items;
}				t_stack;

#endif
