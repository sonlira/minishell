/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:51:55 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/27 14:04:47 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	count_commands(t_cmd *cmd)
{
	size_t	count;

	count = 0;
	while (cmd)
	{
		count++;
		cmd = cmd->next;
	}
	return (count);
}

void	run_cmd(t_cmd *cmd, int **pipes, char **env)
{
	int	fd_infile;
	int	fd_outfile;
	int	fd_herdoc;
	size_t	i;

	i = 0;
	if (cmd->infile)
		fd_infile = open(cmd->infile, O_RDONLY);
	if (cmd->outfile)
	{
		if (cmd->append)
			fd_outfile = open(cmd->outfile[i++], O_WRONLY | O_CREAT | O_APPEND, 0644);
		else
			fd_outfile = open(cmd->outfile[i++], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		while (cmd->outfile[i])
		{
			open(cmd->outfile[i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
			close(cmd->outfile[i]);
			i++;
		}
	}
	
	
	// if (cmd->prev == NULL)
	
}

void	execute_pipeline(t_shell *shell, t_cmd *cmd)
{
	size_t	size;
	size_t	i;
	int		**pipes;
	pid_t	*pids;

	// pids = NULL;
	// pipes = NULL;
	size = count_commands(cmd);
	init_pipes(&pipes, (size - 1));
	if (!init_forks(&pids, size))
		return ;
	while (i < size)
	{
		if (pids[i] == 0)
		{
			run_cmd(cmd, pipes, shell->env_cpy);
			exit(EXIT_OK);
		}
		i++;
	}
	wait_and_free_forks(&pids, size);
	destroy_pipes(&pipes, (size - 1));
}

void	execute_shell_command(t_shell *shell)
{
	size_t	i;

	i = 0;
	while (shell->cmd_list[i])
	{
		execute_pipeline(shell, shell->cmd_list[i]);
		i++;
	}
	return ;
}
