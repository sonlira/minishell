/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_executor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 21:32:18 by abaldelo          #+#    #+#             */
/*   Updated: 2025/06/03 18:01:33 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	setup_command_fds(t_cmd *cmd)
{
	if (cmd->last_redir == REDIR_HEREDOC && cmd->fd.heredoc >= 0)
		dup2(cmd->fd.heredoc, STDIN_FILENO);
	if (cmd->last_redir == REDIR_INFILE)
	{
		if (!open_infile_if_needed(cmd, &cmd->fd.infile))
			return (false);
		dup2(cmd->fd.infile, STDIN_FILENO);
	}
	if (cmd->outfile)
	{
		if (!open_outfile_if_needed(cmd, &cmd->fd.outfile))
			return (false);
		dup2(cmd->fd.outfile, STDOUT_FILENO);
	}
	return (true);
}

static void	close_command_fds(t_shell *shell, t_cmd_fds fds, size_t idx)
{
	size_t	i;

	if (fds.infile >= 0)
		close(fds.infile);
	if (fds.outfile >= 0)
		close(fds.outfile);
	if (fds.heredoc >= 0)
		close(fds.heredoc);
	if (shell->pipes)
	{
		i = 0;
		while (i < (shell->cmd_count - 1))
		{
			if (i != idx - 1)
				close(shell->pipes[i][0]);
			if (i != idx)
				close(shell->pipes[i][1]);
			i++;
		}
	}
}

static int	get_exit_code_from_errno(int errnum)
{
	if (errnum == ENOENT)
		return (UNKNOWN_COMMAND);
	else if (errnum == EACCES || errnum == EISDIR)
		return (CMD_NOT_EXECUTABLE);
	else
		return (EXIT_KO);
}

void	execute_simple_cmd(t_shell *shell, t_cmd *cmd)
{
	if (!shell || !cmd)
		return ;
	if (!setup_command_fds(cmd))
		exit(EXIT_KO);
	close_command_fds(shell, cmd->fd, 0);
	if (is_builtin(cmd->cmd))
		exit(execute_builtin(shell, cmd));
	if (ft_execvp(cmd->cmd, cmd->args, shell->env_cpy) == -1)
	{
		ft_eprintf("minishell: %s: %s\n", cmd->cmd, strerror(errno));
		exit(get_exit_code_from_errno(errno));
	}
}

void	execute_piped_cmd(t_shell *shell, t_cmd *cmd, int **pipes, size_t idx)
{
	if (!shell || !cmd || !pipes)
		return ;
	if (!setup_command_fds(cmd))
		exit(EXIT_KO);
	if (cmd->last_redir == REDIR_NONE && cmd->prev)
		dup2(pipes[idx - 1][0], STDIN_FILENO);
	if (!cmd->outfile && cmd->next)
		dup2(pipes[idx][1], STDOUT_FILENO);
	close_command_fds(shell, cmd->fd, idx);
	if (is_builtin(cmd->cmd))
		exit(execute_builtin(shell, cmd));
	if (ft_execvp(cmd->cmd, cmd->args, shell->env_cpy) == -1)
	{
		ft_eprintf("minishell: %s: %s\n", cmd->cmd, strerror(errno));
		exit(get_exit_code_from_errno(errno));
	}
}
