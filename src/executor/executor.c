/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:51:55 by abaldelo          #+#    #+#             */
/*   Updated: 2025/06/03 00:05:43 by abaldelo         ###   ########.fr       */
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
	shell->last_exit = execute_builtin(shell, cmd);
	return (true);
}

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
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_IGN);
		if (!handle_heredoc(shell, cmd, pip))
			exit(EXIT_KO);
		exit(EXIT_OK);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
		{
			write(STDOUT_FILENO, "\n", 1);
			shell->last_exit = 130;
			return (false);
		}
		if (!WIFEXITED(status) || WEXITSTATUS(status) != EXIT_OK)
			return (false);
	}
	return (true);
}

static bool	process_heredocs(t_shell *shell, t_cmd *cmd)
{
	int	pip[2];

	ignore_signals();
	while (cmd)
	{
		if (pipe(pip) == -1)
			return (false);
		signal(SIGINT, heredoc_sigint_handler);
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
	signal(SIGINT, handler_sigint);
	return (true);
}

static void	child_execution(t_shell *sh, t_cmd *cmd, size_t idx)
{
	if (sh->pipes)
		execute_piped_cmd(sh, cmd, sh->pipes, idx);
	else
		execute_simple_cmd(sh, cmd);
}

static void	execute_pipeline(t_shell *sh, t_cmd *cmd)
{
	int		status;

	if (execute_builtin_cmd(sh, cmd))
		return ;
	sh->cmd_count = count_commands(cmd);
	if (sh->cmd_count > 1 && !init_pipes(&sh->pipes, (sh->cmd_count - 1)))
		return ;
	if (!process_heredocs(sh, cmd))
		return ;
	if (!init_forks(sh, cmd, child_execution))
		return (destroy_pipes(&sh->pipes, (sh->cmd_count - 1)));
	if (sh->pipes)
		destroy_pipes(&sh->pipes, (sh->cmd_count - 1));
	wait_and_free_forks(&sh->pids, sh->cmd_count, &status);
	if (WIFEXITED(status))
		sh->last_exit = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		sh->last_exit = 128 + WTERMSIG(status);
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
