/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_heredocs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 00:04:23 by abaldelo          #+#    #+#             */
/*   Updated: 2025/06/06 21:44:39 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	heredoc_child(t_shell *shell, t_cmd *cmd, int pipes[2])
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
		if (!handle_heredoc(shell, cmd, pipes))
			exit(EXIT_KO);
		exit(EXIT_OK);
	}
	ignore_child_signals();
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		return (shell->last_exit = 130, false);
	}
	if (!WIFEXITED(status) || WEXITSTATUS(status) != EXIT_OK)
		return (false);
	return (true);
}

bool	process_heredocs(t_shell *shell, t_cmd *cmd)
{
	int	heredoc_pipes[2];

	while (cmd)
	{
		if (pipe(heredoc_pipes) == -1)
			return (false);
		if (!heredoc_child(shell, cmd, heredoc_pipes))
		{
			close(heredoc_pipes[0]);
			close(heredoc_pipes[1]);
			return (false);
		}
		close(heredoc_pipes[1]);
		cmd->fd.heredoc = heredoc_pipes[0];
		cmd = cmd->next;
	}
	return (true);
}
