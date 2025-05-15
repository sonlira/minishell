/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:52:03 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/15 12:56:47 by bgil-fer         ###   ########.fr       */
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
	cmd->quoted = false;
	cmd->next = NULL;
	return (cmd);
}

bool	create_cmd_array(t_shell *shell, size_t size)
{
	size_t	i;

	shell->cmd_list = ft_calloc((size + 1), sizeof(t_cmd));
	if (!shell->cmd_list)
		return (false);
	i = 0;
	while (i < size)
	{
		shell->cmd_list[i] = create_cmd_struct();
		i++;
	}
	return (true);
}

static void	free_cmd(t_cmd *cmd, t_cmd *tmp)
{
	if (cmd->next)
		tmp = cmd->next;
	if (cmd->args)
		ft_free_split(&cmd->args);
	if (cmd->outfile)
		ft_free_split(&cmd->outfile);
	if (cmd->cmd)
		free(cmd->cmd);
	if (cmd->infile)
		free(cmd->infile);
	if (cmd->delimiter)
		free(cmd->delimiter);
}

void	free_struct(t_shell *shell)
{
	size_t	i;
	t_cmd	*tmp;
	t_cmd	*cmd;

	if (shell->env_cpy)
		ft_free_split(&shell->env_cpy);
	i = 0;
	if (shell->cmd_list)
	{
		while (shell->cmd_list[i])
		{
			cmd = shell->cmd_list[i];
			while (cmd)
			{
				tmp = NULL;
				free_cmd(cmd, tmp);
				cmd = tmp;
			}
			free(shell->cmd_list[i]);
			i++;
		}
		free(shell->cmd_list);
	}
}
