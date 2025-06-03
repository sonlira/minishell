/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:15:43 by abaldelo          #+#    #+#             */
/*   Updated: 2025/06/02 21:53:57 by abaldelo         ###   ########.fr       */
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
		waitpid((*pids)[i], status, 0);
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
	// t_cmd	*tmp;

	if (!shell || !cmd || shell->cmd_count < 1)
		return (false);
	shell->pids = ft_calloc(shell->cmd_count, sizeof(pid_t));
	if (!shell->pids)
		return (false);
	i = 0;
	while (i < shell->cmd_count && cmd)
	{
		// tmp = cmd->next;
		shell->pids[i] = fork();
		if (shell->pids[i] == -1)
			return (kill_forks(&shell->pids, i), false);
		if (shell->pids[i] == 0)
		{
			child_fn(shell, cmd, i);
			exit(EXIT_OK);
		}
		i++;
		cmd = cmd->next;
	}
	return (true);
}
