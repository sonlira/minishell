/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:08:53 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/30 19:01:16 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_cmd(t_cmd *cmd)
{
	if (cmd->cmd)
		free(cmd->cmd);
	if (cmd->args)
		ft_free_split(&cmd->args);
	if (cmd->outfile)
		ft_free_split(&cmd->outfile);
	if (cmd->infile)
		free(cmd->infile);
	if (cmd->delimiter)
		free(cmd->delimiter);
}

void	free_cmd_list(t_shell *shell)
{
	size_t	i;
	t_cmd	*tmp;
	t_cmd	*cmd;

	if (!shell)
		return ;
	i = 0;
	if (shell->cmd_list)
	{
		while (shell->cmd_list[i])
		{
			cmd = shell->cmd_list[i];
			while (cmd)
			{
				tmp = cmd->next;
				free_cmd(cmd);
				cmd = tmp;
			}
			free(shell->cmd_list[i]);
			i++;
		}
		free(shell->cmd_list);
	}
	shell->cmd_list = NULL;
}

void	free_struct(t_shell *shell)
{
	if (!shell)
		return ;
	if (shell->env_cpy)
		ft_free_split(&shell->env_cpy);
	if (shell->cmd_list)
		free_cmd_list(shell);
	if (shell->pids)
		wait_and_free_forks(&shell->pids, shell->cmd_count, NULL);
	if (shell->pipes)
		destroy_pipes(shell->pipes, (shell->cmd_count - 1));
}
