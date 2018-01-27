/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 18:22:27 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/27 08:10:04 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_stack	*get_element_string(char **av)
{
	int32_t	count;
	char	**parameters;
	t_stack	*stack;

	if (*av == NULL)
		return (NULL);
	if ((stack = (t_stack*)malloc(sizeof(t_stack))) == NULL)
		return (NULL);
	parameters = ft_strsplit(*av, ' ');
	count = 0;
	while (parameters[count] != 0)
		++count;
	return (stack = return_stack(count, parameters));
}
