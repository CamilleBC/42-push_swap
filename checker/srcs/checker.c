/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:15:49 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/20 21:16:29 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Un premier nommé checker qui prend des entiers en paramètres et qui lit des
** instructions sur l’entrée standard. Une fois ces instructions lues, checker
** les exécute puis affiche OK si les entiers sont triés, ou KO sinon.
*/

#include "checker.h"

void print_stack(int8_t way, t_stack stack)
{
	int32_t	i;

	i = 0;
	if (way == TOP)
	{
		printf("\nTop:\n");
		while (stack.top != NULL)
		{
			printf("Stack #%d: %d\n", i++, stack.top->element);
			stack.top = stack.top->next;
		}
	}
	else
	{
		printf("\nBottom:\n");
		while (stack.bottom != NULL)
		{
			printf("Stack #%d: %d\n", i++, stack.bottom->element);
			stack.bottom = stack.bottom->prev;
		}
	}
}

void print_instructions(int32_t instr[MAX_INSTR])
{
	int32_t	i = 0;

	while (instr[i])
	{
		printf("Instruction #%d: %s\n", i, (char *)&instr[i]);
		++i;
	}
}

int	main (int ac, char **av)
{
	int32_t	instructions[MAX_INSTR];
	int32_t	status;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (SUCCESS);
	else if (ac == 2)
		stack_a = get_element_string(&av[1]);
	else
		stack_a = return_stack(ac - 1, &av[1]);
	if (stack_a == NULL)
	{
		ft_putstr("Error\n");
		return (SUCCESS);
	}
	stack_b = init_stack();
	printf("\nOriginal Stack:");
	print_stack(TOP, *stack_a);
	if (return_instructions(&instructions) == ERROR)
		ft_putstr("Error\n");
	sort_elements(instructions, stack_a, stack_b);
	printf("\n|-------|\n|Result:|\n|-------|\n");
	if ((status = check_elements(*stack_a, *stack_b)) == FAILURE)
		ft_putstr("KO\n");
	else if (status == SUCCESS)
		ft_putstr("OK\n");
	free_stack(&stack_a);
	free_stack(&stack_b);
	printf("\nFinal Stack:");
	print_stack(TOP, *stack_a);
	printf("\nInstructions:\n");
	print_instructions(instructions);
	return (SUCCESS);
}
