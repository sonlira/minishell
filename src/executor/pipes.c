/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:26:05 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/28 23:07:11 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_pipes(int **pipes, size_t size)
{
	size_t	i;

	if (!pipes || size < 1)
		return ;
	i = 0;
	while (i < size)
	{
		if (pipes[i][0] >= 0)
			close(pipes[i][0]);
		if (pipes[i][1] >= 0)
			close(pipes[i][1]);
		i++;
	}
}

void	destroy_pipes(int ***pipes, size_t size)
{
	if (!pipes || !*pipes || size < 1)
		return ;
	close_pipes(*pipes, size);
	free_matrix(pipes, size);
}

bool	init_pipes(int ***pipes, size_t size)
{
	size_t	i;

	if (!pipes || *pipes || size < 1)
		return (false);
	if (!create_matrix(pipes, size, 2))
		return (false);
	i = 0;
	while (i < size)
	{
		if (pipe((*pipes)[i]) == -1)
			return (destroy_pipes(pipes, i), false);
		i++;
	}
	return (true);
}
