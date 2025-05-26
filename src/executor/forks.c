/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:15:43 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/26 21:00:20 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	wait_forks(pid_t **pids, size_t size)
{
	size_t	i;

	if (!pids || size < 1)
		return ;
	i = 0;
	while (i < size)
	{
		waitpid(pids[i], NULL, 0);
		i++;
	}
}

void	cleanup_forks(pid_t **pids, size_t size)
{
	if (!pids || size < 1)
		return ;
	wait_forks(pids, size);
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
	wait_forks(pids, size);
	free(*pids);
	*pids = NULL;
}

bool	init_forks(pid_t **pids, size_t size)
{
	size_t	i;

	if (!pids || size < 1)
		return (false);
	*pids = ft_calloc(size, sizeof(pid_t));
	if (!*pids)
		return (false);
	i = 0;
	while (i < size)
	{
		(*pids)[i] = fork();
		if ((*pids)[i] == -1)
		{
			kill_forks(pids, i);
			return (false);
		}
		i++;
	}
	return (true);
}
