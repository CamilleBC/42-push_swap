#include "checker.h"

static int32_t	check_instructions(int32_t *instr)
{
	int32_t	i;

	i = 0;
	if (instr == NULL)
		return (SUCCESS);
	while (instr[i] != 0)
	{
		if (!(instr[i] == SA
			|| instr[i] == SB
			|| instr[i] == SS
			|| instr[i] == PA
			|| instr[i] == PB
			|| instr[i] == RA
			|| instr[i] == RB
			|| instr[i] == RR
			|| instr[i] == RRA
			|| instr[i] == RRB
			|| instr[i] == RRR))
				return (ERROR);
		++i;
	}
	return (SUCCESS);
}

/*
** We cast the char pointer into an in32_t pointer to get the raw value of the
** first four octets (no instruction is longer than 3 chars)
** We need to mask the first 2 bytes, as we can get artefacts from other lines
** WARNING: Intel PCs are little endians so bytes are in reverse order.
*/

int32_t			return_instructions(t_cmd *cmds)
{
	char	*line;
	int32_t	status;
	int32_t	i;

	i = 0;
	while ((status = get_next_line(0, &line)) > FILE_READ)
	{
		if (ft_strlen(line) > 3)
		{
			free(line);
			return (ERROR);
		}
		else if (cmds->cmd_array == NULL || !(i % (MAX_CMD / sizeof(int32_t) - 1)))
			cmds->cmd_array = ft_realloc(cmds->cmd_array, i * sizeof(int32_t),
						i * sizeof(int32_t) + MAX_CMD);
		cmds->cmd_array[i++] = (*(int32_t *)line & 0x00FFFFFF);
		free(line);
	}
	free(line);
	if (status == ERROR)
		return (ERROR);
	if (check_instructions(cmds->cmd_array) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
/*
int32_t			return_instructions(t_cmd *cmds)
{
	char	*line;
	int32_t	status;
	int32_t	i;
	int32_t	*instr;

	i = 0;
	instr = cmds->cmd_array;
	while ((status = get_next_line(0, &line)) > FILE_READ)
	{
		if (ft_strlen(line) > 3)
		{
			free(line);
			return (ERROR);
		}
		else if (instr == NULL || !(i % (MAX_INSTR / sizeof(instr) - 1)))
			instr = ft_realloc(instr, i * sizeof(*instr),
						i * sizeof(instr) + MAX_INSTR);
		instr[i++] = (*(int32_t *)line & 0x00FFFFFF);
		free(line);
	}
	free(line);
	cmds->cmd_array = instr;
	if (status == ERROR)
		return (ERROR);
	if (check_instructions(instr) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
*/
