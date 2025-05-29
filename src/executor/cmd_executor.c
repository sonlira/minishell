/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_executor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 21:32:18 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/29 21:44:32 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	setup_command_fds(t_shell *shell, t_cmd *cmd, t_cmd_fds *fd)
{
	init_cmd_fds(fd);
	if (cmd->heredoc)
	{
		if (!handle_heredoc(shell, cmd, &fd->heredoc))
			return (false);
		if (cmd->last_redir == REDIR_HEREDOC)
			dup2(fd->heredoc, STDIN);
	}
	if (cmd->infile)
	{
		if (!open_infile_if_needed(cmd, &fd->infile))
			return (false);
		if (cmd->last_redir == REDIR_INFILE)
			dup2(fd->infile, STDIN);
	}
	if (cmd->outfile)
	{
		if (!open_outfile_if_needed(cmd, &fd->outfile))
			return (false);
		dup2(fd->outfile, STDOUT);
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
	t_cmd_fds	fd;

	if (!shell || !cmd)
		return ;
	if (!setup_command_fds(shell, cmd, &fd))
		exit(EXIT_KO);
	close_command_fds(shell, fd, 0);
	if (is_builtin(cmd->cmd))
		exit(execute_builtin(cmd->args, &shell->env_cpy));
	if (ft_execvp(cmd->cmd, cmd->args, shell->env_cpy) == -1)
	{
		ft_eprintf("minishell: %s: %s\n", cmd->cmd, strerror(errno));
		exit(get_exit_code_from_errno(errno));
	}
}

void	execute_piped_cmd(t_shell *shell, t_cmd *cmd, int **pipes, size_t idx)
{
	t_cmd_fds	fd;

	if (!shell || !cmd || !pipes)
		return ;
	if (!setup_command_fds(shell, cmd, &fd))
		exit(EXIT_KO);
	if (cmd->last_redir == REDIR_NONE && cmd->prev)
		dup2(pipes[idx - 1][0], STDIN);
	if (!cmd->outfile && cmd->next)
		dup2(pipes[idx][1], STDOUT);
	close_command_fds(shell, fd, idx);
	if (is_builtin(cmd->cmd))
		exit(execute_builtin(cmd->args, &shell->env_cpy));
	if (ft_execvp(cmd->cmd, cmd->args, shell->env_cpy) == -1)
	{
		ft_eprintf("minishell: %s: %s\n", cmd->cmd, strerror(errno));
		exit(get_exit_code_from_errno(errno));
	}
}
