/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:52:03 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/19 17:35:34 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	init_shell_struct(t_shell *shell, char **envp)
{
	if (!shell || !envp)
		return (false);
	shell->env_cpy = copy_env((const char **)envp);
	if (!shell->env_cpy)
		return (false);
	shell->last_exit = 0;
	shell->running = true;
	shell->cmd_list = NULL;
	return (true);
}

t_cmd	*create_cmd_struct(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->cmd = NULL;
	cmd->args = NULL;
	cmd->infile = NULL;
	cmd->outfile = NULL;
	cmd->append = false;
	cmd->heredoc = false;
	cmd->delimiter = NULL;
	cmd->is_quoted = false;
	cmd->next = NULL;
	return (cmd);
}

bool	create_cmd_list(t_shell *shell, size_t size)
{
	size_t	i;

	shell->cmd_list = ft_calloc((size + 1), sizeof(t_cmd));
	if (!shell->cmd_list)
		return (false);
	i = 0;
	while (i < size)
	{
		shell->cmd_list[i] = create_cmd_struct();
		if (!shell->cmd_list[i])
			return (free_cmd_list(shell), false);
		i++;
	}
	return (true);
}
