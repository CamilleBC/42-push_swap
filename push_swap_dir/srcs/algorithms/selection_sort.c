#include "push_swap.h"

t_cmd	*selection_sort(t_stack stack)
{
	t_cmd	*cmds;
	int		position;

	if (!(cmds = init_instructions()))
		return (NULL);
	while (stack.head_a->next)
	{
		stack.smallest = return_smallest_element(stack.head_a);
		position = find_element(stack.head_a, stack.smallest);
		//debug
		// ft_print("\n*********************\n");
		// print_stack(stack);
		// ft_print("Smallest element: %d || position: %d\n", stack.smallest, position);
		// ft_print("\n*********************\n");
		//debug
		rotate_to_position(cmds, &stack, position, STACK_A);
		add_and_exec_cmd(PB, cmds, &stack);
	}
	while (stack.head_b)
		add_and_exec_cmd(PA, cmds, &stack);
	return (cmds);
}
