/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:51:55 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/30 16:57:21 by abaldelo         ###   ########.fr       */
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

static bool	execute_builtin_cmd(t_shell *shell, t_cmd *cmd)
{
	if (!is_builtin(cmd->cmd))
		return (false);
	if (cmd->outfile || cmd->last_redir != REDIR_NONE)
		return (false);
	if (cmd->prev || cmd->next)
		return (false);
	shell->last_exit = execute_builtin(cmd->args, &shell->env_cpy);
	return (true);
}

static void	child_execution(t_shell *sh, t_cmd *cmd, size_t idx)
{
	if (sh->pipes)
		execute_piped_cmd(sh, cmd, sh->pipes, idx);
	else
		execute_simple_cmd(sh, cmd);
}

static void	execute_pipeline(t_shell *shell, t_cmd *cmd)
{
	int		status;

	if (execute_builtin_cmd(shell, cmd))
		return ;
	status = 0;
	shell->cmd_count = count_commands(cmd);
	if (shell->cmd_count > 1)
	{
		if (!init_pipes(&shell->pipes, (shell->cmd_count - 1)))
			return ;
	}
	if (!init_forks(shell, cmd, child_execution))
		return (destroy_pipes(&shell->pipes, (shell->cmd_count - 1)));
	if (shell->pipes)
		destroy_pipes(&shell->pipes, (shell->cmd_count - 1));
	wait_and_free_forks(&shell->pids, shell->cmd_count, &status);
	if (WIFEXITED(status))
		shell->last_exit = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		shell->last_exit = 128 + WTERMSIG(status);
}

void	execute_shell_command(t_shell *shell)
{
	size_t	i;

	if (!shell || !shell->cmd_list)
		return ;
	i = 0;
	while (shell->cmd_list[i])
	{
		execute_pipeline(shell, shell->cmd_list[i]);
		i++;
	}
}
