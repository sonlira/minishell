/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_heredocs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 00:04:23 by abaldelo          #+#    #+#             */
/*   Updated: 2025/06/03 21:39:08 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	heredoc_child(t_shell *shell, t_cmd *cmd, int pip[2])
{
	pid_t	pid;
	int		status;

	if (!cmd->heredoc)
		return (true);
	pid = fork();
	if (pid == -1)
		return (false);
	if (pid == 0)
	{
		setup_exec_signals();
		if (!handle_heredoc(shell, cmd, pip))
			exit(EXIT_KO);
		exit(EXIT_OK);
	}
	else
	{
		ignore_child_signals();
		waitpid(pid, &status, 0);
		if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
		{
			ft_putstr_fd("\n", STDOUT_FILENO);
			shell->last_exit = 130;
			return (false);
		}
		if (!WIFEXITED(status) || WEXITSTATUS(status) != EXIT_OK)
			return (false);
	}
	return (true);
}

bool	process_heredocs(t_shell *shell, t_cmd *cmd)
{
	int	pip[2];

	while (cmd)
	{
		if (pipe(pip) == -1)
			return (false);
		if (!heredoc_child(shell, cmd, pip))
		{
			close(pip[0]);
			close(pip[1]);
			return (false);
		}
		close(pip[1]);
		cmd->fd.heredoc = pip[0];
		cmd = cmd->next;
	}
	return (true);
}
