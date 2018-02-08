/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 17:37:48 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/08 12:11:37 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

# include "shared.h"
# include "stack.h"

/*
** Intel PCs (including Macs) are little endians, so string bytes are in
** reverse order.
*/

# define EXEC	(int8_t)1
# define SIM	(int8_t)0
# define NO_CMD	(int32_t)0x0
# define SA		(int32_t)0x6173
# define SB		(int32_t)0x6273
# define SS		(int32_t)0x7373
# define PA		(int32_t)0x6170
# define PB		(int32_t)0x6270
# define RA		(int32_t)0x6172
# define RB		(int32_t)0x6272
# define RR		(int32_t)0x7272
# define RRA	(int32_t)0x617272
# define RRB	(int32_t)0x627272
# define RRR	(int32_t)0x727272
# define MAX_CMD	50000

typedef struct	s_cmd
{
	int32_t	cmd_array[MAX_CMD];
	int64_t	count;
}				t_cmd;

int32_t	add_and_exec_cmd(int32_t cmd, t_cmd *cmds, t_stack *stack);
int32_t	add_cmd(int32_t cmd, t_cmd *cmds);
void	append_instructions(t_cmd *original, t_cmd *to_append);
void	exec_command(int32_t cmd, t_stack *stack);
void	exec_instructions(t_cmd cmds, t_stack *stack);

/*
** INIT and FREE functions
*/

void	free_instructions(t_cmd *cmds);
t_cmd	*init_instructions(void);

/*
** INSTRUCTION SET
*/

void	push_a(t_stack *stack);
void	push_b(t_stack *stack);
void	rev_rotate_a(t_stack *stack);
void	rev_rotate_b(t_stack *stack);
void	rev_rotate_ab(t_stack *stack);
void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	rotate_ab(t_stack *stack);
void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	swap_ab(t_stack *stack);

#endif
