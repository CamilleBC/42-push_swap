/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 17:18:00 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/20 16:11:42 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "common.h"
# include "stack.h"
# include "../libft/includes/libft.h"

typedef struct	s_lst
{
	struct s_lst	*next;
	struct s_lst	*prev;
	int32_t			element;
}				t_lst;

typedef struct	s_stack
{
	t_lst	*top;
	t_lst	*bottom;
}				t_stack;

int32_t			check_double(int32_t value, t_stack stack);
t_stack			*get_element_string(char **av);
t_stack			*init_stack(void);
t_stack			*return_stack(int ac, char **av);

#endif
