/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:15:43 by abaldelo          #+#    #+#             */
/*   Updated: 2025/06/16 12:25:44 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	wait_forks(pid_t **pids, size_t size, int *status)
{
	size_t	i;

	if (!pids || size < 1)
		return ;
	i = 0;
	while (i < size)
	{
		ignore_child_signals();
		waitpid((*pids)[i], status, 0);
		if (WIFSIGNALED(*status) && WTERMSIG(*status) == SIGINT)
			ft_putstr_fd("\n", STDOUT_FILENO);
		else if (WIFSIGNALED(*status) && WTERMSIG(*status) == SIGQUIT)
			ft_putstr_fd("Quit\n", STDOUT_FILENO);
		i++;
	}
}

void	wait_and_free_forks(pid_t **pids, size_t size, int *status)
{
	if (!pids || size < 1)
		return ;
	wait_forks(pids, size, status);
	free(*pids);
	*pids = NULL;
}

static void	kill_forks(pid_t **pids, size_t size)
{
	size_t	i;

	if (!pids || size < 1)
		return ;
	i = 0;
	while (i < size)
	{
		if ((*pids)[i] > 0)
			kill((*pids)[i], SIGTERM);
		i++;
	}
	wait_forks(pids, size, NULL);
	free(*pids);
	*pids = NULL;
}

bool	init_forks(t_shell *shell, t_cmd *cmd,
	void (*child_fn)(t_shell *, t_cmd *, size_t idx))
{
	size_t	i;

	if (!shell || !cmd || shell->cmd_count < 1)
		return (false);
	shell->pids = ft_calloc(shell->cmd_count, sizeof(pid_t));
	if (!shell->pids)
		return (false);
	i = 0;
	while (i < shell->cmd_count && cmd)
	{
		shell->pids[i] = fork();
		if (shell->pids[i] == -1)
			return (kill_forks(&shell->pids, i), false);
		if (shell->pids[i] == 0)
		{
			// setup_exec_signals();
			signal(SIGINT, SIG_DFL);
			signal(SIGQUIT, SIG_DFL);
			child_fn(shell, cmd, i);
			exit(EXIT_OK);
		}
		i++;
		cmd = cmd->next;
	}
	return (true);
}
