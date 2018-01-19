/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 17:18:00 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/19 17:35:38 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "common.h"
# include "../libft/includes/libft.h"

/*
** Forward declaration of s_stack to avoid circular dependencies
*/

struct s_stack;

int32_t	check_double(int32_t value, struct s_stack stack);

#endif
