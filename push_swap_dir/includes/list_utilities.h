/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utilities.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:32:34 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/13 14:58:40 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_UTILITIES_H
# define LIST_UTILITIES_H

# include "push_swap.h"

t_lst	*bisect_list(t_lst *head);
t_lst	*copy_list(t_lst *original);
t_lst	*merge_lists(t_lst *half1, t_lst *half2);
t_lst	*mergesort_list(t_lst *list);

#endif
